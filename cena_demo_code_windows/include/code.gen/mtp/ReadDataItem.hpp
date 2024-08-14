/**
 * @file ReadDataItem.hpp
 * @date Tuesday, August 4, 2020
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_READ_DATA_ITEM_HPP
#define HAVE_READ_DATA_ITEM_HPP

#pragma once

#include "mtp/base/ReadDataItem.hpp"

/*
 * This definition recasts a ReadDataItem to a DataItem of the same type, making it writable.
 * This is only meant to be used by the API itself, not the user.
 */
/**
 * @macro FORCE_READDATAITEM_MEMBER_WRITE
 * @brief Allows writing a non-null ReadDataItem that is a member of `this`.
 *        **This macro is not safe to be used in userspace, as it may easily break spec-conformancy!**
 *        Your MTP class will provide appropriate setters/getters (which will use this macro internally).
 * @param _type is the template type of the dataitem
 * @param _value is a const value of the given _type
 * @param _field is the name of the member, e.g. `VOut` for the ReadDataItem `AnaMan->Vout`. Must provide setVOut(const _type& value).
 */
#ifndef FORCE_READDATAITEM_MEMBER_WRITE
    #define FORCE_READDATAITEM_MEMBER_WRITE(_type, _value, _field) \
        if(this->get##_field() != nullptr) { \
            static_cast<const std::shared_ptr<semodia::controlengine::native::model::mtp::DataItem<_type>>>(this->get ##_field() )->set( static_cast<_type>(_value)); \
        }
#endif

/**
 * @macro FORCE_READDATAITEM_ANY_WRITE
 * @brief Allows writing any non-null ReadDataItem by recasting it to a DataItem and accessing its write function
 *        **This macro is not safe to be used in userspace, as it may easily break spec-conformancy!** Your MTP class
 *        will provide appropriate setters/getters.
 * @param _type is the template type of the dataitem
 * @param _value is a const value of the given _type
 * @param _target is a ptr of `const ReadDataItem<_type>*` to be written
 */
#ifndef FORCE_READDATAITEM_ANY_WRITE
    #define FORCE_READDATAITEM_ANY_WRITE(_type, _value, _targetitem) \
        if( (_targetitem) != nullptr) { \
            static_cast<const std::shared_ptr<semodia::controlengine::native::model::mtp::DataItem<_type>>>(_targetitem)->set( static_cast<_type>(_value) ); \
        }
#endif

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @class ReadDataItem
     * @brief The read data item specifying the information of an attribute defined within the standard. The access is readonly within the OPC UA server. The data type is specified via a generic argument.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    template <typename dt>
    class ReadDataItem : public base::ReadDataItem<dt>
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::ReadDataItem::base::ReadDataItem for pre-constructor-call allocation. 
         *        DataType is derived from the template argument in @see mtp::DataItem
         */
        ReadDataItem(std::shared_ptr<mtp::OpcUaNodeItem> OpcUaNode, std::shared_ptr<dt> DefaultValue)
            : base::ReadDataItem<dt>(OpcUaNode, DefaultValue)
        {
            if(DefaultValue != nullptr)
            {
                this->value = DefaultValue;
                this->defaultValue = DefaultValue;
            }
        };

        /**
         * @ingroup MTP API
         * @brief Atlernate constructor, Directly stores the DataType value in the DataItem.
         */
        ReadDataItem(std::shared_ptr<mtp::OpcUaNodeItem> OpcUaNode, dt DefaultValue)
            : base::ReadDataItem<dt>(OpcUaNode, std::shared_ptr<dt>(nullptr))
        {
            this->value = DefaultValue;
            this->defaultValue = DefaultValue;
        };

       /**
        * @ingroup MTP API
        * @brief Atlernate constructor, Directly stores the DataType value in the DataItem. Omits OpcUa node.
        */
        ReadDataItem(const dt& DefaultValue)
            : base::ReadDataItem<dt>(std::shared_ptr<mtp::OpcUaNodeItem>(nullptr), std::shared_ptr<dt>(nullptr))
        {
            this->value = DefaultValue;
            this->defaultValue = DefaultValue;
        };

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::ReadDataItem::~base::ReadDataItem  
          */
        virtual ~ReadDataItem() 
        {
            return;
        };

        /**
         * @brief ReadDataItems are not writable by the model.
         * @details ReadDataItems do not inherit the DataItem set(). They explicitly use their own voided setter.
         *          If re-casted to a DataItem, this makes ReadDataItems writable again, which is vital for higher-level
         *          logic that needs to access values and knows how/when this is valid to perform.
         *          Users should never cast ReadDataItems, unless they are familiar with the norm and intended use of the ReadDataItem!
         * @param value; disregarded
         */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
        // cppcheck-suppress duplInheritedMember
        void set([[maybe_unused]] dt value)
        {
            return;
        };

#pragma GCC diagnostic pop

        /**
         * @brief Copy operator; value cannot be changed, but name and defaultValue will be copied
         * @param lhs is the datatype of the DataItem
         */
        ReadDataItem(const ReadDataItem<dt>& other)
                : base::ReadDataItem<dt>(other)
        {
            return;
        };

        /**
         * @brief Assignment operator; value cannot be changed, but name and defaultValue will be copied
         * @param lhs is the datatype of the DataItem
         */
        ReadDataItem<dt>& operator=(const ReadDataItem<dt>& rhs)
        {
            this->setDefaultValue(* const_cast<dt*>(rhs.getDefaultValue()));
            this->setName( const_cast<ReadDataItem<dt>&>(rhs).getName());
            return *this;
        };

        /**
         * @brief Assignment operator for dataType; not applicable for Read-Only ReadDataItem
         * @param lhs is the value to be used
         */
        ReadDataItem<dt>& operator=([[maybe_unused]] const dt& rhs)
        {
            return *this;
        };

        /**
         * @brief Comparison operator with another Item of the same dt
         * @return true if values match (name, defaultvalue, etc are ignored)
         */
        virtual bool operator==(const ReadDataItem<dt>& rhs) const
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

#endif // defined HAVE_READ_DATA_ITEM_HPP