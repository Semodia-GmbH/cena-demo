/**
 * @date 8/17/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_OPCUASERVEROPEN62541_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_OPCUASERVEROPEN62541_HPP

#pragma once

#include <functional>
#include <map>
#include <vector>
#include <list>

#include "open62541_compat.hpp"
#include "opcua/uatypes/NodeId.hpp"
#include "opcua/IOpcUa.hpp"
#include "opcua/IOpcUaServer.hpp"
#include "tasking/BasicTaskLoopTask.hpp"
#include "logging/LogLevels.hpp"
#include "Open62541LogRedirector.hpp"
namespace semodia::controlengine::native::reflection::opcua
{
    /**
     * @class OpcUaServerValueCallbackDescriptor
     * @brief A Descriptor, used by the server to create a callback-map for nodes.
     */
    class OpcUaServerValueCallbackDescriptor {
    public:
        OpcUaServerValueCallbackDescriptor()
                :   path(""),
                    beforeReadCallback(nullptr),
                    afterWriteCallback(nullptr)
        {};

        OpcUaServerValueCallbackDescriptor(std::string path)
                :   path(path),
                    beforeReadCallback(nullptr),
                    afterWriteCallback(nullptr)
        {};

        const std::string& getAssociatedPath() const
        {
            return this->path;
        };

        std::string path;

        /**
         * @brief beforeReadCallback is a pointer to an std::functional called before the server reads a value during a read request; nullptr if unset
         */
        OpcUaChangeNotificationCallback beforeReadCallback;

        /**
         * @brief afterWriteCallback is a pointer to an std::functional called after the server has written a value during a write request; nullptr if unset
         */
        OpcUaChangeNotificationCallback afterWriteCallback;

        /**
         * @brief dataSourceReadCallback is a pointer to a list of std::functional called by the server to read the value of a node (function provides read-value); nullptr if unset
         */
        std::list<OpcUaReadValueCallback> dataSourceReadCallbacks;

        /**
         * @brief dataSourceWriteCallback is a pointer to a list of std::functional called by the server to write the value of a node (function expected to persist write-value); nullptr if unset
         */
        std::list<OpcUaWriteValueCallback> dataSourceWriteCallbacks;
    };

    /**
     * @class OpcUaServerOpen62541
     * @brief Server implementation for open62541 stack
     * @details WARNING: Open62541LogRedirector **must** be first specialization; the class `this` is attached as the void* logContext and gets reinterpret-casted!
     */
    class OpcUaServerOpen62541 : public Open62541LogRedirector, public IOpcUaServer, public osal::tasking::BasicTaskLoopTask
    {
    private:
        /**
         * @brief locked whenever the server contents are manipulated in a threaded environment
         */
        std::unique_ptr<osal::locking::ILockable> serverOperationsLock;

        /**
         * @brief Communicates if the server is currently available - significant for testing connects
         */
        OpcUaNetworkStatus status;

        /**
         * @brief An internal map of callbacks associated with a specific nodeId
         */
        std::map<NodeId, OpcUaServerValueCallbackDescriptor> valueCallbacks;

        const std::uint16_t serverPort;


        /**
         * @brief Attempts to lock the client mutex if not NULL
         */
        void beginAtomicServerOperation();

        /**
         * @brief Attempts to unlock the client mutex if not NULL
         */
        void endAtomicServerOperation();
        
    protected:
        /**
         * @brief the actual server, created during `doStart()` and torn down on `doTerminate()`
         */
        UA_Server* server;

        /**
         * @brief Creates a new server instance and initializes it
         */
        virtual void start() override;

        /**
         * @brief Will call `ua_server_run_iterate()`
         */
        virtual void iterate() override;

        /**
         * @brief Shuts the current server down and deallocates it. ALl address space contents are lost.
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
         *        Note that this function will always follow the first string match; if multiple nodes have the same name,
         *        only the first one will be considered to be part of the path.
         * @param path is the path to follow; if path is empty, UA_NODEID_NULL is returned
         * @param relativeBase is the node the search should start from; if UA_NODEID_NULL is passed /root is assumed.
         * @return If the node is found, returns the Id of the Node; UA_NODEID_NULL otherwise
         */
        virtual UA_NodeId getNodeByPath( const std::string& path, const UA_NodeId& relativeBase);

        /**
         * @brief Wrapper: Checks if server is alive and the node can be found; virtually every server-user-interaction will call this function
         * @param path affected
         * @param nodeId of the paths parent node (dirname)
         * @return GOOD, ERROR_NODE_NODE_FOUND or ERROR_OFFLINE
         */
        virtual OpcUaStatusCode checkServerSanity_NodeParent(const std::string& path, UA_NodeId &id) final;

        /**
         * @brief Wrapper: Checks if server is alive and the node can be found; virtually every server-user-interaction will call this function
         * @param path affected
         * @param nodeId of the paths node (cleanPath)
         * @return GOOD, ERROR_NODE_NODE_FOUND or ERROR_OFFLINE
         */
        virtual OpcUaStatusCode checkServerSanity_Node(const std::string& path, UA_NodeId &id) final;

        /**
         * @brief Wrapper: Checks if server is alive and the node can be found. Overload that supports NodeIds.
         * @param nodeId affected
         * @param uaNodeId the respective UA_nodeId
         * @return GOOD, ERROR_NODE_NODE_FOUND or ERROR_OFFLINE
         */
        virtual OpcUaStatusCode checkServerSanity_Node(const NodeId& nodeId ,UA_NodeId &uaNodeId) final;

    public:
        OpcUaServerOpen62541(std::unique_ptr<osal::locking::ILockable> atomicTaskOperationsLock, std::unique_ptr<osal::locking::ILockable> serverOperationsLock);
        OpcUaServerOpen62541(const std::uint16_t& port, std::unique_ptr<osal::locking::ILockable> atomicTaskOperationsLock, std::unique_ptr<osal::locking::ILockable> serverOperationsLock);

            virtual ~OpcUaServerOpen62541();

        /**
         * @brief The following function is invoked by @see beforeReadCallback_entry() after the class instance is recovered from the context.
         *        The function will search the registered callbacks for a matching function and invoke it.
         * @ingroup open62541_callbacks
         * @param nodeId is the ID the operation is conducted on.
         */
        virtual void beforeReadCallback(const NodeId& nodeId) final;

        /**
         * @brief Extracts the server-class instance from the context and invokes @see beforeReadCallback()
         */
        static void beforeReadCallback_entry( UA_Server *server, const UA_NodeId *sessionId, void *sessionContext,
                                              const UA_NodeId *nodeid, void *nodeContext, const UA_NumericRange *range,
                                              const UA_DataValue *data);

        /**
         * @brief The following function is invoked by @see afterWriteCallback_entry() after the class instance is recovered from the context.
         *        The function will search the registered callbacks for a matching function and invoke it.
         * @ingroup open62541_callbacks
         * @param nodeId is the ID the operation is conducted on.
         */
        virtual void afterWriteCallback(const NodeId& nodeId) final;

        /**
         * @brief Extracts the server-class instance from the context and invokes @see afterWriteCallback()
         */
        static void afterWriteCallback_entry( UA_Server *server,
                                              const UA_NodeId *sessionId, void *sessionContext,
                                              const UA_NodeId *nodeId, void *nodeContext,
                                              const UA_NumericRange *range, const UA_DataValue *data);

        /**
         * @brief The following function is invoked by @see delegateReadCallback_entry() after the class instance is recovered from the context.
         *        The function will search the registered callbacks for a matching function and invoke it.
         *        The invoked function is expected to provide the value that is to be returned to the client as a read result.
         * @ingroup open62541_callbacks
         * @param nodeId is the ID the operation is conducted on.
         */
        virtual UA_StatusCode delegateReadCallback(const NodeId& nodeId, std::any& value) final;

        /**
         * @brief Extracts the server-class instance from the context and invokes @see delegateReadCallback()
         */
        static UA_StatusCode delegateReadCallback_entry( UA_Server *server,
                                                         const UA_NodeId *sessionId, void *sessionContext,
                                                         const UA_NodeId *nodeId, void *nodeContext,
                                                         UA_Boolean sourceTimeStamp, const UA_NumericRange *range,
                                                         UA_DataValue *dataValue);

        /**
         * @brief The following function is invoked by @see delegateWriteCallback_entry() after the class instance is recovered from the context.
         *        The function will search the registered callbacks for a matching function and invoke it.
         *        The invoked function is expected persist the value provided by the client.
         * @ingroup open62541_callbacks
         * @param nodeId is the ID the operation is conducted on.
         */
        virtual UA_StatusCode delegateWriteCallback(const NodeId& nodeId, const std::any& value) final;

        /**
         * @brief Extracts the server-class instance from the context and invokes @see delegateWriteCallback_entry()
         */
        static UA_StatusCode delegateWriteCallback_entry( UA_Server *server,
                                                          const UA_NodeId *sessionId, void *sessionContext,
                                                          const UA_NodeId *nodeId, void *nodeContext,
                                                          const UA_NumericRange *range, const UA_DataValue *data);

        // inherited from server interface
        OpcUaNetworkStatus getStatus() final;
        virtual OpcUaStatusCode getIdOfPath(const std::string& path, NodeId& id) override;
        virtual OpcUaStatusCode getPathOfNodeId(const NodeId& nodeId, std::string& path);
        virtual OpcUaStatusCode browse(const std::string& path, std::vector<std::string>& resultList) override;
        virtual OpcUaStatusCode link(const std::string &linkTarget, const std::string &linkLocation) override;
        virtual OpcUaStatusCode link(const NodeId& linkTarget, const std::string& linkLocation) override;
        virtual OpcUaStatusCode createObject(const std::string& path) override;
        virtual OpcUaStatusCode createObject(const std::string &path, const NodeId& requestedId) override;
        virtual OpcUaStatusCode createView(const std::string &path) override;
        virtual OpcUaStatusCode createView(const std::string &path, const NodeId& requestedId) override;
        virtual OpcUaStatusCode createVariable(const std::string& path, const std::any& value, bool writable) override;
        virtual OpcUaStatusCode createVariable(const std::string &path, const std::any &value, const NodeId& requestedId, bool writable) override;
        virtual OpcUaStatusCode deleteNode(const std::string &path) override;
        virtual OpcUaStatusCode deleteNode(const NodeId &nodeToDelete) override;

        virtual OpcUaStatusCode readVariableValue(const std::string& path, std::any& value) override;
        virtual OpcUaStatusCode writeVariableValue(const std::string& path, const std::any& value) override;
        OpcUaStatusCode writeVariableValue(const NodeId& nodeId, const std::any& value) override;

        virtual OpcUaStatusCode attachValueChangeNotifications(const std::string &path, OpcUaChangeNotificationCallback onRead, OpcUaChangeNotificationCallback onWrite) override;
        virtual OpcUaStatusCode detachValueChangeNotifications(const std::string &path) override;
        virtual OpcUaStatusCode attachValueSourceCallbacks(const std::string &path, OpcUaReadValueCallback readCallback, OpcUaWriteValueCallback writeCallback) override;
        virtual OpcUaStatusCode attachValueSourceCallbacks(const NodeId& id, OpcUaReadValueCallback readCallback, OpcUaWriteValueCallback writeCallback) override;
        virtual OpcUaStatusCode detachValueSourceCallbacks(const std::string &path) override;
        virtual OpcUaStatusCode detachValueSourceCallbacks(const NodeId& nodeId) override;
        virtual OpcUaStatusCode createNamespace(const std::string& namespaceUrl) override;

        virtual OpcUaStatusCode getNamespaceIndexByUrl(const std::string &namespaceUrl, std::uint16_t *namespaceIndex) override;
        virtual OpcUaStatusCode nodeIdExists(const NodeId& id) override;

    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_OPCUASERVEROPEN62541_HPP
