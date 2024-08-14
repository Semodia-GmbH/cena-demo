/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ServiceInteractionTextReference.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_INTERACTION_TEXT_REFERENCE_BASE_HPP
#define HAVE_SERVICE_INTERACTION_TEXT_REFERENCE_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/TextReference.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class ServiceInteraction;
    
    class ServiceInteractionTextReference;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ServiceInteractionTextReference
     * @brief Extension for a service interaction at a service.. This is the base class generated based on the Model Type Package Specification.
     */
    class ServiceInteractionTextReference : public mtp::TextReference
    {
    private:
        
        /**
          * @brief Association Reference. The referenced service interaction.
          */ 
        std::shared_ptr<mtp::ServiceInteraction> Reference;
    
    protected:
        ServiceInteractionTextReference( 
            std::shared_ptr<mtp::ServiceInteraction> Reference
        ) : mtp::TextReference(), Reference(Reference)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ServiceInteractionTextReference destructor for additional functionality. 
          */
        virtual ~ServiceInteractionTextReference() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ServiceInteractionTextReference;
        }
        

        /* Get-/Setters for association attribute Reference */
        virtual void setReference(std::shared_ptr<mtp::ServiceInteraction>& Reference) 
        { 
            this->Reference = Reference; 
            return;
        };
        virtual std::shared_ptr<mtp::ServiceInteraction> getReference() const
        { 
            return this->Reference; 
        };

    };   
}

#endif // defined HAVE_SERVICE_INTERACTION_TEXT_REFERENCE_BASE_HPP