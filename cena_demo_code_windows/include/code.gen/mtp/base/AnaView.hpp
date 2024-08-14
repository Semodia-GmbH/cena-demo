/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file AnaView.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_ANA_VIEW_BASE_HPP
#define HAVE_ANA_VIEW_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/IndicatorElement.hpp"

#include "mtp/ReadDataItem.hpp"
#include "mtp/ScaleSettingsBaseFunction.hpp"
#include <cstdint>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    template<typename dt> class ReadDataItem;
    template<typename dt> class ScaleSettingsBaseFunction;
    
    class AnaView;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class AnaView
     * @brief AnaView defines a view element of an analogue value.. This is the base class generated based on the Model Type Package Specification.
     */
    class AnaView : public mtp::IndicatorElement
    {
    private:
        
        /**
          * @brief Generic structure V. V defines the value.
          */
        std::shared_ptr<mtp::ReadDataItem<float>> V;
        /**
          * @brief Generic structure VScaleSettings. VScaleSettings define the limits by design of a value, which cannot be changed during runtime.
          */
        std::shared_ptr<mtp::ScaleSettingsBaseFunction<float>> VScaleSettings;
        /**
          * @brief Generic structure VUnit. VUnit defines the unit of the values.
          */
        std::shared_ptr<mtp::ReadDataItem<std::int16_t>> VUnit;
    
    protected:
        AnaView( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped, 
            std::shared_ptr<mtp::MissedValueFlag> MissedValueFlag, 
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC, 
            std::shared_ptr<mtp::ReadDataItem<float>> V, 
            std::shared_ptr<mtp::ScaleSettingsBaseFunction<float>> VScaleSettings, 
            std::shared_ptr<mtp::ReadDataItem<std::int16_t>> VUnit
        ) : mtp::IndicatorElement(TagName, TagDescription, References, ObjectItem, Timestamped, MissedValueFlag, WQC), V(V), VScaleSettings(VScaleSettings), VUnit(VUnit)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see AnaView destructor for additional functionality. 
          */
        virtual ~AnaView() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::AnaView;
        }
        

        /* Get-/Setters for Generic Attribute Structure V */
        virtual void setV(std::shared_ptr<mtp::ReadDataItem<float>>& V) 
        { 
            this->V = V; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<float>> getV() const
        {  
            return this->V; 
        };

        /* Get-/Setters for Generic Attribute Structure VScaleSettings */
        virtual void setVScaleSettings(std::shared_ptr<mtp::ScaleSettingsBaseFunction<float>>& VScaleSettings) 
        { 
            this->VScaleSettings = VScaleSettings; 
            return;
        };
        virtual const std::shared_ptr<mtp::ScaleSettingsBaseFunction<float>> getVScaleSettings() const
        {  
            return this->VScaleSettings; 
        };

        /* Get-/Setters for Generic Attribute Structure VUnit */
        virtual void setVUnit(std::shared_ptr<mtp::ReadDataItem<std::int16_t>>& VUnit) 
        { 
            this->VUnit = VUnit; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::int16_t>> getVUnit() const
        {  
            return this->VUnit; 
        };
    };   
}

#endif // defined HAVE_ANA_VIEW_BASE_HPP