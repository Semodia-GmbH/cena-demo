/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ServiceSourceModeBaseFunction.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_SOURCE_MODE_BASE_FUNCTION_BASE_HPP
#define HAVE_SERVICE_SOURCE_MODE_BASE_FUNCTION_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/BaseFunction.hpp"

#include "mtp/ReadDataItem.hpp"
#include "mtp/ReadWriteDataItem.hpp"

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    template<typename dt> class ReadDataItem;
    template<typename dt> class ReadWriteDataItem;
    
    class ServiceSourceModeBaseFunction;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ServiceSourceModeBaseFunction
     * @brief ServiceSourceMode defines the SourceMode of the service.. This is the base class generated based on the Model Type Package Specification.
     */
    class ServiceSourceModeBaseFunction : public mtp::BaseFunction
    {
    private:
        
        /**
          * @brief Generic structure SrcChannel. SrcChannel defines the active SourceMode interaction channel. If the value is 0 the operator switches shall be used, if the value is 1 the automatic switches shall be used.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> SrcChannel;
        /**
          * @brief Generic structure SrcExtAut. SrcExtAut defines to set the SourceMode to External by automatic interaction.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> SrcExtAut;
        /**
          * @brief Generic structure SrcIntAut. SrcIntAut defines to set the SourceMode to Internal by automatic interaction.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> SrcIntAut;
        /**
          * @brief Generic structure SrcIntOp. SrcIntOp defines to set the SourceMode to Internal by operator interaction.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> SrcIntOp;
        /**
          * @brief Generic structure SrcExtOp. SrcExtOp defines to set the SourceMode to External by operator interaction.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> SrcExtOp;
        /**
          * @brief Generic structure SrcIntAct. SrcIntAct defines that the active SourceMode is Internal.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> SrcIntAct;
        /**
          * @brief Generic structure SrcExtAct. SrcExtAct defines that the active SourceMode is External.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> SrcExtAct;
    
    protected:
        ServiceSourceModeBaseFunction( 
            std::shared_ptr<mtp::ReadDataItem<bool>> SrcChannel, 
            std::shared_ptr<mtp::ReadDataItem<bool>> SrcExtAut, 
            std::shared_ptr<mtp::ReadDataItem<bool>> SrcIntAut, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> SrcIntOp, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> SrcExtOp, 
            std::shared_ptr<mtp::ReadDataItem<bool>> SrcIntAct, 
            std::shared_ptr<mtp::ReadDataItem<bool>> SrcExtAct
        ) : mtp::BaseFunction(), SrcChannel(SrcChannel), SrcExtAut(SrcExtAut), SrcIntAut(SrcIntAut), SrcIntOp(SrcIntOp), SrcExtOp(SrcExtOp), SrcIntAct(SrcIntAct), SrcExtAct(SrcExtAct)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ServiceSourceModeBaseFunction destructor for additional functionality. 
          */
        virtual ~ServiceSourceModeBaseFunction() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ServiceSourceModeBaseFunction;
        }
        

        /* Get-/Setters for Generic Attribute Structure SrcChannel */
        virtual void setSrcChannel(std::shared_ptr<mtp::ReadDataItem<bool>>& SrcChannel) 
        { 
            this->SrcChannel = SrcChannel; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getSrcChannel() const
        {  
            return this->SrcChannel; 
        };

        /* Get-/Setters for Generic Attribute Structure SrcExtAut */
        virtual void setSrcExtAut(std::shared_ptr<mtp::ReadDataItem<bool>>& SrcExtAut) 
        { 
            this->SrcExtAut = SrcExtAut; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getSrcExtAut() const
        {  
            return this->SrcExtAut; 
        };

        /* Get-/Setters for Generic Attribute Structure SrcIntAut */
        virtual void setSrcIntAut(std::shared_ptr<mtp::ReadDataItem<bool>>& SrcIntAut) 
        { 
            this->SrcIntAut = SrcIntAut; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getSrcIntAut() const
        {  
            return this->SrcIntAut; 
        };

        /* Get-/Setters for Generic Attribute Structure SrcIntOp */
        virtual void setSrcIntOp(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& SrcIntOp) 
        { 
            this->SrcIntOp = SrcIntOp; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getSrcIntOp() const
        {  
            return this->SrcIntOp; 
        };

        /* Get-/Setters for Generic Attribute Structure SrcExtOp */
        virtual void setSrcExtOp(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& SrcExtOp) 
        { 
            this->SrcExtOp = SrcExtOp; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getSrcExtOp() const
        {  
            return this->SrcExtOp; 
        };

        /* Get-/Setters for Generic Attribute Structure SrcIntAct */
        virtual void setSrcIntAct(std::shared_ptr<mtp::ReadDataItem<bool>>& SrcIntAct) 
        { 
            this->SrcIntAct = SrcIntAct; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getSrcIntAct() const
        {  
            return this->SrcIntAct; 
        };

        /* Get-/Setters for Generic Attribute Structure SrcExtAct */
        virtual void setSrcExtAct(std::shared_ptr<mtp::ReadDataItem<bool>>& SrcExtAct) 
        { 
            this->SrcExtAct = SrcExtAct; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getSrcExtAct() const
        {  
            return this->SrcExtAct; 
        };
    };   
}

#endif // defined HAVE_SERVICE_SOURCE_MODE_BASE_FUNCTION_BASE_HPP