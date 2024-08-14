/**
 * @author  Chris Paul Iatrou
 * @created 14.09.2020
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_TRANSITION_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_TRANSITION_HPP

#pragma once

#include <functional>
#include <memory>
#include "ITransition.hpp"

namespace semodia::controlengine::native::util::statemachine {
    class IState;

    /**
     * @typedef guardFunction
     * @brief   a function that sets boolean; this allows lambda-functions to be used in this role
     */
    typedef std::function<void(bool&)> guardFunction;

    /**
     * @class Transition
     * @brief A transition between two states
     */
    class Transition : public ITransition {
    protected:
        std::shared_ptr<IState> targetState;
        guardFunction guard;

    public:
        Transition(std::shared_ptr<IState> targetState, guardFunction guard);
        virtual ~Transition() = default;

        // Inherited from interface
        /**
         * @copydoc semodia::controlengine::native::util::statemachine::ITransition::getTargetState()
         */
        virtual IState& getTargetState() override;

        /**
         * @copydoc semodia::controlengine::native::util::statemachine::ITransition::test()
         */
        virtual bool test() override;
    };

} //namespace



#endif //SEMODIA_CONTROLENGINE_NATIVE_TRANSITION_HPP
