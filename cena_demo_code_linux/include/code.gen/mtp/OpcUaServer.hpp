/**
 * @file OpcUaServer.hpp
 * @date Wednesday, 19 January 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_OPC_UA_SERVER_HPP
#define HAVE_OPC_UA_SERVER_HPP

#pragma once

#include "mtp/base/OpcUaServer.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class OpcUaServer
     * @brief The OPC UA server object. Containing the information of the OPC UA server.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class OpcUaServer : public base::OpcUaServer
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _OpcUaServer::_OpcUaServer for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        OpcUaServer( 
            const std::string& Name, 
            const std::string& EndpointUrl, 
            const std::uint16_t& MaxSessions, 
            const bool& IsDefault, 
            std::shared_ptr<mtp::OpcUaBasicServerProfile> BasicServerProfile, 
            std::shared_ptr<mtp::OpcUaStandardServerProfile> StandardServerProfile, 
            std::shared_ptr<mtp::OpcUaExtendedServerProfile> ExtendedServerProfile
        );

        /**
         * @brief Simplified CTor - creates a Basic server profile and sets itself as default
         * @param Name
         * @param EndpointUrl
         */
        OpcUaServer(
                const std::string& Name,
                const std::string& EndpointUrl
        );

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _OpcUaServer::~_OpcUaServer  
          */
        virtual ~OpcUaServer() = default;
    };   
}

#endif // defined HAVE_OPC_UA_SERVER_HPP