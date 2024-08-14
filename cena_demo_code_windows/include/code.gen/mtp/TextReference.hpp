//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file TextReference.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_TEXT_REFERENCE_HPP
#define HAVE_TEXT_REFERENCE_HPP

#pragma once

#include "mtp/base/TextReference.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class TextReference
     * @brief Base for text reference extensions.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class TextReference : public base::TextReference
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _TextReference::_TextReference for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        TextReference(
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _TextReference::~_TextReference  
          */
        virtual ~TextReference() = default;
    };   
}

#endif // defined HAVE_TEXT_REFERENCE_HPP