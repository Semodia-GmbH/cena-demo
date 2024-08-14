/**
 * @author  Chris Paul Iatrou
 * @created 9/14/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_HIERARCHICSTATE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_HIERARCHICSTATE_HPP

#pragma once

#include <map>
#include <list>
#include <memory>
#include <utility>

#include "IState.hpp"
#include "Transition.hpp"
#include "SMStatusCode.hpp"

namespace semodia::controlengine::native::util::statemachine {
    typedef std::function<void(void)> userStateAction;

    /**
     * @class NestedState
     * @brief A State that can have any number of simultaneously active substates.
     *        May be considered a state machine in its own right.
     * @param idType is used to identify a state - it is also used to store and retrieve substates from a map.
     */
    template<typename idType>
    class HierarchicState : public IState
    {
    protected:
        std::map<idType, std::shared_ptr<HierarchicState<idType>>> substates;
        std::list<Transition> transitions;

        idType stateId;
        bool initial;
        bool final;
        bool historizing;

        /**
         * @brief Has been activated by enter and may execute stay or exit if not final
         */
        bool active;

        /**
         * @brief Historical state that has run/exited before (active states are not initial)
         */
        bool paused;

        userStateAction entryUserAction;
        userStateAction stayUserAction;
        userStateAction exitUserAction;
        userStateAction abortUserAction;

    public:
        HierarchicState(idType id, bool isInitial=false, bool isFinal=false, bool isHistorizing =false)
            :   stateId(id),
                initial(isInitial),
                final(isFinal),
                historizing(isHistorizing),
                active(false),
                paused(false),
                entryUserAction([](){return;}),
                stayUserAction([](){return;}),
                exitUserAction([](){return;}),
                abortUserAction([](){return;})
        {
            return;
        };

        HierarchicState(idType id, userStateAction onEntry, userStateAction onStay, userStateAction onExit, userStateAction onAbort,  bool isInitial=false, bool isFinal=false, bool isHistorizing=false)
                :   stateId(id),
                    initial(isInitial),
                    final(isFinal),
                    historizing(isHistorizing),
                    active(false),
                    paused(false),
                    entryUserAction(std::move(onEntry)),
                    stayUserAction(std::move(onStay)),
                    exitUserAction(std::move(onExit)),
                    abortUserAction(std::move(onAbort))
        {
            return;
        };

        virtual ~HierarchicState() = default;

        // Status; inherited by interface
        /**
         * @copydoc semodia::controlengine::native::util::statemachine::IState::isInitial()
         */
        virtual bool isInitial() const final
        {
            return this->initial;
        };

        /**
         * @copydoc semodia::controlengine::native::util::statemachine::IState::isFinal()
         */
        virtual bool isFinal() const final
        {
            return this->final;
        };

        /**
         * @copydoc semodia::controlengine::native::util::statemachine::IState::isHistorizing()
         */
        virtual bool isHistorizing() const final
        {
            return this->historizing;
        };

        /**
         * @copydoc semodia::controlengine::native::util::statemachine::IState::isActive()
         */
        virtual bool isActive() const final
        {
            return this->active;
        };

        /**
         * @copydoc semodia::controlengine::native::util::statemachine::IState::isPaused()
         */
        virtual bool isPaused() const final
        {
            return this->historizing && this->paused;
        };

        // Runtime; inherited by interface; these can be overwritten
        /**
         * @copydoc semodia::controlengine::native::util::statemachine::IState::enter()
         */
        virtual void enter() override {
            this->active = true;

            // Set all initial substates to active (in historic states: Only if not paused)
            if (!this->isHistorizing() || ( this->isHistorizing() && !this->isPaused() )) {
                // Warning correct: We don't use _; we also don't intend to in this context
                for ([[maybe_unused]] auto const&[_, s] : this->substates) {
                    if (s->isInitial() ) {
                        s->enter();
                    }
                }
            }

            this->paused = false;

            this->entryUserAction();

            return;
        }

        /**
         * @copydoc semodia::controlengine::native::util::statemachine::IState::stay();
         */
        virtual void stay() override {
            if (!this->isActive() || this->isFinal()) {
                // Final states don't execute "stay"
                return;
            }

            // Check all transitions; take first active transition
            for (auto &t : this->transitions) {
                if (t.test()) {
                    this->exit();
                    t.getTargetState().enter();
                    return;
                }
            }

            this->stayUserAction();

            // Tick substates. To avoid "chasing" an execution token (A->B->C) from one state to the next, create
            // a list of active states first, then explicitly process those.
            std::list<std::shared_ptr<HierarchicState<idType>>> activeStates;
            // Warning correct: We don't use _; we also don't intend to in this context
            for ([[maybe_unused]] auto const&[_, s] : this->substates) {
                if (s->isActive() ) {
                    activeStates.push_back(s);
                }
            }
            for(auto& s : activeStates) {
                s->stay();
            }

            return;
        }

        /**
         * @copydoc semodia::controlengine::native::util::statemachine::IState::exit()
         */
        virtual void exit() override {
            if (!this->isActive() || this->isFinal()) {
                // Final states cannot be exited
                return;
            }
            this->active = false;

            this->exitUserAction();

            if (this->isHistorizing()) {
                // Historizing states are just paused; substates will resume
                this->paused = true;
            }
            else {
                // Non-Historizing states abort their substates
                // Warning correct: We don't use _; we also don't intend to in this context
                for ([[maybe_unused]] auto const&[_, s] : this->substates) {
                    if (s->isActive()) {
                        s->abort();
                    }
                }
            }

            return;
        }

        /**
        * @copydoc  semodia::controlengine::native::util::statemachine::IState::abort();
        */
        virtual void abort() override {
            if (!this->isActive() || this->isFinal()) {
                // Final states cannot be aborted
                return;
            }

            if (this->isHistorizing()) {
                this->paused = false;
            }

            this->active = false;

            this->abortUserAction();

            // Also abort all substates
            // Warning correct: We don't use _; we also don't intend to in this context
            for ([[maybe_unused]] auto const&[_, s] : this->substates) {
                if (s->isActive()) {
                    s->abort();
                }
            }

            return;
        }

        // New functions
        /**
         * @brief A HierarchicState is identified by an ID type (i.e. a string)
         * @return the ID of this state
         */
        virtual const idType& getId() const {
            return this->stateId;
        }

        /**
         * @brief Create a new substate
         * @return GOOD on success, ERROR_STATEIDEXISTS if the ID is already used (no state created)
         */
        virtual SM_StatusCode addSubstate(std::shared_ptr<HierarchicState<idType>> newState)
        {
            // Test if the ID is unique in our map
            if (this->substates.count(newState->getId()) != 0) {
                return SM_StatusCode::ERROR_STATEIDEXISTS;
            }
            this->substates.insert(std::pair<idType, std::shared_ptr<HierarchicState<idType>>> (newState->getId(), newState));

            return SM_StatusCode::GOOD;
        };

        /**
         * @brief Create a new substate
         * @return GOOD on success, ERROR_STATEIDEXISTS if the ID is already used (no state created)
         */
        virtual SM_StatusCode addSubstate(idType id, bool isInitial, bool isFinal, bool isHistorizing)
        {
            return this->addSubstate(std::make_shared<HierarchicState<idType>>(id, isInitial, isFinal, isHistorizing));
        };

        /**
         * @brief Create a new substate
         * @return GOOD on success, ERROR_STATEIDEXISTS if the ID is already used (no state created)
         */
        virtual SM_StatusCode addSubstate(idType id, userStateAction onEntry, userStateAction onStay, userStateAction onExit, userStateAction onAbort, bool isInitial, bool isFinal, bool isHistorizing)
        {
            return this->addSubstate(std::make_shared<HierarchicState<idType>>(
                id, onEntry, onStay, onExit, onAbort, isInitial, isFinal, isHistorizing));
        };

        /**
         * @brief Create a new addTransition to this state
         * @return GOOD on success, ERROR_ILLEGALOPERATION if this is a final state
         */
        virtual SM_StatusCode addTransition(std::shared_ptr<HierarchicState<idType>> toState, guardFunction guard)
        {
            if (this->isFinal()) {
                return SM_StatusCode::ERROR_ILLEGALOPERATION;
            }
            this->transitions.push_back(Transition(toState, guard));

            return SM_StatusCode::GOOD;
        };

        /**
         * @brief Find the transition identified by fromSubstate in our list of substates and add a new transition to it
         * @return GOOD on success, ERROR_ILLEGALOPERATION if fromstate is a final state, ERROR_STATENOTFOUND if either state was not found
         */
        virtual SM_StatusCode addTransition(idType fromSubstate, idType toSubstate, guardFunction guard)
        {
            // both states must exist ...
            if (this->substates.count(fromSubstate) == 0 || this->substates.count(toSubstate) == 0) {
                return SM_StatusCode::ERROR_STATENOTFOUND;
            }

            // ... so we can safely add the transition
            return this->getSubstate(fromSubstate)->addTransition(this->getSubstate(toSubstate), guard);
        };

        /**
         * @param The ID of the substate in question
         * @return A shared pointer to the substate or a nullptr
         */
        virtual std::shared_ptr<HierarchicState<idType>> getSubstate(idType subStateId) const
        {
            std::shared_ptr<HierarchicState<idType>> retval = nullptr;

            // find() maintains const, while [substateId] would attempt to add substate to map if not found...
            auto entry = this->substates.find(subStateId);
            if (entry != this->substates.end())
            {
                retval = entry->second;
            }

            return retval;
        };

        /**
         * @brief Search any child states recursively and retrieve a state with the given ID
         * @param The ID of the substate in question
         * @return A shared pointer to the substate or a nullptr
         */
        virtual std::shared_ptr<HierarchicState<idType>> getNestedSubstate(idType subStateId) const
        {
            std::shared_ptr<HierarchicState<idType>> retval = this->getSubstate(subStateId);

            if (retval == nullptr) {
                for ([[maybe_unused]] auto const&[_, s] : this->substates) {
                    retval = s->getNestedSubstate(subStateId);
                    if (retval != nullptr) {
                        return retval;
                    }
                }
            }

            return retval;
        };

        /**
         * @brief Switches the action invoked when the state is aborted
         * @param action
         */
        void setAbortUserAction(userStateAction action)
        {
            this->abortUserAction = action;
        };

        /**
         * @brief Switches the action invoked when the state exits using a transition
         * @param action
         */
        void setExitUserAction(userStateAction action)
        {
            this->exitUserAction = action;
        };

        /**
         * @brief Switches the action invoked when the state is active an no transition is taken
         * @param action
         */
        void setStayUserAction(userStateAction action)
        {
            this->stayUserAction = action;
        };

        /**
         * @brief Switches the action invoked when the state becomes active using a transition or initial
         * @param action
         */
        void setEntryUserAction(userStateAction action)
        {
            this->entryUserAction = action;
        };
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_HIERARCHICSTATE_HPP
