/*
 * @file MissedValueFlag.hpp
 * @date Wednesday, 12 January 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_MISSED_VALUE_FLAG_HPP
#define HAVE_MISSED_VALUE_FLAG_HPP

#pragma once

#include "mtp/base/MissedValueFlag.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class MissedValueFlag
     * @brief Extension for a missed value flag at report values.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class MissedValueFlag : public base::MissedValueFlag
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _MissedValueFlag::_MissedValueFlag for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        MissedValueFlag(std::shared_ptr<mtp::ReadDataItem<bool>> MissedValue);

        /**
         * @brief Simplified C'Tor; default missed flag to "False"
         */
        MissedValueFlag();
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _MissedValueFlag::~_MissedValueFlag  
          */
        virtual ~MissedValueFlag() = default;

        /**
         * @brief Allows setting the the built-in boolean
         * @return GOOD if ReadDataItem was updated, potentially MODEL_ELEMENT_MISSING
         */
        virtual MtpStatusCode setFlag(const bool& valueMissed);

        /**
         * @return Returns the value of the built in flag or `false` if no ReadDataItem is associated with the flag
         */
        virtual bool getFlag() const;
    };
}

#endif // defined HAVE_MISSED_VALUE_FLAG_HPP