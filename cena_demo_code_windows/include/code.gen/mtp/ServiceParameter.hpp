/**
 * @file ServiceParameter.hpp
 * @date Thursday, September 24, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_PARAMETER_HPP
#define HAVE_SERVICE_PARAMETER_HPP

#pragma once

#include <map>
#include <memory>

#include "mtp/base/ServiceParameter.hpp"
#include "mtp/MtpStatusCode.hpp"
#include "mtp/ServiceStateId.hpp"

namespace semodia::controlengine::native::model::mtp
{
    class Service;   // Calls protected update on ConfigurationParameters
    class Procedure; // Calls protected update on ProcedureParameters
    class ServiceOperationModeBaseFunction;
    class ServiceSourceModeBaseFunction;

    /**
     * @enum StateBasedUpdateEnableSetting
     * @brief Used by services and procedures to set and examine ApplyEn() settings
     */
    enum class StateBasedUpdateEnableSetting
    {
        ParameterControlled, //! ApplyEn is defined solely by the parameter itself; there is no ApplyEn-automation in relation to states
        EnabledByState,      //! Indicates that the service will attempt to set/enable ApplyEn for this parameter in a specific service state
        DisabledByState      //! Indicates that the service will attempt to unset/disable ApplyEn for this parameter in a specific service state
    };

    /**
     * @class ServiceParameter
     * @brief The service parameter.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ServiceParameter : public base::ServiceParameter
    {
    private:
        /**
         * @brief Holds the State based Auto-ApplyEn for this parameter
         */
        std::map<mtp::ServiceStateId, bool> stateBasedEnables;

    protected:
        // Updates are only issued from our service class
        friend Service;
        friend Procedure;

        /**
         * @brief Forwards to @see ParameterElement::updateRequest
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual MtpStatusCode updateRequest(const std::shared_ptr<ServiceOperationModeBaseFunction>& serviceOperationMode,
                                            const std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& serviceSourceMode,
                                            const mtp::ServiceStateId& currentState);

        /**
         * @brief Forwards to @see ParameterElement::updateSetpoint
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual MtpStatusCode updateSetpoint(const std::shared_ptr<ServiceOperationModeBaseFunction>& serviceOperationMode,
                                             const std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& serviceSourceMode,
                                             const mtp::ServiceStateId& currentState);

        /**
         * @brief Tests each parameter if it is sync()'d to the service and if so, forces it's ApplyInt/Op/Ext so it will update
         * @details Should never be called from userspace (simply request values from the ParameterElement or call service.update()).
         *          This function is meant to be triggered via the ServiceControl's ApplyBaseFunction for procedures in specific service operetions/source modes.
         *          This is handled entirely by the mtp::Service class.
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        [[nodiscard]] virtual mtp::MtpStatusCode applyUpdateToSyncedParameters(const std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& serviceSourceMode, const std::shared_ptr<ServiceOperationModeBaseFunction>& serviceOperationMode) const;

    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::ServiceParameter::base::ServiceParameter for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ServiceParameter(const std::string& Name, std::shared_ptr<mtp::ParameterElement> ReferencedDataAssembly);

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::ServiceParameter::~base::ServiceParameter  
          */
        virtual ~ServiceParameter();

        /**
         * @brief   Sets automation for all user-accessible states to `enableParameterUpdatesInState`
         * @details Handy if your would need to set almost all transient states (PAUSING, COMPLETING, ABORTING, STOPPING, etc.) individually, which is a common scenario
         */
        void setAllStateBasedUpdateEnables(const StateBasedUpdateEnableSetting &enableParameterUpdatesInState);

        /**
         * @brief   Allows defining (or removing) an ApplyEnable setting
         * @details This automation is applied to all procedure parameters, even in IDLE
         * @param   StateBasedEnableSetting is the tristate mode enforced by the Configuration- or ProcedureParameter
         */
        void setStateBasedUpdateEnable(const mtp::ServiceStateId& forState, const StateBasedUpdateEnableSetting& enableParameterUpdatesInState);

        /**
         * @brief  Retrieve the current (tristate) setting for this Parameter and state
         * @return ParameterControlled if no override was defined; EnabledByState if `true`, DisabledByState if `false`
         */
        [[nodiscard]] StateBasedUpdateEnableSetting getStateBasedUpdateEnable(const mtp::ServiceStateId& forState) const;

        /**
         * @return Forwards to @see ParameterElement::isSynced
         */
        [[nodiscard]] virtual bool isSynced() const;

        /**
         * @brief @see ParameterElement::isUpdatingAllowed()
         */
        [[nodiscard]] virtual bool isUpdatingAllowed() const;
    };   
}

#endif // defined HAVE_SERVICE_PARAMETER_HPP