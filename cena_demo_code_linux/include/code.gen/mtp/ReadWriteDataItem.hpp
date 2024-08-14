/**
 * @file ReadWriteDataItem.hpp
 * @date Tuesday, August 4, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_READ_WRITE_DATA_ITEM_HPP
#define HAVE_READ_WRITE_DATA_ITEM_HPP

#pragma once

#include "mtp/base/ReadWriteDataItem.hpp"

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @class ReadWriteDataItem
     * @brief The read write data item specifying the information of an attribute defined within the standard. The access is read write within the OPC UA server. The data type is specified via a generic argument.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    template <typename dt>
    class ReadWriteDataItem : public base::ReadWriteDataItem<dt>
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::ReadWriteDataItem::base::ReadWriteDataItem for pre-constructor-call allocation.
         */
        ReadWriteDataItem(std::shared_ptr<mtp::OpcUaNodeItem> OpcUaNode, std::shared_ptr<dt> DefaultValue)
            :   base::ReadWriteDataItem<dt>(OpcUaNode, DefaultValue)
        {
            if(DefaultValue != nullptr)
            {
                this->value = DefaultValue;
                this->defaultValue = DefaultValue;
            }
            return;
        };

        /**
         * @ingroup MTP API
         * @brief Alternate constructor, Directly stores the DataType value in the DataItem.
         */
        ReadWriteDataItem(std::shared_ptr<mtp::OpcUaNodeItem> OpcUaNode, const dt& DefaultValue)
            :   base::ReadWriteDataItem<dt>(OpcUaNode, std::shared_ptr<dt>(nullptr))
        {
            this->value = DefaultValue;
            this->defaultValue = DefaultValue;
        };

        /**
        * @ingroup MTP API
        * @brief Alternate constructor, Directly stores the DataType value in the DataItem. Omits OpcUa node.
        */
        ReadWriteDataItem(const dt& DefaultValue)
            :   base::ReadWriteDataItem<dt>(std::shared_ptr<mtp::OpcUaNodeItem>(nullptr), std::shared_ptr<dt>(nullptr))
        {
            this->value = DefaultValue;
            this->defaultValue = DefaultValue;
            return;
        };

        ReadWriteDataItem(const ReadWriteDataItem& other) = default;

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::ReadWriteDataItem::~base::ReadWriteDataItem  
          */
        virtual ~ReadWriteDataItem() 
        {
            return;
        };

        /**
         * @brief Assignment operator for another default reuses values and defaultValue; node is retained.
         * @param rhs is the datatype of the DataItem
         */
        virtual ReadWriteDataItem<dt>& operator=(const ReadWriteDataItem<dt>& rhs)
        {
            this->set(const_cast<ReadWriteDataItem<dt>&>(rhs).get());
            auto otherDefaultValue = rhs.getDefaultValue();
            this->setDefaultValue(otherDefaultValue);
            return *this;
        };

        /**
         * @brief Direct assignment of contained datatype is allowed
         * @param rhs is the value to be used
         */
        using DataItem<dt>::operator=;

        /**
         * @brief Comparison operator with another Item of the same dt
         * @return true if values match (name, defaultvalue, etc are ignored)
         */
        virtual bool operator==(const ReadWriteDataItem<dt>& rhs) const
        {
            return (rhs.get() == this->get());
        };

        /**
         * @brief Direct Value-Comparison operator for dataType; ReadWriteItem is treated as a value of its dt
         * @return true if values match (name, defaultvalue, etc are ignored)
         */
        virtual bool operator==(const dt& rhs) const
        {
            return (rhs == this->get());
        };

        // Explicitly use the base class definition here as we do not add any different behaviour regarding the overload
        using DataItem<dt>::operator==;
    };   
}

#endif // defined HAVE_READ_WRITE_DATA_ITEM_HPP