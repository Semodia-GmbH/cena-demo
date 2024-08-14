/**
 * @file      StateChannelId.hpp
 * @date      9/30/20
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_STATECHANNELID_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_STATECHANNELID_HPP

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @enum StateChannelId
     * @brief Identifies who has control over selecting which values are used in an operation mode
     */
    enum class StateChannelId
    {
        External,   //! POL or its Operator is responsible for selecting if which value (*Int, *Man, *Op) are used
        PEA         //! PEA is responsible for selecting if which value (*Int, *Man, *Op) are used
    };
} //namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_STATECHANNELID_HPP