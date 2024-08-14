//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file ConfigurationParameter.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_CONFIGURATION_PARAMETER_HPP
#define HAVE_CONFIGURATION_PARAMETER_HPP

#pragma once

#include <map>

#include "mtp/base/ConfigurationParameter.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    // Early definition for friend
    class Service;
    class ServiceOperationModeBaseFunction;
    class ServiceSourceModeBaseFunction;

    /**
     * @class ConfigurationParameter
     * @brief The configuration parameter.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ConfigurationParameter : public base::ConfigurationParameter
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _ConfigurationParameter::_ConfigurationParameter for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ConfigurationParameter( 
            const std::string& Name, 
            std::shared_ptr<mtp::ParameterElement> ReferencedDataAssembly
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _ConfigurationParameter::~_ConfigurationParameter  
          */
        virtual ~ConfigurationParameter() = default;

    };   
}

#endif // defined HAVE_CONFIGURATION_PARAMETER_HPP