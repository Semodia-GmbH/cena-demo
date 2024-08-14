/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file OpcUaServer.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_OPC_UA_SERVER_BASE_HPP
#define HAVE_OPC_UA_SERVER_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/SemanticModelEntity.hpp"

#include <string>
#include <cstdint>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class OpcUaBasicServerProfile;
    class OpcUaStandardServerProfile;
    class OpcUaExtendedServerProfile;
    
    class OpcUaServer;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class OpcUaServer
     * @brief The OPC UA server object. Containing the information of the OPC UA server.. This is the base class generated based on the Model Type Package Specification.
     */
    class OpcUaServer : public mtp::SemanticModelEntity
    {
    private:
        /**
          * @brief Simple attribute Name. The name of the OPC UA server within the MTP.
          */ 
        std::string Name;
        /**
          * @brief Simple attribute EndpointUrl. The endpoint URL of the OPC UA server.
          */ 
        std::string EndpointUrl;
        /**
          * @brief Simple attribute MaxSessions. Maximum number of client sessions that are supported simultaneously.
          */ 
        std::uint16_t MaxSessions;
        /**
          * @brief Simple attribute IsDefault. Defines if this OPC UA server is the default OPC UA server which is used for all items without a specified corresponding OPC UA server.
          */ 
        bool IsDefault;
        
        /**
          * @brief Association BasicServerProfile. Defines communication related capabilities specified by the basic server profile for OPC UA.
          */ 
        std::shared_ptr<mtp::OpcUaBasicServerProfile> BasicServerProfile;
        /**
          * @brief Association StandardServerProfile. Defines communication related capabilities specified by the standard server profile for OPC UA.
          */ 
        std::shared_ptr<mtp::OpcUaStandardServerProfile> StandardServerProfile;
        /**
          * @brief Association ExtendedServerProfile. Defines communication related capabilities specified by the extended server profile for OPC UA.
          */ 
        std::shared_ptr<mtp::OpcUaExtendedServerProfile> ExtendedServerProfile;
    
    protected:
        OpcUaServer( 
            const std::string& Name, 
            const std::string& EndpointUrl, 
            const std::uint16_t& MaxSessions, 
            const bool& IsDefault, 
            std::shared_ptr<mtp::OpcUaBasicServerProfile> BasicServerProfile, 
            std::shared_ptr<mtp::OpcUaStandardServerProfile> StandardServerProfile, 
            std::shared_ptr<mtp::OpcUaExtendedServerProfile> ExtendedServerProfile
        ) : mtp::SemanticModelEntity(), Name(Name), EndpointUrl(EndpointUrl), MaxSessions(MaxSessions), IsDefault(IsDefault), BasicServerProfile(BasicServerProfile), StandardServerProfile(StandardServerProfile), ExtendedServerProfile(ExtendedServerProfile)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see OpcUaServer destructor for additional functionality. 
          */
        virtual ~OpcUaServer() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::OpcUaServer;
        }
        
         
        /* Get-/Setters for simple attribute Name */
        virtual void setName(const std::string& Name) 
        { 
            this->Name = Name; 
            return;
        };
        virtual std::string getName() const
        { 
            return this->Name; 
        };

        /* Get-/Setters for simple attribute EndpointUrl */
        virtual void setEndpointUrl(const std::string& EndpointUrl) 
        { 
            this->EndpointUrl = EndpointUrl; 
            return;
        };
        virtual std::string getEndpointUrl() const
        { 
            return this->EndpointUrl; 
        };

        /* Get-/Setters for simple attribute MaxSessions */
        virtual void setMaxSessions(const std::uint16_t& MaxSessions) 
        { 
            this->MaxSessions = MaxSessions; 
            return;
        };
        virtual std::uint16_t getMaxSessions() const
        { 
            return this->MaxSessions; 
        };

        /* Get-/Setters for simple attribute IsDefault */
        virtual void setIsDefault(const bool& IsDefault) 
        { 
            this->IsDefault = IsDefault; 
            return;
        };
        virtual bool getIsDefault() const
        { 
            return this->IsDefault; 
        };


        /* Get-/Setters for association attribute BasicServerProfile */
        virtual void setBasicServerProfile(std::shared_ptr<mtp::OpcUaBasicServerProfile>& BasicServerProfile) 
        { 
            this->BasicServerProfile = BasicServerProfile; 
            return;
        };
        virtual std::shared_ptr<mtp::OpcUaBasicServerProfile> getBasicServerProfile() const
        { 
            return this->BasicServerProfile; 
        };

        /* Get-/Setters for association attribute StandardServerProfile */
        virtual void setStandardServerProfile(std::shared_ptr<mtp::OpcUaStandardServerProfile>& StandardServerProfile) 
        { 
            this->StandardServerProfile = StandardServerProfile; 
            return;
        };
        virtual std::shared_ptr<mtp::OpcUaStandardServerProfile> getStandardServerProfile() const
        { 
            return this->StandardServerProfile; 
        };

        /* Get-/Setters for association attribute ExtendedServerProfile */
        virtual void setExtendedServerProfile(std::shared_ptr<mtp::OpcUaExtendedServerProfile>& ExtendedServerProfile) 
        { 
            this->ExtendedServerProfile = ExtendedServerProfile; 
            return;
        };
        virtual std::shared_ptr<mtp::OpcUaExtendedServerProfile> getExtendedServerProfile() const
        { 
            return this->ExtendedServerProfile; 
        };

    };   
}

#endif // defined HAVE_OPC_UA_SERVER_BASE_HPP