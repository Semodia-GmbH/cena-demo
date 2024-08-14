/**
 * @file      IServiceOperationAndSourceMode.hpp
 * @date      1/31/22
 * @createdBy ichrispa
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_ISERVICEOPERATIONANDSOURCEMODE_HPP
#define CONTROLENGINE_NATIVE_ISERVICEOPERATIONANDSOURCEMODE_HPP

#include "mtp/MtpStatusCode.hpp"
#include "mtp/OperationModeId.hpp"
#include "mtp/ServiceSourceModeId.hpp"

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @class IServiceOperationAndSourceMode
     * @brief Interface specification for classes that provide a combination of ServiceOperationModes and ServiceSourceMode
     */
    class IServiceOperationAndSourceMode
    {
    protected:
        /**
         * @brief Updates service and operation modes in tandem to ensure valid combinations and flags. Changes modes as a result.
         * @details This method should not be called from userspace; it is usually invoked by the Service-Class, restrictions on when/in what states to call this function may apply (i.e. to procedure- or serviceparameters).
         * @return GOOD on success, ERROR_NOT_AVAILABLE if sync is active (parameters only), ERROR_MISSING_MODEL_ELEMENT or appropriate error code
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual mtp::MtpStatusCode updateOperationAndServiceMode() = 0;

    public:
        IServiceOperationAndSourceMode() = default;
        virtual ~IServiceOperationAndSourceMode() = default;

        /**
         * @brief Requests the given OperationMode (Offline, Operator, Automatic) and the source (Internal, External).
         *        This only affects the internal mode - if sync is set, this has no effect on the ParameterElement
         * @param mode is one of Offline, Operator or Automatic
         * @param source may be internal or external and is only effective in combination with Automatic
         */
        virtual MtpStatusCode requestOperationMode(const mtp::OperationModeId& mode, const mtp::ServiceSourceModeId& source) = 0;

        /**
         * @brief Determines whether control of operationsMode and sourceMode are handled by the PEA requests or
         *        if the Operator mode requests are prioritized over the PEAs. @see ServiceControl::requestModeControl()
         *        This only affects the internal mode - if sync is set, this has no effect on the ParameterElement
         * @param modeControlledByPEA `true` sets the PEA as controller over the modes, i.e. a requested mode will be
         *        assumed if it is legal to do so.
         */
        virtual mtp::MtpStatusCode requestModeControl(const bool& modeControlledByPEA) = 0;

        /**
         * @return True both SourceChannels are `true`; false if status cannot be determined (ELEMENT_MISSING), is inconsistent or on error
         */
        virtual mtp::MtpStatusCode isControlledByPEA(bool& peaControlled) const = 0;

        /**
         * @brief Redirects to @see isControlledByPEA(bool& peaControlled), disregarding the statuscode
         * @details Usage of functions that do not evaluate possible errors in userspace is discouraged
         */
        [[nodiscard]] virtual bool isControlledByPEA() const
        {
            bool value = false;
            if(mtp::MtpStatusCode::GOOD == (this->isControlledByPEA(value)))
            {
                return value;
            }
            return false;
        };

        /**
         * @return True if OpMode is offline; false if status cannot be determined (ELEMENT_MISSING) or on error
         */
        virtual mtp::MtpStatusCode isOffline(bool &offline) const = 0;

        /**
         * @brief Redirects to @see isOffline(bool& peaControlled), disregarding the statuscode
         * @details Usage of functions that do not evaluate possible errors in userspace is discouraged
         */
        [[nodiscard]] virtual bool isOffline() const
        {
            bool value = false;
            if(mtp::MtpStatusCode::GOOD == (this->isOffline(value)))
            {
                return value;
            }
            return false;
        };

        /**
         * @return True if OpMode is Op; false if status cannot be determined (ELEMENT_MISSING) or on error
         */
        virtual mtp::MtpStatusCode isOperatorControlled(bool &operatorControlled) const = 0;

        /**
         * @brief Redirects to @see isOperatorControlled(bool& peaControlled), disregarding the statuscode
         * @details Usage of functions that do not evaluate possible errors in userspace is discouraged
         */
        [[nodiscard]] virtual bool isOperatorControlled() const
        {
            bool value = false;
            if(mtp::MtpStatusCode::GOOD == (this->isOperatorControlled(value)))
            {
                return value;
            }
            return false;
        };

        /**
         * @return True if OpMode is Automatic and SourceMode is Internal; false if status cannot be determined (ELEMENT_MISSING) or on error
         */
        virtual mtp::MtpStatusCode isAutomaticInternal(bool &automaticInternal) const = 0;

        /**
        * @brief Redirects to @see isAutomatic(bool& peaControlled), disregarding the statuscode
        * @details Usage of functions that do not evaluate possible errors in userspace is discouraged
        */
        [[nodiscard]] virtual bool isAutomaticInternal() const
        {
            bool value = false;
            if(mtp::MtpStatusCode::GOOD == (this->isAutomaticInternal(value)))
            {
                return value;
            }
            return false;
        };

        /**
         * @return True if OpMode is Automatic and SourceMode is External; false if status cannot be determined (ELEMENT_MISSING) or on error
         */
        virtual mtp::MtpStatusCode isAutomaticExternal(bool &automaticExternal) const = 0;

        /**
        * @brief Redirects to @see isAutomaticExternal(bool& peaControlled), disregarding the statuscode
        * @details Usage of functions that do not evaluate possible errors in userspace is discouraged
        */
        [[nodiscard]] virtual bool isAutomaticExternal() const
        {
            bool value = false;
            if(mtp::MtpStatusCode::GOOD == (this->isAutomaticExternal(value)))
            {
                return value;
            }
            return false;
        };
    };
}; // namespace
#endif //CONTROLENGINE_NATIVE_ISERVICEOPERATIONANDSOURCEMODE_HPP
