/**
 * @file ParameterElement.hpp
 * @date Thursday, 13 January 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PARAMETER_ELEMENT_HPP
#define HAVE_PARAMETER_ELEMENT_HPP

#pragma once

#include "mtp/IApplyValue.hpp"
#include "mtp/ApplyBaseFunction.hpp"
#include "mtp/IServiceOperationAndSourceMode.hpp"
#include "mtp/MtpStatusCode.hpp"
#include "mtp/OperationModeId.hpp"
#include "mtp/ServiceSourceModeId.hpp"
#include "mtp/base/ParameterElement.hpp"
#include "mtp/ServiceSourceModeBaseFunction.hpp"
#include "mtp/ServiceOperationModeBaseFunction.hpp"
#include "mtp/ProcedureParameter.hpp"
namespace semodia::controlengine::native::model::mtp 
{
    // friend, access updates on behalf of service
    class ServiceParameter;
    
    /**
     * @class ParameterElement
     * @brief Base class for defining parameters of a service.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ParameterElement : public base::ParameterElement, public mtp::IApplyValue, public mtp::IServiceOperationAndSourceMode
    {
    protected:
        // Updating of Service- and ProcedureParameter should always be triggered by a service that provides appropriate op/source modes
        friend ServiceParameter;

        /**
         * @brief Request an update of out; the function chooses whether to use the provided service modes or its own internal modes based on sync
         *        Intended to be called by the owning Service/ServiceProcedure
         * @details Should never be called from userspace; this function will be called by the owning Configuration- or ProcedureParameter-classes with valid op-/sourcemodes
         * @param serviceSourceMode is the sourceMode of the owning/parent service, only used if sync=true
         * @param serviceOperationMode is the operationMode of the owning/parent service, only used if sync=true
         */
        [[deprecated("Method should only be used by Configuration- or ProcedureParameter-classes (API-internal)")]]
        virtual MtpStatusCode updateRequest(const std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& serviceSourceMode,
                                            const std::shared_ptr<ServiceOperationModeBaseFunction>& serviceOperationMode) = 0;

        /**
         * @brief   Invoked by the service class to copy the request value to the setpoint output; limitations may apply to when this may occur
         * @details Should never be called from userspace; this function will be called by the owning Configuration- or ProcedureParameter-classes with valid op-/sourcemodes
         * @details For ConfigurationParameters, this function may only be invoked when the service is offline and transitions to online.
         *          For ProcedureParameters, this function may be invoked at any time.
         *          For this function to have an effect, the effective mode of the parameter must be operator or automatic.
         * @param serviceSourceMode is the sourceMode of the owning/parent service, only used if sync=true
         * @param serviceOperationMode is the operationMode of the owning/parent service, only used if sync=true
         */
        [[deprecated("Method should only be used by  Configuration- or ProcedureParameter-classes (API-internal)")]]
        virtual MtpStatusCode updateSetpoint(const std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& serviceSourceMode,
                                             const std::shared_ptr<ServiceOperationModeBaseFunction>& serviceOperationMode) = 0;

        /**
         * @brief Updates this parameters operation mode IF it is not synced to the service
         *        @see ServiceOperationOperationModeBaseFunction::getUpdatedOperationMode()
         * @details Should never be called from userspace; will change operation mode, but depending on its use as either Service- or ProcedureParameter this update may be conditionally tied to service states
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual MtpStatusCode updateOperationAndServiceMode() override;

    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _ParameterElement::_ParameterElement for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ParameterElement( 
            const std::string& TagName,
            const std::string& TagDescription,
            std::shared_ptr<mtp::InstanceReferences> References,
            std::shared_ptr<mtp::ObjectItem> ObjectItem,
            std::shared_ptr<mtp::Timestamped> Timestamped,
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC,
            std::shared_ptr<mtp::ApplyBaseFunction> Apply,
            std::shared_ptr<mtp::ServiceOperationModeBaseFunction> ServiceOperationMode,
            std::shared_ptr<mtp::ServiceSourceModeBaseFunction> ServiceSourceMode,
            std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>> OSLevel,
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> Sync
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _ParameterElement::~_ParameterElement  
          */
        virtual ~ParameterElement() = default;


        /**
         * @brief Set the sync bit as indicated
         * @param syncToService true forces the parameter to use the service service/opmodes during updates, otherwise internal/own modes are used
         */
        virtual MtpStatusCode setSync(const bool& syncToService);
        using base::ParameterElement::setSync;

        /**
         * @return The current sync bit; true indicates updates modes are supplied by service, false means own source/opmodes are in effect
         */
        virtual bool isSynced() const;

        /**
         * @brief Chooses an effective source/operationMode based on Sync and updates the ParameterElements Source and OperationMode
         * @details This function is called by ParameterElements when updateSetpoint or updateRequest needs to know which mode effectively updates the parameter
         * @param serviceServiceSourceMode provided by the service owning this parameter
         * @param serviceServiceOperationMode provided by the service owning this parameter
         * @param effectiveServiceSourceMode returned containing the effective mode as per sync
         * @param effectiveServiceOperationMode returned containing the effective mode as per sync
         * @retval GOOD or appropriate error code if sync or any of the passed parameters a null
         */
        MtpStatusCode getEffectiveModesAndUpdate(const std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& serviceServiceSourceMode, const std::shared_ptr<mtp::ServiceOperationModeBaseFunction>& serviceServiceOperationMode,
                                                       std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& effectiveServiceSourceMode,     std::shared_ptr<mtp::ServiceOperationModeBaseFunction> &effectiveServiceOperationMode
        );

        // -------------------------
        // Handling Apply base function logic

        /**
         * @brief @see ApplyBaseFunction::requestApplicationOfUpdatedValue()
         */
        virtual mtp::MtpStatusCode requestApplicationOfUpdatedValue();

        /**
         * @brief @see ApplyBaseFunction::requestApplicationOfUpdatedValue()
         */
        virtual MtpStatusCode allowValueUpdates(const bool& allow) override;

        /**
         * @brief @see ApplyBaseFunction::isUpdatingAllowed()
         */
        virtual bool isUpdatingAllowed() const override;

        /**
         * @brief @see ApplyBaseFunction::applyNewValueIfEnabled()
         */
        virtual MtpStatusCode applyNewValueIfEnabled(const std::shared_ptr<mtp::ServiceOperationModeBaseFunction>& effectiveOperationMode,
                                                     const std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& effectiveSourceMode,
                                                     const ApplyNewValueCallback& onApply);

        // -------------------------
        // Handling of Service modes

        /**
         * @brief @see requestOperationMode::requestOperationMode()
         * @details This only affects the internal mode - if sync is set, this has no effect on the ParameterElement
         */
        virtual MtpStatusCode requestOperationMode(const mtp::OperationModeId& mode, const mtp::ServiceSourceModeId& source) override;

        /**
         * @brief @see requestModeControl::requestOperationMode()
         * * @details This only affects the internal mode - if sync is set, this has no effect on the ParameterElement
         */
        virtual MtpStatusCode requestModeControl(const bool &modeControlledByPEA) override;

        /**
         * @brief @see isControlledByPEA::requestOperationMode()
         */
        virtual MtpStatusCode isControlledByPEA(bool &peaControlled) const override;
        using IServiceOperationAndSourceMode::isControlledByPEA; // unshadow base implementation

        /**
         * @brief @see isOffline::requestOperationMode()
         */
        virtual MtpStatusCode isOffline(bool &offline) const override;
        using IServiceOperationAndSourceMode::isOffline; // unshadow base implementation

        /**
         * @brief @see isOperatorControlled::requestOperationMode()
         */
        virtual MtpStatusCode isOperatorControlled(bool &operatorController) const override;
        using IServiceOperationAndSourceMode::isOperatorControlled; // unshadow base implementation

        /**
         * @brief @see isAutomaticInternal::requestOperationMode()
         */
        virtual MtpStatusCode isAutomaticInternal(bool& automaticInternal) const override;
        using IServiceOperationAndSourceMode::isAutomaticInternal; // unshadow base implementation

        /**
         * @brief @see isAutomaticExternal::requestOperationMode()
         */
        virtual MtpStatusCode isAutomaticExternal(bool &automaticExternal) const override;
        using IServiceOperationAndSourceMode::isAutomaticExternal; // unshadow base implementation

        /**
         * @brief Forwards to @see mtp::ApplyBaseFunction::afterApplyDo()
         */
        virtual mtp::MtpStatusCode afterApplyDo(const mtp::NewValueAppliedEventCallback& action);
    };
}

#endif // defined HAVE_PARAMETER_ELEMENT_HPP