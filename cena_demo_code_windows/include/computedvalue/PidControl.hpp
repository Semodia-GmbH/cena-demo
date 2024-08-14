/**
 * @file      PiDControl.hpp
 * @date      1/26/23
 * @author    Georg Graßnick
 * @copyright (c) Semodia GmbH (2023). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_PIDCONTROL_HPP
#define CONTROLENGINE_NATIVE_PIDCONTROL_HPP

#pragma once

#include <algorithm>
#include <limits>
#include <ostream>
#include <type_traits>

namespace semodia::controlengine::native::util::computedvalue
{

    /**
     * @brief Utility class that models a PID Controller
     * @tparam TError datatype used to model the error - numerical type
     * @tparam TInternal datatype used to model the internal calculations - floating point type
     */
    template <
        typename TError,
        typename TInternal,
        typename = typename std::enable_if<std::is_arithmetic<TError>::value, TError>::type,
        typename = typename std::enable_if<std::is_floating_point<TInternal>::value>::type>
    class PidControl
    {
    private:
        TInternal maxChange;
        TInternal minChange;
        TInternal pFactor;
        TInternal iFactor;
        TInternal dFactor;
        TError accumulatedError;
        TError lastIterationError;

        // Debugging cached variables that represent the value of each term of the PidController in the most recent iteration
        TInternal lastPContribution;
        TInternal lastIContribution;
        TInternal lastDContribution;

        /**
         * @brief limit the value to the minimum and maximum values, do not expose infinity or NaN
         * @param value The value to limit
         * @return The limited value
         */
        TInternal limitToTypeBoundaries(const TInternal& value)
        {
            TInternal ret = std::max(value, std::numeric_limits<TInternal>::lowest());
            ret = std::min(ret, std::numeric_limits<TInternal>::max());
            return ret;
        }

    protected:
        /**
         * @brief Create a PID Controller
         * @param minChange maximum proposed change (non absolute)
         * @param maxChange minimum proposed change (non absolute)
         * @param p Coefficient for the Proportional part of the controller
         * @param i Coefficient for the Integral part of the controller
         * @param d Coefficient for the Derivative part of the controller
         * @details Undefined behaviour, if minChange > maxChange.
         *  Access is protected to restrict creation from userspace. Use predefined implementations like FloatPid
         *  or create your own alongside with new test cases.
         *
         */
        PidControl(
            const TInternal p,
            const TInternal i,
            const TInternal d,
            const TInternal minChange = std::numeric_limits<TInternal>::lowest(),
            const TInternal maxChange = std::numeric_limits<TInternal>::max())
            : maxChange(maxChange)
            , minChange(minChange)
            , pFactor(p)
            , iFactor(i)
            , dFactor(d)
            , accumulatedError(0)
            , lastIterationError(0)
            , lastPContribution(0)
            , lastIContribution(0)
            , lastDContribution(0)
        {
            // TODO: Find a way to limit construction on compile time so that minChange > maxChange
            //
            // Can use template parameters and static asserts - but not for float until C++20
            //
            // Can deploy checks at runtime creation - use static factory method and only expose
            // object at success via output parameter?
        }

    public:
        virtual ~PidControl() = default;

        PidControl& operator=(PidControl&& rhs) noexcept = default;
        PidControl& operator=(const PidControl& rhs) noexcept = default;

        /**
         * Tick the PID controller and get the proposed change for the next iteration
         * @param setPoint The value that should be reached
         * @param actualValue The actual value currently measured
         * @param dt The duration of the last iteration
         * @return The proposed new value
         */
        virtual TInternal iterate(const TInternal setPoint, const TInternal actualValue, const TInternal dt)
        {
            const TInternal currentError = limitToTypeBoundaries(setPoint - actualValue);
            this->accumulatedError = limitToTypeBoundaries(this->accumulatedError + currentError * dt);

            const TInternal p = this->pFactor * currentError;
            this->lastPContribution = p;

            const TInternal i = this->iFactor * this->accumulatedError;
            this->lastIContribution = i;

            TInternal d = 0;
            if (dt != 0)
            {
                d = this->dFactor * (currentError - this->lastIterationError) / dt;
            }
            this->lastDContribution = d;

            TInternal output = p + i + d;

            output = std::max(output, this->minChange);
            output = std::min(output, this->maxChange);

            this->lastIterationError = currentError;

            return output;
        }

        virtual void reset() {
            this->accumulatedError = 0;
            this->lastIterationError = 0;
            this->lastPContribution = 0;
            this->lastIContribution = 0;
            this->lastDContribution = 0;
            return;
        }

        friend std::ostream& operator<<(std::ostream& os, const PidControl<TError, TInternal>& pid)
        {
            os << "Error Integral : " << pid.accumulatedError << ", Last Error: " << pid.lastIterationError
               << ", Last P: " << pid.lastPContribution << ", Last I: " << pid.lastIContribution
               << ", Last D: " << pid.lastDContribution;
            return os;
        }
    };
} // namespace semodia::controlengine::native::util::computedvalue
#endif // CONTROLENGINE_NATIVE_PIDCONTROL_HPP
