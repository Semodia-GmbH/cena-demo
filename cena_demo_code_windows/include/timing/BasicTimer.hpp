/**
 * @date      26/11/21
 * @authors   Chris Paul Iatrou, Georg Graßnick
 * @copyright (c) Semodia GmbH (2021). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_BASICTIMER_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_BASICTIMER_HPP

#include <chrono>
#include <cstdint>

#include "timing/ITimer.hpp"

namespace semodia::controlengine::native::osal::timing
{
    /**
     * @class BasicTimer
     * @brief A timer implementation using the chrono library
     */
    class BasicTimer : public ITimer
    {
        /**
         * @brief Relative point in time set using reset()
         */
        std::chrono::time_point<std::chrono::steady_clock> lastSet;

        /**
         * @brief Stores the time-delta required to elapse from a reset(); checked using hasExpired();
         */
        std::chrono::microseconds timeToElapse;

        bool isCurrentlyPaused;
        std::chrono::time_point<std::chrono::steady_clock> pauseStart;
        std::chrono::microseconds pauseDuration;

    public:
        BasicTimer();
        BasicTimer(const std::uint64_t timeout_ticks);
        virtual ~BasicTimer() = default;

        /**
         * @brief This and all derived classes will express 1uS as 1 tick
         */
        uint64_t ticksPerSecond() override final;
        virtual std::uint64_t maxTicks() override;

        virtual void setTimeout(const std::uint64_t timeout_ticks) override;
        virtual uint64_t ticksRemaining() override;
        virtual bool hasExpired() override;

        virtual void reset() override;
        virtual void start() override;
        virtual void stop() override;

        virtual void pause() override;
        virtual void unpause() override;
        virtual bool isPaused() override;
    };
} // namespace semodia::controlengine::native::osal::timing

#endif // SEMODIA_CONTROLENGINE_NATIVE_BASICTIMER_HPP
