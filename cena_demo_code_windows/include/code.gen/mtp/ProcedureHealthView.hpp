/**
 * @file ProcedureHealthView.hpp
 * @date Wednesday, 19 January 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PROCEDURE_HEALTH_VIEW_HPP
#define HAVE_PROCEDURE_HEALTH_VIEW_HPP

#pragma once

#include <map>
#include <functional>

#include "mtp/base/ProcedureHealthView.hpp"
#include "mtp/MtpStatusCode.hpp"
#include "mtp/ServiceCommandId.hpp"
#include "mtp/ServiceStateId.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    // Early definition of friended parent
    class Procedure;
    class ProcedureHealthView;

    /**
     * @brief   Callback invoked by ProcedureHealthView during update to determine which transitions are currently permitted
     * @details Unlike the "CommandEn" variable, which apply an extra 'mask' to only show the POL available
     *          transitions for the current state, Command-Enables in CommandInfo display an FSM-wide information and is
     *          not tied to any particular state.
     */
    typedef std::function<void(mtp::ProcedureHealthView& procedureInfo)> UpdateCommandInfoCallback;

    /**
     * @class ProcedureHealthView
     * @brief Provides the service procedure health information.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ProcedureHealthView : public base::ProcedureHealthView
    {
    private:
        /**
         * @brief Reflects the internal enable/disables for each service state transition
         * @details This is *not* the MTP CommandEn - commandEn is masked to reflect which commands are permitted from the current state
         */
        std::map<mtp::ServiceCommandId, bool> commandEnables;

        /**
         * @brief Called during update() to update which command/transitions are available in the state machine.
         */
        UpdateCommandInfoCallback updateCommandEnables;

        /**
         * @brief Initializes all commandEnables to "permitted"
         */
        void allowAllTransitions();

    protected:
        friend Procedure;

        /**
         * @brief VDI/VDE/NAMUR 2568-4 considers commands-enables as a bitvectors; this command will encode this vector based on our current commandEnables
         * @details Use of this function in userspace is discouraged (but safe),
         *          the vector encoding is likely to change if the state machine is altered;
         *          use @see isCommandEnabled() instead
         * @return A bitwise encoded representation if enabled commands
         */
        virtual std::uint32_t getEnabledCommandsAsBitVector() const;
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _ProcedureHealthView::_ProcedureHealthView for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ProcedureHealthView( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped, 
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC, 
            std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> CommandInfo
        );

        /**
        * @ingroup MTP API
        * @brief Simplified CTor, initialized all values to sensible default
        */
        ProcedureHealthView(
                const std::string& TagName,
                const std::string& TagDescription,
                const UpdateCommandInfoCallback& updateCommandEnables
        );

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _ProcedureHealthView::~_ProcedureHealthView  
          */
        virtual ~ProcedureHealthView() = default;

        /**
         * @brief Updates visible CommandInfo vector based on the current states
         * @return GOOD on success, ERROR_MISSING_MODEL_ELEMENT or an appropriate error code
         */
        virtual mtp::MtpStatusCode update();

        /**
         * @brief Allows userspace to "block" transitions in the service
         * @details This allows/blocks transitions independently of the current state - i.e. this is not MTPs ServiceControl CommandEn, but a global enable/disable mask
         *          ServiceControls CommandEn by contrast is a bitmask that reflects what transitions are enabled for the current state.
         */
        virtual mtp::MtpStatusCode setCommandEnable(const mtp::ServiceCommandId& command, const bool& enabled);

        /**
         * @details This is not the MTP ServiceControl CommandEn - it returns the global mask, independently of the current state of the service FSM.
         *          ServiceControls CommandEn by contrast is a bitmask that reflects what transitions are enabled for the current state.
         * @return true if the transition is in principal allowed
         */
        virtual mtp::MtpStatusCode isCommandEnabled(const mtp::ServiceCommandId& command, bool& enabled) const;
    };   
}

#endif // defined HAVE_PROCEDURE_HEALTH_VIEW_HPP