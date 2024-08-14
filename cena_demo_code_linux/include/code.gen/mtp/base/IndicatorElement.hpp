/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file IndicatorElement.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_INDICATOR_ELEMENT_BASE_HPP
#define HAVE_INDICATOR_ELEMENT_BASE_HPP

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
    class MissedValueFlag;
    template<typename dt> class ReadDataItem;
    
    class IndicatorElement;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class IndicatorElement
     * @brief IndicatorElement defines elements which are used to show values of the PEA.. This is the base class generated based on the Model Type Package Specification.
     */
    class IndicatorElement : public mtp::DataAssembly
    {
    private:
        
        /**
          * @brief Association MissedValueFlag. Interface extension for a missed value flag when indicator element is used by a report value.
          */ 
        std::shared_ptr<mtp::MissedValueFlag> MissedValueFlag;
        
        /**
          * @brief Generic structure WQC. WQC defines the worst quality code of all quality codes of the entity.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC;
    
    protected:
        IndicatorElement( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped, 
            std::shared_ptr<mtp::MissedValueFlag> MissedValueFlag, 
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC
        ) : mtp::DataAssembly(TagName, TagDescription, References, ObjectItem, Timestamped), MissedValueFlag(MissedValueFlag), WQC(WQC)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see IndicatorElement destructor for additional functionality. 
          */
        virtual ~IndicatorElement() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::IndicatorElement;
        }
        

        /* Get-/Setters for association attribute MissedValueFlag */
        virtual void setMissedValueFlag(std::shared_ptr<mtp::MissedValueFlag>& MissedValueFlag) 
        { 
            this->MissedValueFlag = MissedValueFlag; 
            return;
        };
        virtual std::shared_ptr<mtp::MissedValueFlag> getMissedValueFlag() const
        { 
            return this->MissedValueFlag; 
        };


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

#endif // defined HAVE_INDICATOR_ELEMENT_BASE_HPP