/**
 * @file BinServParam.hpp
 * @date Thursday, September 24, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_BIN_SERV_PARAM_HPP
#define HAVE_BIN_SERV_PARAM_HPP

#pragma once

#include <cstdint>
#include <string>
#include "mtp/base/BinServParam.hpp"

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @class BinServParam
     * @brief BinServParam defines a binary service parameter.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class BinServParam : public base::BinServParam
    {
    protected:
        /**
         * @brief @see Servparam::updateRequest
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual MtpStatusCode updateRequest(const std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& serviceSourceMode, const std::shared_ptr<mtp::ServiceOperationModeBaseFunction>& serviceOperationMode) override;

        /**
         * @brief @see Servparam::updateSetpoint
         */
        [[deprecated("Method should only be used by Service-class (API-internal)")]]
        virtual MtpStatusCode updateSetpoint(const std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& serviceSourceMode, const std::shared_ptr<mtp::ServiceOperationModeBaseFunction>& serviceOperationMode) override;

    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::BinServParam::base::BinServParam for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        BinServParam(  const std::string& TagName,
                       const std::string& TagDescription,
                       std::shared_ptr<mtp::InstanceReferences> References,
                       std::shared_ptr<mtp::ObjectItem> ObjectItem,
                       std::shared_ptr<mtp::Timestamped> Timestamped,
                       std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC,
                       std::shared_ptr<mtp::ApplyBaseFunction> Apply,
                       std::shared_ptr<mtp::ServiceOperationModeBaseFunction> ServiceOperationMode,
                       std::shared_ptr<mtp::ServiceSourceModeBaseFunction> ServiceSourceMode,
                       std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>> OSLevel,
                       std::shared_ptr<mtp::ReadWriteDataItem<bool>> Sync,
                       std::shared_ptr<mtp::ReadWriteDataItem<bool>> VExt,
                       std::shared_ptr<mtp::ReadWriteDataItem<bool>> VOp,
                       std::shared_ptr<mtp::ReadDataItem<bool>> VInt,
                       std::shared_ptr<mtp::ReadDataItem<bool>> VReq,
                       std::shared_ptr<mtp::ReadDataItem<bool>> VOut,
                       std::shared_ptr<mtp::ReadDataItem<bool>> VFbk,
                       std::shared_ptr<mtp::ReadDataItem<std::string>> VState0,
                       std::shared_ptr<mtp::ReadDataItem<std::string>> VState1
        );

        /**
         * @ingroup MTP API
         * @brief Simplified C'Tor; handles initialization of all variables
         */
        BinServParam(const std::string& TagName, const std::string&TagDescription,
                     const bool& syncModeToService,
                     const bool& initialValue,
                     const std::string& interpretationOfTrue,
                     const std::string& interpretationOfFalse
        );

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::BinServParam::~base::BinServParam  
          */
        virtual ~BinServParam();

        /**
         * @brief VFbk is the "current actual" value. Calling this function will set the VFbk. This will not update the current setpoint VOut.
         */
        virtual void setCurrentValue(const ReadDataItem<bool>& value);
        virtual void setCurrentValue(const bool& value);

        /**
         * @return the current value of VFbk
         */
        virtual bool getCurrentValue() const;

        /**
         * @return the current value of VOut; this  is updated by @see updateSetpoint
         */
        virtual bool getCurrentSetpoint() const;

        /**
         * @return Request a new setpoint - this function is intended to be called by the POL (using OPC UA), not userspace.
         *         Will update VReq, VOut is updated by @see updateSetpoint
         */
        virtual void requestSetpoint(const bool& newSetpoint);

        /**
         * @brief Allows direct assignment to VFbk
         */
        virtual BinServParam& operator=(const bool& value);

        /**
         * @brief Comparison operator from value targets VFbk
         */
        virtual bool operator==(const bool& rhs) const;

        /**
         * @brief Allow implicit conversion of VFbk to float
         */
        virtual operator bool() const;

    };   
}

#endif // defined HAVE_BIN_SERV_PARAM_HPP