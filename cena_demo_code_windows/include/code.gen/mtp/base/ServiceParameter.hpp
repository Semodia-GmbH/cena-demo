/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ServiceParameter.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_PARAMETER_BASE_HPP
#define HAVE_SERVICE_PARAMETER_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/LinkedObject.hpp"

#include <string>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class ParameterElement;
    
    class ServiceParameter;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ServiceParameter
     * @brief The service parameter.. This is the base class generated based on the Model Type Package Specification.
     */
    class ServiceParameter : public mtp::LinkedObject
    {
    private:
        /**
          * @brief Simple attribute Name. The name of the service parameter.
          */ 
        std::string Name;
        
        /**
          * @brief Association ReferencedDataAssembly. The referenced data assembly providing the dynamic access at runtime.
          */ 
        std::shared_ptr<mtp::ParameterElement> ReferencedDataAssembly;
    
    protected:
        ServiceParameter( 
            const std::string& Name, 
            std::shared_ptr<mtp::ParameterElement> ReferencedDataAssembly
        ) : mtp::LinkedObject(), Name(Name), ReferencedDataAssembly(ReferencedDataAssembly)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ServiceParameter destructor for additional functionality. 
          */
        virtual ~ServiceParameter() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ServiceParameter;
        }
        
         
        /* Get-/Setters for simple attribute Name */
        virtual void setName(const std::string& Name) 
        { 
            this->Name = Name; 
            return;
        };
        virtual std::string getName() const
        { 
            return this->Name; 
        };


        /* Get-/Setters for association attribute ReferencedDataAssembly */
        virtual void setReferencedDataAssembly(std::shared_ptr<mtp::ParameterElement>& ReferencedDataAssembly) 
        { 
            this->ReferencedDataAssembly = ReferencedDataAssembly; 
            return;
        };
        virtual std::shared_ptr<mtp::ParameterElement> getReferencedDataAssembly() const
        { 
            return this->ReferencedDataAssembly; 
        };

    };   
}

#endif // defined HAVE_SERVICE_PARAMETER_BASE_HPP