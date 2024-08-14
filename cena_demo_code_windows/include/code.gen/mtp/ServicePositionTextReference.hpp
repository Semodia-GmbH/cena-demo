//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file ServicePositionTextReference.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_POSITION_TEXT_REFERENCE_HPP
#define HAVE_SERVICE_POSITION_TEXT_REFERENCE_HPP

#pragma once

#include "mtp/base/ServicePositionTextReference.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class ServicePositionTextReference
     * @brief Extension for a service position at a service.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ServicePositionTextReference : public base::ServicePositionTextReference
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _ServicePositionTextReference::_ServicePositionTextReference for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ServicePositionTextReference( 
            std::shared_ptr<mtp::ServicePosition> Reference
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _ServicePositionTextReference::~_ServicePositionTextReference  
          */
        virtual ~ServicePositionTextReference() = default;
    };   
}

#endif // defined HAVE_SERVICE_POSITION_TEXT_REFERENCE_HPP