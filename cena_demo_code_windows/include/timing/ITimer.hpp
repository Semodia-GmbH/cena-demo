/**
 * @date      26/11/21
 * @authors   Chris Paul Iatrou, Georg Graßnick
 * @copyright (c) Semodia GmbH (2021). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ISYSTEMTIMER_H
#define SEMODIA_CONTROLENGINE_NATIVE_ISYSTEMTIMER_H

#pragma once

#include <cstdint>

namespace semodia::controlengine::native::osal::timing
{
    /**
     * @class ITimer
     * @brief A timer that can count down and expire; note that this interface does not offer asynchronous execution
     *        features such as callbacks on exiration or interval calls
     */
    class ITimer
    {
    public:
        virtual ~ITimer() = default;

        /**
         * @brief Convert the amount of abstract "ticks" into a time unit; this is highly dependent on the clocks and
         *        capabilities of the underling system.
         * @return The amount of timer ticks that represent one second.
         */
        virtual std::uint64_t ticksPerSecond() = 0;

        /**
         * @brief Get the maximum number of ticks, this timer can be set to
         * @return The maximum number of ticks supported by this implementation
         */
        virtual std::uint64_t maxTicks() = 0;

        /**
         * @brief Set the amount of ticks that need to occur for a timeout
         * @param ticks
         */
        virtual void setTimeout(const std::uint64_t timeout_ticks) = 0;

        /**
         * @brief Computes the number of underlying timer ticks remaining between start() was called and hasExpired()
         * returning true
         * @return The difference of last start() call to now in ticks, minimum of 0 if timer has expired
         */
        virtual std::uint64_t ticksRemaining() = 0;

        /**
         * @return true if more that `timeout_ticks` have elapsed since @see reset() was called
         */
        virtual bool hasExpired() = 0;

        /**
         * @brief resets the internal counter to `timeout_ticks`, set timer to not paused
         */
        virtual void reset() = 0;

        /**
         * @brief starts the timer; this may have different semantics based on the specific implementation
         */
        virtual void start() = 0;

        /**
         * @brief stops the timer; this may have different semantics based on the specific implementation
         */
        virtual void stop() = 0;

        /**
         * @brief Pause the timer
         * @details While the timer is paused, the timeout will not progress. Use ITimer::unpause to resume the timer.
         */
        virtual void pause() = 0;

        /**
         * @brief Unpause the timer
         */
        virtual void unpause() = 0;

        /**
         * @brief Check, whether the timer is currently paused
         * @return true if the time is paused, else false
         */
        virtual bool isPaused() = 0;
    };
} // namespace semodia::controlengine::native::osal::timing
#endif // SEMODIA_CONTROLENGINE_NATIVE_ISYSTEMTIMER_H
