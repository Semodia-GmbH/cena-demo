/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file DataItem.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_DATA_ITEM_BASE_HPP
#define HAVE_DATA_ITEM_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/SemanticModelEntity.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class OpcUaNodeItem;
    class DataType;
    
    template <typename dt> 
    class DataItem;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class DataItem
     * @brief The data item specifying the information of an attribute defined within the standard. The data type is specified via a generic argument.. This is the base class generated based on the Model Type Package Specification.
     */
    template <typename dt>
    class DataItem : public mtp::SemanticModelEntity
    {
    private:
        
        /**
          * @brief Association OpcUaNode. The corresponding OPC UA node item. If the item is null the data item will be interpreted as a static item without a representation on the OPC UA server.
          */ 
        std::shared_ptr<mtp::OpcUaNodeItem> OpcUaNode;
        
        /**
          * @brief Simple generic structure DefaultValue. The default value of the data item.
          */ 
        std::shared_ptr<dt> DefaultValue;
    
    protected:
        DataItem( 
            std::shared_ptr<mtp::OpcUaNodeItem> OpcUaNode, 
            std::shared_ptr<dt> DefaultValue
        ) : mtp::SemanticModelEntity(), OpcUaNode(OpcUaNode), DefaultValue(DefaultValue)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see DataItem destructor for additional functionality. 
          */
        virtual ~DataItem() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::DataItem;
        }
        

        /* Get-/Setters for association attribute OpcUaNode */
        virtual void setOpcUaNode(std::shared_ptr<mtp::OpcUaNodeItem>& OpcUaNode) 
        { 
            this->OpcUaNode = OpcUaNode; 
            return;
        };
        virtual std::shared_ptr<mtp::OpcUaNodeItem> getOpcUaNode() const
        { 
            return this->OpcUaNode; 
        };

        
        /* Get-/Setters for simple generic attribute structure DefaultValue */
        virtual void setDefaultValue(std::shared_ptr<dt>& DefaultValue) 
        { 
            this->DefaultValue = DefaultValue; 
            return;
        };
        virtual const std::shared_ptr<dt> getDefaultValue() const
        { 
            return this->DefaultValue; 
        };
    };   
}

#endif // defined HAVE_DATA_ITEM_BASE_HPP