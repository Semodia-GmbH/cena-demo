/**
 * @date      9/1/20
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_IOPCUASERVER_H
#define SEMODIA_CONTROLENGINE_NATIVE_IOPCUASERVER_H

#pragma once

#include <functional>
#include <string>

#include "OpcUaStatusCode.hpp"
#include "IOpcUa.hpp"

namespace semodia::controlengine::native::reflection::opcua
{
    /**
     * @typedef OpcUaChangeNotificatioCallback
     * @brief   A function optionally called by the OPC UA Server whenever a valueNode or valueTypeNode is about to be read from or written to.
     *          The value remains stored in the node.
     * @param   const std::string& is the path of the node, as provided by the registered callback
     */
    typedef std::function<void(const std::string&)> OpcUaChangeNotificationCallback;

    /**
     * @typedef OpcUaReadValueCallback
     * @brief   A function optionally called by the OPC UA Server when  a valueNode or valueTypeNode is read; the node
     *          is considered to not store any value, which is requested as a return value in any
     * @param   const std::string& is the path of the node, as provided by the registered callback
     * @param   std::any& is the return value an is expected to contain the value that is returned to the client
     */
    typedef std::function<void(const std::string&, std::any&)> OpcUaReadValueCallback;

    /**
     * @typedef OpcUaWriteValueCallback
     * @brief   A function optionally called by the OPC UA Server when  a valueNode or valueTypeNode is written; the node
     *          is considered to not store any value; the attached any is the value the client intends to update the
     *          value with
     * @param   const std::string& is the path of the node, as provided by the registered callback
     * @param   std::any& is the value provided by the client
     */
    typedef std::function<void(const std::string&, const std::any&)> OpcUaWriteValueCallback;

    /**
     * @class IOpcUaServer
     * @brief Interface to OPC UA Server-specific functionality
     */
    class IOpcUaServer : public IOpcUa
    {
    public:
        virtual ~IOpcUaServer() = default;

        /**
         * @brief Set callback function that are invoked before a value is read and after it is written. The value is stored on the server.
         * @param path is the path of the value node the callbacks should be attached to.
         * @param onRead will be invoked prior to a read.
         * @param onWrite will be invoked after a write.
         * @return GOOD if the callback was attached, NODE_NOT_FOUND if the path is wrong or an otherwise appropriate error code.
         * @details This callback might in fact not be invoked, if ValueSourceCallbacks are registered.
         */
        virtual OpcUaStatusCode attachValueChangeNotifications(const std::string& path, OpcUaChangeNotificationCallback onRead, OpcUaChangeNotificationCallback onWrite) = 0;

        /**
         * @brief Remove the callbacks from the node. Will return GOOD even if no callbacks are attached.
         * @param path is the path of the value node the callbacks should be attached to.
         * @return GOOD if the callback was attached, NODE_NOT_FOUND if the path is wrong or an otherwise appropriate error code.
         */
        virtual OpcUaStatusCode detachValueChangeNotifications(const std::string& path) = 0;

        /**
         * @brief Set callbacks that provide the data value to the server. The value is not stored in the server and the callbacks are invoked with every client interaction.
         * @param path is the path of the value node the callbacks should be attached to.
         * @param readCallback is invoked if a client want to read the value
         * @param writeCallback is invoked when a client provides a value
         * @return GOOD if the callback was attached, NODE_NOT_FOUND if the path is wrong or an otherwise appropriate error code.
         * @details This function can be invoked multiple times, all callbacks will be executed in their registration order. If multiple registered callbacks modify the read data value, the last registered value takes precedence.
         */
        virtual OpcUaStatusCode attachValueSourceCallbacks(const std::string& path, OpcUaReadValueCallback readCallback, OpcUaWriteValueCallback writeCallback) = 0;

        /**
         * @brief Set callbacks that provide the data value to the server. The value is not stored in the server and the callbacks are invoked with every client interaction.
         * @param nodeId is the OpcUa NodeId of the variable node the callbacks should be attached to
         * @param readCallback is invoked if a client want to read the value
         * @param writeCallback is invoked when a client provides a value
         * @return GOOD if the callback was attached, NODE_NOT_FOUND if the path is wrong or an otherwise appropriate error code.
         * @details This function can be invoked multiple times, all callbacks will be executed in their registration order. If multiple registered callbacks modify the read data value, the last registered value takes precedence.
         */
        virtual OpcUaStatusCode attachValueSourceCallbacks(const NodeId& nodeId, OpcUaReadValueCallback readCallback, OpcUaWriteValueCallback writeCallback) = 0;

        /**
         * @brief Remove the callbacks from the node. Will return GOOD even if no callbacks are attached.
         * @param path is the path of the value node the callbacks should be attached to.
         * @return GOOD if the callback was attached, NODE_NOT_FOUND if the path is wrong or an otherwise appropriate error code.
         */
        virtual OpcUaStatusCode detachValueSourceCallbacks(const std::string& path) = 0;

        /**
         * @brief Remove the callbacks from the node. Will return GOOD even if no callbacks are attached.
         * @param path is the NodeId of the value node the callbacks should be attached to.
         * @return GOOD if the callback was attached, NODE_NOT_FOUND if the path is wrong or an otherwise appropriate error code.
         */
        virtual OpcUaStatusCode detachValueSourceCallbacks(const NodeId& nodeId) = 0;

        /**
         * @brief Register a new namespace (and associated index) in the servers namespace url array
         * @param namespaceUrl
         * @return GOOD if operation succeeded or an otherwise appropriate error code.
         */
        virtual OpcUaStatusCode createNamespace(const std::string& namespaceUrl) = 0;

    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_IOPCUASERVER_H