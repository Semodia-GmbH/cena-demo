/*
 * @author  Chris Paul Iatrou
 * @created 8/17/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_IOPCUA_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_IOPCUA_HPP

#pragma once

#include <any>
#include <vector>
#include <string>
#include "opcua/OpcUaStatusCode.hpp"
#include "opcua/uatypes/NodeId.hpp"

namespace semodia::controlengine::native::reflection::opcua {
    /**
     * @enum OpcUaNetworkStatus
     * @brief Brief, very basic description of the current status of a server or client
     */
    enum class OpcUaNetworkStatus {
        OFFLINE,     //! Non-initialized server or client
        INITIALIZED, //! Namespace initialized or connection parameters set
        ONLINE,      //! Server side listening and/or client side connected
    };

    /**
     * @class IOpcUa
     * @brief The interface provided by an OPC UA Servers and Clients. Services return stack-agnostic status codes
     */
    class IOpcUa {
    public:
        virtual ~IOpcUa() = default;

        /**
         * @brief Returns the current status of the underlying server api
         * @return A server status based on the server apis state @see OpcUaServerStatus
         */
        virtual OpcUaNetworkStatus getStatus() = 0;

        /**
         * @brief Resolve and return the NodeID corresponding to this path
         * @param path to resolve, presumed to be an absolute path from /Root
         * @param id where the result is store; on error, the id is set to NULL;
         * @return GOOD if resolve succeeded or an appropriate error code
         */
        virtual OpcUaStatusCode getIdOfPath(const std::string& path, NodeId& id) = 0;

        /**
         * @brief Tests if a specific NodeId exists on a server
         * @details Usable to establish if assets with fixed NodeIds (mainly in MTP) exist on a server
         * @param id is the NodeId to read
         * @return GOOD if NodeId could be read or an appropriate error code
         */
        virtual OpcUaStatusCode nodeIdExists(const NodeId& id) = 0;

        /**
         * @brief Return the (browse-)names of all nodes in the given path
         * @param path to browse, presumed to be an absolute path from /Root
         * @param resultList is a reference to a list that should the node names in this path
         * @return GOOD if the browse operation succeeded, an appropriate errorcode otherwise
         */
        virtual OpcUaStatusCode browse(const std::string& path, std::vector<std::string>& resultList) = 0;

        /**
         * @brief Create a reference (using ORGANIZES); i.e. in UNIX terms `ln -s linkTarget linkLocation/$(basename linkTarget)`
         *        Note that the linkTarget-Node will appear under linkLocation in UA; it cannot be aliased/renamed or otherwise modified.
         * @param linkTarget is an existing node's path (i.e. link target)
         * @param linkLocation is the parent path of the node under which the linked node will appear (i.e. link parent)
         * @return GOOD if the operation succeeded, NODE_NOT_FOUND if the linkTarget does not exist or an appropriate errorcode otherwise
         */
        virtual OpcUaStatusCode link(const std::string& linkTarget, const std::string& linkLocation) = 0;


        /**
         * @brief Will link an existing node (using ORGANIZES) to a target, similar to link("/from/object_a/a", "to/object_b"), but
         *        will attempt to link to a without knowing its path, expecting that the NodeID of a can somehow be retrieved by the stack.
         * @param linkTarget is an existing node's id (i.e. link target)
         * @param linkLocation is the parent path of the node under which the linked node will appear (i.e. link parent)
         * @return GOOD if the operation succeeded, NODE_NOT_FOUND if the linkTarget does not exist or an appropriate errorcode otherwise
         */
         virtual OpcUaStatusCode link(const NodeId& linkTarget, const std::string& linkLocation) = 0;

        /**
         * @brief  Create an object node under the given path, use "/" as a path separator, e.g. "/objects/app/data". Paths are relative to the server root.
         * @param  path of the node to create in *NIX notation, e.g. `/Objects/myThing/myValue`; the parent directory must exist
         * @param  requestedId is a nodeId specifically requested by the client
         * @return  GOOD on success, ERROR_DUPLICATE if the node already exists or an appropriate error code
         */
        virtual OpcUaStatusCode createObject(const std::string& path) = 0;
        virtual OpcUaStatusCode createObject(const std::string& path, const NodeId& requestedId) = 0;

        /**
         * @brief Create a new variable node of a type derived from the passed c container
         * @param path of the node to create in *NIX notation, e.g. `/Objects/myThing/myValue`; the parent directory must exist
         * @param value used to initialize the variable node and to derive the type
         * @param requestedId is a nodeId specifically requested by the client
         * @param writable defines whether the client-side is allowed to write to this node after creation
         * @return GOOD on success, ERROR_DUPLICATE if the node already exists or an appropriate error code
         */
        virtual OpcUaStatusCode createVariable(const std::string& path, const std::any& value, bool writable) = 0;
        virtual OpcUaStatusCode createVariable(const std::string& path, const std::any& value, const NodeId& requestedId, bool writable) = 0;

        /**
         * @brief Create a new view node
         * @param path of the node to create in *NIX notation, e.g. `/Objects/myThing/myValue`; the parent directory must exist
         * @param requestedId is a nodeId specifically requested by the client
         * @return GOOD on success, ERROR_DUPLICATE if the node already exists or an appropriate error code
         */
        virtual OpcUaStatusCode createView(const std::string& path) = 0;
        virtual OpcUaStatusCode createView(const std::string& path, const NodeId& requestedId) = 0;

        /**
         * @brief Reads a given value from the OPC UA namespace; the value is place in `value`
         * @param path The path of the variableNode to read
         * @param value is a reference to the buffer intended to hold the value; on an error, the buffer is cleared().
         * @return GOOD if the value stores data, ERROR_INVALID is an attempt is made to read anything but Variable and VariableType or an appropriate error code
         */
        virtual OpcUaStatusCode readVariableValue(const std::string& path, std::any& value) = 0;

        /**
         * @brief Write the value contained in any to the node addressed by path
         * @param path The path of the variableNode to write
         * @param value is the data to write, contained in an std::any (may be empty)
         * @return GOOD if the write succeeded, ERROR_INVALID if an attempt was made to write anything but Variable and VariableType or an appropriate error code
         */
        virtual OpcUaStatusCode writeVariableValue(const std::string& path, const std::any& value) = 0;

        virtual OpcUaStatusCode writeVariableValue(const NodeId& nodeId, const std::any& value) = 0;

        /**
         * @brief Retrieve the index of a namespace given a namespace url
         * @param namespaceUrl is the url to search in the servers namespace array
         * @param namespaceIndex contains the index of the namespace with the given URL if return value is GOOD (undefined otherwise)
         * @return GOOD if the namespaceUrl is found, ERROR_NOT_FOUND if the namespace was not found or an appropriate error code
         */
        virtual OpcUaStatusCode getNamespaceIndexByUrl(const std::string& namespaceUrl, std::uint16_t* namespaceIndex) = 0;

        /**
         * @brief Delete an Object, View, Variable or type represented by the given browse path. If multiple nodes match the path, the first match will be deleted.
         * @param path of the variableNode to write, considered a list of browseNames concatenated using "/" (e.g. "/Objects/DeviceSet")
         * @return GOOD if the operation succeeded, ERROR_NOT_FOUND if no node was found under the path or an appropriate error code
         */
        virtual OpcUaStatusCode deleteNode(const std::string& path) = 0;
        virtual OpcUaStatusCode deleteNode(const NodeId& nodeToDelete) = 0;
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_IOPCUA_HPP
