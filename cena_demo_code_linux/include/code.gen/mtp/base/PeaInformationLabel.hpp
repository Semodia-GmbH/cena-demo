/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file PeaInformationLabel.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PEA_INFORMATION_LABEL_BASE_HPP
#define HAVE_PEA_INFORMATION_LABEL_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/PeaElement.hpp"

#include "mtp/ReadWriteDataItem.hpp"
#include <string>
#include "mtp/ReadDataItem.hpp"
#include <cstdint>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    template<typename dt> class ReadWriteDataItem;
    template<typename dt> class ReadDataItem;
    
    class PeaInformationLabel;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class PeaInformationLabel
     * @brief Describes product- and instance-specific information for the PEA handling within a modular plant environment.. This is the base class generated based on the Model Type Package Specification.
     */
    class PeaInformationLabel : public mtp::PeaElement
    {
    private:
        
        /**
          * @brief Generic structure AssetId. The asset ID is a unique identifier assigned by the system operator for the PEA, which can be used for maintenance purposes. When a PEA is delivered, the asset ID has the value of the Product instance URI.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<std::string>> AssetId;
        /**
          * @brief Generic structure ComponentName. The component name is the descriptive name of a PEA, which is set by the POL.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<std::string>> ComponentName;
        /**
          * @brief Generic structure DeviceClass. The device class enables a clssification of PEAs.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<std::string>> DeviceClass;
        /**
          * @brief Generic structure DeviceHealth. Contains the aggregated WQC at PEA level.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> DeviceHealth;
        /**
          * @brief Generic structure DeviceManual. Reference to the PEA manual (e.g. URL).
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> DeviceManual;
        /**
          * @brief Generic structure DeviceRevision. The device revision provides the version information of the information technology interface of the PEA. It has to be defined in Major.Minor.Patch notation.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> DeviceRevision;
        /**
          * @brief Generic structure HardwareRevision. The version information of the constructive structure of the PEA. It has to be defined in Major.Minor.Patch notation.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> HardwareRevision;
        /**
          * @brief Generic structure Manufacturer. The name of the PEA manufacturer.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> Manufacturer;
        /**
          * @brief Generic structure ManufacturerUri. The URI of the PEA manufacturer.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> ManufacturerUri;
        /**
          * @brief Generic structure Model. The name of the PEA type which must be identical to the name of the MTP.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> Model;
        /**
          * @brief Generic structure ProductCode. The unique identification of the PEA-type.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> ProductCode;
        /**
          * @brief Generic structure ProductInstanceUri. URI of the PEA (according to DIN SPEC 91406).
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> ProductInstanceUri;
        /**
          * @brief Generic structure RevisionCounter. Provides information regarding changes of the internal configuration.
          */
        std::shared_ptr<mtp::ReadDataItem<std::int16_t>> RevisionCounter;
        /**
          * @brief Generic structure SerialNumber. The serial number of the PEA.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> SerialNumber;
        /**
          * @brief Generic structure SoftwareRevision. The version information of the control software of the PEA. It has to be defined in Major.Minor.Patch notation.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> SoftwareRevision;
    
    protected:
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
        ) : mtp::PeaElement(TagName, TagDescription, References, ObjectItem, Timestamped), AssetId(AssetId), ComponentName(ComponentName), DeviceClass(DeviceClass), DeviceHealth(DeviceHealth), DeviceManual(DeviceManual), DeviceRevision(DeviceRevision), HardwareRevision(HardwareRevision), Manufacturer(Manufacturer), ManufacturerUri(ManufacturerUri), Model(Model), ProductCode(ProductCode), ProductInstanceUri(ProductInstanceUri), RevisionCounter(RevisionCounter), SerialNumber(SerialNumber), SoftwareRevision(SoftwareRevision)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see PeaInformationLabel destructor for additional functionality. 
          */
        virtual ~PeaInformationLabel() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::PeaInformationLabel;
        }
        

        /* Get-/Setters for Generic Attribute Structure AssetId */
        virtual void setAssetId(std::shared_ptr<mtp::ReadWriteDataItem<std::string>>& AssetId) 
        { 
            this->AssetId = AssetId; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<std::string>> getAssetId() const
        {  
            return this->AssetId; 
        };

        /* Get-/Setters for Generic Attribute Structure ComponentName */
        virtual void setComponentName(std::shared_ptr<mtp::ReadWriteDataItem<std::string>>& ComponentName) 
        { 
            this->ComponentName = ComponentName; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<std::string>> getComponentName() const
        {  
            return this->ComponentName; 
        };

        /* Get-/Setters for Generic Attribute Structure DeviceClass */
        virtual void setDeviceClass(std::shared_ptr<mtp::ReadWriteDataItem<std::string>>& DeviceClass) 
        { 
            this->DeviceClass = DeviceClass; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<std::string>> getDeviceClass() const
        {  
            return this->DeviceClass; 
        };

        /* Get-/Setters for Generic Attribute Structure DeviceHealth */
        virtual void setDeviceHealth(std::shared_ptr<mtp::ReadDataItem<std::uint8_t>>& DeviceHealth) 
        { 
            this->DeviceHealth = DeviceHealth; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> getDeviceHealth() const
        {  
            return this->DeviceHealth; 
        };

        /* Get-/Setters for Generic Attribute Structure DeviceManual */
        virtual void setDeviceManual(std::shared_ptr<mtp::ReadDataItem<std::string>>& DeviceManual) 
        { 
            this->DeviceManual = DeviceManual; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getDeviceManual() const
        {  
            return this->DeviceManual; 
        };

        /* Get-/Setters for Generic Attribute Structure DeviceRevision */
        virtual void setDeviceRevision(std::shared_ptr<mtp::ReadDataItem<std::string>>& DeviceRevision) 
        { 
            this->DeviceRevision = DeviceRevision; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getDeviceRevision() const
        {  
            return this->DeviceRevision; 
        };

        /* Get-/Setters for Generic Attribute Structure HardwareRevision */
        virtual void setHardwareRevision(std::shared_ptr<mtp::ReadDataItem<std::string>>& HardwareRevision) 
        { 
            this->HardwareRevision = HardwareRevision; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getHardwareRevision() const
        {  
            return this->HardwareRevision; 
        };

        /* Get-/Setters for Generic Attribute Structure Manufacturer */
        virtual void setManufacturer(std::shared_ptr<mtp::ReadDataItem<std::string>>& Manufacturer) 
        { 
            this->Manufacturer = Manufacturer; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getManufacturer() const
        {  
            return this->Manufacturer; 
        };

        /* Get-/Setters for Generic Attribute Structure ManufacturerUri */
        virtual void setManufacturerUri(std::shared_ptr<mtp::ReadDataItem<std::string>>& ManufacturerUri) 
        { 
            this->ManufacturerUri = ManufacturerUri; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getManufacturerUri() const
        {  
            return this->ManufacturerUri; 
        };

        /* Get-/Setters for Generic Attribute Structure Model */
        virtual void setModel(std::shared_ptr<mtp::ReadDataItem<std::string>>& Model) 
        { 
            this->Model = Model; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getModel() const
        {  
            return this->Model; 
        };

        /* Get-/Setters for Generic Attribute Structure ProductCode */
        virtual void setProductCode(std::shared_ptr<mtp::ReadDataItem<std::string>>& ProductCode) 
        { 
            this->ProductCode = ProductCode; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getProductCode() const
        {  
            return this->ProductCode; 
        };

        /* Get-/Setters for Generic Attribute Structure ProductInstanceUri */
        virtual void setProductInstanceUri(std::shared_ptr<mtp::ReadDataItem<std::string>>& ProductInstanceUri) 
        { 
            this->ProductInstanceUri = ProductInstanceUri; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getProductInstanceUri() const
        {  
            return this->ProductInstanceUri; 
        };

        /* Get-/Setters for Generic Attribute Structure RevisionCounter */
        virtual void setRevisionCounter(std::shared_ptr<mtp::ReadDataItem<std::int16_t>>& RevisionCounter) 
        { 
            this->RevisionCounter = RevisionCounter; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::int16_t>> getRevisionCounter() const
        {  
            return this->RevisionCounter; 
        };

        /* Get-/Setters for Generic Attribute Structure SerialNumber */
        virtual void setSerialNumber(std::shared_ptr<mtp::ReadDataItem<std::string>>& SerialNumber) 
        { 
            this->SerialNumber = SerialNumber; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getSerialNumber() const
        {  
            return this->SerialNumber; 
        };

        /* Get-/Setters for Generic Attribute Structure SoftwareRevision */
        virtual void setSoftwareRevision(std::shared_ptr<mtp::ReadDataItem<std::string>>& SoftwareRevision) 
        { 
            this->SoftwareRevision = SoftwareRevision; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getSoftwareRevision() const
        {  
            return this->SoftwareRevision; 
        };
    };   
}

#endif // defined HAVE_PEA_INFORMATION_LABEL_BASE_HPP