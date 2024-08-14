/**
 * @file PeaInformationLabel.hpp
 * @date Thursday, 13 January 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PEA_INFORMATION_LABEL_HPP
#define HAVE_PEA_INFORMATION_LABEL_HPP

#pragma once

#include "mtp/base/PeaInformationLabel.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class PeaInformationLabel
     * @brief Describes product- and instance-specific information for the PEA handling within a modular plant environment.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class PeaInformationLabel : public base::PeaInformationLabel
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _PeaInformationLabel::_PeaInformationLabel for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        PeaInformationLabel( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References,
            std::shared_ptr<mtp::ObjectItem> ObjectItem,
            std::shared_ptr<mtp::Timestamped> Timestamped,
            std::shared_ptr<mtp::ReadWriteDataItem<std::string>> AssetId,
            std::shared_ptr<mtp::ReadWriteDataItem<std::string>> ComponentName,
            std::shared_ptr<mtp::ReadWriteDataItem<std::string>> DeviceClass,
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> DeviceHealth,
            std::shared_ptr<mtp::ReadDataItem<std::string>> DeviceManual,
            std::shared_ptr<mtp::ReadDataItem<std::string>> DeviceRevision,
            std::shared_ptr<mtp::ReadDataItem<std::string>> HardwareRevision,
            std::shared_ptr<mtp::ReadDataItem<std::string>> Manufacturer,
            std::shared_ptr<mtp::ReadDataItem<std::string>> ManufacturerUri,
            std::shared_ptr<mtp::ReadDataItem<std::string>> Model,
            std::shared_ptr<mtp::ReadDataItem<std::string>> ProductCode,
            std::shared_ptr<mtp::ReadDataItem<std::string>> ProductInstanceUri,
            std::shared_ptr<mtp::ReadDataItem<std::int16_t>> RevisionCounter,
            std::shared_ptr<mtp::ReadDataItem<std::string>> SerialNumber,
            std::shared_ptr<mtp::ReadDataItem<std::string>> SoftwareRevision
        );

        [[deprecated("This constructor is outdated and does not initialize all fields of the PeaInformationLabel. It will be removed in next major release")]]
        PeaInformationLabel(
                const std::string& TagName,
                const std::string& TagDescription,
                const std::string& DeviceManual,
                const std::string& DeviceRevision,
                const std::string& HardwareRevision,
                const std::string& Manufacturer,
                const std::string& ManufacturerUri,
                const std::string& Model,
                const std::string& ProductCode,
                const std::string& ProductInstanceUri,
                const std::int16_t& RevisionCounter,
                const std::string& SerialNumber,
                const std::string& SoftwareRevision
        );

        PeaInformationLabel(
            const std::string& TagName,
            const std::string& TagDescription,
            const std::string& MtpName,
            const std::string& DeviceClass,
            const std::string& DeviceManual,
            const std::string& DeviceRevision,
            const std::string& HardwareRevision,
            const std::string& Manufacturer,
            const std::string& ManufacturerUri,
            const std::string& ProductCode,
            const std::string& ProductInstanceUri,
            const std::int16_t& RevisionCounter,
            const std::string& SerialNumber,
            const std::string& SoftwareRevision);

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _PeaInformationLabel::~_PeaInformationLabel  
          */
        virtual ~PeaInformationLabel() = default;
    };   
}

#endif // defined HAVE_PEA_INFORMATION_LABEL_HPP