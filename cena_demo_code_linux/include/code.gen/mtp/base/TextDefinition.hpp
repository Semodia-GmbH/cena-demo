/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file TextDefinition.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_TEXT_DEFINITION_BASE_HPP
#define HAVE_TEXT_DEFINITION_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/SemanticModelEntity.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    
    class TextDefinition;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class TextDefinition
     * @brief The base text definition.. This is the base class generated based on the Model Type Package Specification.
     */
    class TextDefinition : public mtp::SemanticModelEntity
    {
    private:
    
    protected:
        TextDefinition(
        ) : mtp::SemanticModelEntity()
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see TextDefinition destructor for additional functionality. 
          */
        virtual ~TextDefinition() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::TextDefinition;
        }
        
    };   
}

#endif // defined HAVE_TEXT_DEFINITION_BASE_HPP