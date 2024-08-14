/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ConfigurationParameter.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_CONFIGURATION_PARAMETER_BASE_HPP
#define HAVE_CONFIGURATION_PARAMETER_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/ServiceParameter.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    
    class ConfigurationParameter;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ConfigurationParameter
     * @brief The configuration parameter.. This is the base class generated based on the Model Type Package Specification.
     */
    class ConfigurationParameter : public mtp::ServiceParameter
    {
    private:
    
    protected:
        ConfigurationParameter( 
            const std::string& Name, 
            std::shared_ptr<mtp::ParameterElement> ReferencedDataAssembly
        ) : mtp::ServiceParameter(Name, ReferencedDataAssembly)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ConfigurationParameter destructor for additional functionality. 
          */
        virtual ~ConfigurationParameter() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ConfigurationParameter;
        }
        
    };   
}

#endif // defined HAVE_CONFIGURATION_PARAMETER_BASE_HPP