/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ServiceOperationModeBaseFunction.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_OPERATION_MODE_BASE_FUNCTION_BASE_HPP
#define HAVE_SERVICE_OPERATION_MODE_BASE_FUNCTION_BASE_HPP

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
    
    class ServiceOperationModeBaseFunction;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ServiceOperationModeBaseFunction
     * @brief The ServiceOperationMode defines the operation mode of the service.. This is the base class generated based on the Model Type Package Specification.
     */
    class ServiceOperationModeBaseFunction : public mtp::BaseFunction
    {
    private:
        
        /**
          * @brief Generic structure StateChannel. StateChannel defines the active OperationMode interaction channel. If the value is 0 the operator switches shall be used, if the value is 1 the automatic switches shall be used.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> StateChannel;
        /**
          * @brief Generic structure StateOffAut. StateOffAut defines to set the OperationMode to Offline by automatic interaction.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> StateOffAut;
        /**
          * @brief Generic structure StateOpAut. StateOpAut defines to set the OperationMode to Operator by automatic interaction.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> StateOpAut;
        /**
          * @brief Generic structure StateAutAut. StateAutAut defines to set the OperationMode to Automatic by automatic interaction.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> StateAutAut;
        /**
          * @brief Generic structure StateOffOp. StateOffOp defines to set the OperationMode to Offline by operator interaction.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> StateOffOp;
        /**
          * @brief Generic structure StateOpOp. StateOpOp defines to set the OperationMode to Operator by operator interaction.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> StateOpOp;
        /**
          * @brief Generic structure StateAutOp. StateAutOp defines to set the OperationMode to Automatic by operator interaction.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> StateAutOp;
        /**
          * @brief Generic structure StateOpAct. StateOpAct defines that the active OperationMode is Operator.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> StateOpAct;
        /**
          * @brief Generic structure StateAutAct. StateAutAct defines that the active OperationMode is Automatic.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> StateAutAct;
        /**
          * @brief Generic structure StateOffAct. StateOffAct defines that the active OperationMode is Offline.
          */
        std::shared_ptr<mtp::ReadDataItem<bool>> StateOffAct;
    
    protected:
        ServiceOperationModeBaseFunction( 
            std::shared_ptr<mtp::ReadDataItem<bool>> StateChannel, 
            std::shared_ptr<mtp::ReadDataItem<bool>> StateOffAut, 
            std::shared_ptr<mtp::ReadDataItem<bool>> StateOpAut, 
            std::shared_ptr<mtp::ReadDataItem<bool>> StateAutAut, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> StateOffOp, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> StateOpOp, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> StateAutOp, 
            std::shared_ptr<mtp::ReadDataItem<bool>> StateOpAct, 
            std::shared_ptr<mtp::ReadDataItem<bool>> StateAutAct, 
            std::shared_ptr<mtp::ReadDataItem<bool>> StateOffAct
        ) : mtp::BaseFunction(), StateChannel(StateChannel), StateOffAut(StateOffAut), StateOpAut(StateOpAut), StateAutAut(StateAutAut), StateOffOp(StateOffOp), StateOpOp(StateOpOp), StateAutOp(StateAutOp), StateOpAct(StateOpAct), StateAutAct(StateAutAct), StateOffAct(StateOffAct)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ServiceOperationModeBaseFunction destructor for additional functionality. 
          */
        virtual ~ServiceOperationModeBaseFunction() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ServiceOperationModeBaseFunction;
        }
        

        /* Get-/Setters for Generic Attribute Structure StateChannel */
        virtual void setStateChannel(std::shared_ptr<mtp::ReadDataItem<bool>>& StateChannel) 
        { 
            this->StateChannel = StateChannel; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getStateChannel() const
        {  
            return this->StateChannel; 
        };

        /* Get-/Setters for Generic Attribute Structure StateOffAut */
        virtual void setStateOffAut(std::shared_ptr<mtp::ReadDataItem<bool>>& StateOffAut) 
        { 
            this->StateOffAut = StateOffAut; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getStateOffAut() const
        {  
            return this->StateOffAut; 
        };

        /* Get-/Setters for Generic Attribute Structure StateOpAut */
        virtual void setStateOpAut(std::shared_ptr<mtp::ReadDataItem<bool>>& StateOpAut) 
        { 
            this->StateOpAut = StateOpAut; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getStateOpAut() const
        {  
            return this->StateOpAut; 
        };

        /* Get-/Setters for Generic Attribute Structure StateAutAut */
        virtual void setStateAutAut(std::shared_ptr<mtp::ReadDataItem<bool>>& StateAutAut) 
        { 
            this->StateAutAut = StateAutAut; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getStateAutAut() const
        {  
            return this->StateAutAut; 
        };

        /* Get-/Setters for Generic Attribute Structure StateOffOp */
        virtual void setStateOffOp(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& StateOffOp) 
        { 
            this->StateOffOp = StateOffOp; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getStateOffOp() const
        {  
            return this->StateOffOp; 
        };

        /* Get-/Setters for Generic Attribute Structure StateOpOp */
        virtual void setStateOpOp(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& StateOpOp) 
        { 
            this->StateOpOp = StateOpOp; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getStateOpOp() const
        {  
            return this->StateOpOp; 
        };

        /* Get-/Setters for Generic Attribute Structure StateAutOp */
        virtual void setStateAutOp(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& StateAutOp) 
        { 
            this->StateAutOp = StateAutOp; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getStateAutOp() const
        {  
            return this->StateAutOp; 
        };

        /* Get-/Setters for Generic Attribute Structure StateOpAct */
        virtual void setStateOpAct(std::shared_ptr<mtp::ReadDataItem<bool>>& StateOpAct) 
        { 
            this->StateOpAct = StateOpAct; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getStateOpAct() const
        {  
            return this->StateOpAct; 
        };

        /* Get-/Setters for Generic Attribute Structure StateAutAct */
        virtual void setStateAutAct(std::shared_ptr<mtp::ReadDataItem<bool>>& StateAutAct) 
        { 
            this->StateAutAct = StateAutAct; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getStateAutAct() const
        {  
            return this->StateAutAct; 
        };

        /* Get-/Setters for Generic Attribute Structure StateOffAct */
        virtual void setStateOffAct(std::shared_ptr<mtp::ReadDataItem<bool>>& StateOffAct) 
        { 
            this->StateOffAct = StateOffAct; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<bool>> getStateOffAct() const
        {  
            return this->StateOffAct; 
        };
    };   
}

#endif // defined HAVE_SERVICE_OPERATION_MODE_BASE_FUNCTION_BASE_HPP