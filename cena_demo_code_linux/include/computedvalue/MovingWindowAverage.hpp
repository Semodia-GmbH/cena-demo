/**
 * @file      MovingWindowAverageValue.hpp
 * @date      4/7/22
 * @createdBy ichrispa
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_MOVINGWINDOWAVERAGEVALUE_HPP
#define CONTROLENGINE_NATIVE_MOVINGWINDOWAVERAGEVALUE_HPP

#pragma once

#include "computedvalue/AbstractMovingWindow.hpp"
namespace semodia::controlengine::native::util::computedvalue
{
    /**
     * @class MovingWindowAverageValue
     * @brief Provides an arithmetic mean of a numeric value
     */
    template<typename N>
    class MovingWindowAverage : public AbstractMovingWindow<N>
    {
    public:
        MovingWindowAverage(const std::uint32_t windowSize, const N& initialValue)
            : AbstractMovingWindow<N>(windowSize, initialValue)
        {
            return;
        }
        virtual ~MovingWindowAverage() = default;

        MovingWindowAverage(const MovingWindowAverage &other) = default;
        MovingWindowAverage<N>& operator=(const MovingWindowAverage<N>& other) = default;

        using AbstractMovingWindow<N>::operator=;

        /**
         * @brief Add avg+value to window and returns the resulting average
         */
        virtual MovingWindowAverage& operator+=(const N& value)
        {
            this->operator=(this->getValue() + value);
            return *this;
        }

        /**
         * @brief Add avg-value to window and returns the resulting average
         */
        virtual MovingWindowAverage& operator-=(const N& value)
        {
            this->operator=(this->getValue() - value);
            return *this;
        }

        /**
         * @brief Add avg*value to window and returns the resulting average
         */
        virtual MovingWindowAverage& operator*=(const N& value)
        {
            this->operator=(this->getValue() * value);
            return *this;
        }

        /**
         * @brief Add avg/value to window and returns the resulting average
         */
        virtual MovingWindowAverage& operator/=(const N& value)
        {
            this->operator=(this->getValue() / value);
            return *this;
        }

        /**
         * @brief creates the numeric average of the values in the window
         */
        virtual N getValue() const override
        {
            if(this->windowPosition == 0 && !this->windowRollOver)
            {
                // theoretically undefined/empty; returns the default value
                // Cast added in case the values added are e.g. mtp::AnaViews
                return static_cast<N>(this->window[0]);
            }

            N sum = 0;
            for(std::size_t i=0; (i<this->windowSize) && (this->windowRollOver || (!this->windowRollOver && i<this->windowPosition)); i++)
            {
                sum+=this->window[i];
            }
            if(!this->windowRollOver)
            {
                return sum/this->windowPosition;
            }
            return sum/this->windowSize;
        }
    };
} // namespace

#endif //CONTROLENGINE_NATIVE_MOVINGWINDOWAVERAGEVALUE_HPP
