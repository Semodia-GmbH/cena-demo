/************************************************************************/
/* This file is *generated* - manual modifications will be overwritten. */
/* Removing or modifying this comment line will *NOT* protect this file */
/************************************************************************/

/**
 * @file ServiceControl.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_CONTROL_BASE_HPP
#define HAVE_SERVICE_CONTROL_BASE_HPP

#pragma once

#include <cstdint>
#include <memory>
#include "mtp/MtpTypeIndex.hpp"

// parent class
#include "mtp/ServiceElement.hpp"

#include "mtp/ReadWriteDataItem.hpp"
#include <cstdint>
#include "mtp/ReadDataItem.hpp"
#include <string>

// Early-definition of implementation class in case this base class uses circular references in its associative attributes.
namespace semodia::controlengine::native::model::mtp 
{
    class ServiceOperationModeBaseFunction;
    class ServiceSourceModeBaseFunction;
    class ApplyBaseFunction;
    template<typename dt> class ReadWriteDataItem;
    template<typename dt> class ReadDataItem;
    
    class ServiceControl;
}

namespace semodia::controlengine::native::model::mtp::base 
{
    /**
     * @class ServiceControl
     * @brief ServiceControl defines a service.. This is the base class generated based on the Model Type Package Specification.
     */
    class ServiceControl : public mtp::ServiceElement
    {
    private:
        
        /**
          * @brief Association ServiceOperationMode. The ServiceOperationMode defines the operation mode of the service.
          */ 
        std::shared_ptr<mtp::ServiceOperationModeBaseFunction> ServiceOperationMode;
        /**
          * @brief Association ServiceSourceMode. ServiceSourceMode defines the SourceMode of the service.
          */ 
        std::shared_ptr<mtp::ServiceSourceModeBaseFunction> ServiceSourceMode;
        /**
          * @brief Association ProcParamApply. Provides the apply functionality for all synchronized procedure parameters.
          */ 
        std::shared_ptr<mtp::ApplyBaseFunction> ProcParamApply;
        /**
          * @brief Association ConfigParamApply. Provides the apply functionality for all synchronized configuration parameters.
          */ 
        std::shared_ptr<mtp::ApplyBaseFunction> ConfigParamApply;
        
        /**
          * @brief Generic structure OSLevel. OSLevel defines the current active operator station to send commands. OSLevel of zero defines a local panel.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>> OSLevel;
        /**
          * @brief Generic structure CommandOp. CommandOp defines the command by the operator.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> CommandOp;
        /**
          * @brief Generic structure CommandInt. CommandInt defines the command by automatic-internal.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> CommandInt;
        /**
          * @brief Generic structure CommandExt. CommandExt defines the command by automatic-external.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> CommandExt;
        /**
          * @brief Generic structure ProcedureOp. ProcedureOp defines the choice of the procedure by the operator.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> ProcedureOp;
        /**
          * @brief Generic structure ProcedureInt. ProcedureInt defines the choice of the procedure by PEA-internal automatic.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> ProcedureInt;
        /**
          * @brief Generic structure ProcedureExt. ProcedureExt defines the choice of the procedure by PEA-external (e.g. POL) automatic.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> ProcedureExt;
        /**
          * @brief Generic structure StateCur. StateCur defines the current active state of a service.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> StateCur;
        /**
          * @brief Generic structure CommandEn. CommandEn defines a variable to enable commands of a service.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> CommandEn;
        /**
          * @brief Generic structure ProcedureCur. ProcedureCur defines the current active procedure.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> ProcedureCur;
        /**
          * @brief Generic structure ProcedureReq. ProcedureReq defines the requested procedure.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> ProcedureReq;
        /**
          * @brief Generic structure PosTextID. PostTextID defines the active ID of corresponding texts to give additional information about the current state of the service.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> PosTextID;
        /**
          * @brief Generic structure InteractQuestionID. InteractQuestionID defines the active ID of a question for the operator.
          */
        std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> InteractQuestionID;
        /**
          * @brief Generic structure InteractAnswerID. InteractAnswerID defines the ID of the answer chosen by the operator.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> InteractAnswerID;
        /**
          * @brief Generic structure InteractAddInfo. Defines additional information for the interaction.
          */
        std::shared_ptr<mtp::ReadDataItem<std::string>> InteractAddInfo;
        /**
          * @brief Generic structure ReportValueFreeze. Freeze flag for all report values of the service.
          */
        std::shared_ptr<mtp::ReadWriteDataItem<bool>> ReportValueFreeze;
    
    protected:
        ServiceControl( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped, 
            std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC, 
            std::shared_ptr<mtp::ServiceOperationModeBaseFunction> ServiceOperationMode, 
            std::shared_ptr<mtp::ServiceSourceModeBaseFunction> ServiceSourceMode, 
            std::shared_ptr<mtp::ApplyBaseFunction> ProcParamApply, 
            std::shared_ptr<mtp::ApplyBaseFunction> ConfigParamApply, 
            std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>> OSLevel, 
            std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> CommandOp, 
            std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> CommandInt, 
            std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> CommandExt, 
            std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> ProcedureOp, 
            std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> ProcedureInt, 
            std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> ProcedureExt, 
            std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> StateCur, 
            std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> CommandEn, 
            std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> ProcedureCur, 
            std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> ProcedureReq, 
            std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> PosTextID, 
            std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> InteractQuestionID, 
            std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> InteractAnswerID, 
            std::shared_ptr<mtp::ReadDataItem<std::string>> InteractAddInfo, 
            std::shared_ptr<mtp::ReadWriteDataItem<bool>> ReportValueFreeze
        ) : mtp::ServiceElement(TagName, TagDescription, References, ObjectItem, Timestamped, WQC), ServiceOperationMode(ServiceOperationMode), ServiceSourceMode(ServiceSourceMode), ProcParamApply(ProcParamApply), ConfigParamApply(ConfigParamApply), OSLevel(OSLevel), CommandOp(CommandOp), CommandInt(CommandInt), CommandExt(CommandExt), ProcedureOp(ProcedureOp), ProcedureInt(ProcedureInt), ProcedureExt(ProcedureExt), StateCur(StateCur), CommandEn(CommandEn), ProcedureCur(ProcedureCur), ProcedureReq(ProcedureReq), PosTextID(PosTextID), InteractQuestionID(InteractQuestionID), InteractAnswerID(InteractAnswerID), InteractAddInfo(InteractAddInfo), ReportValueFreeze(ReportValueFreeze)
        { 
            return;
        };
        
        
        
    public:
        /**
          * @brief Base class destructor: Will delete all list items, explicitly delete pointers and set all pointers to `nullptr`; 
          *        @see ServiceControl destructor for additional functionality. 
          */
        virtual ~ServiceControl() 
        {
            
            return;        
        };
        
        /**
          * @see mtp::SemanticModelEntity::getTypeId()
          */
        virtual mtp::MtpTypeIndex getTypeId() const override
        {
            return mtp::MtpTypeIndex::ServiceControl;
        }
        

        /* Get-/Setters for association attribute ServiceOperationMode */
        virtual void setServiceOperationMode(std::shared_ptr<mtp::ServiceOperationModeBaseFunction>& ServiceOperationMode) 
        { 
            this->ServiceOperationMode = ServiceOperationMode; 
            return;
        };
        virtual std::shared_ptr<mtp::ServiceOperationModeBaseFunction> getServiceOperationMode() const
        { 
            return this->ServiceOperationMode; 
        };

        /* Get-/Setters for association attribute ServiceSourceMode */
        virtual void setServiceSourceMode(std::shared_ptr<mtp::ServiceSourceModeBaseFunction>& ServiceSourceMode) 
        { 
            this->ServiceSourceMode = ServiceSourceMode; 
            return;
        };
        virtual std::shared_ptr<mtp::ServiceSourceModeBaseFunction> getServiceSourceMode() const
        { 
            return this->ServiceSourceMode; 
        };

        /* Get-/Setters for association attribute ProcParamApply */
        virtual void setProcParamApply(std::shared_ptr<mtp::ApplyBaseFunction>& ProcParamApply) 
        { 
            this->ProcParamApply = ProcParamApply; 
            return;
        };
        virtual std::shared_ptr<mtp::ApplyBaseFunction> getProcParamApply() const
        { 
            return this->ProcParamApply; 
        };

        /* Get-/Setters for association attribute ConfigParamApply */
        virtual void setConfigParamApply(std::shared_ptr<mtp::ApplyBaseFunction>& ConfigParamApply) 
        { 
            this->ConfigParamApply = ConfigParamApply; 
            return;
        };
        virtual std::shared_ptr<mtp::ApplyBaseFunction> getConfigParamApply() const
        { 
            return this->ConfigParamApply; 
        };


        /* Get-/Setters for Generic Attribute Structure OSLevel */
        virtual void setOSLevel(std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>>& OSLevel) 
        { 
            this->OSLevel = OSLevel; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<std::uint8_t>> getOSLevel() const
        {  
            return this->OSLevel; 
        };

        /* Get-/Setters for Generic Attribute Structure CommandOp */
        virtual void setCommandOp(std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>>& CommandOp) 
        { 
            this->CommandOp = CommandOp; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> getCommandOp() const
        {  
            return this->CommandOp; 
        };

        /* Get-/Setters for Generic Attribute Structure CommandInt */
        virtual void setCommandInt(std::shared_ptr<mtp::ReadDataItem<std::uint32_t>>& CommandInt) 
        { 
            this->CommandInt = CommandInt; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> getCommandInt() const
        {  
            return this->CommandInt; 
        };

        /* Get-/Setters for Generic Attribute Structure CommandExt */
        virtual void setCommandExt(std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>>& CommandExt) 
        { 
            this->CommandExt = CommandExt; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> getCommandExt() const
        {  
            return this->CommandExt; 
        };

        /* Get-/Setters for Generic Attribute Structure ProcedureOp */
        virtual void setProcedureOp(std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>>& ProcedureOp) 
        { 
            this->ProcedureOp = ProcedureOp; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> getProcedureOp() const
        {  
            return this->ProcedureOp; 
        };

        /* Get-/Setters for Generic Attribute Structure ProcedureInt */
        virtual void setProcedureInt(std::shared_ptr<mtp::ReadDataItem<std::uint32_t>>& ProcedureInt) 
        { 
            this->ProcedureInt = ProcedureInt; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> getProcedureInt() const
        {  
            return this->ProcedureInt; 
        };

        /* Get-/Setters for Generic Attribute Structure ProcedureExt */
        virtual void setProcedureExt(std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>>& ProcedureExt) 
        { 
            this->ProcedureExt = ProcedureExt; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> getProcedureExt() const
        {  
            return this->ProcedureExt; 
        };

        /* Get-/Setters for Generic Attribute Structure StateCur */
        virtual void setStateCur(std::shared_ptr<mtp::ReadDataItem<std::uint32_t>>& StateCur) 
        { 
            this->StateCur = StateCur; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> getStateCur() const
        {  
            return this->StateCur; 
        };

        /* Get-/Setters for Generic Attribute Structure CommandEn */
        virtual void setCommandEn(std::shared_ptr<mtp::ReadDataItem<std::uint32_t>>& CommandEn) 
        { 
            this->CommandEn = CommandEn; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> getCommandEn() const
        {  
            return this->CommandEn; 
        };

        /* Get-/Setters for Generic Attribute Structure ProcedureCur */
        virtual void setProcedureCur(std::shared_ptr<mtp::ReadDataItem<std::uint32_t>>& ProcedureCur) 
        { 
            this->ProcedureCur = ProcedureCur; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> getProcedureCur() const
        {  
            return this->ProcedureCur; 
        };

        /* Get-/Setters for Generic Attribute Structure ProcedureReq */
        virtual void setProcedureReq(std::shared_ptr<mtp::ReadDataItem<std::uint32_t>>& ProcedureReq) 
        { 
            this->ProcedureReq = ProcedureReq; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> getProcedureReq() const
        {  
            return this->ProcedureReq; 
        };

        /* Get-/Setters for Generic Attribute Structure PosTextID */
        virtual void setPosTextID(std::shared_ptr<mtp::ReadDataItem<std::uint32_t>>& PosTextID) 
        { 
            this->PosTextID = PosTextID; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> getPosTextID() const
        {  
            return this->PosTextID; 
        };

        /* Get-/Setters for Generic Attribute Structure InteractQuestionID */
        virtual void setInteractQuestionID(std::shared_ptr<mtp::ReadDataItem<std::uint32_t>>& InteractQuestionID) 
        { 
            this->InteractQuestionID = InteractQuestionID; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::uint32_t>> getInteractQuestionID() const
        {  
            return this->InteractQuestionID; 
        };

        /* Get-/Setters for Generic Attribute Structure InteractAnswerID */
        virtual void setInteractAnswerID(std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>>& InteractAnswerID) 
        { 
            this->InteractAnswerID = InteractAnswerID; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<std::uint32_t>> getInteractAnswerID() const
        {  
            return this->InteractAnswerID; 
        };

        /* Get-/Setters for Generic Attribute Structure InteractAddInfo */
        virtual void setInteractAddInfo(std::shared_ptr<mtp::ReadDataItem<std::string>>& InteractAddInfo) 
        { 
            this->InteractAddInfo = InteractAddInfo; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadDataItem<std::string>> getInteractAddInfo() const
        {  
            return this->InteractAddInfo; 
        };

        /* Get-/Setters for Generic Attribute Structure ReportValueFreeze */
        virtual void setReportValueFreeze(std::shared_ptr<mtp::ReadWriteDataItem<bool>>& ReportValueFreeze) 
        { 
            this->ReportValueFreeze = ReportValueFreeze; 
            return;
        };
        virtual const std::shared_ptr<mtp::ReadWriteDataItem<bool>> getReportValueFreeze() const
        {  
            return this->ReportValueFreeze; 
        };
    };   
}

#endif // defined HAVE_SERVICE_CONTROL_BASE_HPP