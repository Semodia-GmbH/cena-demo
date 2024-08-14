/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ApplyBaseFunction.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_APPLY_BASE_FUNCTION_BASE_HPP
#define HAVE_APPLY_BASE_FUNCTION_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/BaseFunction.hpp"

#include "mtp/ReadWriteDataItem.hpp"
#include "mtp/ReadDataItem.hpp"

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    template<typename dt> class ReadWriteDataItem;
    template<typename dt> class ReadDataItem;
    
    class ApplyBaseFunction;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ApplyBaseFunction
     * @brief Base function which provides the apply functionality of values according to part four.. This is the base class generated based on the Model Type Package Specification.
     */
    class ApplyBaseFunction : public mtp::BaseFunction
    {
    private:
        
        /**
          * @brief Generic structure ApplyOp. Value application flag from operator.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> ApplyOp;
        /**
          * @brief Generic structure ApplyInt. Value application flag from internal.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> ApplyInt;
        /**
          * @brief Generic structure ApplyExt. Value application flag from POL.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> ApplyExt;
        /**
          * @brief Generic structure ApplyEn. Flag to signalize if new values can be applied.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> ApplyEn;
    
    protected:
        ApplyBaseFunction( 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> ApplyOp, 
            std::shared_ptr<mtp::ReadDataItem<bool>> ApplyInt, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> ApplyExt, 
            std::shared_ptr<mtp::ReadDataItem<bool>> ApplyEn
        ) : mtp::BaseFunction(), ApplyOp(ApplyOp), ApplyInt(ApplyInt), ApplyExt(ApplyExt), ApplyEn(ApplyEn)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ApplyBaseFunction destructor for additional functionality. 
          */
        virtual ~ApplyBaseFunction() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ApplyBaseFunction;
        }
        

        /* Get-/Setters for Generic Attribute Structure ApplyOp */
        virtual void setApplyOp(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& ApplyOp) 
        { 
            this->ApplyOp = ApplyOp; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getApplyOp() const
        {  
            return this->ApplyOp; 
        };

        /* Get-/Setters for Generic Attribute Structure ApplyInt */
        virtual void setApplyInt(std::shared_ptr<mtp::ReadDataItem<bool>>& ApplyInt) 
        { 
            this->ApplyInt = ApplyInt; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getApplyInt() const
        {  
            return this->ApplyInt; 
        };

        /* Get-/Setters for Generic Attribute Structure ApplyExt */
        virtual void setApplyExt(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& ApplyExt) 
        { 
            this->ApplyExt = ApplyExt; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getApplyExt() const
        {  
            return this->ApplyExt; 
        };

        /* Get-/Setters for Generic Attribute Structure ApplyEn */
        virtual void setApplyEn(std::shared_ptr<mtp::ReadDataItem<bool>>& ApplyEn) 
        { 
            this->ApplyEn = ApplyEn; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getApplyEn() const
        {  
            return this->ApplyEn; 
        };
    };   
}

#endif // defined HAVE_APPLY_BASE_FUNCTION_BASE_HPP