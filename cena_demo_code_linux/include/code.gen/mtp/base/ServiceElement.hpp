/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ServiceElement.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_ELEMENT_BASE_HPP
#define HAVE_SERVICE_ELEMENT_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/DataAssembly.hpp"

#include "mtp/ReadDataItem.hpp"
#include <cstdint>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    template<typename dt> class ReadDataItem;
    
    class ServiceElement;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ServiceElement
     * @brief Base class for all service specific data assembly children.. This is the base class generated based on the Model Type Package Specification.
     */
    class ServiceElement : public mtp::DataAssembly
    {
    private:
        
        /**
          * @brief Generic structure WQC. WQC defines the worst quality code of all quality codes of the entity.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC;
    
    protected:
        ServiceElement( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped, 
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC
        ) : mtp::DataAssembly(TagName, TagDescription, References, ObjectItem, Timestamped), WQC(WQC)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ServiceElement destructor for additional functionality. 
          */
        virtual ~ServiceElement() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ServiceElement;
        }
        

        /* Get-/Setters for Generic Attribute Structure WQC */
        virtual void setWQC(std::shared_ptr<mtp::ReadDataItem<std::uint8_t>>& WQC) 
        { 
            this->WQC = WQC; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> getWQC() const
        {  
            return this->WQC; 
        };
    };   
}

#endif // defined HAVE_SERVICE_ELEMENT_BASE_HPP