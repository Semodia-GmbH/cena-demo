/**
 * @file Service.hpp
 * @date Thursday, September 24, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_HPP
#define HAVE_SERVICE_HPP

#pragma once

#include <map>
#include "mtp/base/Service.hpp"
#include "mtp/IServiceOperationAndSourceMode.hpp"
#include "mtp/ServicePositionTextReference.hpp"
#include "mtp/ServiceInteractionTextReference.hpp"
#include "mtp/ServiceInteraction.hpp"
#include "mtp/ServiceCommandId.hpp"
#include "mtp/ServiceStateId.hpp"
#include "mtp/OperationModeId.hpp"
#include "mtp/ServiceSourceModeId.hpp"
#include "mtp/StateChannelId.hpp"
#include "mtp/MtpStatusCode.hpp"
#include "mtp/ConfigurationParameter.hpp"
#include "mtp/ProcedureHealthView.hpp"

#include "statemachine/HierarchicState.hpp"

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @enum CommandEnabled
     * @brief A bitmask to check if transitions are usable.
     */
    enum class CommandEnabled {
        UNDEFINED   = 1 << 0,
        RESET       = 1 << 1,
        START       = 1 << 2,
        STOP        = 1 << 3,
        HOLD        = 1 << 4,
        UNHOLD      = 1 << 5,
        PAUSE       = 1 << 6,
        RESUME      = 1 << 7,
        ABORT       = 1 << 8,
        RESTART     = 1 << 9,
        COMPLETE    = 1 << 10,
    };

    /**
     * @class Service
     * @brief The service object encapsulates the process functionality.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class Service : public base::Service, public mtp::IServiceOperationAndSourceMode
    {
    // Shorthand for service state type:
    using ServiceState = util::statemachine::HierarchicState<mtp::ServiceStateId>;
    private:
        /**
         * @brief Reading ServiceControl->command is a destructive process (there is no CommandCur); this buffer
         *        reads the current command at the beginning of update() and makes it available to all FSM transitions
         */
        ServiceCommandId lastIssuedCommandRead;

        /**
         * @brief Records whether a produres callback ("user logic") for a SC-state is done; callbacks that return
         *        "completed = false" can block the service progression
         */
        std::map<mtp::ServiceStateId, bool> serviceCallbackCompletionStatus;

        /**
         * @brief Examines @see serviceCallbackCompletionStatus to determine if a callback reports completion
         * @return false if completion is false, false if callback was not run after state exits, false if callback was never run.
         *         true if a callback exists that has returned true (i.e. was invoked).
         */
        mtp::MtpStatusCode hasServiceCallbackCompleted(const mtp::ServiceStateId& forState, bool& completed) const;

        /**
         * @brief Creates our FSM and registers callbacks for transitions, entry, exit and stay
         */
        mtp::MtpStatusCode constructStateMachine();

        /**
         * @brief Identifies the currently selected Procedure based on ProcedureCur, then attempts to find a pointer to it
         * @return nullptr on error; a pointer to the current procedure otherwise
         */
        std::shared_ptr<mtp::Procedure> getCurrentProcedure() const;

        /**
         * @brief Stay-Callbacks for MTP Service states redirect here to update & manage @see serviceCallbackCompletionStatus()
         */
        void executeUserCallbackAndUpdateCompletionStatus(const mtp::ServiceStateId& forState);

        /**
         * @brief Updates the requests and ApplyEn automation on state changes; this is called during update() and prior to invoking callbacks
         */
        void updateConfigurationParameterSetpoints();

    protected:
        /**
         * @brief Top level state of our finite state machine, described in VDI/VDE/NAMUR 2658 part 4
         */
        ServiceState fsm;

        /**
         * @brief Maps MTP states (not top level, not "hidden" initial states) to IDs so we can quickly access them
         */
        std::map<mtp::ServiceStateId, std::shared_ptr<ServiceState>> states;

        /**
         * @brief forwards to @see ServiceControl::updateOperationAndServiceMode
         * @details Assumes the service has update StateCur either before or directly after ticking the state machine.
         *          @see Service::update() for when the function is invoked.
         */
        virtual MtpStatusCode updateOperationAndServiceMode() override;

    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::Service::base::Service for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        Service( const std::string& Name,
                 std::shared_ptr<mtp::ServiceControl> ReferencedServiceControl,
                 std::shared_ptr<mtp::ServiceInteractionTextReference> ServiceInteraction,
                 std::shared_ptr<mtp::ServicePositionTextReference> ServicePosition);

       /**
        * @ingroup MTP API
        * @brief Simplified C'Tor
        */
        Service(const std::string& Name);

        // --------------------------------------------
        //

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::Service::~base::Service  
          */
        virtual ~Service();

        /**
         * @brief Updates states, parameters and procedure logic as required by the services current state
         * @return GOOD on success, appropriate errorcode otherwise
         */
        mtp::MtpStatusCode update();

        /**
         * @brief forwards to @see ServiceControl::requestOperationMode
         */
        virtual MtpStatusCode requestOperationMode(const OperationModeId &mode, const ServiceSourceModeId &source) override;

        /**
         * @brief forwards to @see ServiceControl::requestModeControl
         */
        virtual MtpStatusCode requestModeControl(const bool &modeControlledByPEA) override;

        /**
         * @brief forwards to @see ServiceControl::isControlledByPEA
         */
        virtual MtpStatusCode isControlledByPEA(bool &peaControlled) const override;
        using IServiceOperationAndSourceMode::isControlledByPEA;

        /**
         * @brief forwards to @see ServiceControl::isOffline
         */
        virtual MtpStatusCode isOffline(bool &offline) const override;
        using IServiceOperationAndSourceMode::isOffline;

        /**
         * @brief forwards to @see ServiceControl::isOperatorControlled
         */
        virtual MtpStatusCode isOperatorControlled(bool &operatorControlled) const override;
        using IServiceOperationAndSourceMode::isOperatorControlled;

        /**
         * @brief forwards to @see ServiceControl::isAutomaticInternal
         */
        virtual MtpStatusCode isAutomaticInternal(bool &automaticInternal) const override;
        using IServiceOperationAndSourceMode::isAutomaticInternal;

        /**
         * @brief forwards to @see ServiceControl::isAutomaticExternal
         */
        virtual MtpStatusCode isAutomaticExternal(bool &automaticExternal) const override;
        using IServiceOperationAndSourceMode::isAutomaticExternal;

        //-----------------------------
        // State/FSM handling
        /**
         * @brief Returns which MTP-conforming state of our FSM is currently active
         * @details The id returned is the actual active state of the FSM, not necessarily the reported StateCur of the ServiceControl
         * @return UNKNOWN when offline, NOT_USED of error or the state ID currently active
         */
        virtual mtp::ServiceStateId getCurrentActiveState() const;

        /**
         * @brief forwards to @see ServiceControl::requestCommand
         */
        virtual mtp::MtpStatusCode requestCommand(const mtp::ServiceCommandId& command);

        /**
         * @brief If not in IDLE and a valid procedure is selected (`ProcedureCur`), this forwards to @see mtp::ProcedureHealthView::isCommandEnabled
         *        Otherwise, if in IDLE, it will attempt to use `ProcedureReq` to the same effect.
         */
        virtual mtp::MtpStatusCode isCommandEnabled(const mtp::ServiceCommandId& command, bool& enabled) const;

        //-----------------------------
        // Procedure handling

        /**
         * @brief Create and add a new procedure
         * @param assignedProcedureId contains a unique, non-0 ID incrementally assigned by the Service class if GOOD is returned
         * @param updateEnabledCommands is called periodically to update which service state transitions are allowed for this procedure - default is to allow all transitions
         * @return GOOD on success, an appropriate error code otherwise
         */
        virtual mtp::MtpStatusCode createProcedure(const std::string& name, const bool& isSelfCompleting, std::uint32_t& assignedProcedureId, const UpdateCommandInfoCallback& updateEnabledCommands);

        /**
         * @brief   Do not use.
         * @details Procedures **must** carry unique IDs which are assigned during @see createProcedure.
         *          The implementation of the base function does not ensure this and is explicitly masked here.
         */
        [[deprecated("Masks unsafe (generated) method in base class; do not use")]]
        virtual size_t addProcedure(std::shared_ptr<mtp::Procedure> &Procedure) override final;

        /**
         * @brief Searches and returns the procedure by name
         * @details Unique names are not guaranteed by the implementation - retrieving procedures by ID should be preferred if names can be ambiguous
         * @param name to search for
         * @param procedure will be set to point to the first procedure with the given name; nullptr otherwise
         * @return GOOD if procedure was found and pointer set, an appropriate error code otherwise
         */
        virtual mtp::MtpStatusCode getProcedureByName(const std::string& name, std::shared_ptr<mtp::Procedure>& procedure);

        /**
         * @brief Changes semantics of underlying base::Service function of same name; identifies procedure by ProcedureId instead of by index
         * @param id is the unique ProcedureID assigned during createProcedure
         * @return pointer to the procedure or a nullptr of the procedure was not found
         */
        virtual std::shared_ptr<mtp::Procedure> getProcedureByID(const size_t id) const override;

        /**
         * @brief Forwards to @see ServiceControl::requestProcedure
         */
        virtual mtp::MtpStatusCode requestProcedure(const std::uint32_t& procedureId);

        //-----------------------------
        // Configuration parameter handling

        /**
         * @brief Forwards to @see ServiceControl::isConfigurationParameterUpdateAllowed()
         */
        virtual bool isConfigurationParameterUpdateAllowed() const;

        /**
         * @brief Forwards to @see ServiceControl::requestApplicationOfUpdatedConfigurationParameterValues()
         */
        virtual mtp::MtpStatusCode requestApplicationOfUpdatedConfigurationParameterValues();

        /**
         * @brief Forwards to @see ServiceControl::isConfigurationParameterUpdateAllowed()
         */
        virtual bool isProcedureParameterUpdateAllowed() const;

        /**
         * @brief Forwards to @see ServiceControl::requestApplicationOfUpdatedProcedureParameterValues()
         */
        virtual mtp::MtpStatusCode requestApplicationOfUpdatedProcedureParameterValues();

        /**
         * @brief Creates a new parameter tied to a pre-existing `ParameterElement`
         * @param name is an index/name for the parameter that identifies this parameter within the service. It may be distinct from the ParameterElements TagName!
         */
        virtual mtp::MtpStatusCode createConfigurationParameter(const std::string& name, const std::shared_ptr<mtp::ParameterElement> &parameter);

        /**
         * @brief Creates a new parameter tied to a pre-existing `ParameterElement`;
         * @details Will create a configurationParameter with the same name as the ParameterElements tagName
         */
        virtual mtp::MtpStatusCode createConfigurationParameter(const std::shared_ptr<mtp::ParameterElement> &parameter);

        /**
         * @brief   Retrieves a configuration parameter
         * @details Allows manipulating service-related issues of parameter, e.g. their automatic handling of ApplyEn in various service states
         * @param   name is the ConfigurationParameterName to be retrieved - note that this is not the ParameterElements name, but the name assigned to the Config parameter during creation!
         * @param   parameter is a pointer that will be set to the given parameter if GOOD is returned
         * @return  GOOD if parameter was found and pointer points to it; NOT_FOUND otherwise.
         */
        virtual mtp::MtpStatusCode getConfigurationParameterByName(const std::string& name, std::shared_ptr<mtp::ConfigurationParameter> &parameter) const;

        /**
         * @brief Retrieves a ProcessValueIn contained in a InputElement of the given name
         * @return GOOD if parameter was found and pointer points to it; NOT_FOUND otherwise.
         */
        virtual mtp::MtpStatusCode getConfigurationParameterByName(const std::string& name, std::shared_ptr<mtp::ParameterElement> &value) const;
    };   
}

#endif // defined HAVE_SERVICE_HPP