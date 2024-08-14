/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ServiceSet.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_SET_BASE_HPP
#define HAVE_SERVICE_SET_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/MtpSet.hpp"

#include <string>
#include <vector>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class Service;
    
    class ServiceSet;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ServiceSet
     * @brief Defines the service aspect of the MTP.. This is the base class generated based on the Model Type Package Specification.
     */
    class ServiceSet : public mtp::MtpSet
    {
    private:
        /**
          * @brief Simple attribute Version. The version of the aspect. Defines the implemented version of the standard.
          *        (constant) This value is constant and can't be changed after instantiation.
          */ 
        const std::string Version;
        /**
          * @brief Simple attribute DocumentIdentifier. The document identifier of the aspect.
          */ 
        std::string DocumentIdentifier;
        
        /**
          * @brief Association list Services. The list of services which are included within the MTP.
          */ 
        std::vector<std::shared_ptr<mtp::Service>> Services;
    
    protected:
        ServiceSet( 
            const std::string& Version, 
            const std::string& DocumentIdentifier
        ) : mtp::MtpSet(), Version(Version), DocumentIdentifier(DocumentIdentifier)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ServiceSet destructor for additional functionality. 
          */
        virtual ~ServiceSet() 
        {

            // empty our lists of associations
            Services.clear();
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ServiceSet;
        }
        
         
        /* Get-/Setters for simple attribute Version */
        virtual const std::string getVersion() const
        { 
            return this->Version; 
        };

        /* Get-/Setters for simple attribute DocumentIdentifier */
        virtual void setDocumentIdentifier(const std::string& DocumentIdentifier) 
        { 
            this->DocumentIdentifier = DocumentIdentifier; 
            return;
        };
        virtual std::string getDocumentIdentifier() const
        { 
            return this->DocumentIdentifier; 
        };


        /* Get-/Setters for Associative list Services */
        /**
         * @brief Return the number of elements in the association list
         */
        virtual size_t getServiceCount() const
        {
            return this->Services.size();
        };
        /**
         * @return the associative list item by identifier; return NULL if the item was not found.
         */
        virtual std::shared_ptr<mtp::Service> getServiceByID(const size_t id) const
        { 
            if (id >= this->Services.size()) 
            {
                return nullptr;
            }
            return this->Services[id];
        };
        /**
         * @brief Add a new element to the back of the association list
         * @returns the position of the added element in the list of associations. 
         */
        virtual size_t addService(std::shared_ptr<mtp::Service>& Service) 
        { 
            // FIXME: Needs to check the allowable multiplicity of the association!
            this->Services.push_back(Service);
            return this->Services.size()-1;
        };
        /**
         * @brief Remove a given association by providing its id/position in the list of associations.
         * @returns true if the object was erased; false otherwise.
         */
        virtual bool removeServiceByPos(const size_t pos)  
        { 
            // FIXME: Needs to check the allowable multiplicity of the association! In particular 1..1 and 1..*
            size_t i = 0;
            for(auto it = this->Services.begin(); it != this->Services.end(); it++) {
                if (i == pos) { 
                    this->Services.erase(it);
                    return true;
                }
            }
            return false;
        };
    };   
}

#endif // defined HAVE_SERVICE_SET_BASE_HPP