/**
 * @file      ServiceSourceModeId.hpp
 * @date      10/1/20
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_SERVICESOURCEMODE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_SERVICESOURCEMODE_HPP

namespace semodia::controlengine::native::model::mtp {
    /**
     * @enum ServiceSourceModeId
     * @brief Identifies the value source in automatic operation modes of services; principally the same as a
     *        @see SourceModeId, but uses "EXTERNAL" in its naming scheme instead of "MANUAL"
     *
     */
    enum class ServiceSourceModeId {
        None,       //! Value returned if not in Automatic
        External,   //! Value update from manual inputs ending on `*Ext`
        Internal    //! Value updates originate from variables ending on `*Int`, which are set by the pea
    };
} //namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_SERVICESOURCEMODE_HPP
