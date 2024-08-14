/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file PeaElement.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PEA_ELEMENT_BASE_HPP
#define HAVE_PEA_ELEMENT_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/DataAssembly.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    
    class PeaElement;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class PeaElement
     * @brief PeaElement defines PEA-wide once-only information.. This is the base class generated based on the Model Type Package Specification.
     */
    class PeaElement : public mtp::DataAssembly
    {
    private:
    
    protected:
        PeaElement( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped
        ) : mtp::DataAssembly(TagName, TagDescription, References, ObjectItem, Timestamped)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see PeaElement destructor for additional functionality. 
          */
        virtual ~PeaElement() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::PeaElement;
        }
        
    };   
}

#endif // defined HAVE_PEA_ELEMENT_BASE_HPP