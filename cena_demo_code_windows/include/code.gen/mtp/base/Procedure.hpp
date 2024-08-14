/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file Procedure.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PROCEDURE_BASE_HPP
#define HAVE_PROCEDURE_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/LinkedObject.hpp"

#include <string>
#include <cstdint>
#include <vector>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class ProcedureHealthView;
    class DataAssembly;
    class ReportValue;
    class ProcedureParameter;
    class FunctionClassification;
    class ProcessValueIn;
    class ProcessValueOut;
    
    class Procedure;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class Procedure
     * @brief The procedure executing the specified behavior.. This is the base class generated based on the Model Type Package Specification.
     */
    class Procedure : public mtp::LinkedObject
    {
    private:
        /**
          * @brief Simple attribute Name. The name of the service procedure.
          */ 
        std::string Name;
        /**
          * @brief Simple attribute IsSelfCompleting. Defines if the procedure is self completing or not.
          */ 
        bool IsSelfCompleting;
        /**
          * @brief Simple attribute ProcedureId. The ID of the procedure which must be unique within the service.
          */ 
        std::uint32_t ProcedureId;
        
        /**
          * @brief Association ReferencedProcedureHealthView. The referenced procedure health view.
          */ 
        std::shared_ptr<mtp::ProcedureHealthView> ReferencedProcedureHealthView;
        
        /**
          * @brief Association list RequiredEquipments. The list of required equipment at runtime of the procedure.
          */ 
        std::vector<std::shared_ptr<mtp::DataAssembly>> RequiredEquipments;
        /**
          * @brief Association list ReportValues. The list of corresponding report values.
          */ 
        std::vector<std::shared_ptr<mtp::ReportValue>> ReportValues;
        /**
          * @brief Association list ProcedureParameters. The list of corresponding procedure parameters.
          */ 
        std::vector<std::shared_ptr<mtp::ProcedureParameter>> ProcedureParameters;
        /**
          * @brief Association list Classifications. The list of function classifications describing the procedure.
          */ 
        std::vector<std::shared_ptr<mtp::FunctionClassification>> Classifications;
        /**
          * @brief Association list ProcessValueIns. The list of corresponding process value inputs.
          */ 
        std::vector<std::shared_ptr<mtp::ProcessValueIn>> ProcessValueIns;
        /**
          * @brief Association list ProcessValueOuts. The list of corresponding process value outputs.
          */ 
        std::vector<std::shared_ptr<mtp::ProcessValueOut>> ProcessValueOuts;
    
    protected:
        Procedure( 
            const std::string& Name, 
            const bool& IsSelfCompleting, 
            const std::uint32_t& ProcedureId, 
            std::shared_ptr<mtp::ProcedureHealthView> ReferencedProcedureHealthView
        ) : mtp::LinkedObject(), Name(Name), IsSelfCompleting(IsSelfCompleting), ProcedureId(ProcedureId), ReferencedProcedureHealthView(ReferencedProcedureHealthView)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see Procedure destructor for additional functionality. 
          */
        virtual ~Procedure() 
        {

            // empty our lists of associations
            RequiredEquipments.clear();
            ReportValues.clear();
            ProcedureParameters.clear();
            Classifications.clear();
            ProcessValueIns.clear();
            ProcessValueOuts.clear();
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::Procedure;
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

        /* Get-/Setters for simple attribute IsSelfCompleting */
        virtual void setIsSelfCompleting(const bool& IsSelfCompleting) 
        { 
            this->IsSelfCompleting = IsSelfCompleting; 
            return;
        };
        virtual bool getIsSelfCompleting() const
        { 
            return this->IsSelfCompleting; 
        };

        /* Get-/Setters for simple attribute ProcedureId */
        virtual void setProcedureId(const std::uint32_t& ProcedureId) 
        { 
            this->ProcedureId = ProcedureId; 
            return;
        };
        virtual std::uint32_t getProcedureId() const
        { 
            return this->ProcedureId; 
        };


        /* Get-/Setters for association attribute ReferencedProcedureHealthView */
        virtual void setReferencedProcedureHealthView(std::shared_ptr<mtp::ProcedureHealthView>& ReferencedProcedureHealthView) 
        { 
            this->ReferencedProcedureHealthView = ReferencedProcedureHealthView; 
            return;
        };
        virtual std::shared_ptr<mtp::ProcedureHealthView> getReferencedProcedureHealthView() const
        { 
            return this->ReferencedProcedureHealthView; 
        };


        /* Get-/Setters for Associative list RequiredEquipments */
        /**
         * @brief Return the number of elements in the association list
         */
        virtual size_t getRequiredEquipmentCount() const
        {
            return this->RequiredEquipments.size();
        };
        /**
         * @return the associative list item by identifier; return NULL if the item was not found.
         */
        virtual std::shared_ptr<mtp::DataAssembly> getRequiredEquipmentByID(const size_t id) const
        { 
            if (id >= this->RequiredEquipments.size()) 
            {
                return nullptr;
            }
            return this->RequiredEquipments[id];
        };
        /**
         * @brief Add a new element to the back of the association list
         * @returns the position of the added element in the list of associations. 
         */
        virtual size_t addRequiredEquipment(std::shared_ptr<mtp::DataAssembly>& RequiredEquipment) 
        { 
            // FIXME: Needs to check the allowable multiplicity of the association!
            this->RequiredEquipments.push_back(RequiredEquipment);
            return this->RequiredEquipments.size()-1;
        };
        /**
         * @brief Remove a given association by providing its id/position in the list of associations.
         * @returns true if the object was erased; false otherwise.
         */
        virtual bool removeRequiredEquipmentByPos(const size_t pos)  
        { 
            // FIXME: Needs to check the allowable multiplicity of the association! In particular 1..1 and 1..*
            size_t i = 0;
            for(auto it = this->RequiredEquipments.begin(); it != this->RequiredEquipments.end(); it++) {
                if (i == pos) { 
                    this->RequiredEquipments.erase(it);
                    return true;
                }
            }
            return false;
        };

        /* Get-/Setters for Associative list ReportValues */
        /**
         * @brief Return the number of elements in the association list
         */
        virtual size_t getReportValueCount() const
        {
            return this->ReportValues.size();
        };
        /**
         * @return the associative list item by identifier; return NULL if the item was not found.
         */
        virtual std::shared_ptr<mtp::ReportValue> getReportValueByID(const size_t id) const
        { 
            if (id >= this->ReportValues.size()) 
            {
                return nullptr;
            }
            return this->ReportValues[id];
        };
        /**
         * @brief Add a new element to the back of the association list
         * @returns the position of the added element in the list of associations. 
         */
        virtual size_t addReportValue(std::shared_ptr<mtp::ReportValue>& ReportValue) 
        { 
            // FIXME: Needs to check the allowable multiplicity of the association!
            this->ReportValues.push_back(ReportValue);
            return this->ReportValues.size()-1;
        };
        /**
         * @brief Remove a given association by providing its id/position in the list of associations.
         * @returns true if the object was erased; false otherwise.
         */
        virtual bool removeReportValueByPos(const size_t pos)  
        { 
            // FIXME: Needs to check the allowable multiplicity of the association! In particular 1..1 and 1..*
            size_t i = 0;
            for(auto it = this->ReportValues.begin(); it != this->ReportValues.end(); it++) {
                if (i == pos) { 
                    this->ReportValues.erase(it);
                    return true;
                }
            }
            return false;
        };

        /* Get-/Setters for Associative list ProcedureParameters */
        /**
         * @brief Return the number of elements in the association list
         */
        virtual size_t getProcedureParameterCount() const
        {
            return this->ProcedureParameters.size();
        };
        /**
         * @return the associative list item by identifier; return NULL if the item was not found.
         */
        virtual std::shared_ptr<mtp::ProcedureParameter> getProcedureParameterByID(const size_t id) const
        { 
            if (id >= this->ProcedureParameters.size()) 
            {
                return nullptr;
            }
            return this->ProcedureParameters[id];
        };
        /**
         * @brief Add a new element to the back of the association list
         * @returns the position of the added element in the list of associations. 
         */
        virtual size_t addProcedureParameter(std::shared_ptr<mtp::ProcedureParameter>& ProcedureParameter) 
        { 
            // FIXME: Needs to check the allowable multiplicity of the association!
            this->ProcedureParameters.push_back(ProcedureParameter);
            return this->ProcedureParameters.size()-1;
        };
        /**
         * @brief Remove a given association by providing its id/position in the list of associations.
         * @returns true if the object was erased; false otherwise.
         */
        virtual bool removeProcedureParameterByPos(const size_t pos)  
        { 
            // FIXME: Needs to check the allowable multiplicity of the association! In particular 1..1 and 1..*
            size_t i = 0;
            for(auto it = this->ProcedureParameters.begin(); it != this->ProcedureParameters.end(); it++) {
                if (i == pos) { 
                    this->ProcedureParameters.erase(it);
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

        /* Get-/Setters for Associative list ProcessValueIns */
        /**
         * @brief Return the number of elements in the association list
         */
        virtual size_t getProcessValueInCount() const
        {
            return this->ProcessValueIns.size();
        };
        /**
         * @return the associative list item by identifier; return NULL if the item was not found.
         */
        virtual std::shared_ptr<mtp::ProcessValueIn> getProcessValueInByID(const size_t id) const
        { 
            if (id >= this->ProcessValueIns.size()) 
            {
                return nullptr;
            }
            return this->ProcessValueIns[id];
        };
        /**
         * @brief Add a new element to the back of the association list
         * @returns the position of the added element in the list of associations. 
         */
        virtual size_t addProcessValueIn(std::shared_ptr<mtp::ProcessValueIn>& ProcessValueIn) 
        { 
            // FIXME: Needs to check the allowable multiplicity of the association!
            this->ProcessValueIns.push_back(ProcessValueIn);
            return this->ProcessValueIns.size()-1;
        };
        /**
         * @brief Remove a given association by providing its id/position in the list of associations.
         * @returns true if the object was erased; false otherwise.
         */
        virtual bool removeProcessValueInByPos(const size_t pos)  
        { 
            // FIXME: Needs to check the allowable multiplicity of the association! In particular 1..1 and 1..*
            size_t i = 0;
            for(auto it = this->ProcessValueIns.begin(); it != this->ProcessValueIns.end(); it++) {
                if (i == pos) { 
                    this->ProcessValueIns.erase(it);
                    return true;
                }
            }
            return false;
        };

        /* Get-/Setters for Associative list ProcessValueOuts */
        /**
         * @brief Return the number of elements in the association list
         */
        virtual size_t getProcessValueOutCount() const
        {
            return this->ProcessValueOuts.size();
        };
        /**
         * @return the associative list item by identifier; return NULL if the item was not found.
         */
        virtual std::shared_ptr<mtp::ProcessValueOut> getProcessValueOutByID(const size_t id) const
        { 
            if (id >= this->ProcessValueOuts.size()) 
            {
                return nullptr;
            }
            return this->ProcessValueOuts[id];
        };
        /**
         * @brief Add a new element to the back of the association list
         * @returns the position of the added element in the list of associations. 
         */
        virtual size_t addProcessValueOut(std::shared_ptr<mtp::ProcessValueOut>& ProcessValueOut) 
        { 
            // FIXME: Needs to check the allowable multiplicity of the association!
            this->ProcessValueOuts.push_back(ProcessValueOut);
            return this->ProcessValueOuts.size()-1;
        };
        /**
         * @brief Remove a given association by providing its id/position in the list of associations.
         * @returns true if the object was erased; false otherwise.
         */
        virtual bool removeProcessValueOutByPos(const size_t pos)  
        { 
            // FIXME: Needs to check the allowable multiplicity of the association! In particular 1..1 and 1..*
            size_t i = 0;
            for(auto it = this->ProcessValueOuts.begin(); it != this->ProcessValueOuts.end(); it++) {
                if (i == pos) { 
                    this->ProcessValueOuts.erase(it);
                    return true;
                }
            }
            return false;
        };
    };   
}

#endif // defined HAVE_PROCEDURE_BASE_HPP