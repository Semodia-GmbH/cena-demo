//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file ServiceInteraction.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_INTERACTION_HPP
#define HAVE_SERVICE_INTERACTION_HPP

#pragma once

#include "mtp/base/ServiceInteraction.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class ServiceInteraction
     * @brief The service interaction.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ServiceInteraction : public base::ServiceInteraction
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _ServiceInteraction::_ServiceInteraction for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ServiceInteraction( 
            const std::string& Name
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _ServiceInteraction::~_ServiceInteraction  
          */
        virtual ~ServiceInteraction() = default;
    };   
}

#endif // defined HAVE_SERVICE_INTERACTION_HPP