/**
 * @file DataItem.hpp
 * @date Tuesday, August 4, 2020
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_DATA_ITEM_HPP
#define HAVE_DATA_ITEM_HPP

#pragma once

#include "mtp/base/DataItem.hpp"
#include "mtp/MtpStatusCode.hpp"
#include "mtp/OpcUaNodeIdType.hpp"
#include "mtp/OpcUaNodeItem.hpp"
#include <ctime>

#ifdef SEMODIA_CONTROLENGINE_READDATAITEM_ENABLE_CALLBACKS
#include "locking/Lock.hpp"
#include "locking/LockedObject.hpp"
#include <functional>
#include <map>
#include <memory>
#include <string>
#endif

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @class DataItem
     * @brief The data item specifying the information of an attribute defined within the standard. The data type is specified via a generic argument.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    template <typename dt>
    class DataItem : public base::DataItem<dt>
    {
    private:
    protected:
        dt defaultValue;
        dt value;

#ifdef SEMODIA_CONTROLENGINE_READDATAITEM_ENABLE_CALLBACKS
        dt lastValue;
        semodia::controlengine::native::osal::locking::LockedObject<
            std::map<const std::string, std::function<void(const dt newVal)>>>
            onChangeCallbacks;
#endif

    public:
        /**
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::DataItem::base::DataItem for pre-constructor-call allocation. 
         *        The DataType is derived from the template argument. Both setters and getters for a value are
         *        provided.
         */
        DataItem(std::shared_ptr<mtp::OpcUaNodeItem> OpcUaNode, std::shared_ptr<dt> DefaultValue)
            : base::DataItem<dt>(OpcUaNode, DefaultValue)
#ifdef SEMODIA_CONTROLENGINE_READDATAITEM_ENABLE_CALLBACKS
            , lastValue()
            , onChangeCallbacks(
                  std::make_unique<semodia::controlengine::native::osal::locking::Lock>(),
                  std::map<const std::string, std::function<void(const dt newVal)>>())
#endif
        {
            if (DefaultValue != nullptr)
            {
                this->defaultValue = *DefaultValue;
                this->value = *DefaultValue;
            }
            return;
        };

        /**
         * @brief Allocates a new pointer to make the base-class happy, but assigns value to itself directly
         */
        DataItem(std::shared_ptr<mtp::OpcUaNodeItem> OpcUaNode, const dt& DefaultValue)
            : base::DataItem<dt>(OpcUaNode, std::make_shared<dt>(DefaultValue))
#ifdef SEMODIA_CONTROLENGINE_READDATAITEM_ENABLE_CALLBACKS
            , lastValue(DefaultValue)
            , onChangeCallbacks(
                  std::make_unique<semodia::controlengine::native::osal::locking::Lock>(),
                  std::map<const std::string, std::function<void(const dt newVal)>>())
#endif
        {
            this->defaultValue = DefaultValue;
            this->value = DefaultValue;
            return;
        };

        /**
         * @brief Copy constructor creates a shallow copy of the parent
         */
        // cppcheck creates a false positive here, as assignment is achieved by calling the base constructor
        // cppcheck-suppress missingMemberCopy
        DataItem(const DataItem& other)
            : base::DataItem<dt>(other.getOpcUaNode(), other.getDefaultValue())
            , defaultValue(other.defaultValue)
            , value(other.value)
#ifdef SEMODIA_CONTROLENGINE_READDATAITEM_ENABLE_CALLBACKS
            , lastValue(other.lastValue)
            , onChangeCallbacks(
                  std::make_unique<semodia::controlengine::native::osal::locking::Lock>(),
                  other.onChangeCallbacks.getCopy())
#endif
        {
            return;
        };

        virtual ~DataItem() 
        {
            return;
        };

        /* Get-/Setters for simple generic attribute structure DefaultValue */
        /**
          * @ingroup MTP API
          * @brief Overwritten base::DataItem base implementation; accesses the enclosed dt directly instead of the base::DataItems
          *        superfluous pointer. The pointer is non the less set to point to this atteched value.
          */
        virtual void setDefaultValue(std::shared_ptr<dt>& DefaultValue) override
        {
            this->defaultValue = *DefaultValue;
        };
        virtual void setDefaultValue(const dt& DefaultValue)
        {
            this->defaultValue = DefaultValue;
        };
        virtual const std::shared_ptr<dt> getDefaultValue() const override
        {
            return std::make_shared<dt>(this->defaultValue);
        };

#ifdef SEMODIA_CONTROLENGINE_READDATAITEM_ENABLE_CALLBACKS
        void invokeCallbacks(const std::map<const std::string, std::function<void(const dt newVal)>>& callbacks)
        {
            for (const auto& callbackPair : callbacks)
            {
                callbackPair.second(this->value);
            }
        }
#endif
        /**
         * @brief Allows access to an attached value of type dt. This field does not exist in base::DataItem.
         * @details  Note that this function is not virtual, allowing using classes to choose if they want to use the
         *           specializations set (with possible restrictions, @see ReadDataItem::set()) or if they want to force
         *           access over this function. Note that casting to a DataItem to force access should only be done by
         *           users familiar with VDI 2658 and the DataItems usage context!
         * @param value
         */
        void set(dt value)
        {
            this->value = value;
#ifdef SEMODIA_CONTROLENGINE_READDATAITEM_ENABLE_CALLBACKS
            if (this->lastValue != value)
            {
                this->onChangeCallbacks.interact(
                    std::bind(&DataItem<dt>::invokeCallbacks, this, std::placeholders::_1));
                this->lastValue = value;
            }
#endif
        };

        /**
         * @returns Returns a copy of the attached value (not a reference); use set() to change the attached value.
         */
        virtual const dt& get() const
        {
            return this->value;
        };

        /**
         * @brief   User-friendly function to set the desired OPC UA nodeId of this dataItem
         * @param   namespaceUrl is the namespace urn to be used, e.g. "urn:mtpStatic.application.server"; behavior depends on reflector implementation
         * @param   nodeId is the nodeId to be assigned to this node. If formatted "i=1000", "s=..." the parser will attempt to generate this type of ID,
         *          but if it encounters an error it will pick the next best suited type. If the specifier is missing entirely, the parser will guess.
         *          @see OpcUaNodeItem::idTypeFromString for more details.
         * @return  GOOD on success, ERROR_NOT_EMPTY if an OpcUaNodeItem pointer is already set (unclear if we may delete it or not)
         */
        virtual MtpStatusCode setFixedOpcUaNodeId(const std::string& nodeId, const std::string& namespaceUrl) const
        {
            if (this->getOpcUaNode() != nullptr) {
                return MtpStatusCode::ERROR_NOT_EMPTY;
            }
            
            auto node = std::make_shared<mtp::OpcUaNodeItem>(
                    "",  /* name: ignored by reflector */
                    nodeId,  /* nodeid: "s=..."*/
                    namespaceUrl,
                    OpcUaNodeIdType::Numeric,  /* type: ignored by reflector, determined from nodeId string */
                    std::shared_ptr<mtp::OpcUaServer>(nullptr)/* type: ignored */
            );
            const_cast<DataItem<dt>*>(this)->setOpcUaNode(node);
            return MtpStatusCode::GOOD;
        };

        /**
        * @brief Allow implicit conversion of any DataItem to its datatype
        * @return value by reference as per get()
        */
        operator const dt& () const
        {
            return this->get();
        };

        // --- Operator ---

        /**
         * @brief Copy-operator for another default reuses values and defaultValue; node is retained.
         * @param lhs is the datatype of the DataItem
         */
        DataItem<dt>& operator=(const DataItem<dt>& rhs)
        {
            this->set(const_cast<DataItem<dt>&>(rhs).get());
            auto otherDefaultValue = rhs.getDefaultValue();
            this->setDefaultValue(otherDefaultValue);
            return *this;
        };

        /**
         * @brief Direct assignment of contained datatype is allowed  (applies Builtin type to  DataItem)
         * @param lhs is the value to be used
         */
        DataItem<dt>& operator=(const dt rhs)
        {
            this->set(rhs);
            return *this;
        };

        /**
         * @brief Larger-than operator
         * @return true if value > other.value
         */
        virtual bool operator>(const DataItem<dt>& rhs)
        {
            return (this->value > rhs.value);
        };

        /**
         * @brief Direct Larger-than operator for dataType (compares DataItem with BuiltIn-Type)
         * @return true if value > other.value
         */
        virtual bool operator>(const dt rhs)
        {
            return this->get() > rhs;
        };

        /**
         * @brief Comparison operator
         * @return true if values match (name defaultvalue, etc are ignored)
         */
        virtual bool operator==(const DataItem<dt>& rhs) const
        {
            return (rhs.get() == this->get());
        };

        /**
         * @brief Comparison operator for dataType (compares DataItem with BuiltIn-Type)
         * @return true if values match (name defaultvalue, etc are ignored)
         */
        virtual bool operator==(const dt& rhs) const
        {
            return (rhs == this->get());
        };

        /**
         * @brief Inequality operator
         * @return true if values do not match
         */
        virtual bool operator!=(const DataItem<dt>& rhs) const
        {
            return !(this->get() == rhs.get());
        };

        /**
         * @brief Inequality operator for dataType (compares DataItem with BuiltIn-Type)
         * @return true if values match (name defaultvalue, etc are ignored)
         */
        virtual bool operator!=(const dt& rhs) const
        {
            return (rhs != this->get());
        };

        /**
         * @brief Allow conversion to native type
         */
        virtual explicit operator dt() final
        {
            return this->value;
        }


#ifdef SEMODIA_CONTROLENGINE_READDATAITEM_ENABLE_CALLBACKS
        /**
         * @brief Register a new callback that is invoked, whenever DataItem::set is called with a different value
         * than its current value.
         * @param callbackId A string that is used to represent registrar
         * @param callback The callback function that is invoked synchronously whenever the value is changed via DataItem::set
         * @return MtpStatusCode::GOOD if the registration was successful, MtpStatusCode::ERROR on failure
         */
        [[nodiscard]] MtpStatusCode registerOnChangeCallback(
            const std::string& callbackId,
            std::function<void(const dt newValue)>&& callback)
        {
            mtp::MtpStatusCode statusCode = mtp::MtpStatusCode::ERROR;
            this->onChangeCallbacks.interact(
                [&](std::map<const std::string, std::function<void(const dt newVal)>>& map)
                {
                    const auto retval = map.try_emplace(callbackId, callback);
                    if (retval.second)
                    {
                        statusCode = mtp::MtpStatusCode::GOOD;
                    }
                    return;
                });
            return statusCode;
        }
#endif
    };
} // namespace semodia::controlengine::native::model::mtp

#endif // defined HAVE_DATA_ITEM_HPP