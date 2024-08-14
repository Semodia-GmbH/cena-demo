/**
 * @author  Chris Paul Iatrou
 * @created 14.09.2020
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ITRANSISITION_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ITRANSISITION_HPP

#pragma once

#include "IState.hpp"

namespace semodia::controlengine::native::util::statemachine {
    /**
     * @class ITransition
     * @brief 
     */
    class ITransition {
    public:
        virtual ~ITransition() = default;

        /**
         * @brief test the transition guard
         * @return return true if the followup-state can be activated.
         */
        virtual bool test() = 0;

        /**
         * @return the state configured as target of this transition
         */
        virtual IState& getTargetState() = 0;
    };
} //namespace



#endif //SEMODIA_CONTROLENGINE_NATIVE_ITRANSISITION_HPP
