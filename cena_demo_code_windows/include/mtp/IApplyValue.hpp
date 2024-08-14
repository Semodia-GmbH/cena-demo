/**
 * @file      IApplyValue.hpp
 * @date      1/27/22
 * @createdBy ichrispa
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_IAPPLYVALUE_HPP
#define CONTROLENGINE_NATIVE_IAPPLYVALUE_HPP

#include "mtp/MtpStatusCode.hpp"

namespace semodia::controlengine::native::model::mtp
{

    /**
    * @class  IApplyValue
    * @brief Interface describes interface provided by functions that implement "ApplyBaseFunction" to provide a uniform interface
    */
    class IApplyValue
    {
    public:
        IApplyValue() = default;
        virtual ~IApplyValue() = default;

        /**
         * @brief Used by the PEA to allow/interdict value updates of a ParameterElements in general; setting to true
         *        will enable evaluation of the ApplyExt/Op/Int update triggers.
         * @param allow
         * @return GOOD on success, an appropriate error code otherwise
         */
        virtual mtp::MtpStatusCode requestApplicationOfUpdatedValue() = 0;

        /**
          * @brief Reports on the applyEnable status, setable using @see allowValueUpdates()
          * @param allow is set to ApplyEn value (if GOOD is returned) or false if model elements are missing
          * @return GOOD on success, an appropriate error code otherwise
          */
        virtual mtp::MtpStatusCode allowValueUpdates(const bool& allow) = 0;

        /**
         * @brief Checks the apply-flags based on the current source- and operationmode and invokes the `onApply`
         *        callback if appropriate
         * @return true if AppleEn exists and is set, false otherwise
         */
        virtual bool isUpdatingAllowed() const = 0;
    };
};

#endif //CONTROLENGINE_NATIVE_IAPPLYVALUE_HPP