/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file MissedValueFlag.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_MISSED_VALUE_FLAG_BASE_HPP
#define HAVE_MISSED_VALUE_FLAG_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/SemanticModelEntity.hpp"

#include "mtp/ReadDataItem.hpp"

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    template<typename dt> class ReadDataItem;
    
    class MissedValueFlag;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class MissedValueFlag
     * @brief Extension for a missed value flag at report values.. This is the base class generated based on the Model Type Package Specification.
     */
    class MissedValueFlag : public mtp::SemanticModelEntity
    {
    private:
        
        /**
          * @brief Generic structure MissedValue. Defines if the value of the report value has been changed twice during a freeze.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> MissedValue;
    
    protected:
        MissedValueFlag( 
            std::shared_ptr<mtp::ReadDataItem<bool>> MissedValue
        ) : mtp::SemanticModelEntity(), MissedValue(MissedValue)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see MissedValueFlag destructor for additional functionality. 
          */
        virtual ~MissedValueFlag() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::MissedValueFlag;
        }
        

        /* Get-/Setters for Generic Attribute Structure MissedValue */
        virtual void setMissedValue(std::shared_ptr<mtp::ReadDataItem<bool>>& MissedValue) 
        { 
            this->MissedValue = MissedValue; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getMissedValue() const
        {  
            return this->MissedValue; 
        };
    };   
}

#endif // defined HAVE_MISSED_VALUE_FLAG_BASE_HPP