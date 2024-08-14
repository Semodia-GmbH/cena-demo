/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file OpcUaNodeItem.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_OPC_UA_NODE_ITEM_BASE_HPP
#define HAVE_OPC_UA_NODE_ITEM_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/SemanticModelEntity.hpp"

#include <string>
#include "mtp/OpcUaNodeIdType.hpp"

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class OpcUaServer;
    
    class OpcUaNodeItem;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class OpcUaNodeItem
     * @brief The OPC UA node item defining the necessary information to access a node within the corresponding OPC UA server.. This is the base class generated based on the Model Type Package Specification.
     */
    class OpcUaNodeItem : public mtp::SemanticModelEntity
    {
    private:
        /**
          * @brief Simple attribute Name. Name of the OPC UA Node external interface.
          */ 
        std::string Name;
        /**
          * @brief Simple attribute NodeId. The node ID of the item.
          */ 
        std::string NodeId;
        /**
          * @brief Simple attribute NamespaceUrl. The namespace URL of the item.
          */ 
        std::string NamespaceUrl;
        
        /**
          * @brief Enumeration NodeIdType. The node ID type of the item.
          */ 
        mtp::OpcUaNodeIdType NodeIdType;
        
        /**
          * @brief Association Server. The corresponding OPC UA server which holds the OPC UA item. If the server is null, the default OPC UA server will be used within generation.
          */ 
        std::shared_ptr<mtp::OpcUaServer> Server;
    
    protected:
        OpcUaNodeItem( 
            const std::string& Name, 
            const std::string& NodeId, 
            const std::string& NamespaceUrl, 
            OpcUaNodeIdType NodeIdType, 
            std::shared_ptr<mtp::OpcUaServer> Server
        ) : mtp::SemanticModelEntity(), Name(Name), NodeId(NodeId), NamespaceUrl(NamespaceUrl), NodeIdType(NodeIdType), Server(Server)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see OpcUaNodeItem destructor for additional functionality. 
          */
        virtual ~OpcUaNodeItem() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::OpcUaNodeItem;
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

        /* Get-/Setters for simple attribute NodeId */
        virtual void setNodeId(const std::string& NodeId) 
        { 
            this->NodeId = NodeId; 
            return;
        };
        virtual std::string getNodeId() const
        { 
            return this->NodeId; 
        };

        /* Get-/Setters for simple attribute NamespaceUrl */
        virtual void setNamespaceUrl(const std::string& NamespaceUrl) 
        { 
            this->NamespaceUrl = NamespaceUrl; 
            return;
        };
        virtual std::string getNamespaceUrl() const
        { 
            return this->NamespaceUrl; 
        };

        
        /* Get-/Setters for Enumeration attribute NodeIdType */
        virtual void setNodeIdType(const mtp::OpcUaNodeIdType NodeIdType) 
        { 
            this->NodeIdType = NodeIdType; 
            return;
        };
        virtual mtp::OpcUaNodeIdType getNodeIdType() const
        { 
            return this->NodeIdType; 
        };


        /* Get-/Setters for association attribute Server */
        virtual void setServer(std::shared_ptr<mtp::OpcUaServer>& Server) 
        { 
            this->Server = Server; 
            return;
        };
        virtual std::shared_ptr<mtp::OpcUaServer> getServer() const
        { 
            return this->Server; 
        };

    };   
}

#endif // defined HAVE_OPC_UA_NODE_ITEM_BASE_HPP