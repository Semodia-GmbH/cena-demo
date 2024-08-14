/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file DataAssembly.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_DATA_ASSEMBLY_BASE_HPP
#define HAVE_DATA_ASSEMBLY_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/LinkedObject.hpp"

#include <string>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class InstanceReferences;
    class ObjectItem;
    class Timestamped;
    
    class DataAssembly;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class DataAssembly
     * @brief DataAssembly defines an element of the InstanceList.. This is the base class generated based on the Model Type Package Specification.
     */
    class DataAssembly : public mtp::LinkedObject
    {
    private:
        /**
          * @brief Simple attribute TagName. The TagName describes the name of the entity.
          */ 
        std::string TagName;
        /**
          * @brief Simple attribute TagDescription. The TagDescription provides a description of the entity.
          */ 
        std::string TagDescription;
        
        /**
          * @brief Association References. Lists all references from other objects to the data assembly instance.
          */ 
        std::shared_ptr<mtp::InstanceReferences> References;
        /**
          * @brief Association ObjectItem. Represents the related object within the server, which is to organize composites of methods or data items. If the included node item is not set the object item will be not added to the server.
          */ 
        std::shared_ptr<mtp::ObjectItem> ObjectItem;
        /**
          * @brief Association Timestamped. Interface extension for the last processing time stamp.
          */ 
        std::shared_ptr<mtp::Timestamped> Timestamped;
    
    protected:
        DataAssembly( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped
        ) : mtp::LinkedObject(), TagName(TagName), TagDescription(TagDescription), References(References), ObjectItem(ObjectItem), Timestamped(Timestamped)
        { 
            return;
        };
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see DataAssembly destructor for additional functionality. 
          */
        virtual ~DataAssembly() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::DataAssembly;
        }
        
         
        /* Get-/Setters for simple attribute TagName */
        virtual void setTagName(const std::string& TagName) 
        { 
            this->TagName = TagName; 
            return;
        };
        virtual std::string getTagName() const
        { 
            return this->TagName; 
        };

        /* Get-/Setters for simple attribute TagDescription */
        virtual void setTagDescription(const std::string& TagDescription) 
        { 
            this->TagDescription = TagDescription; 
            return;
        };
        virtual std::string getTagDescription() const
        { 
            return this->TagDescription; 
        };


        /* Get-/Setters for association attribute References */
        virtual void setReferences(std::shared_ptr<mtp::InstanceReferences>& References) 
        { 
            this->References = References; 
            return;
        };
        virtual std::shared_ptr<mtp::InstanceReferences> getReferences() const
        { 
            return this->References; 
        };

        /* Get-/Setters for association attribute ObjectItem */
        virtual void setObjectItem(std::shared_ptr<mtp::ObjectItem>& ObjectItem) 
        { 
            this->ObjectItem = ObjectItem; 
            return;
        };
        virtual std::shared_ptr<mtp::ObjectItem> getObjectItem() const
        { 
            return this->ObjectItem; 
        };

        /* Get-/Setters for association attribute Timestamped */
        virtual void setTimestamped(std::shared_ptr<mtp::Timestamped>& Timestamped) 
        { 
            this->Timestamped = Timestamped; 
            return;
        };
        virtual std::shared_ptr<mtp::Timestamped> getTimestamped() const
        { 
            return this->Timestamped; 
        };

    };   
}

#endif // defined HAVE_DATA_ASSEMBLY_BASE_HPP