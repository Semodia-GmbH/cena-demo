/**
 * @author  Chris Paul Iatrou
 * @created 14.09.2020
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ISTATE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ISTATE_HPP


namespace semodia::controlengine::native::util::statemachine {
    /**
     * @class IState
     * @brief The interface of an arbitrary state
     */
    class IState {
    public:
        virtual ~IState() = default;

        // Status
        /**
         * @ingroup stateStatus
         * @brief A state is active either if it `isInitial()` or if `enter()` was called, but `exit()` was not.
         *        A final state is never active.
         * @return true if active.
         */
        virtual bool isActive() const = 0;

        /**
         * @ingroup stateStatus
         * @brief A state is initial if it is active when the state machine starts (without invoking enter()).
         *        An initial state can only call stay() and exit();
         * @return true if initial.
         */
        virtual bool isInitial() const = 0;

        /**
         * @ingroup stateStatus
         * @brief A final state cannot be exited (transitions are always false) and does not execute stay();
         * @return true if final.
         */
        virtual bool isFinal() const = 0;

        /**
         * @ingroup stateStatus
         * @brief  A historizing state will remember the last substate that was active when exit() or abort() was called.
         *         If re-entered, the last active state (or states) will be re-activated.
         * @return
         */
        virtual bool isHistorizing() const = 0;

        /**
         * @ingroup stateStatus
         * @brief  A historizing state will use its initial substates on first activation; if exited, it is considered paused.
         *         The next entry will not activate initial states but case already active states to re-enter().
         *         Aborting will not pause a historic state, next entry will use initial substates again.
         * @return
         */
        virtual bool isPaused() const = 0;

        // Actions
        /**
         * @ingroup stateRuntime
         * @brief Activates initial substates (or historic states). If non-initial, this runs user-code if attached.
         */
        virtual void enter() = 0;

        /**
         * @ingroup stateRuntime
         * @brief Checks transitions in all active substates; exits() them if transitions are found and invokes enter()
         *        on transition targets if true. Calls stay() in active substates otherwise. Invokes user code if attached.
         */
        virtual void stay() = 0;

        /**
         * @ingroup stateRuntime
         * @brief Invokes abort() in all active substates that are non-final. Saves historic state if configured.
         *        Calls user code if attached.
         */
        virtual void exit() = 0;

        /**
         * @ingroup stateRuntime
         * @brief Invokes abort() in all active substates that are non-final. Saves historic state if configured.
         *        Calls user code if attached.
         */
        virtual void abort() = 0;
    };
} //namespace



#endif //SEMODIA_CONTROLENGINE_NATIVE_ISTATE_HPP
