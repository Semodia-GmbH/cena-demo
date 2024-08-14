/**
 * @file      MovingWindow.hpp
 * @date      4/7/22
 * @createdBy ichrispa
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_ABSTRACTMOVINGWINDOW_HPP
#define CONTROLENGINE_NATIVE_ABSTRACTMOVINGWINDOW_HPP

#pragma once

#include <cstdint>
#include <vector>

namespace semodia::controlengine::native::util::computedvalue
{
    /**
     * @class MovingWindow
     * @brief Provides the mechanism for adding values to a common vector; interpretation of this data is up to the specialization
     */
    template<typename N>
    class AbstractMovingWindow
    {
    protected:
        std::vector<N> window;

        /**
         * @brief Maximum desired size of the window
         */
        const std::size_t windowSize;

        /**
         * @brief Next slow in the vector used to store a new value
         */
        std::size_t windowPosition;

        /**
         * @brief Signals if the window was filled with values at least once or if 0..windowsPostition constitutes "all values"
         */
        bool windowRollOver;

    public:
        /**
         * @brief Creates a new moving window of any type (usually numeric)
         * @param windowSize is the number of values that should fit into the window
         * @param initialValue is the value used to initialize the first element, ensuring that even if no values have been added a sensible value is returned
         */
        AbstractMovingWindow(const std::uint32_t windowSize, const N& initialValue)
                : windowSize(windowSize < 1 ? 1 : windowSize)
                , windowPosition(0)
                , windowRollOver(false)
        {
            for(unsigned i = 0; i<windowSize; i++)
            {
                window.push_back(initialValue);
            }
            return;
        }
        virtual ~AbstractMovingWindow() = default;

        AbstractMovingWindow(const AbstractMovingWindow &other) = default;
        virtual AbstractMovingWindow<N>& operator=(const AbstractMovingWindow<N>& other) = default;

        /**
         * @brief Adds a value to the moving window
         */
        virtual AbstractMovingWindow<N>& operator=(const N& value)
        {
            if(this->windowPosition >= this->windowSize)
            {
                this->windowPosition = 0;
                windowRollOver = true;
            }

            this->window[this->windowPosition] = value;
            this->windowPosition++;

            return *this;
        }

        /**
         * @brief  This interpretation of the window must be implemented by specialization
         * @return Returns a native value, computed based on the contents of the window contents
         */
        virtual N getValue() const = 0;

        /**
         * @brief Permit use of the value as a native type N
         */
        virtual operator N() const
        {
            return this->getValue();
        }
    };
} // namespace

#endif //CONTROLENGINE_NATIVE_ABSTRACTMOVINGWINDOW_HPP
