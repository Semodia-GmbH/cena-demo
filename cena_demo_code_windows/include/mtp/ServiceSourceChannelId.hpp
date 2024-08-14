/**
 * @file      ServiceSourceChannelId.hpp
 * @date      10/1/20
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_SERVICESOURCECHANNELID_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_SERVICESOURCECHANNELID_HPP

namespace semodia::controlengine::native::model::mtp {
    /**
     * @enum ServiceSourceChannelId
     * @brief For who controls the selection of values
     */
    enum class ServiceSourceChannelId {
        External,   //! POL or its Operator is responsible for selecting if which value (*Int, *Man, *Op) are used
        PEA         //! PEA is responsible for selecting if which value (*Int, *Man, *Op) are used
    };
} //namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_SERVICESOURCECHANNELID_HPP
