/**
 * @created 8/17/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_OPCUACLIENTOPEN62541_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_OPCUACLIENTOPEN62541_HPP

#pragma once

#include "opcua/IOpcUaClient.hpp"
#include "open62541_compat.hpp"
#include "Open62541LogRedirector.hpp"
#include "tasking/BasicTaskLoopTask.hpp"
#include "timing/BasicTimer.hpp"

#include <functional>
#include <map>
#include <vector>
#include <optional>

namespace semodia::controlengine::native::reflection::opcua
{
    /**
    * @class OpcUaClientOpen62541
    * @brief Wraps the open62541 client in a self-reliant, connection-refreshing task
    * @details WARNING: Open62541LogRedirector **must** be first specialization; the class `this` is attached as the void* logContext and gets reinterpret-casted!
    */
    class OpcUaClientOpen62541 : public Open62541LogRedirector, public IOpcUaClient, public osal::tasking::BasicTaskLoopTask
        {
    private:
        UA_Client* client;
        std::unique_ptr<osal::locking::ILockable> clientOperationsLock;
        std::map<std::pair<UA_UInt32, UA_UInt32>, OpcUaSubscriptionCallback> monitoredItemCallbacks;

        /**
         * @brief Stores the Target URI of the server to connect to (for possible reconnects)
         */
        std::string serverUri;

        /**
         * @brief Contact timer for server keepalives; is reset when communications occur. Iterate uses this timer
         *        to prevent needless securechannel refreshes when regular communications have already taken care of
         *        refreshing the connection.
         */
        osal::timing::BasicTimer keepAliveTimer;

        bool performHouseKeeping;
        std::optional<unsigned  int> subscriptionId;

        /**
         * @brief Attempts to lock the client mutex if not NULL
         */
        void beginAtomicClientOperation();

        /**
         * @brief Attempts to unlock the client mutex if not NULL
         */
        void endAtomicClientOperation();
    protected:
        // inherited from task
        /**
         * @brief Allocates a new client
         */
        virtual void start() override;

        /**
         * @brief Performs connection maintenance by refreshing the securechannel.
         */
        virtual void iterate() override;

        /**
         * @brief Disconnects and **deallocates** the client
         */
        virtual void stop() override;

        /**
        * @brief Wrapper for issuing browse-operations to the server. Invokes the callback for every result found
        */
        virtual UA_StatusCode forEachBrowseResultDo(const UA_NodeId& nodeToBrowse,
                                                    const UA_BrowseDirection& direction,
                                                    const UA_BrowseResultMask& resultsFields,
                                                    const std::uint32_t& nodeClassMask,
                                                    std::function<void(const UA_ReferenceDescription& result)> callback);

        /**
         * @brief Starts a recursive browse operation, starting from relativeBase, following the nodes by BrowseName.
         * @param path is the path to follow; if path is empty, UA_NODEID_NULL is returned
         * @param relativeBase is the node the search should start from; if UA_NODEID_NULL is passed /root is assumed.
         * @return If the node is found, returns the Id of the Node; UA_NODEID_NULL otherwise
         */
        virtual UA_NodeId getNodeByPath( const std::string& path, const UA_NodeId& relativeBase);

        /**
         * @brief Wrapper: Checks if client is alive and the node's parent (dirname) can be found on the server
         * @param path affected
         * @param nodeId of the paths parent node (dirname)
         * @return GOOD, ERROR_NODE_NODE_FOUND or ERROR_OFFLINE
         */
        virtual OpcUaStatusCode checkClientSanity_NodeParent(const std::string &path, UA_NodeId& nodeId) final;

        /**
         * @brief Wrapper: Checks if client is alive and the node can be found on the server
         * @param path affected
         * @param nodeId of the paths parent node (dirname)
         * @return GOOD, ERROR_NODE_NODE_FOUND or ERROR_OFFLINE
         */
        virtual OpcUaStatusCode checkClientSanity_Node(const std::string &path, UA_NodeId& nodeId) final;

    public:
        OpcUaClientOpen62541(std::unique_ptr<osal::locking::ILockable> atomicTaskOperationsLock, std::unique_ptr<osal::locking::ILockable> clientOperationsLock);
        virtual ~OpcUaClientOpen62541();

        // Inherited from client interface
        /**
         * @brief Connects to the given Uri; if no client is allocated using @see doStart(), this will also allocate a new client instance.
         * @param serverUri
         * @return GOOD if a connection is established
         */
        virtual OpcUaStatusCode connect(const std::string& serverUri) override;

        virtual OpcUaStatusCode connect(const std::string& serverUri, const std::vector<std::uint8_t>& certificate, std::vector<std::uint8_t>& keyfile, const std::string& applicationUrn) override;

        /**
         * @brief Disconnects and deallocated the client
         * @return GOOD; this call cannot fail as the client will be destroyed
         */
        virtual OpcUaStatusCode disconnect() override;

        OpcUaStatusCode subscribe(const NodeId& node, OpcUaSubscriptionCallback subscriptionCallback) override;
        OpcUaStatusCode subscribe(const std::string& browsePath, OpcUaSubscriptionCallback subscriptionCallback) override;

        // Inherited from OpcUa interface
        OpcUaNetworkStatus getStatus() final;
        virtual OpcUaStatusCode getIdOfPath(const std::string& path, NodeId& id) override;
        virtual OpcUaStatusCode browse(const std::string& path, std::vector<std::string> &resultList) override;
        virtual OpcUaStatusCode link(const std::string &linkTarget, const std::string &linkLocation) override;
        virtual OpcUaStatusCode link(const NodeId& linkTarget, const std::string &linkLocation) override;
        virtual OpcUaStatusCode createObject(const std::string& path) override;
        virtual OpcUaStatusCode createObject(const std::string &path, const NodeId& requestedId) override;
        virtual OpcUaStatusCode createView(const std::string &path) override;
        virtual OpcUaStatusCode createView(const std::string &path, const NodeId& requestedId) override;
        virtual OpcUaStatusCode createVariable(const std::string& path, const std::any& value, bool writable) override;
        virtual OpcUaStatusCode createVariable(const std::string &path, const std::any &value, const NodeId& requestedId, bool writable) override;
        virtual OpcUaStatusCode readVariableValue(const std::string& path, std::any& value) override;
        virtual OpcUaStatusCode writeVariableValue(const std::string& path, const std::any& value) override;
        virtual OpcUaStatusCode writeVariableValue(const NodeId& nodeId, const std::any &value) override;
        virtual OpcUaStatusCode getNamespaceIndexByUrl(const std::string &namespaceUrl, uint16_t *namespaceIndex) override;
        virtual OpcUaStatusCode deleteNode(const std::string &path) override;
        virtual OpcUaStatusCode deleteNode(const NodeId &nodeToDelete) override;
        virtual OpcUaStatusCode nodeIdExists(const NodeId& id) override;
    };
} // namespace


#endif //SEMODIA_CONTROLENGINE_NATIVE_OPCUACLIENTOPEN62541_HPP
