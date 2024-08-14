//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file TextDefinition.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_TEXT_DEFINITION_HPP
#define HAVE_TEXT_DEFINITION_HPP

#pragma once

#include "mtp/base/TextDefinition.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class TextDefinition
     * @brief The base text definition.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class TextDefinition : public base::TextDefinition
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _TextDefinition::_TextDefinition for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        TextDefinition(
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _TextDefinition::~_TextDefinition  
          */
        virtual ~TextDefinition() = default;
    };   
}

#endif // defined HAVE_TEXT_DEFINITION_HPP