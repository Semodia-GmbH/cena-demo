/**
 * @file ScaleSettingsBaseFunction.hpp
 * @date Wednesday, September 16, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SCALE_SETTINGS_BASE_FUNCTION_HPP
#define HAVE_SCALE_SETTINGS_BASE_FUNCTION_HPP

#pragma once

#include "mtp/base/ScaleSettingsBaseFunction.hpp"
#include "mtp/ReadDataItem.hpp"
#include "mtp/ReadDataItem.hpp"
namespace semodia::controlengine::native::model::mtp
{
    /**
     * @class ScaleSettingsBaseFunction
     * @brief ScaleSettings define the limits by design of a value, which cannot be changed during runtime.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    template <typename dt>
    class ScaleSettingsBaseFunction : public base::ScaleSettingsBaseFunction<dt>
    {
    private:
        /**
         * @brief Swichtes Min/Max if Min>Max
         */
        void ensureSaneOrdering()
        {
            if(this->getSclMax() != nullptr && this->getSclMin() != nullptr)
            {
                if (*this->getSclMin() > *this->getSclMax() )
                {
                    dt swap = *this->getSclMin();
                    FORCE_READDATAITEM_MEMBER_WRITE(dt, *this->getSclMax(), SclMin);
                    FORCE_READDATAITEM_MEMBER_WRITE(dt, swap, SclMax);
                }
            }
            return;
        }

    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::ScaleSettingsBaseFunction::base::ScaleSettingsBaseFunction for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ScaleSettingsBaseFunction(std::shared_ptr<mtp::ReadDataItem<dt>>  SclMin, std::shared_ptr<mtp::ReadDataItem<dt>>  SclMax)
            :   base::ScaleSettingsBaseFunction<dt>(SclMin, SclMax)
        {
            this->ensureSaneOrdering();
            return;
        };

        /**
         * @ingroup MTP API
         * @brief Simplified direct-from-value constructor; calls `new` internally to provide a more user-friendly initializer
         */
        ScaleSettingsBaseFunction(const dt SclMin, const dt SclMax)
            :   base::ScaleSettingsBaseFunction<dt>(
                    std::make_shared<ReadDataItem<dt>>(nullptr, SclMin),
                    std::make_shared<ReadDataItem<dt>>(nullptr, SclMax)
                )
        {
            this->ensureSaneOrdering();
            return;
        };

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::ScaleSettingsBaseFunction::~base::ScaleSettingsBaseFunction  
          */
        virtual ~ScaleSettingsBaseFunction() = default;
    };   
}

#endif // defined HAVE_SCALE_SETTINGS_BASE_FUNCTION_HPP