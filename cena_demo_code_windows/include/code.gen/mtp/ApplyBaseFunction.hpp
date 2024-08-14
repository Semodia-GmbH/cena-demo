/**
 * @file ApplyBaseFunction.hpp
 * @date Thursday, 13 January 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_APPLY_BASE_FUNCTION_HPP
#define HAVE_APPLY_BASE_FUNCTION_HPP

#pragma once

#include <memory>
#include <functional>
#include "mtp/base/ApplyBaseFunction.hpp"
#include "mtp/IApplyValue.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    // Early definitions
    class ServiceSourceModeBaseFunction;
    class ServiceOperationModeBaseFunction;

    /**
     * @brief Callback invoked when ApplyBaseFunction determines that a value should be applied to the target
     * @param newValue is the effectove value to be applied
     */
    typedef std::function<void()> ApplyNewValueCallback;

    /**
     * @brief Optional callback assigned from userspace that is called *after* the parameter is updated
     */
    typedef std::function<void()> NewValueAppliedEventCallback;

    /**
     * @class ApplyBaseFunction
     * @brief Base function which provides the apply functionality of values according to part four.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ApplyBaseFunction : public base::ApplyBaseFunction, public mtp::IApplyValue
    {
    private:
        /**
         * @brief   Optional userspace callback to inform of a newly applied parameter
         * @details Especially nifty for ConfigurationParameters and ProcedureParameters that are not meant to be
         *          re-evaluated in each execution cycle, but rather only trigger an action when applied (i.e. to
         *          configure smart field devices)
         */
        NewValueAppliedEventCallback afterApplyCompletedCallback;

        /**
         * @brief Empty callback assigned to all ApplyBaseFunctions
         */
        static NewValueAppliedEventCallback emptyApplyCompletedCallback;
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _ApplyBaseFunction::_ApplyBaseFunction for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ApplyBaseFunction( 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> ApplyOp,
            std::shared_ptr<mtp::ReadDataItem<bool>> ApplyInt,
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> ApplyExt,
            std::shared_ptr<mtp::ReadDataItem<bool>> ApplyEn
        );

        /**
         * @brief Simplified CTor; sets apply to false
         */
        ApplyBaseFunction();

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _ApplyBaseFunction::~_ApplyBaseFunction  
          */
        virtual ~ApplyBaseFunction() = default;

        /**
         * @brief Used by the PEA to allow/interdict value updates of a ParameterElements in general; setting to true
         *        will enable evaluation of the ApplyExt/Op/Int update triggers.
         * @param allow
         * @return
         */
        virtual MtpStatusCode allowValueUpdates(const bool& allow);

        /**
         * @brief Reports on the applyEnable status, setable using @see allowValueUpdates()
         * @return ApplyEn value or false if model elements are missing
         */
        virtual bool isUpdatingAllowed() const;

        /**
         * @brief Sets the ApplyInt flag
         * @return GOOD or ERROR_MISSING_ELEMENT if model elements are missing
         */
        virtual MtpStatusCode requestApplicationOfUpdatedValue();

        /**
         * @brief Checks the apply-flags based on the current source- and operationmode and invokes the `onApply`
         *        callback if appropriate
         */
        virtual MtpStatusCode applyNewValueIfEnabled( const std::shared_ptr<mtp::ServiceOperationModeBaseFunction>& effectiveOperationMode,
                                                      const std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& effectiveSourceMode,
                                                      const ApplyNewValueCallback& onApply);

        /**
         * @brief Allows userspace to assign an optional callback to this Base-Function that will be invoked *after* the
         *        stack has updated the value on account of an Apply()
         * @details This callback does not mean the value was changed (i.e. was 0 and new value is also 0 would still trigger this callback).
         *          This callback will also be triggered if Apply() was valid, but another stack function refused to change the value.
         * @param  action
         * @return GOOD
         */
        virtual MtpStatusCode afterApplyDo(const mtp::NewValueAppliedEventCallback& action);
    };   
}

#endif // defined HAVE_APPLY_BASE_FUNCTION_HPP