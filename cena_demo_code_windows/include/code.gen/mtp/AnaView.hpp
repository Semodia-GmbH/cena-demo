/**
 * @file AnaView.hpp
 * @date Wednesday, September 16, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_ANA_VIEW_HPP
#define HAVE_ANA_VIEW_HPP

#pragma once

#include "mtp/base/AnaView.hpp"
#include "mtp/UnitCode.hpp"

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @class AnaView
     * @brief AnaView defines a view element of an analogue value..
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class AnaView : public base::AnaView, public IFreezableValue<float>
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::AnaView::base::AnaView for pre-constructor-call allocation.
         *        May add additional logic after default values have been assigned.
         */
        AnaView(const std::string& TagName, const std::string& TagDescription,
                std::shared_ptr<mtp::InstanceReferences> References, std::shared_ptr<mtp::ObjectItem> ObjectItem, std::shared_ptr<mtp::Timestamped> Timestamped,
                std::shared_ptr<mtp::MissedValueFlag> MissedValueFlag,
                std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC,
                std::shared_ptr<mtp::ReadDataItem<float>> V,
                std::shared_ptr<mtp::ScaleSettingsBaseFunction<float>> VScaleSettings,
                std::shared_ptr<mtp::ReadDataItem<std::int16_t>> VUnit
        );

        /**
         * @ingroup MTP API
         * @brief Simplified direct-from-value constructor; calls `new` internally to provide a more user-friendly initializer
         */
        AnaView( const std::string& TagName, const std::string& TagDescription,
                 float V,
                 float VScaleMin, float VScaleMax,
                 mtp::UnitCode VUnit
        );

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers
          *        to null; those are done by base class @see base::AnaView::~base::AnaView
          */
        virtual ~AnaView() = default;

        /**
         * @brief Setting an AnaView sets the AnaView.V to the given value
         * @param value
         */
        virtual void setV(const float& value);
        using base::AnaView::setV;

        /**
         * @brief Assignment operator is a shorthand for @see setV()
         * @param value
         */
        virtual AnaView& operator=(const float& rhs);

        /**
         * @brief Allow direct comparison of AnaView with float
         */
        virtual bool operator==(const float& rhs) const;

        /**
         * @brief Derived from ==
         */
        virtual bool operator!=(const float& rhs) const;

        /**
         * @brief Allow implicit conversion of anaviews to floats (acting on VOut)
         */
        operator float();
    };
}

#endif // defined HAVE_ANA_VIEW_HPP