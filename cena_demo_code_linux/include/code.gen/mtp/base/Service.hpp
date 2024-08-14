/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file Service.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_BASE_HPP
#define HAVE_SERVICE_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/LinkedObject.hpp"

#include <string>
#include <vector>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class ServiceControl;
    class ServiceInteractionTextReference;
    class ServicePositionTextReference;
    class Procedure;
    class ConfigurationParameter;
    class FunctionClassification;
    
    class Service;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class Service
     * @brief The service object encapsulates the process functionality.. This is the base class generated based on the Model Type Package Specification.
     */
    class Service : public mtp::LinkedObject
    {
    private:
        /**
          * @brief Simple attribute Name. The name of the service.
          */ 
        std::string Name;
        
        /**
          * @brief Association ReferencedServiceControl. The referenced service control object providing the dynamic access.
          */ 
        std::shared_ptr<mtp::ServiceControl> ReferencedServiceControl;
        /**
          * @brief Association ServiceInteraction. Interface extension for a service interaction.
          */ 
        std::shared_ptr<mtp::ServiceInteractionTextReference> ServiceInteraction;
        /**
          * @brief Association ServicePosition. Interface extension for a service position.
          */ 
        std::shared_ptr<mtp::ServicePositionTextReference> ServicePosition;
        
        /**
          * @brief Association list Procedures. The list of procedures.
          */ 
        std::vector<std::shared_ptr<mtp::Procedure>> Procedures;
        /**
          * @brief Association list ConfigurationParameters. The list of associated configuration parameters.
          */ 
        std::vector<std::shared_ptr<mtp::ConfigurationParameter>> ConfigurationParameters;
        /**
          * @brief Association list Classifications. The list of function classifications describing the service.
          */ 
        std::vector<std::shared_ptr<mtp::FunctionClassification>> Classifications;
    
    protected:
        Service( 
            const std::string& Name, 
            std::shared_ptr<mtp::ServiceControl> ReferencedServiceControl, 
            std::shared_ptr<mtp::ServiceInteractionTextReference> ServiceInteraction, 
            std::shared_ptr<mtp::ServicePositionTextReference> ServicePosition
        ) : mtp::LinkedObject(), Name(Name), ReferencedServiceControl(ReferencedServiceControl), ServiceInteraction(ServiceInteraction), ServicePosition(ServicePosition)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see Service destructor for additional functionality. 
          */
        virtual ~Service() 
        {

            // empty our lists of associations
            Procedures.clear();
            ConfigurationParameters.clear();
            Classifications.clear();
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::Service;
        }
        
         
        /* Get-/Setters for simple attribute Name */
        virtual void setName(const std::string& Name) 
        { 
            this->Name = Name; 
            return;
        };
        virtual std::string getName() const
        { 
            return this->Name; 
        };


        /* Get-/Setters for association attribute ReferencedServiceControl */
        virtual void setReferencedServiceControl(std::shared_ptr<mtp::ServiceControl>& ReferencedServiceControl) 
        { 
            this->ReferencedServiceControl = ReferencedServiceControl; 
            return;
        };
        virtual std::shared_ptr<mtp::ServiceControl> getReferencedServiceControl() const
        { 
            return this->ReferencedServiceControl; 
        };

        /* Get-/Setters for association attribute ServiceInteraction */
        virtual void setServiceInteraction(std::shared_ptr<mtp::ServiceInteractionTextReference>& ServiceInteraction) 
        { 
            this->ServiceInteraction = ServiceInteraction; 
            return;
        };
        virtual std::shared_ptr<mtp::ServiceInteractionTextReference> getServiceInteraction() const
        { 
            return this->ServiceInteraction; 
        };

        /* Get-/Setters for association attribute ServicePosition */
        virtual void setServicePosition(std::shared_ptr<mtp::ServicePositionTextReference>& ServicePosition) 
        { 
            this->ServicePosition = ServicePosition; 
            return;
        };
        virtual std::shared_ptr<mtp::ServicePositionTextReference> getServicePosition() const
        { 
            return this->ServicePosition; 
        };


        /* Get-/Setters for Associative list Procedures */
        /**
         * @brief Return the number of elements in the association list
         */
        virtual size_t getProcedureCount() const
        {
            return this->Procedures.size();
        };
        /**
         * @return the associative list item by identifier; return NULL if the item was not found.
         */
        virtual std::shared_ptr<mtp::Procedure> getProcedureByID(const size_t id) const
        { 
            if (id >= this->Procedures.size()) 
            {
                return nullptr;
            }
            return this->Procedures[id];
        };
        /**
         * @brief Add a new element to the back of the association list
         * @returns the position of the added element in the list of associations. 
         */
        virtual size_t addProcedure(std::shared_ptr<mtp::Procedure>& Procedure) 
        { 
            // FIXME: Needs to check the allowable multiplicity of the association!
            this->Procedures.push_back(Procedure);
            return this->Procedures.size()-1;
        };
        /**
         * @brief Remove a given association by providing its id/position in the list of associations.
         * @returns true if the object was erased; false otherwise.
         */
        virtual bool removeProcedureByPos(const size_t pos)  
        { 
            // FIXME: Needs to check the allowable multiplicity of the association! In particular 1..1 and 1..*
            size_t i = 0;
            for(auto it = this->Procedures.begin(); it != this->Procedures.end(); it++) {
                if (i == pos) { 
                    this->Procedures.erase(it);
                    return true;
                }
            }
            return false;
        };

        /* Get-/Setters for Associative list ConfigurationParameters */
        /**
         * @brief Return the number of elements in the association list
         */
        virtual size_t getConfigurationParameterCount() const
        {
            return this->ConfigurationParameters.size();
        };
        /**
         * @return the associative list item by identifier; return NULL if the item was not found.
         */
        virtual std::shared_ptr<mtp::ConfigurationParameter> getConfigurationParameterByID(const size_t id) const
        { 
            if (id >= this->ConfigurationParameters.size()) 
            {
                return nullptr;
            }
            return this->ConfigurationParameters[id];
        };
        /**
         * @brief Add a new element to the back of the association list
         * @returns the position of the added element in the list of associations. 
         */
        virtual size_t addConfigurationParameter(std::shared_ptr<mtp::ConfigurationParameter>& ConfigurationParameter) 
        { 
            // FIXME: Needs to check the allowable multiplicity of the association!
            this->ConfigurationParameters.push_back(ConfigurationParameter);
            return this->ConfigurationParameters.size()-1;
        };
        /**
         * @brief Remove a given association by providing its id/position in the list of associations.
         * @returns true if the object was erased; false otherwise.
         */
        virtual bool removeConfigurationParameterByPos(const size_t pos)  
        { 
            // FIXME: Needs to check the allowable multiplicity of the association! In particular 1..1 and 1..*
            size_t i = 0;
            for(auto it = this->ConfigurationParameters.begin(); it != this->ConfigurationParameters.end(); it++) {
                if (i == pos) { 
                    this->ConfigurationParameters.erase(it);
                    return true;
                }
            }
            return false;
        };

        /* Get-/Setters for Associative list Classifications */
        /**
         * @brief Return the number of elements in the association list
         */
        virtual size_t getClassificationCount() const
        {
            return this->Classifications.size();
        };
        /**
         * @return the associative list item by identifier; return NULL if the item was not found.
         */
        virtual std::shared_ptr<mtp::FunctionClassification> getClassificationByID(const size_t id) const
        { 
            if (id >= this->Classifications.size()) 
            {
                return nullptr;
            }
            return this->Classifications[id];
        };
        /**
         * @brief Add a new element to the back of the association list
         * @returns the position of the added element in the list of associations. 
         */
        virtual size_t addClassification(std::shared_ptr<mtp::FunctionClassification>& Classification) 
        { 
            // FIXME: Needs to check the allowable multiplicity of the association!
            this->Classifications.push_back(Classification);
            return this->Classifications.size()-1;
        };
        /**
         * @brief Remove a given association by providing its id/position in the list of associations.
         * @returns true if the object was erased; false otherwise.
         */
        virtual bool removeClassificationByPos(const size_t pos)  
        { 
            // FIXME: Needs to check the allowable multiplicity of the association! In particular 1..1 and 1..*
            size_t i = 0;
            for(auto it = this->Classifications.begin(); it != this->Classifications.end(); it++) {
                if (i == pos) { 
                    this->Classifications.erase(it);
                    return true;
                }
            }
            return false;
        };
    };   
}

#endif // defined HAVE_SERVICE_BASE_HPP