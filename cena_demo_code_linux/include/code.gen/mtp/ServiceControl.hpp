/**
 * @file ServiceControl.hpp
 * @date Thursday, September 24, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_CONTROL_HPP
#define HAVE_SERVICE_CONTROL_HPP

#pragma once

#include "mtp/base/ServiceControl.hpp"
#include "mtp/IServiceOperationAndSourceMode.hpp"
#include "mtp/ServiceStateId.hpp"
#include "mtp/ServiceCommandId.hpp"
#include "mtp/MtpStatusCode.hpp"
#include "mtp/IQualityCode.hpp"
#include "mtp/ApplyBaseFunction.hpp"

namespace semodia::controlengine::native::model::mtp
{
    // Early definitions
    class Service;

    /**
     * @class ServiceControl
     * @brief ServiceControl defines a service.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ServiceControl : public base::ServiceControl, public IServiceOperationAndSourceMode
    {
    protected:
        /**
         * @brief All ServiceControl members should be considered members of mtp::Service... unfortunately, that's not
         *        how the VDI/VDE/NAMUR 2568-4 models services. We are left with friending our Service class.
         */
        friend mtp::Service;

        /**
         * @brief    @see IServiceOperationAndSourceMode::requestOperationMode()
         * @details  Method should only be used by Service-class (API-internal)
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual MtpStatusCode requestOperationMode(const mtp::OperationModeId& mode, const mtp::ServiceSourceModeId& source) override;

        /**
         * @brief    @see IServiceOperationAndSourceMode::requestModeControl()
         * @details  Method should only be used by Service-class (API-internal)
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual MtpStatusCode requestModeControl(const bool &modeControlledByPEA) override;

        /**
         * @brief @see IServiceOperationAndSourceMode::updateOperationAndServiceMode()
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual MtpStatusCode updateOperationAndServiceMode() override;

       /**
        * @brief Called by service FSM to update the state number visible to POL if the state changes
        * @details Should never be called from userspace and has no effect on actual Service FSM
        * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
        */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual mtp::MtpStatusCode setCurrentState(const mtp::ServiceStateId& state);

        /**
        * @brief Updates the POL-visible enabled commands, represented as a bitvector;
         *       CurrentState is used to create a bitMask that hides transitions from other states than currentState, so setCurrentState should be called first
        * @details Should never be called from userspace.
         *         The enabled commands need to be retrieved from the currently active or selected procedure, which can currently only be determined by the service class.
        * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
        */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual mtp::MtpStatusCode setCurrentCommandEn(const std::uint32_t& commandEnableVector);

        /**
         * @brief   Determines correct source of command (Int/Ext/Op) and returns the effective command;
         * @details Should never be called from userspace; this will change the command seen by the FSM and may cause the FSM to ignore/miss a POL input if updated at the wrong point in time
         * @param   command is set to NONE or a valid command;
         *          note that 'requesting' a command does in no way suggest that the PEA will accept this input to its FSM
         * @return  GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual mtp::MtpStatusCode getUpdatedRequestedCommand(mtp::ServiceCommandId& command);

        /**
         * @brief Transfers ProcedureReq to ProcedureCur and clear/resets request fields
         * @details Should never be called from userspace; happens during specific point in service execution
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual mtp::MtpStatusCode getUpdatedCurrentProcedureId(std::uint32_t& procedureId);

        /**
         * @brief Indicates if all service-owned ConfigurationParameters have their respective ApplyEn set
         * @details Should never be called from userspace; this is determined by the service by querying all parameters
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual mtp::MtpStatusCode allowConfigurationParameterUpdates(const bool& allow);

        /**
         * @brief Indicates if all procedure-owned ProcedureParameters in the currently active procedure have their respective ApplyEn set
         * @details Should never be called from userspace; this is determined by the service & active procedure by querying all parameters
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual mtp::MtpStatusCode allowProcedureParameterUpdates(const bool& allow);

    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::ServiceControl::base::ServiceControl for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ServiceControl(const std::string& TagName,
                       const std::string& TagDescription,
                       std::shared_ptr<InstanceReferences> References,
                       std::shared_ptr<mtp::ObjectItem> ObjectItem,
                       std::shared_ptr<mtp::Timestamped> Timestamped,
                       std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC,
                       std::shared_ptr<mtp::ServiceOperationModeBaseFunction> ServiceOperationMode,
                       std::shared_ptr<mtp::ServiceSourceModeBaseFunction> ServiceSourceMode,
                       std::shared_ptr<mtp::ApplyBaseFunction> ProcParamApply,
                       std::shared_ptr<mtp::ApplyBaseFunction> ConfigParamApply,
                       std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>> OSLevel,
                       std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> CommandOp,
                       std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> CommandInt,
                       std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> CommandExt,
                       std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> ProcedureOp,
                       std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> ProcedureInt,
                       std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> ProcedureExt,
                       std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> StateCur,
                       std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> CommandEn,
                       std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> ProcedureCur,
                       std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> ProcedureReq,
                       std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> PosTextID,
                       std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> InteractQuestionID,
                       std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> InteractAnswerID,
                       std::shared_ptr<mtp::ReadDataItem<std::string>> InteractAddInfo,
                       std::shared_ptr<mtp::ReadWriteDataItem<bool>> ReportValueFreeze
        );

        /**
         * @ingroup MTP API
         * @brief Simplified C'Tor; creates all variables on its own
         */
        ServiceControl(const std::string& TagName, const std::string& TagDescription);

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pouinters 
          *        to null; those are done by base class @see base::ServiceControl::~base::ServiceControl  
          */
        virtual ~ServiceControl();

        /**
         * @brief Update Source|OpModes, Procedure|CommandRequests
         * @param configParamApplyCallback called if ApplyBaseFunction determines an update of the serviceParameters is required.
         *        This must be handled by the service or the respective currently active procedure as managed by the service.
         * @param procParamApplyCallback called if ApplyBaseFunction determines an update of the  procedureParameters is required
         *        This must be handled by the service or the respective currently active procedure as managed by the service.
         * @return GOOD on success, an appropriate error code otherwise
         */
        virtual MtpStatusCode update(const mtp::ApplyNewValueCallback& configParamApplyCallback,
                                     const mtp::ApplyNewValueCallback& procParamApplyCallback);

        // -------------------------
        // Handling of Service modes
        /**
         * @brief @see IServiceOperationAndSourceMode::isControlledByPEA()
         */
        virtual MtpStatusCode isControlledByPEA(bool &peaControlled) const override;
        using IServiceOperationAndSourceMode::isControlledByPEA; // unshadow base implementation

        /**
         * @brief @see IServiceOperationAndSourceMode::isOffline()
         */
        virtual MtpStatusCode isOffline(bool &offline) const override;
        using IServiceOperationAndSourceMode::isOffline; // unshadow base implementation

        /**
         * @brief @see IServiceOperationAndSourceMode::isOperatorControlled()
         */
        virtual MtpStatusCode isOperatorControlled(bool &operatorController) const override;
        using IServiceOperationAndSourceMode::isOperatorControlled; // unshadow base implementation
        /**
         * @brief @see IServiceOperationAndSourceMode::isAutomaticInternal()
         */
        virtual MtpStatusCode isAutomaticInternal(bool& automaticInternal) const override;
        using IServiceOperationAndSourceMode::isAutomaticInternal; // unshadow base implementation

        /**
         * @brief @see IServiceOperationAndSourceMode::isAutomaticExternal()
         */
        virtual MtpStatusCode isAutomaticExternal(bool &automaticExternal) const override;
        using IServiceOperationAndSourceMode::isAutomaticExternal; // unshadow base implementation

        // --------------------------------
        // Get/Setting StateCur (sanitized)
        /**
         * @brief Sets state to contain the valid enum representation of the current state - or UNKNOWN on error
         * @param state will be set to StateCur if GOOD is returned
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
         */
        virtual mtp::MtpStatusCode getCurrentState(mtp::ServiceStateId& state);

        // --------------------------------
        // Procedure and Command Requests
        /**
         * @brief Requests the Procedure, which will be considered when in mode Automatic/Internal
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
         */
        virtual mtp::MtpStatusCode requestProcedure(const std::uint32_t& procedureId);

        /**
         * @brief Evaluates Op/SourceMode and updates procedureReq if not offline
         * @param requestedProcedureId will be set to the effectively requested Id or 0 to indicate "none"
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
         */
        virtual mtp::MtpStatusCode getUpdatedRequestedProcedureId(std::uint32_t& requestedProcedureId);

        /**
         * @brief Returns ProcedureCur without updating or handshaking any MTP variables
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
         */
        virtual mtp::MtpStatusCode getCurrentProcedureId(std::uint32_t& procedureId);

        /**
         * @brief Requests the Command/Transition, which will be considered when in mode Automatic/Internal
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or appropriate error code
         */
        virtual mtp::MtpStatusCode requestCommand(const mtp::ServiceCommandId& command);

        /**
         * @brief Reports if a cumulative "Apply" of all service configuration parameters is permitted
         * @return True if all the services ConfigurationParameters have ApplyEn set; false otherwise
         */
        virtual bool isConfigurationParameterUpdateAllowed() const;

        /**
         * @brief Forwards to @see ApplyBaseFunction::requestApplicationOfUpdatedValue() of ConfigurationParameter ApplyBaseFunction
         */
        virtual mtp::MtpStatusCode requestApplicationOfUpdatedConfigurationParameterValues();

        /**
         * @brief Reports if a cumulative "Apply" of all service procedure parameters is permitted
         * @return True if all the services ConfigurationParameters of the currently active procedure have ApplyEn set; false otherwise
         */
        virtual bool isProcedureParameterUpdateAllowed() const;

        /**
         * @brief Forwards to @see ApplyBaseFunction::requestApplicationOfUpdatedValue() of ProcedureParameter ApplyBaseFunction
         */
        virtual mtp::MtpStatusCode requestApplicationOfUpdatedProcedureParameterValues();
    };
}

#endif // defined HAVE_SERVICE_CONTROL_HPP