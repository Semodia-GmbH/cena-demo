/**
 * @file ServiceOperationModeBaseFunction.hpp
 * @date Thursday, September 24, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_OPERATION_MODE_BASE_FUNCTION_HPP
#define HAVE_SERVICE_OPERATION_MODE_BASE_FUNCTION_HPP

#pragma once

#include "mtp/base/ServiceOperationModeBaseFunction.hpp"
#include "mtp/StateChannelId.hpp"
#include "mtp/OperationModeId.hpp"
#include "mtp/ServiceStateId.hpp"

namespace semodia::controlengine::native::model::mtp
{
    class ServiceControl;
    class ParameterElement;

    /**
     * @class ServiceOperationModeBaseFunction
     * @brief The ServiceOperationMode defines the operation mode of the service.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ServiceOperationModeBaseFunction : public base::ServiceOperationModeBaseFunction
    {
    protected:
        // Updating the service operation mode is (at least for services) tied to the current state;
        // these two classes should be able to update the operation mode, but userspace should not
        friend ServiceControl;
        friend ParameterElement;

        /**
         * @brief   Evaluate the StateChannel and requested modes, update all outputs and return the current Operations
         *          mode. Changing from Offline to * if the currentServiceState is not UNDEFINED is prohibited.
         *          Changing into Offline when the currentServiceState is not IDLE is prohibited.
         * @details Should never be called from userspace; updating ServiceOperationModes is tied to the current state of the FSM
         * @param   currentServiceState is the current service state.
         * @return  One of three OpModeSourceIds
         */
        virtual OperationModeId getUpdatedOperationMode(const ServiceStateId& currentServiceState);

        /**
         * @brief Alias for @see getUpdatedOperationMode(ServiceStateId::IDLE); this function allows non-service classes
         *        to update the service mode with all transition permissions --> @see ParameterElement::getUpdatedOperationMode()
         * @details Should never be called from userspace; updating ServiceOperationModes is tied to the current state of the FSM
         * @return One of three OpModeSourceIds
         */
        virtual OperationModeId getUpdatedOperationMode();

    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::ServiceOperationModeBaseFunction::base::ServiceOperationModeBaseFunction for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ServiceOperationModeBaseFunction(
                std::shared_ptr<mtp::ReadDataItem<bool>> StateChannel,
                std::shared_ptr<mtp::ReadDataItem<bool>> StateOffAut,
                std::shared_ptr<mtp::ReadDataItem<bool>> StateOpAut,
                std::shared_ptr<mtp::ReadDataItem<bool>> StateAutAut,
                std::shared_ptr<mtp::ReadWriteDataItem<bool>> StateOffOp,
                std::shared_ptr<mtp::ReadWriteDataItem<bool>> StateOpOp,
                std::shared_ptr<mtp::ReadWriteDataItem<bool>> StateAutOp,
                std::shared_ptr<mtp::ReadDataItem<bool>> StateOpAct,
                std::shared_ptr<mtp::ReadDataItem<bool>> StateAutAct,
                std::shared_ptr<mtp::ReadDataItem<bool>> StateOffAct
        );

        /**
         * @ingroup MTP API
         * @brief Simplified C'Tor; generates all member variables with defaults
         */
        ServiceOperationModeBaseFunction();

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::ServiceOperationModeBaseFunction::~base::ServiceOperationModeBaseFunction  
          */
        virtual ~ServiceOperationModeBaseFunction() = default;

        /**
         * @brief Copies the effective mode bits ("*Act") of the other ServiceOperationModeBaseFunction
         */
        ServiceOperationModeBaseFunction& operator=(const ServiceOperationModeBaseFunction& other);

        /**
         * @brief Will return the current mode based on the current (prioritized) *Act vector; will set Offline if all outputs are false
         * @return one of 3 operation modes
         */
        virtual OperationModeId getCurrentOperationMode();

        /**
         * @brief Alias for @see ServiceOperationModeBaseFunction::getCurrentOperationMode
         * @return true if getCurrentOperationMode() == OFFLINE
         */
        bool isOffline();

        /**
         * @brief Alias for @see ServiceOperationModeBaseFunction::getCurrentOperationMode
         * @return true if getCurrentOperationMode() == OPERATOR
         */
        bool isOperator();

        /**
         * @brief Alias for @see ServiceOperationModeBaseFunction::getCurrentOperationMode
         * @return true if getCurrentOperationMode() == AUTOMATIC
         */
        bool isAutomatic();


        /**
         * @brief If StateChannel is set to PEA (default), this will access OffAut, OpAut and AutAut to request a service
         *        operation mode on behalf of the PEA. If StateChannel is set to HMI, OffOp, OpOp and AutOp will be
         *        used instead to request operation modes on behalf of a locally attached HMI.
         * @param mode to set.
         */
        virtual void requestOperationMode(const OperationModeId mode);

        /**
         * @brief Evaluate the StateChannel and requested modes, update all outputs and return the current Operations mode
         */
        virtual void setStateChannelSource(const StateChannelId stateChannel);

        /**
         * @brief Accesses boolean StateChannel and returns the current mode as proper enum.
         * @return Configured StateChannel (HMI or PEA)
         */
        StateChannelId getStateChannelSource() const;
    };
}

#endif // defined HAVE_SERVICE_OPERATION_MODE_BASE_FUNCTION_HPP