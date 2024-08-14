/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ModuleTypePackage.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_MODULE_TYPE_PACKAGE_BASE_HPP
#define HAVE_MODULE_TYPE_PACKAGE_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/SemanticModelEntity.hpp"

#include <string>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class VendorInformation;
    class CommunicationSet;
    class HmiSet;
    class ServiceSet;
    class ProcessValueSet;
    class TextSet;
    class AlarmSet;
    class PeaInformationLabel;
    class WebServerUrlInfo;
    
    class ModuleTypePackage;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ModuleTypePackage
     * @brief The module type package of the process equipment assembly. Containing all MTP aspects.. This is the base class generated based on the Model Type Package Specification.
     */
    class ModuleTypePackage : public mtp::SemanticModelEntity
    {
    private:
        /**
          * @brief Simple attribute Name. The name of the module type package.
          */ 
        std::string Name;
        /**
          * @brief Simple attribute Version. The version of the module type package which will be generated.
          */ 
        std::string Version;
        /**
          * @brief Simple attribute DeviceRevision. The device revision provides the version information of the information technology interface of the PEA. It has to be defined in Major.Minor.Patch notation.
          */ 
        std::string DeviceRevision;
        /**
          * @brief Simple attribute ManufacturerUri. The URI of the manufacturer.
          */ 
        std::string ManufacturerUri;
        /**
          * @brief Simple attribute ProductCode. The unique identification of the PEA-type.
          */ 
        std::string ProductCode;
        
        /**
          * @brief Association Vendor. The vendor of the process equipment assembly.
          */ 
        std::shared_ptr<mtp::VendorInformation> Vendor;
        /**
          * @brief Association Communication. The communication aspect of the module type package.
          */ 
        std::shared_ptr<mtp::CommunicationSet> Communication;
        /**
          * @brief Association Hmis. The HMI aspect of the module type package.
          */ 
        std::shared_ptr<mtp::HmiSet> Hmis;
        /**
          * @brief Association Control. The service aspect of the module type package.
          */ 
        std::shared_ptr<mtp::ServiceSet> Control;
        /**
          * @brief Association ProcessValues. The process values aspect of the module type package.
          */ 
        std::shared_ptr<mtp::ProcessValueSet> ProcessValues;
        /**
          * @brief Association TextInteractions. The text aspect of the module type package.
          */ 
        std::shared_ptr<mtp::TextSet> TextInteractions;
        /**
          * @brief Association Alarms. The alarm and event aspect of the module type package.
          */ 
        std::shared_ptr<mtp::AlarmSet> Alarms;
        /**
          * @brief Association PeaInformation. Provides information to identify PEA type and PEA instance.
          */ 
        std::shared_ptr<mtp::PeaInformationLabel> PeaInformation;
        /**
          * @brief Association WebServerUrl. Describes the endpoint of a proprietary web server.
          */ 
        std::shared_ptr<mtp::WebServerUrlInfo> WebServerUrl;
    
    protected:
        ModuleTypePackage( 
            const std::string& Name, 
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
            std::shared_ptr<mtp::WebServerUrlInfo> WebServerUrl
        ) : mtp::SemanticModelEntity(), Name(Name), Version(Version), DeviceRevision(DeviceRevision), ManufacturerUri(ManufacturerUri), ProductCode(ProductCode), Vendor(Vendor), Communication(Communication), Hmis(Hmis), Control(Control), ProcessValues(ProcessValues), TextInteractions(TextInteractions), Alarms(Alarms), PeaInformation(PeaInformation), WebServerUrl(WebServerUrl)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ModuleTypePackage destructor for additional functionality. 
          */
        virtual ~ModuleTypePackage() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ModuleTypePackage;
        }
        
         
        /* Get-/Setters for simple attribute Name */
        virtual void setName(const std::string& Name) 
        { 
            this->Name = Name; 
            return;
        };
        virtual std::string getName() const
        { 
            return this->Name; 
        };

        /* Get-/Setters for simple attribute Version */
        virtual void setVersion(const std::string& Version) 
        { 
            this->Version = Version; 
            return;
        };
        virtual std::string getVersion() const
        { 
            return this->Version; 
        };

        /* Get-/Setters for simple attribute DeviceRevision */
        virtual void setDeviceRevision(const std::string& DeviceRevision) 
        { 
            this->DeviceRevision = DeviceRevision; 
            return;
        };
        virtual std::string getDeviceRevision() const
        { 
            return this->DeviceRevision; 
        };

        /* Get-/Setters for simple attribute ManufacturerUri */
        virtual void setManufacturerUri(const std::string& ManufacturerUri) 
        { 
            this->ManufacturerUri = ManufacturerUri; 
            return;
        };
        virtual std::string getManufacturerUri() const
        { 
            return this->ManufacturerUri; 
        };

        /* Get-/Setters for simple attribute ProductCode */
        virtual void setProductCode(const std::string& ProductCode) 
        { 
            this->ProductCode = ProductCode; 
            return;
        };
        virtual std::string getProductCode() const
        { 
            return this->ProductCode; 
        };


        /* Get-/Setters for association attribute Vendor */
        virtual void setVendor(std::shared_ptr<mtp::VendorInformation>& Vendor) 
        { 
            this->Vendor = Vendor; 
            return;
        };
        virtual std::shared_ptr<mtp::VendorInformation> getVendor() const
        { 
            return this->Vendor; 
        };

        /* Get-/Setters for association attribute Communication */
        virtual void setCommunication(std::shared_ptr<mtp::CommunicationSet>& Communication) 
        { 
            this->Communication = Communication; 
            return;
        };
        virtual std::shared_ptr<mtp::CommunicationSet> getCommunication() const
        { 
            return this->Communication; 
        };

        /* Get-/Setters for association attribute Hmis */
        virtual void setHmis(std::shared_ptr<mtp::HmiSet>& Hmis) 
        { 
            this->Hmis = Hmis; 
            return;
        };
        virtual std::shared_ptr<mtp::HmiSet> getHmis() const
        { 
            return this->Hmis; 
        };

        /* Get-/Setters for association attribute Control */
        virtual void setControl(std::shared_ptr<mtp::ServiceSet>& Control) 
        { 
            this->Control = Control; 
            return;
        };
        virtual std::shared_ptr<mtp::ServiceSet> getControl() const
        { 
            return this->Control; 
        };

        /* Get-/Setters for association attribute ProcessValues */
        virtual void setProcessValues(std::shared_ptr<mtp::ProcessValueSet>& ProcessValues) 
        { 
            this->ProcessValues = ProcessValues; 
            return;
        };
        virtual std::shared_ptr<mtp::ProcessValueSet> getProcessValues() const
        { 
            return this->ProcessValues; 
        };

        /* Get-/Setters for association attribute TextInteractions */
        virtual void setTextInteractions(std::shared_ptr<mtp::TextSet>& TextInteractions) 
        { 
            this->TextInteractions = TextInteractions; 
            return;
        };
        virtual std::shared_ptr<mtp::TextSet> getTextInteractions() const
        { 
            return this->TextInteractions; 
        };

        /* Get-/Setters for association attribute Alarms */
        virtual void setAlarms(std::shared_ptr<mtp::AlarmSet>& Alarms) 
        { 
            this->Alarms = Alarms; 
            return;
        };
        virtual std::shared_ptr<mtp::AlarmSet> getAlarms() const
        { 
            return this->Alarms; 
        };

        /* Get-/Setters for association attribute PeaInformation */
        virtual void setPeaInformation(std::shared_ptr<mtp::PeaInformationLabel>& PeaInformation) 
        { 
            this->PeaInformation = PeaInformation; 
            return;
        };
        virtual std::shared_ptr<mtp::PeaInformationLabel> getPeaInformation() const
        { 
            return this->PeaInformation; 
        };

        /* Get-/Setters for association attribute WebServerUrl */
        virtual void setWebServerUrl(std::shared_ptr<mtp::WebServerUrlInfo>& WebServerUrl) 
        { 
            this->WebServerUrl = WebServerUrl; 
            return;
        };
        virtual std::shared_ptr<mtp::WebServerUrlInfo> getWebServerUrl() const
        { 
            return this->WebServerUrl; 
        };

    };   
}

#endif // defined HAVE_MODULE_TYPE_PACKAGE_BASE_HPP