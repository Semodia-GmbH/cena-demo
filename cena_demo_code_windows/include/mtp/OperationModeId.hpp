/**
 * @file      OperationModeId.hpp
 * @date      9/30/20
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_OPERATIONMODEID_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_OPERATIONMODEID_HPP

namespace semodia::controlengine::native::model::mtp {
    /**
     * @enum StateChannelId
     * @brief Identifies if a variables contents should be updated from one of the three requesters: None, Operator
     *        or one of two Automatic sources from the PEA (Programming or HMI)
     */
    enum class OperationModeId {
        Offline,     //! Values cannot be changed
        Operator,    //! Use `valueNameOp`
        Automatic    //! Depending on source mode: Use either `valueNameExt` or `valueNameInt`
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_OPERATIONMODEID_HPP
