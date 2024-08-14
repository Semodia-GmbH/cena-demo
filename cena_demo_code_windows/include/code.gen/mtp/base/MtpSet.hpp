/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file MtpSet.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_MTP_SET_BASE_HPP
#define HAVE_MTP_SET_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/SemanticModelEntity.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    
    class MtpSet;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class MtpSet
     * @brief The MTP set defines the base for all aspects.. This is the base class generated based on the Model Type Package Specification.
     */
    class MtpSet : public mtp::SemanticModelEntity
    {
    private:
    
    protected:
        MtpSet(
        ) : mtp::SemanticModelEntity()
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see MtpSet destructor for additional functionality. 
          */
        virtual ~MtpSet() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::MtpSet;
        }
        
    };   
}

#endif // defined HAVE_MTP_SET_BASE_HPP