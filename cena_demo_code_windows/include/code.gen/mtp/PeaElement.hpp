//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file PeaElement.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PEA_ELEMENT_HPP
#define HAVE_PEA_ELEMENT_HPP

#pragma once

#include "mtp/base/PeaElement.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class PeaElement
     * @brief PeaElement defines PEA-wide once-only information.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class PeaElement : public base::PeaElement
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _PeaElement::_PeaElement for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        PeaElement( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _PeaElement::~_PeaElement  
          */
        virtual ~PeaElement() = default;
    };   
}

#endif // defined HAVE_PEA_ELEMENT_HPP