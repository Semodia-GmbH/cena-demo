/**
 * @file IndicatorElement.hpp
 * @date Thursday, September 24, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_INDICATOR_ELEMENT_HPP
#define HAVE_INDICATOR_ELEMENT_HPP

#pragma once

#include "mtp/base/IndicatorElement.hpp"
#include "mtp/QualityCode.hpp"
#include "mtp/IQualityCode.hpp"
#include "mtp/IFreezableValue.hpp"

namespace semodia::controlengine::native::model::mtp
{

    /**
     * @class IndicatorElement
     * @brief IndicatorElement defines elements which are used to show values of the PEA.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class IndicatorElement : public base::IndicatorElement, public IQualityCode
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::IndicatorElement::base::IndicatorElement for pre-constructor-call allocation.
         *        May add additional logic after default values have been assigned.
         */
        IndicatorElement(const std::string& TagName, const std::string& TagDescription,
                         std::shared_ptr<mtp::InstanceReferences> References, std::shared_ptr<mtp::ObjectItem> ObjectItem, std::shared_ptr<mtp::Timestamped> Timestamped,
                         std::shared_ptr<mtp::MissedValueFlag> MissedValueFlag, std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC);

        /**
         * @ingroup MTP API
         * @brief Simplified constructor; allocates dependencies and sets WQC to WQC::NO_STATUS
         */
        IndicatorElement(const std::string& TagName, const std::string& TagDescription);

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::IndicatorElement::~base::IndicatorElement  
          */
        virtual ~IndicatorElement();

        /**
         * @see IQualityCode::setQualityCode
         */
        virtual mtp::MtpStatusCode setQualityCode(const mtp::QualityCode& WQCValue) override;

        /**
         * @see IQualityCode::setQualityCode
         */
        virtual const mtp::QualityCode getQualityCode() const override;

        /**
         * @brief   Called by the MTP/CE to update any values related to the indicator element
         * @details Does nothing by default, though (DInt|Ana|Bin)Mon may overwrite this behavior
         * @return  GOOD
         */
        virtual mtp::MtpStatusCode update();
    };   
}

#endif // defined HAVE_INDICATOR_ELEMENT_HPP