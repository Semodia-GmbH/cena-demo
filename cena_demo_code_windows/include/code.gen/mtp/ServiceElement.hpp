/**
 * @file ServiceElement.hpp
 * @date Wednesday, 19 January 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_ELEMENT_HPP
#define HAVE_SERVICE_ELEMENT_HPP

#pragma once

#include "mtp/base/ServiceElement.hpp"
#include "mtp/IQualityCode.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class ServiceElement
     * @brief Base class for all service specific data assembly children..
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ServiceElement : public base::ServiceElement, public mtp::IQualityCode
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _ServiceElement::_ServiceElement for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ServiceElement( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped, 
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC
        );

        /**
         * @ingroup MTP API
         * @brief Simplified CTor, initialized all values to sensible default
         */
        ServiceElement(
                const std::string& TagName,
                const std::string& TagDescription
        );

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _ServiceElement::~_ServiceElement  
          */
        virtual ~ServiceElement() = default;

        virtual MtpStatusCode setQualityCode(const QualityCode &qualityCode) override;

        virtual const QualityCode getQualityCode() const override;
    };   
}

#endif // defined HAVE_SERVICE_ELEMENT_HPP