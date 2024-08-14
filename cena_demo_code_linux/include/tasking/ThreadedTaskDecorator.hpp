/**
 * @date      8/27/20
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_THREADEDTASKDECORATOR_H
#define SEMODIA_CONTROLENGINE_NATIVE_THREADEDTASKDECORATOR_H

#include <thread>
#include "tasking/ITask.hpp"
#include <atomic>

namespace semodia::controlengine::native::osal::tasking {
    /**
     * @class ThreadedTaskDecorator
     * @brief   A decoratation option for tasks that allows threaded execution in the respective OS
     * @details User this decorator alongside the actual task instance; make sure to doStop() the thread decorator *before* the ITask pointed to is destroyed
     */
    class ThreadedTaskDecorator : public tasking::ITask {
    private:
        /**
         * @brief A pointer to the task we wrap in the thread; note that this is in effect only a pointer, so we
         *        have no control over the actual objects lifetime
         */
        ITask& wrappedTask;
        std::thread* runnerThread;

        /**
         * @brief instructs the thread to run/stop; non-mutex-secured, only change this from the decorator, never from the thread
         */
        std::atomic<bool> threadRun;

        /**
         * @brief to maintain semantics with task-loop-tasks, we start running the thread contents only if the user
         *        has instructed us to run (even thought the thread is created through start). This boolean acts a a gate
         *        to calling the wrapped doRun() inside the thread.
         */
        std::atomic<bool> doRunCalled;

        /**
         * @brief Time to sleep between iterations of the wrapped task in microseconds
         */
        std::atomic<std::chrono::microseconds> sleepTime;

        /**
         * @brief Indicates, whether the thread decorator will pause between iterations
         * @details True, if sleepTime == 0
         */
        std::atomic<bool> doSleep;

        /**
         * @brief main thread loop, exited if threadRun==false. Will invoke wrappedTask.doRun() if doRunCalled==true.
         */
        virtual void iterate() override;

    public:
        ThreadedTaskDecorator(ITask& wrappedTask);

        virtual ~ThreadedTaskDecorator();

        // Inherited from ITask
        /**
         * @brief Runs the wrapped tasks start, then wraps it in a thread. The thread is gated and will only doRun()
         *        the wrapped task if doRun() was invoked at least once.
         */
        virtual void doStart() override;

        /**
         * @brief ungates the thread's invocation of the wrapped task
         */
        virtual void doRun() override;
        /**
         * @brief stop the thread, then invoke the wrapped tasks stop function
         */
        virtual void doTerminate() override;

        /**
         * @brief Set the sleep time between iterations
         * @details This timeout is not intended as a means to delay a task; for tasks that are meant to only run every
         * X seconds, please use the @see tasking::FrequencyLimitedTaskLoopTask. This call to sleep is meant as a
         * voluntary task preemption between calls to iterate() on the timescale of ~100uS-500uS. Set to
         * std::chrono::microseconds::zero() to disable sleeping.
         */
        void setSleepTime(const std::chrono::microseconds);
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_THREADEDTASKDECORATOR_H
