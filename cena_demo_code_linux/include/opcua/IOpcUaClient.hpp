/**
 * @date      9/1/20
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_IOPCUACLIENT_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_IOPCUACLIENT_HPP

#pragma once

#include <functional>
#include <string>

#include "IOpcUa.hpp"
#include "OpcUaStatusCode.hpp"

namespace semodia::controlengine::native::reflection::opcua
{

    typedef std::function<void(std::any newVal)> OpcUaSubscriptionCallback;
    typedef std::function<void(const std::string& deletedSubscription)> OpcUaSubscriptionDeletionCallback;

    /**
     * @class IOpcUaClient
     * @brief OPC UA Client-specific functionality
     */
    class IOpcUaClient : public IOpcUa
    {
    public:
        virtual ~IOpcUaClient() = default;

        virtual OpcUaStatusCode connect(const std::string& serverUri) = 0;

        virtual OpcUaStatusCode connect(
            const std::string& serverUri,
            const std::vector<std::uint8_t>& certificate,
            std::vector<std::uint8_t>& keyfile,
            const std::string& applicationUrn) = 0;

        virtual OpcUaStatusCode disconnect() = 0;

        virtual OpcUaStatusCode subscribe(const NodeId& node, OpcUaSubscriptionCallback subscriptionCallback) = 0;
        virtual OpcUaStatusCode subscribe(const std::string& browsePath, OpcUaSubscriptionCallback) = 0;
    };
} // namespace semodia::controlengine::native::reflection::opcua

#endif // SEMODIA_CONTROLENGINE_NATIVE_IOPCUACLIENT_HPP
