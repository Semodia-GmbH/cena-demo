/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ReadDataItem.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_READ_DATA_ITEM_BASE_HPP
#define HAVE_READ_DATA_ITEM_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/DataItem.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    
    template <typename dt> 
    class ReadDataItem;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ReadDataItem
     * @brief The read data item specifying the information of an attribute defined within the standard. The access is readonly within the OPC UA server. The data type is specified via a generic argument.. This is the base class generated based on the Model Type Package Specification.
     */
    template <typename dt>
    class ReadDataItem : public mtp::DataItem<dt>
    {
    private:
    
    protected:
        ReadDataItem( 
            std::shared_ptr<mtp::OpcUaNodeItem> OpcUaNode, 
            std::shared_ptr<dt> DefaultValue
        ) : mtp::DataItem<dt>(OpcUaNode, DefaultValue)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ReadDataItem destructor for additional functionality. 
          */
        virtual ~ReadDataItem() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ReadDataItem;
        }
        
    };   
}

#endif // defined HAVE_READ_DATA_ITEM_BASE_HPP