/**
 * @file      IFreezableValue.hpp
 * @date      1/17/22
 * @createdBy ichrispa
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_IFREEZABLEVALUE_HPP
#define CONTROLENGINE_NATIVE_IFREEZABLEVALUE_HPP

#pragma once

#include <memory>
#include <functional>
#include <cstdint>
#include "mtp/MtpStatusCode.hpp"
#include "mtp/MissedValueFlag.hpp"

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @brief Callback invoked when the value should actually be updated (allows chaining limiters, alarms, freeze, etc in the dataassembly logic)
     */
    template<typename dt>
    using updateFreezableValueCallback = std::function<void(const dt &newValue)>;

    /**
     * @class IFreezableValue
     * @brief Interface and logic for an IndicatorElement whose value can be "frozen" by Services
     * @details Frozen IndicatorElements will signals missed updates via their "MissedValueUpdateFlag" while suppressing
     *          changes to their VOut value field.
     */
    template<typename dt>
    class IFreezableValue
    {
    private:
        bool frozen;
        std::uint8_t missedUpdateCounter;

        /**
         * @brief Defines how many writes t the value need to be missed before we raise the missed value flag
         */
        const std::uint8_t missedValueThreshold;
    protected:
        /**
         * @brief Invokes the update callback IF not frozen; tracks the number of updates and sets missedValueFlag if required
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT if the pointer to the flag is invalid
         */
        MtpStatusCode updateValueIfNotFrozen(const dt& newValue, const dt& currentValue, std::shared_ptr<mtp::MissedValueFlag>& missedValueFlag, updateFreezableValueCallback<dt> doUpdateUsing)
        {
            if(missedValueFlag == nullptr)
            {
                return MtpStatusCode::ERROR_MISSING_MODEL_ELEMENT;
            }

            if(this->frozen == false)
            {
                missedUpdateCounter = 0;
                missedValueFlag->setFlag(false);
                doUpdateUsing(newValue);
            }
            else if(currentValue != newValue)
            {
                // Only count updates that would modify the value (drivers are likely to update values as they please)
                missedUpdateCounter++;

                if(missedUpdateCounter >= missedValueThreshold)
                {
                    missedValueFlag->setFlag(true);
                }
            }
            return MtpStatusCode::GOOD;
        };

    public:
        IFreezableValue()
            : frozen(false)
            , missedUpdateCounter(0)
            , missedValueThreshold(2)
        {
            return;
        };

        virtual ~IFreezableValue()
        {
            return;
        };

        IFreezableValue(const IFreezableValue &other) = default;
        IFreezableValue &operator=(const IFreezableValue &rhs) = default;

        /**
         * @brief Enables services and the userspace to suppress value changes to an indicator element
         * @param freeze true will suppress updates and set the missed-value flag if more than 2 write occur,
         *        setting freeze to false will (re)enable updates and clear the flag.
         * @return
         */
        MtpStatusCode setFreeze(const bool doFreeze)
        {
            this->frozen = doFreeze;
            if(this->frozen == false)
            {
                missedUpdateCounter = 0;
            }

            return MtpStatusCode::GOOD;
        };

        /**
         * @return `true` if this IndicatorElement suppresses any changes to its output value
         */
        const bool& isFrozen() const
        {
            return this->frozen;
        }

    };
} // namespace

#endif //CONTROLENGINE_NATIVE_IFREEZABLEVALUE_HPP
