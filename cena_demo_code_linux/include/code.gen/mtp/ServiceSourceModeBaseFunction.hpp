/**
 * @file ServiceSourceModeBaseFunction.hpp
 * @date Thursday, September 24, 2020
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_SOURCE_MODE_BASE_FUNCTION_HPP
#define HAVE_SERVICE_SOURCE_MODE_BASE_FUNCTION_HPP

#pragma once

#include "base/ServiceSourceModeBaseFunction.hpp"
#include "mtp/ServiceSourceModeId.hpp"
#include "mtp/ServiceSourceChannelId.hpp"

namespace semodia::controlengine::native::model::mtp {
    /**
     * @class ServiceSourceModeBaseFunction
     * @brief ServiceSourceMode defines the SourceMode of the service (either External or Internal) when the service is
     *        in automatic mode.
     */
    class ServiceSourceModeBaseFunction : public base::ServiceSourceModeBaseFunction
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _ServiceSourceModeBaseFunction::_ServiceSourceModeBaseFunction for
         *        pre-constructor-call allocation.
         */
        ServiceSourceModeBaseFunction(
                std::shared_ptr<mtp::ReadDataItem<bool>> SrcChannel,
                std::shared_ptr<mtp::ReadDataItem<bool>> SrcExtAut,
                std::shared_ptr<mtp::ReadDataItem<bool>> SrcIntAut,
                std::shared_ptr<mtp::ReadWriteDataItem<bool>> SrcIntOp,
                std::shared_ptr<mtp::ReadWriteDataItem<bool>> SrcExtOp,
                std::shared_ptr<mtp::ReadDataItem<bool>> SrcIntAct,
                std::shared_ptr<mtp::ReadDataItem<bool>> SrcExtAct
        );

        /**
         * @ingroup MTP API
         * @brief Simplified C'Tor; initialize all member variables to defaults
         */
        ServiceSourceModeBaseFunction();

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers
          *        to null; those are done by base class @see _ServiceSourceModeBaseFunction::~_ServiceSourceModeBaseFunction
          */
        virtual ~ServiceSourceModeBaseFunction() = default;

        /**
         * @brief Copies the effective mode bits ("*Act") of the other ServiceOperationModeBaseFunction
         */
        ServiceSourceModeBaseFunction& operator=(const ServiceSourceModeBaseFunction& other);

        /**
         * @return the current source channel as a clean, well-intrepretable enum instead of a confusing boolean
         */
        virtual ServiceSourceChannelId getSourceChannel();

        /**
         * @brief Set the current source channel
         */
        virtual void setSourceChannel(ServiceSourceChannelId channel);

        /**
         * @brief Interprets Src[Int/Ext]Act to the current mode; no change is effected
         * * @details This is a convenience function for @see getCurrentSourceMode() == INTERNAL
         */
        [[nodiscard]]
        virtual bool isModeInternal() const;

        /**
         * @brief Interprets Src[Int/Ext]Act to the current mode; no change is effected.
         * @details This is a convenience function for @see getCurrentSourceMode() == EXTERNAL
         */
        [[nodiscard]]
        virtual bool isModeExternal() const;

        /**
         * @brief Updates the source modes `*Act` variables based on the inputs.
         *        The caller should only call this function in Automatic mode, it will always update the outputs.
         * @return Returns the current op moden (Int or Ext)
         */
        virtual ServiceSourceModeId getUpdatedSourceMode();

        /**
         * @brief Evaluates *Act signals and returns current mode (does not change mode or evaluate requests)
         * @return Returns the current op moden (Int or Ext)
         */
        virtual ServiceSourceModeId getCurrentSourceMode() const;

        /**
         * @brief Sets `SrcIntAut` and `SrcExtAut` according to selection.
         */
        virtual void requestSourceMode(ServiceSourceModeId mode);

        /**
         * @brief Sets both `SrcIntAut` and `SrcExtAut` to false, independently of selected sources. Used if Operationmode
         *        is not automatic. This does not change the requested mode; the next call to getSource will set these
         *        variables again.
         */
        virtual void clearSourceMode();
    };
}

#endif // defined HAVE_SERVICE_SOURCE_MODE_BASE_FUNCTION_HPP