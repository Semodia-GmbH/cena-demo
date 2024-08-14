/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ParameterElement.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PARAMETER_ELEMENT_BASE_HPP
#define HAVE_PARAMETER_ELEMENT_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/ServiceElement.hpp"

#include "mtp/ReadWriteDataItem.hpp"
#include <cstdint>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class ApplyBaseFunction;
    class ServiceOperationModeBaseFunction;
    class ServiceSourceModeBaseFunction;
    template<typename dt> class ReadWriteDataItem;
    
    class ParameterElement;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ParameterElement
     * @brief Base class for defining parameters of a service.. This is the base class generated based on the Model Type Package Specification.
     */
    class ParameterElement : public mtp::ServiceElement
    {
    private:
        
        /**
          * @brief Association Apply. Provides the apply functionality of the parameter.
          */ 
        std::shared_ptr<mtp::ApplyBaseFunction> Apply;
        /**
          * @brief Association ServiceOperationMode. The ServiceOperationMode defines the operation mode of the service.
          */ 
        std::shared_ptr<mtp::ServiceOperationModeBaseFunction> ServiceOperationMode;
        /**
          * @brief Association ServiceSourceMode. ServiceSourceMode defines the SourceMode of the service.
          */ 
        std::shared_ptr<mtp::ServiceSourceModeBaseFunction> ServiceSourceMode;
        
        /**
          * @brief Generic structure OSLevel. OSLevel defines the current active operator station to send commands. OSLevel of zero defines a local panel.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>> OSLevel;
        /**
          * @brief Generic structure Sync. Sync defines the enabling of the synchronization mode. If the value is 1 the parameter mode shall be synchronized with the service mode.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> Sync;
    
    protected:
        ParameterElement( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped, 
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC, 
            std::shared_ptr<mtp::ApplyBaseFunction> Apply, 
            std::shared_ptr<mtp::ServiceOperationModeBaseFunction> ServiceOperationMode, 
            std::shared_ptr<mtp::ServiceSourceModeBaseFunction> ServiceSourceMode, 
            std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>> OSLevel, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> Sync
        ) : mtp::ServiceElement(TagName, TagDescription, References, ObjectItem, Timestamped, WQC), Apply(Apply), ServiceOperationMode(ServiceOperationMode), ServiceSourceMode(ServiceSourceMode), OSLevel(OSLevel), Sync(Sync)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ParameterElement destructor for additional functionality. 
          */
        virtual ~ParameterElement() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ParameterElement;
        }
        

        /* Get-/Setters for association attribute Apply */
        virtual void setApply(std::shared_ptr<mtp::ApplyBaseFunction>& Apply) 
        { 
            this->Apply = Apply; 
            return;
        };
        virtual std::shared_ptr<mtp::ApplyBaseFunction> getApply() const
        { 
            return this->Apply; 
        };

        /* Get-/Setters for association attribute ServiceOperationMode */
        virtual void setServiceOperationMode(std::shared_ptr<mtp::ServiceOperationModeBaseFunction>& ServiceOperationMode) 
        { 
            this->ServiceOperationMode = ServiceOperationMode; 
            return;
        };
        virtual std::shared_ptr<mtp::ServiceOperationModeBaseFunction> getServiceOperationMode() const
        { 
            return this->ServiceOperationMode; 
        };

        /* Get-/Setters for association attribute ServiceSourceMode */
        virtual void setServiceSourceMode(std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& ServiceSourceMode) 
        { 
            this->ServiceSourceMode = ServiceSourceMode; 
            return;
        };
        virtual std::shared_ptr<mtp::ServiceSourceModeBaseFunction> getServiceSourceMode() const
        { 
            return this->ServiceSourceMode; 
        };


        /* Get-/Setters for Generic Attribute Structure OSLevel */
        virtual void setOSLevel(std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>>& OSLevel) 
        { 
            this->OSLevel = OSLevel; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>> getOSLevel() const
        {  
            return this->OSLevel; 
        };

        /* Get-/Setters for Generic Attribute Structure Sync */
        virtual void setSync(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& Sync) 
        { 
            this->Sync = Sync; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getSync() const
        {  
            return this->Sync; 
        };
    };   
}

#endif // defined HAVE_PARAMETER_ELEMENT_BASE_HPP