/**
 * @author  Chris Paul Iatrou
 * @created 14.09.2020
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_SMSTATUSCODE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_SMSTATUSCODE_HPP

#pragma once

namespace semodia::controlengine::native::util::statemachine {
    /**
     * @enum SM_StatusCode
     * @brief Status code return values for the state machine
     */
    enum class SM_StatusCode {
        GOOD,
        ERROR_STATENOTFOUND,
        ERROR_STATEIDEXISTS,
        ERROR_ILLEGALOPERATION
    };

} //namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_SMSTATUSCODE_HPP
