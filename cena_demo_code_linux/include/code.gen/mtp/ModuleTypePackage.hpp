/**
 * @file ModuleTypePackage.hpp
 * @date Friday, September 18, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_MODULE_TYPE_PACKAGE_HPP
#define HAVE_MODULE_TYPE_PACKAGE_HPP

#pragma once

#include "mtp/base/ModuleTypePackage.hpp"
#include "mtp/MtpStatusCode.hpp"

namespace semodia::controlengine::native::model::mtp
{
    class DataAssembly;

    /**
     * @class ModuleTypePackage
     * @brief The module type package of the process equipment assembly. Containing all MTP aspects.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ModuleTypePackage : public base::ModuleTypePackage
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::ModuleTypePackage::base::ModuleTypePackage for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ModuleTypePackage(  const std::string& Name,
                            const std::string& Version,
                            const std::string& DeviceRevision,
                            const std::string& ManufacturerUri,
                            const std::string& ProductCode,
                            std::shared_ptr<mtp::VendorInformation> Vendor,
                            std::shared_ptr<mtp::CommunicationSet> Communication,
                            std::shared_ptr<mtp::HmiSet> Hmis,
                            std::shared_ptr<mtp::ServiceSet> Control,
                            std::shared_ptr<mtp::ProcessValueSet> ProcessValues,
                            std::shared_ptr<mtp::TextSet> TextInteractions,
                            std::shared_ptr<mtp::AlarmSet> Alarms,
                            std::shared_ptr<mtp::PeaInformationLabel> PeaInformation,
                            std::shared_ptr<mtp::WebServerUrlInfo> WebServerUrl);

        /**
         * @ingroup MTP API
         * @brief Convenient shorthand for creating an mtp; sets are allocated automatically.
         * @details
         *  Assumes Version == DeviceRevision = SoftwareRevision
         *  Sets OPC UA Server to NULL (given that if the POL can read this, it has found the server anyway)
         */
        [[deprecated("This constructor is outdated and does not initialize all fields of the PeaInformationLabel. It will be removed in next major release")]]
        ModuleTypePackage(const std::string& Name,
                          const std::string& DocumentId,
                          const std::string& DeviceManual,
                          const std::string& HardwareRevision,
                          const std::string& Manufacturer,
                          const std::string& ManufacturerUri,
                          const std::string& Model,
                          const std::string& ProductCode,
                          const std::string& ProductInstanceUri,
                          const std::string& SerialNumber,
                          const std::string& SoftwareRevision,
                          const std::string& Vendor,
                          const std::string& VendorURI,
                          const std::string& WebServerURI);

        /**
         * @ingroup MTP API
         * @brief Convenient shorthand for creating an mtp; sets are allocated automatically.
         * @details
         *  Assumes Version == DeviceRevision = SoftwareRevision
         *  Sets OPC UA Server to NULL (given that if the POL can read this, it has found the server anyway)
         */
        ModuleTypePackage(
            const std::string& Name,
            const std::string& DeviceClass,
            const std::string& DeviceManual,
            const std::string& HardwareRevision,
            const std::string& Manufacturer,
            const std::string& ManufacturerUri,
            const std::string& ProductCode,
            const std::string& ProductInstanceUri,
            const std::string& SerialNumber,
            const std::string& SoftwareVersion,
            const std::string& Vendor,
            const std::string& VendorURI,
            const std::string& WebServerURI);

        /**
          * @ingroup MTP API
          * @brief will delete all attached sets
          */
        virtual ~ModuleTypePackage();

        /**
         * @ingroup MTP API
         * @brief Add a new Data Assembly to our list of Instances.
         * @return true on success, false if adding failed
         */
        MtpStatusCode addDataAssembly(std::shared_ptr<mtp::DataAssembly> da);

        /**
         * @ingroup MTP API
         * @brief  Alias/convenience function for @see ServiceSet::createService()
         * @return GOOD on success, ERROR_NAME_NOT_UNIQUE if the name is not unique or an appropriate error code
         */
        MtpStatusCode createService(std::string serviceName);

        /**
         * @brief Update DataAssemblies and services
         * @return GOOD on success, an appropriate error code otherwise
         */
        MtpStatusCode update();
    };   
}

#endif // defined HAVE_MODULE_TYPE_PACKAGE_HPP