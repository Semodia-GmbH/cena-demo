/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file BinView.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_BIN_VIEW_BASE_HPP
#define HAVE_BIN_VIEW_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/IndicatorElement.hpp"

#include "mtp/ReadDataItem.hpp"
#include <string>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    template<typename dt> class ReadDataItem;
    
    class BinView;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class BinView
     * @brief BinView defines a view element of a binary value.. This is the base class generated based on the Model Type Package Specification.
     */
    class BinView : public mtp::IndicatorElement
    {
    private:
        
        /**
          * @brief Generic structure V. V defines the value.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> V;
        /**
          * @brief Generic structure VState0. VState0 defines a text for the false state.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> VState0;
        /**
          * @brief Generic structure VState1. VState1 defines a text for the true state.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> VState1;
    
    protected:
        BinView( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped, 
            std::shared_ptr<mtp::MissedValueFlag> MissedValueFlag, 
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC, 
            std::shared_ptr<mtp::ReadDataItem<bool>> V, 
            std::shared_ptr<mtp::ReadDataItem<std::string>> VState0, 
            std::shared_ptr<mtp::ReadDataItem<std::string>> VState1
        ) : mtp::IndicatorElement(TagName, TagDescription, References, ObjectItem, Timestamped, MissedValueFlag, WQC), V(V), VState0(VState0), VState1(VState1)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see BinView destructor for additional functionality. 
          */
        virtual ~BinView() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::BinView;
        }
        

        /* Get-/Setters for Generic Attribute Structure V */
        virtual void setV(std::shared_ptr<mtp::ReadDataItem<bool>>& V) 
        { 
            this->V = V; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getV() const
        {  
            return this->V; 
        };

        /* Get-/Setters for Generic Attribute Structure VState0 */
        virtual void setVState0(std::shared_ptr<mtp::ReadDataItem<std::string>>& VState0) 
        { 
            this->VState0 = VState0; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getVState0() const
        {  
            return this->VState0; 
        };

        /* Get-/Setters for Generic Attribute Structure VState1 */
        virtual void setVState1(std::shared_ptr<mtp::ReadDataItem<std::string>>& VState1) 
        { 
            this->VState1 = VState1; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getVState1() const
        {  
            return this->VState1; 
        };
    };   
}

#endif // defined HAVE_BIN_VIEW_BASE_HPP