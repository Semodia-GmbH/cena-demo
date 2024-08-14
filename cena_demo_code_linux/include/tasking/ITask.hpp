/* 
 * @brief   The rudimentary task interface
 * @author  Chris Paul Iatrou
 * @created 7/21/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ITASK_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ITASK_HPP

#pragma once

#include "tasking/TaskState.hpp"
#include "locking/ILockable.hpp"

/**
 * @brief Contains Task-Models, Interfaces and Cross-Plattform tasks implementation for the Operating System Abstraction Layer
 */
namespace semodia::controlengine::native::osal::tasking{
    /**
     * @brief Interface class describing a task that can be started, run and stopped. Implementations may include both
     *        threaded task models and iterated task loops.
     */
    class ITask {
    private:
        /**
         * @brief Copy constructor is deleted; a task can not be copied, as that would imply that the task including its
         *        internal state can be trivially copied as well.
         */
        ITask(const ITask &) = delete;
        ITask& operator= (const ITask &) = delete;
    protected:
        /**
         * @brief The task state; can be publicy read but only settable privately
         */
        TaskState state;
        
        /**
         * @brief Set 'true' to instruct the (possibly threaded) task to keep running.
         *        A threaded main loop should terminate if this becomes false.
         */
        bool run;
        
        /**
         * @ingroup taskStatus
         * @brief Update the internal state of this task; default implementation is not thread-safe.
         * @param newState
         */
        virtual void setTaskState(const TaskState newState) { this->state = newState; };
        
        /**
         * @ingroup taskBusinessLogic
         * @brief Called before start() is called by doStart() or run is set.
         */
        virtual void preStart() {};
    
        /**
         * @ingroup taskBusinessLogic
         * @brief Describes the startup logic of a task. Called by doStart().
         */
        virtual void start() {};
    
        /**
         * @ingroup taskBusinessLogic
         * @brief Describes how a task is initialized before start() is called. Called by doStart().
         */
        virtual void postStart() {};
    
        /**
         * @ingroup taskBusinessLogic
         * @brief Execute the business logic exactly once. Can be called either directly by doRun() or by thread if the OS supports it.
         *        iterate() must exit/return if run==false.
         */
        virtual void iterate() = 0;
    
        /**
         * @ingroup taskBusinessLogic
         * @brief Actions performed prior to stop(). Called by doTerminate() before run=false is set.
         */
        virtual void preStop() {};
    
        /**
         * @ingroup taskBusinessLogic
         * @brief Actions performed to stop the task. Called by doTerminate().
         */
        virtual void stop() {};
    
        /**
         * @ingroup taskBusinessLogic
         * @brief Actions performed once after the task is stopped. Called by doTerminate().
         */
        virtual void postStop() {};
        
    public:
        ITask() : state(TaskState::stopped), run(false) {} ;
        
        /**
         * @ingroup taskControl
         * @brief Handles initializing a task using (pre/post)-start(). May set run=true for doRun.
         */
        virtual void doStart() = 0;
        
        /**
         * @ingroup taskControl
         * @brief If the task is running, this will handle how/when iterate() is invoked. Note that this function should
         *        not change bool run on its own (see doStart and doTerminate).
         */
        virtual void doRun() = 0;
    
        /**
         * @ingroup taskControl
         * @brief Waits for the task to stop running and calls (pre/post)-stop(). Sets run=false and waits for run-loop
         *        or doRun to exit.
         */
        virtual void doTerminate() = 0;
        
        /**
         * @ingroup taskStatus
         * @return true if doRun and not amRunning; default implementation is not thread-safe.
         */
        virtual TaskState getTaskState() { return this->state; };
    };
} //namespace semodia::controlengine::native::osal::tasking

#endif //SEMODIA_CONTROLENGINE_NATIVE_ITASK_HPP
