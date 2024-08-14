/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ServicePositionTextReference.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_POSITION_TEXT_REFERENCE_BASE_HPP
#define HAVE_SERVICE_POSITION_TEXT_REFERENCE_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/TextReference.hpp"


// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class ServicePosition;
    
    class ServicePositionTextReference;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ServicePositionTextReference
     * @brief Extension for a service position at a service.. This is the base class generated based on the Model Type Package Specification.
     */
    class ServicePositionTextReference : public mtp::TextReference
    {
    private:
        
        /**
          * @brief Association Reference. The referenced service position.
          */ 
        std::shared_ptr<mtp::ServicePosition> Reference;
    
    protected:
        ServicePositionTextReference( 
            std::shared_ptr<mtp::ServicePosition> Reference
        ) : mtp::TextReference(), Reference(Reference)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ServicePositionTextReference destructor for additional functionality. 
          */
        virtual ~ServicePositionTextReference() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ServicePositionTextReference;
        }
        

        /* Get-/Setters for association attribute Reference */
        virtual void setReference(std::shared_ptr<mtp::ServicePosition>& Reference) 
        { 
            this->Reference = Reference; 
            return;
        };
        virtual std::shared_ptr<mtp::ServicePosition> getReference() const
        { 
            return this->Reference; 
        };

    };   
}

#endif // defined HAVE_SERVICE_POSITION_TEXT_REFERENCE_BASE_HPP