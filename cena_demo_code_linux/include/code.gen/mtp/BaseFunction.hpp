//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file BaseFunction.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_BASE_FUNCTION_HPP
#define HAVE_BASE_FUNCTION_HPP

#pragma once

#include "mtp/base/BaseFunction.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class BaseFunction
     * @brief Abstract base function class.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class BaseFunction : public base::BaseFunction
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _BaseFunction::_BaseFunction for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        BaseFunction(
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _BaseFunction::~_BaseFunction  
          */
        virtual ~BaseFunction() = default;
    };   
}

#endif // defined HAVE_BASE_FUNCTION_HPP