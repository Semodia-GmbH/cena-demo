//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file LinkedObject.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_LINKED_OBJECT_HPP
#define HAVE_LINKED_OBJECT_HPP

#pragma once

#include "mtp/base/LinkedObject.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class LinkedObject
     * @brief Basic cross referencing object.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class LinkedObject : public base::LinkedObject
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _LinkedObject::_LinkedObject for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        LinkedObject(
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _LinkedObject::~_LinkedObject  
          */
        virtual ~LinkedObject() = default;
    };   
}

#endif // defined HAVE_LINKED_OBJECT_HPP