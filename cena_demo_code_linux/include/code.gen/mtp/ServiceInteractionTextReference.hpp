//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file ServiceInteractionTextReference.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_INTERACTION_TEXT_REFERENCE_HPP
#define HAVE_SERVICE_INTERACTION_TEXT_REFERENCE_HPP

#pragma once

#include "mtp/base/ServiceInteractionTextReference.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class ServiceInteractionTextReference
     * @brief Extension for a service interaction at a service.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ServiceInteractionTextReference : public base::ServiceInteractionTextReference
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _ServiceInteractionTextReference::_ServiceInteractionTextReference for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ServiceInteractionTextReference( 
            std::shared_ptr<mtp::ServiceInteraction> Reference
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _ServiceInteractionTextReference::~_ServiceInteractionTextReference  
          */
        virtual ~ServiceInteractionTextReference() = default;
    };   
}

#endif // defined HAVE_SERVICE_INTERACTION_TEXT_REFERENCE_HPP