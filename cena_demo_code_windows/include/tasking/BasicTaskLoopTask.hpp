/*
 * @author  Chris Paul Iatrou
 * @created 7/21/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_BASICTASKLOOPTASK_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_BASICTASKLOOPTASK_HPP

#pragma once

#include <memory>
#include "locking/ILockable.hpp"
#include "tasking/ITask.hpp"

namespace semodia::controlengine::native::osal::tasking {
    /**
     * @brief A task designed for doRun() to be periodically called from a main loop or task handler (as opposed to a threaded task).
     *        This task employs locks for accessing status values, so it should be thread safe (depending on the implementation of the
     *        ILockable lock).
     */
    class BasicTaskLoopTask : public ITask {
    private:
        /**
         * @brief locked() when the taskstate or run variables are accessed. Also, access to iterate() is locked, so
         *        the business logic cannot be active multiple times if doRun() is invoked repeatedly.
         */
        std::unique_ptr<locking::ILockable> atomicTaskOperationsLock;

        /**
         * @brief Attempts to lock the mutex if
         */
        void enterAtomicExecution();

        /**
         * @brief Attempts to lock the mutex if
         */
        void exitAtomicExecution();

    protected:
        virtual void setTaskState(TaskState newState) override;
        
    public:
        /**
         * @brief Constructs a new loopable task that uses the given lock
         * @param atomicTaskOperationsLock
         */
        BasicTaskLoopTask(std::unique_ptr<locking::ILockable> atomicTaskOperationsLock);
        virtual ~BasicTaskLoopTask() ;
        
        // Inherited from ITask (see ITask documentation)
        virtual void doStart() override;
    
        // Inherited from ITask (see ITask documentation)
        virtual void doRun() override;
    
        // Inherited from ITask (see ITask documentation)
        virtual void doTerminate() override;
        
        virtual TaskState getTaskState() override;
    };
} //namespace semodia::controlengine::native::osal::tasking

#endif //SEMODIA_CONTROLENGINE_NATIVE_BASICTASKLOOPTASK_HPP
