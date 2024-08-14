/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ServiceInteraction.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_INTERACTION_BASE_HPP
#define HAVE_SERVICE_INTERACTION_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/TextDefinition.hpp"

#include <string>
#include <vector>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class Question;
    
    class ServiceInteraction;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ServiceInteraction
     * @brief The service interaction.. This is the base class generated based on the Model Type Package Specification.
     */
    class ServiceInteraction : public mtp::TextDefinition
    {
    private:
        /**
          * @brief Simple attribute Name. The name of the service interaction.
          */ 
        std::string Name;
        
        /**
          * @brief Association list Questions. The list of corresponding questions.
          */ 
        std::vector<std::shared_ptr<mtp::Question>> Questions;
    
    protected:
        ServiceInteraction( 
            const std::string& Name
        ) : mtp::TextDefinition(), Name(Name)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ServiceInteraction destructor for additional functionality. 
          */
        virtual ~ServiceInteraction() 
        {

            // empty our lists of associations
            Questions.clear();
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ServiceInteraction;
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


        /* Get-/Setters for Associative list Questions */
        /**
         * @brief Return the number of elements in the association list
         */
        virtual size_t getQuestionCount() const
        {
            return this->Questions.size();
        };
        /**
         * @return the associative list item by identifier; return NULL if the item was not found.
         */
        virtual std::shared_ptr<mtp::Question> getQuestionByID(const size_t id) const
        { 
            if (id >= this->Questions.size()) 
            {
                return nullptr;
            }
            return this->Questions[id];
        };
        /**
         * @brief Add a new element to the back of the association list
         * @returns the position of the added element in the list of associations. 
         */
        virtual size_t addQuestion(std::shared_ptr<mtp::Question>& Question) 
        { 
            // FIXME: Needs to check the allowable multiplicity of the association!
            this->Questions.push_back(Question);
            return this->Questions.size()-1;
        };
        /**
         * @brief Remove a given association by providing its id/position in the list of associations.
         * @returns true if the object was erased; false otherwise.
         */
        virtual bool removeQuestionByPos(const size_t pos)  
        { 
            // FIXME: Needs to check the allowable multiplicity of the association! In particular 1..1 and 1..*
            size_t i = 0;
            for(auto it = this->Questions.begin(); it != this->Questions.end(); it++) {
                if (i == pos) { 
                    this->Questions.erase(it);
                    return true;
                }
            }
            return false;
        };
    };   
}

#endif // defined HAVE_SERVICE_INTERACTION_BASE_HPP