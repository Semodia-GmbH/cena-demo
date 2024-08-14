/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file BaseFunction.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_BASE_FUNCTION_BASE_HPP
#define HAVE_BASE_FUNCTION_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/SemanticModelEntity.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    
    class BaseFunction;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class BaseFunction
     * @brief Abstract base function class.. This is the base class generated based on the Model Type Package Specification.
     */
    class BaseFunction : public mtp::SemanticModelEntity
    {
    private:
    
    protected:
        BaseFunction(
        ) : mtp::SemanticModelEntity()
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see BaseFunction destructor for additional functionality. 
          */
        virtual ~BaseFunction() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::BaseFunction;
        }
        
    };   
}

#endif // defined HAVE_BASE_FUNCTION_BASE_HPP