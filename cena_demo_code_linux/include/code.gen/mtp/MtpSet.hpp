//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file MtpSet.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_MTP_SET_HPP
#define HAVE_MTP_SET_HPP

#pragma once

#include "mtp/base/MtpSet.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class MtpSet
     * @brief The MTP set defines the base for all aspects.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class MtpSet : public base::MtpSet
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _MtpSet::_MtpSet for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        MtpSet(
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _MtpSet::~_MtpSet  
          */
        virtual ~MtpSet() = default;
    };   
}

#endif // defined HAVE_MTP_SET_HPP