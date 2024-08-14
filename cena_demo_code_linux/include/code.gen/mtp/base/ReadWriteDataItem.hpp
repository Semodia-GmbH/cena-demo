/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ReadWriteDataItem.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_READ_WRITE_DATA_ITEM_BASE_HPP
#define HAVE_READ_WRITE_DATA_ITEM_BASE_HPP

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
    class ReadWriteDataItem;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ReadWriteDataItem
     * @brief The read write data item specifying the information of an attribute defined within the standard. The access is read write within the OPC UA server. The data type is specified via a generic argument.. This is the base class generated based on the Model Type Package Specification.
     */
    template <typename dt>
    class ReadWriteDataItem : public mtp::DataItem<dt>
    {
    private:
    
    protected:
        ReadWriteDataItem( 
            std::shared_ptr<mtp::OpcUaNodeItem> OpcUaNode, 
            std::shared_ptr<dt> DefaultValue
        ) : mtp::DataItem<dt>(OpcUaNode, DefaultValue)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ReadWriteDataItem destructor for additional functionality. 
          */
        virtual ~ReadWriteDataItem() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ReadWriteDataItem;
        }
        
    };   
}

#endif // defined HAVE_READ_WRITE_DATA_ITEM_BASE_HPP