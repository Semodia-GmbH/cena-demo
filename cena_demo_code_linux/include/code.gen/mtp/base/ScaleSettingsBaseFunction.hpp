/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ScaleSettingsBaseFunction.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SCALE_SETTINGS_BASE_FUNCTION_BASE_HPP
#define HAVE_SCALE_SETTINGS_BASE_FUNCTION_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/BaseFunction.hpp"

#include "mtp/ReadDataItem.hpp"

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    template<typename dt> class ReadDataItem;
    
    template <typename dt> 
    class ScaleSettingsBaseFunction;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ScaleSettingsBaseFunction
     * @brief ScaleSettings define the limits by design of a value, which cannot be changed during runtime.. This is the base class generated based on the Model Type Package Specification.
     */
    template <typename dt>
    class ScaleSettingsBaseFunction : public mtp::BaseFunction
    {
    private:
        
        /**
          * @brief Generic structure SclMin. SclMin defines the minimum limit by design of a value.
          */
        std::shared_ptr<mtp::ReadDataItem<dt>> SclMin;
        /**
          * @brief Generic structure SclMax. SclMax defines the maximum limit by design of a value.
          */
        std::shared_ptr<mtp::ReadDataItem<dt>> SclMax;
    
    protected:
        ScaleSettingsBaseFunction( 
            std::shared_ptr<mtp::ReadDataItem<dt>> SclMin, 
            std::shared_ptr<mtp::ReadDataItem<dt>> SclMax
        ) : mtp::BaseFunction(), SclMin(SclMin), SclMax(SclMax)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ScaleSettingsBaseFunction destructor for additional functionality. 
          */
        virtual ~ScaleSettingsBaseFunction() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ScaleSettingsBaseFunction;
        }
        

        /* Get-/Setters for Generic Attribute Structure SclMin */
        virtual void setSclMin(std::shared_ptr<mtp::ReadDataItem<dt>>& SclMin) 
        { 
            this->SclMin = SclMin; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<dt>> getSclMin() const
        {  
            return this->SclMin; 
        };

        /* Get-/Setters for Generic Attribute Structure SclMax */
        virtual void setSclMax(std::shared_ptr<mtp::ReadDataItem<dt>>& SclMax) 
        { 
            this->SclMax = SclMax; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<dt>> getSclMax() const
        {  
            return this->SclMax; 
        };
    };   
}

#endif // defined HAVE_SCALE_SETTINGS_BASE_FUNCTION_BASE_HPP