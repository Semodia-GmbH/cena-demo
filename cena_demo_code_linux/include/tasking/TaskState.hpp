/*
 * @author  Chris Paul Iatrou
 * @created 7/22/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_TASKSTATE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_TASKSTATE_HPP

#pragma once

namespace semodia::controlengine::native::osal::tasking{
    /**
     * @brief Describe the run-state of the current task to external observers
     *        A task is subject to a simple state life-cycle model
     *
     * @startuml
        [*] --> Stopped
        
        Starting : "doStart() called, but not complete"
        Started : "doStart() complete"
        Running : "doRun() completed at least once"
        Stopping : "doStop() called, but not complete"
        Idle: "Task ready to run, but currently idling"
        
        Stopped --> Starting
        Starting --> Started
        
        Started --> Running
        Started --> Stopping
        
        Idle --> Running
        Running --> Idle
        
        Running --> Stopping
        Stopping --> Stopped
     * @enduml
     *
     * The conceptual difference between "started" and "running" is best understood in terms of multi-threading: A
     * started task is ready to run, but currently not executing. A running task has a started thread that is running the
     * business logic in the background. In voluntary/cooperative task models, a task is running while iterate() has not
     * completed. An idling task has run once, but is also currently not in iterate().
     *
     * Some Task specializations may choose to forgo non-applicable state transitions.
     *
     */
    enum class TaskState {
        starting, //! task is currently starting (which might be blocking/waiting)
        started,  //! task has been initialized and is ready to run
        running,  //! task is currently executing its business logic (iterate)
        idle,     //! task has been started and has run, but is currently not running
        stopping, //! task is currently stopping (which might be blocking/waiting)
        stopped,  //! task is not initialized
        aborted   //! error state, something went wrong
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_TASKSTATE_HPP
