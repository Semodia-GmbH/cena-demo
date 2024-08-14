/**
 * @file Procedure.hpp
 * @date Wednesday, 19 January 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PROCEDURE_HPP
#define HAVE_PROCEDURE_HPP

#pragma once

#include "mtp/base/Procedure.hpp"
#include "mtp/MtpStatusCode.hpp"
#include "mtp/ServiceCommandId.hpp"
#include "mtp/ServiceStateId.hpp"
#include "mtp/ProcedureHealthView.hpp"
#include "mtp/ParameterElement.hpp"

namespace semodia::controlengine::native::model::mtp
{
    // Early definition of friended parent
    class Service;
    class ServiceSourceModeBaseFunction;
    class ServiceOperationModeBaseFunction;
    class IndicatorElement;
    class ProcessValueIn;
    class ProcessValueOut;
    class InputElement;

    typedef std::function<void(bool& completed)> ProcedureCallback;

    /**
     * @class Procedure
     * @brief The procedure executing the specified behavior.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class Procedure : public base::Procedure
    {
    private:
        /**
         * @brief Organizes callbacks to the user logic
         */
        std::map<mtp::ServiceStateId, ProcedureCallback> callbacks;

    protected:
        friend Service;

        /**
         * @brief Updates visible CommandInfo vector based on the current states
         * @details Should never be called from userspace
         * @param currentServiceState is passed along for the benefit of auto-updating procedure parameter ApplyEn's
         * @param serviceOperationMode is passed along for the benefit of auto-updating procedure parameter ApplyEn's
         * @param serviceSourceMode is passed along for the benefit of auto-updating procedure parameter ApplyEn's
         * @param procedureIsActiveOrSelected influences how parameters are updated; non-selected/active procedures will only update Requests; selected/Active will update setpoints and potentially trigger apply-callbacks
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or an appropriate error code
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual mtp::MtpStatusCode update(const std::shared_ptr<mtp::ServiceOperationModeBaseFunction> &serviceOperationMode,
                                          const std::shared_ptr<mtp::ServiceSourceModeBaseFunction> &serviceSourceMode,
                                          const mtp::ServiceStateId& currentServiceState,
                                          const bool& procedureIsActiveOrSelected);

        /**
         * @brief Forwards to @see ProcedureHealthView::getEnabledCommandsAsBitVector
         */
        virtual mtp::MtpStatusCode getEnabledCommandsAsBitVector(std::uint32_t& bitVector) const;


        /**
         * @brief  Forwards to @see ServiceParameter::applyUpdateToSyncedParameters for each registered parameter
         * @details Should never be called from userspace; @see ServiceParameter::applyUpdateToSyncedParameters
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        [[nodiscard]] virtual mtp::MtpStatusCode applyUpdateToSyncedParameters(const std::shared_ptr<mtp::ServiceSourceModeBaseFunction> &effectiveSourceMode, const std::shared_ptr<mtp::ServiceOperationModeBaseFunction> &effectiveOperationMode) const;

        /**
         * @brief   Sets the freeze-bit for all registered ReportValues
         * @details Should never be called from userspace; called by the owning service to set/unset freeze when entering/leaving COMPLETED, ABORTED or STOPPED
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual mtp::MtpStatusCode setFreezeForAllReportValues(const bool& enableFreeze) const;

    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _Procedure::_Procedure for pre-constructor-call allocation.
         *        May add additional logic after default values have been assigned.
         */
        Procedure(
            const std::string& Name,
            const bool& IsSelfCompleting,
            const std::uint32_t& ProcedureId,
            std::shared_ptr<mtp::ProcedureHealthView> ReferencedProcedureHealthView
        );

        /**
         * @brief Simplified C'Tor, will handle creation of HealthView
         */
        Procedure(
            const std::string& Name,
            const bool& IsSelfCompleting,
            const std::uint32_t& ProcedureId,
            const UpdateCommandInfoCallback& updateCommandEnables
        );

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _Procedure::~_Procedure  
          */
        virtual ~Procedure() = default;

        /**
         * @brief Forwards to @see mtp::ProcedureHealthView::setCommandEnable
         */
        virtual mtp::MtpStatusCode setCommandEnable(const mtp::ServiceCommandId& command, const bool& enabled);

        /**
         * @brief Forwards to @see mtp::ProcedureHealthView::isCommandEnabled
         */
        virtual mtp::MtpStatusCode isCommandEnabled(const mtp::ServiceCommandId& command, bool& enabled) const;

        /**
         * @return true if self-completing (goes to COMPLETING when EXECUTE is done) ; false otherwise
         */
        virtual bool getSelfCompleting() const;

        /**
         * @brief Controls whether the service, when running this procedure, goes to COMPLETING when EXECUTE is done
         * @param selfCompletesInExecute true causes self-completing
         * @return GOOD if set, an appropriate error code otherwise
         */
        virtual mtp::MtpStatusCode setSelfCompleting(const bool& selfCompletesInExecute);

        //------
        // Callback related

        /**
         * @brief  Calls the associated callback function; usually called by the parent service when appropriate
         * @param  hasCompleted is passed to the callback and must be set to `false` if userspace wants to stay in the current state; otherwise, issued commands or SC transitions may be used to leave the state
         * @return GOOD on success, BAD_NO_CALLBACK if there is no callback associated with this state
         */
        virtual mtp::MtpStatusCode invokeCallback(const mtp::ServiceStateId& forState, bool& hasCompleted);

        /**
         * @brief  Attaches/associates the callback function with this specific state of the parent service, replacing any existing callback
         * @return GOOD on success, an appropriate error code otherwise
         */
        virtual mtp::MtpStatusCode attachUserCallback(const mtp::ServiceStateId& serviceState, const ProcedureCallback& onServiceStateExecutionDo);

        /**
         * @brief Removes a callback associated with this state
         * @return GOOD
         */
        virtual mtp::MtpStatusCode detachUserCallback(const mtp::ServiceStateId& serviceState);

        /**
         * @return True if a callback is attached; false otherwise
         */
        virtual bool hasUserCallbackAssignedTo(const mtp::ServiceStateId& serviceState) const;

        // --------------------
        // Parameter Handling

        /**
         * @brief Examines the ApplyEn-setting of all procedure
         * @return true if all sync'd parameters have their ApplyEn set
         */
        virtual bool isUpdateAllowedForSyncedParameters() const;

        // ----
        /**
         * @brief Creates a new parameter tied to a pre-existing `ParameterElement`
         * @param name is an index/name for the parameter that identifies this parameter within the procedure. It may be distinct from the ParameterElements TagName!
         */
        virtual mtp::MtpStatusCode createProcedureParameter(const std::string& name, const std::shared_ptr<mtp::ParameterElement> &parameter);

        /**
         * @brief Creates a new parameter tied to a pre-existing `ParameterElement`;
         * @details Will create a configurationParameter with the same name as the ParameterElements tagName
         */
        virtual mtp::MtpStatusCode createProcedureParameter(const std::shared_ptr<mtp::ParameterElement> &parameter);

        /**
         * @brief   Retrieves a procedure parameter
         * @details Allows manipulating procedure-related issues of parameter, e.g. their automatic handling of ApplyEn in various service states
         * @param   name is the ProcedureParameter to be retrieved - note that this is not the ParameterElements name, but the name assigned to the parameter during creation!
         * @param   parameter is a pointer that will be set to the given parameter if GOOD is returned
         * @return  GOOD if parameter was found and pointer points to it; NOT_FOUND otherwise.
         */
        virtual mtp::MtpStatusCode getProcedureParameterByName(const std::string& name, std::shared_ptr<mtp::ProcedureParameter> &parameter) const;

        /**
         * @brief Retrieves a ParameterElement contained in a ProcedureParameter of the given name
         * @return GOOD if parameter was found and pointer points to it; NOT_FOUND otherwise.
         */
        virtual mtp::MtpStatusCode getProcedureParameterByName(const std::string& name, std::shared_ptr<mtp::ParameterElement> &value) const;

        // ----
        /**
         * @brief Creates a new ReportValue tied to a pre-existing `IndicatorElement`
         * @details Will create a configurationParameter with the same name as the ParameterElements tagName
         */
        virtual mtp::MtpStatusCode createReportValue(const std::shared_ptr<mtp::IndicatorElement> &parameter);

        /**
         * @brief   Retrieves a ReportValue
         * @param   name is the ReportValue to be retrieved - note that this is not the IndicatorElement TagName, but the name assigned to the parameter during creation!
         * @param   parameter is a pointer that will be set to the given ReportValue if GOOD is returned
         * @return  GOOD a ReportValue with the given Name (NOT TagName) was found and pointer points to it; NOT_FOUND otherwise.
         */
        virtual mtp::MtpStatusCode getReportValueByName(const std::string& name, std::shared_ptr<mtp::ReportValue> &parameter) const;

        /**
         * @brief Retrieves a IndicatorElement contained in a ReportValue of the given name
         * @return GOOD if parameter was found and pointer points to it; NOT_FOUND otherwise.
         */
        virtual mtp::MtpStatusCode getReportValueByName(const std::string& name, std::shared_ptr<mtp::IndicatorElement> &value) const;

        // ----
        /**
         * @brief Creates a new ProcessValueOut tied to a pre-existing `IndicatorElement`
         * @details Will create a configurationParameter with the same name as the ParameterElements tagName
         */
        virtual mtp::MtpStatusCode createProcessValueOut(const std::shared_ptr<mtp::IndicatorElement> &parameter);

        /**
         * @brief   Retrieves a ProcessValueOut
         * @param   name is the ProcessValueOut to be retrieved - note that this is not the IndicatorElement TagName, but the name assigned to the parameter during creation!
         * @param   parameter is a pointer that will be set to the given ReportValue if GOOD is returned
         * @return  GOOD a ProcessValueOut with the given Name (NOT TagName) was found and pointer points to it; NOT_FOUND otherwise.
         */
        virtual mtp::MtpStatusCode getProcessValueOutByName(const std::string& name, std::shared_ptr<mtp::ProcessValueOut> &parameter) const;

        /**
         * @brief Retrieves a ProcessValueOut contained in a IndicatorElement of the given name
         * @return GOOD if parameter was found and pointer points to it; NOT_FOUND otherwise.
         */
        virtual mtp::MtpStatusCode getProcessValueOutByName(const std::string& name, std::shared_ptr<mtp::IndicatorElement> &value) const;

        // ----
        /**
         * @brief Creates a new ProcessValueIn tied to a pre-existing `IndicatorElement`
         * @details Will create a configurationParameter with the same name as the ParameterElements tagName
         */
        virtual mtp::MtpStatusCode createProcessValueIn(const std::shared_ptr<mtp::InputElement> &parameter);

        /**
         * @brief   Retrieves a ProcessValueOut
         * @param   name is the ProcessValueOut to be retrieved - note that this is not the IndicatorElement TagName, but the name assigned to the parameter during creation!
         * @param   parameter is a pointer that will be set to the given ReportValue if GOOD is returned
         * @return  GOOD a ProcessValueOut with the given Name (NOT TagName) was found and pointer points to it; NOT_FOUND otherwise.
         */
        virtual mtp::MtpStatusCode getProcessValueInByName(const std::string& name, std::shared_ptr<mtp::ProcessValueIn> &parameter) const;

        /**
         * @brief Retrieves a ProcessValueIn contained in a InputElement of the given name
         * @return GOOD if parameter was found and pointer points to it; NOT_FOUND otherwise.
         */
        virtual mtp::MtpStatusCode getProcessValueInByName(const std::string& name, std::shared_ptr<mtp::InputElement> &value) const;
    };
}

#endif // defined HAVE_PROCEDURE_HPP