/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ProcedureHealthView.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PROCEDURE_HEALTH_VIEW_BASE_HPP
#define HAVE_PROCEDURE_HEALTH_VIEW_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/ServiceElement.hpp"

#include "mtp/ReadDataItem.hpp"
#include <cstdint>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    template<typename dt> class ReadDataItem;
    
    class ProcedureHealthView;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ProcedureHealthView
     * @brief Provides the service procedure health information.. This is the base class generated based on the Model Type Package Specification.
     */
    class ProcedureHealthView : public mtp::ServiceElement
    {
    private:
        
        /**
          * @brief Generic structure CommandInfo. Describes the possible commands for the corresponding procedure.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> CommandInfo;
    
    protected:
        ProcedureHealthView( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped, 
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC, 
            std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> CommandInfo
        ) : mtp::ServiceElement(TagName, TagDescription, References, ObjectItem, Timestamped, WQC), CommandInfo(CommandInfo)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ProcedureHealthView destructor for additional functionality. 
          */
        virtual ~ProcedureHealthView() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ProcedureHealthView;
        }
        

        /* Get-/Setters for Generic Attribute Structure CommandInfo */
        virtual void setCommandInfo(std::shared_ptr<mtp::ReadDataItem<std::uint32_t>>& CommandInfo) 
        { 
            this->CommandInfo = CommandInfo; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> getCommandInfo() const
        {  
            return this->CommandInfo; 
        };
    };   
}

#endif // defined HAVE_PROCEDURE_HEALTH_VIEW_BASE_HPP