/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file LinkedObject.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_LINKED_OBJECT_BASE_HPP
#define HAVE_LINKED_OBJECT_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/SemanticModelEntity.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    
    class LinkedObject;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class LinkedObject
     * @brief Basic cross referencing object.. This is the base class generated based on the Model Type Package Specification.
     */
    class LinkedObject : public mtp::SemanticModelEntity
    {
    private:
    
    protected:
        LinkedObject(
        ) : mtp::SemanticModelEntity()
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see LinkedObject destructor for additional functionality. 
          */
        virtual ~LinkedObject() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::LinkedObject;
        }
        
    };   
}

#endif // defined HAVE_LINKED_OBJECT_BASE_HPP