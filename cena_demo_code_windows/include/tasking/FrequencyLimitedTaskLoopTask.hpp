/**
 * @file      FrequencyLimitedTaskLoopTask.hpp
 * @date      3/16/21
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2021). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_TASKING_FREQUENCYLIMITEDTASKLOOPTASK_HPP
#define SEMODIA_CONTROLENGINE_TASKING_FREQUENCYLIMITEDTASKLOOPTASK_HPP

#pragma once

#include <memory>
#include <cstdint>

#include "timing/ITimer.hpp"
#include "tasking/BasicTaskLoopTask.hpp"

namespace semodia::controlengine::native::osal::tasking
{
    /**
     * @class FrequencyLimitedTaskLoopTask
     * @brief Abstract extension of BasicTaskLoopTask that will only iterate every N time ticks and with the ability to report its next scheduled execution
     * @details BasicTaskLoopTask run every time doRun() is called. This class gates doRun() with a timer, so that
     *          doRun() can be called but iterate() will only trigger once in the configured interval.
     *          The class can report how many ticks a timer has remaining, which enables a main loop to schedule a task.
     */
    class FrequencyLimitedTaskLoopTask : public BasicTaskLoopTask
    {
    private:
        /**
         * @brief Exclusively owned timer; default interval is 0 ticks, which makes FrequencyLimitedTaskLoopTask behave
         *        exactly like a BasicTaskLoopTask.
         */
        std::unique_ptr<timing::ITimer> taskTimer;

    public:
        /**
         * @brief Create a new task, BasicTaskLoopTask
         * @param @see BasicTaskLoopTask::BasicTaskLoopTask()
         * @param timer is the timer owned by this class (ownership passes to the task); tick count on the timer is set to 0
         */
        FrequencyLimitedTaskLoopTask(std::unique_ptr<locking::ILockable> taskLock, std::unique_ptr<timing::ITimer> taskTimer);

        /**
         * @brief Create a new task, BasicTaskLoopTask
         * @param @see BasicTaskLoopTask::BasicTaskLoopTask()
         * @param timer is the timer owned by this class (ownership passes to the task)
         * @param executionIntervalInMilliseconds is the initial value for the timer ticks (which is computed based on the specific timer instance)
         */
        FrequencyLimitedTaskLoopTask(std::unique_ptr<locking::ILockable> taskLock, std::unique_ptr<timing::ITimer> taskTimer, const float& executionIntervalInMilliseconds);

        virtual ~FrequencyLimitedTaskLoopTask() ;

        FrequencyLimitedTaskLoopTask(const FrequencyLimitedTaskLoopTask &other) = default;
        FrequencyLimitedTaskLoopTask &operator=(const FrequencyLimitedTaskLoopTask &rhs) = default;

        /**
         * @brief Reset our timer before calling parent implementation @see BasicTaskLoopTask::doRun()
         */
        virtual void doStart() override;

        /**
         * @brief Only calls parent implementation @see BasicTaskLoopTask::doRun() if our timer has expired
         */
        virtual void doRun() override;

        /**
         * @return the number of ticks per seconds as reported by our timer instance
         */
        virtual std::uint64_t getTimerTicksPerSecond() const;

        /**
         * @brief Sets this tasks execution interval (overwrites any option prev. set by CTor)
         */
        virtual void setTickCountBetweenIterations(const std::uint64_t& ticks);

        /**
         * @return the number of ticks remaining on the internal task timer
         */
        virtual std::uint64_t getTicksToNextIteration() const;
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_TASKING_FREQUENCYLIMITEDTASKLOOPTASK_HPP
