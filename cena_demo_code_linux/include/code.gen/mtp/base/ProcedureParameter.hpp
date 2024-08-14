/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ProcedureParameter.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PROCEDURE_PARAMETER_BASE_HPP
#define HAVE_PROCEDURE_PARAMETER_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/ServiceParameter.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    
    class ProcedureParameter;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ProcedureParameter
     * @brief The procedure parameter.. This is the base class generated based on the Model Type Package Specification.
     */
    class ProcedureParameter : public mtp::ServiceParameter
    {
    private:

    protected:
        ProcedureParameter( 
            const std::string& Name, 
            std::shared_ptr<mtp::ParameterElement> ReferencedDataAssembly
        ) : mtp::ServiceParameter(Name, ReferencedDataAssembly)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ProcedureParameter destructor for additional functionality. 
          */
        virtual ~ProcedureParameter() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ProcedureParameter;
        }
        
    };   
}

#endif // defined HAVE_PROCEDURE_PARAMETER_BASE_HPP