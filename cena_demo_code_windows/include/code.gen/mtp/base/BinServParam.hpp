/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file BinServParam.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_BIN_SERV_PARAM_BASE_HPP
#define HAVE_BIN_SERV_PARAM_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/ParameterElement.hpp"

#include "mtp/ReadWriteDataItem.hpp"
#include "mtp/ReadDataItem.hpp"
#include <string>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    template<typename dt> class ReadWriteDataItem;
    template<typename dt> class ReadDataItem;
    
    class BinServParam;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class BinServParam
     * @brief BinServParam defines a binary service parameter.. This is the base class generated based on the Model Type Package Specification.
     */
    class BinServParam : public mtp::ParameterElement
    {
    private:
        
        /**
          * @brief Generic structure VExt. VExt defines a value of an external source.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> VExt;
        /**
          * @brief Generic structure VOp. VOp defines the value set manually.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> VOp;
        /**
          * @brief Generic structure VInt. VInt defines an internal value.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> VInt;
        /**
          * @brief Generic structure VReq. VReq defines the requested value variable.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> VReq;
        /**
          * @brief Generic structure VOut. VOut defines the current value.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> VOut;
        /**
          * @brief Generic structure VFbk. VFbk defines the processed value, which can be limited.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> VFbk;
        /**
          * @brief Generic structure VState0. VState0 defines a text for the false state.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> VState0;
        /**
          * @brief Generic structure VState1. VState1 defines a text for the true state.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> VState1;
    
    protected:
        BinServParam( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped, 
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC, 
            std::shared_ptr<mtp::ApplyBaseFunction> Apply, 
            std::shared_ptr<mtp::ServiceOperationModeBaseFunction> ServiceOperationMode, 
            std::shared_ptr<mtp::ServiceSourceModeBaseFunction> ServiceSourceMode, 
            std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>> OSLevel, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> Sync, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> VExt, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> VOp, 
            std::shared_ptr<mtp::ReadDataItem<bool>> VInt, 
            std::shared_ptr<mtp::ReadDataItem<bool>> VReq, 
            std::shared_ptr<mtp::ReadDataItem<bool>> VOut, 
            std::shared_ptr<mtp::ReadDataItem<bool>> VFbk, 
            std::shared_ptr<mtp::ReadDataItem<std::string>> VState0, 
            std::shared_ptr<mtp::ReadDataItem<std::string>> VState1
        ) : mtp::ParameterElement(TagName, TagDescription, References, ObjectItem, Timestamped, WQC, Apply, ServiceOperationMode, ServiceSourceMode, OSLevel, Sync), VExt(VExt), VOp(VOp), VInt(VInt), VReq(VReq), VOut(VOut), VFbk(VFbk), VState0(VState0), VState1(VState1)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see BinServParam destructor for additional functionality. 
          */
        virtual ~BinServParam() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::BinServParam;
        }
        

        /* Get-/Setters for Generic Attribute Structure VExt */
        virtual void setVExt(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& VExt) 
        { 
            this->VExt = VExt; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getVExt() const
        {  
            return this->VExt; 
        };

        /* Get-/Setters for Generic Attribute Structure VOp */
        virtual void setVOp(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& VOp) 
        { 
            this->VOp = VOp; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getVOp() const
        {  
            return this->VOp; 
        };

        /* Get-/Setters for Generic Attribute Structure VInt */
        virtual void setVInt(std::shared_ptr<mtp::ReadDataItem<bool>>& VInt) 
        { 
            this->VInt = VInt; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getVInt() const
        {  
            return this->VInt; 
        };

        /* Get-/Setters for Generic Attribute Structure VReq */
        virtual void setVReq(std::shared_ptr<mtp::ReadDataItem<bool>>& VReq) 
        { 
            this->VReq = VReq; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getVReq() const
        {  
            return this->VReq; 
        };

        /* Get-/Setters for Generic Attribute Structure VOut */
        virtual void setVOut(std::shared_ptr<mtp::ReadDataItem<bool>>& VOut) 
        { 
            this->VOut = VOut; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getVOut() const
        {  
            return this->VOut; 
        };

        /* Get-/Setters for Generic Attribute Structure VFbk */
        virtual void setVFbk(std::shared_ptr<mtp::ReadDataItem<bool>>& VFbk) 
        { 
            this->VFbk = VFbk; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getVFbk() const
        {  
            return this->VFbk; 
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

#endif // defined HAVE_BIN_SERV_PARAM_BASE_HPP