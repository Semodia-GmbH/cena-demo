/***********************************************************************/
/* This file is *generated* - manual modification will be overwritten. */
/***********************************************************************/

/**
 * @file MtpTypeIndex.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_MTPTYPEINDEX_HPP
#define HAVE_MTPTYPEINDEX_HPP

#pragma once

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @enum MtpTypeIndex
     * @brief An index of all classes present in the model; used primarily as RTTI for DataAssembly lookup
     */
    enum class MtpTypeIndex
    {
        InputElementConfigAnalog, //! Defines a valid configuration set consisting of unit and scale settings (min and max) for analog input elements.
        InputElementConfigDInt, //! Defines a valid configuration set consisting of unit and scale settings (min and max) for DInt input elements.
        AlarmGroup, //! Structure element for alarms. One group belongs to on specific MTP object.
        BaseEvent, //! Semodia specific base class for event types.
        AlarmRelation, //! Relation of two alarms in different groups.
        ModuleTypePackage, //! The module type package of the process equipment assembly. Containing all MTP aspects.
        VendorInformation, //! The vendor information.
        DataItem, //! The data item specifying the information of an attribute defined within the standard. The data type is specified via a generic argument.
        Picture, //! The picture element containing all elements of the picture.
        TopologyObject, //! The topology object defining objects within the topological structure of the picture.
        PortObject, //! The port object defining the connection port for the elements within the picture.
        Connection, //! The connection describes a connection between two ports.
        SemanticGroup, //! The semantic group clustering different objects.
        Coordinate, //! A coordinate describing X and Y coordinate of an element in pixels.
        FunctionClassification, //! Defines a semantic reference to a function classification standard.
        TextStructure, //! The text structure.
        EventMessages, //! Message list containing alarm message.
        TextDefinition, //! The base text definition.
        MtpSet, //! The MTP set defines the base for all aspects.
        BaseFunction, //! Abstract base function class.
        InstanceReferences, //! The references of the data assembly instance.
        AttachmentGroup, //! Defines a group of attachments.
        AttachmentReference, //! The reference information of the attached document.
        LinkedObject, //! Basic cross referencing object.
        OpcUaServer, //! The OPC UA server object. Containing the information of the OPC UA server.
        OpcUaNodeItem, //! The OPC UA node item defining the necessary information to access a node within the corresponding OPC UA server.
        ObjectItem, //! Represents an object, which is to organize composites of methods or data items.
        DataAssembly, //! DataAssembly defines an element of the InstanceList.
        AlarmSet, //! Defines the alarm aspect of the MTP.
        ServiceAlarmGroup, //! Collection of alarms related to referenced service.
        ServiceParameterAlarmGroup, //! Collection of alarms related to the referenced service parameter.
        TagAlarmGroup, //! Collection of alarms related to referenced tag (assembly).
        SystemAlarmGroup, //! Collection of system alarms that do not belong to a tag or service but are triggered by the automation system.
        Alarm, //! Expanded event with additional attributes for operator handling.
        Event, //! Basic event that is used to raise a message.
        CommunicationSet, //! The communication set. It is the default aspect which has to be included within each MTP.
        Junction, //! The junction which defines a connection of three connections.
        Termination, //! The termination describes HMI boundaries of the picture. A termination itself describes undirected boundaries.
        VisualObject, //! The visual object defining a symbol which is placed within the picture.
        FunctionLine, //! The functional line describes logical connections.
        MeasurementLine, //! The measurement line describes a connection between a material flow and an information flow.
        Pipe, //! The pipe describes material flows.
        LogicalPort, //! The logical port which can be connected via a function line.
        MeasurementPoint, //! The measurement point which can be connected via a measurement line.
        Nozzle, //! The nozzle which can be connected via a pipe.
        HmiSet, //! Defines the HMI aspect of the MTP.
        ScaleSettingsBaseFunction, //! ScaleSettings define the limits by design of a value, which cannot be changed during runtime.
        ValueLimitationBaseFunction, //! ValueLimitation defines the limitation of a value, additionally to ScaleSettings.
        OperationModeBaseFunction, //! OperationMode defines the different operation modes: Offline, Operator and Automatic.
        SourceModeBaseFunction, //! SourceMode defines a mode to differ between internal and manual sources for values.
        InterlockBaseFunction, //! Interlock defines all interlocks regarding the element.
        FeedbackMonitoringBaseFunction, //! FeedbackMonitoring defines a monitoring of static and dynamic errors.
        ResetBaseFunction, //! Reset defines a reset function of values for this element.
        LimitMonitoringBaseFunction, //! LimitMonitoring defines a monitoring of up to six limits of a value.
        LockItemBaseFunction, //! LockItem defines an item within a LockView.
        ServiceSet, //! Defines the service aspect of the MTP.
        Service, //! The service object encapsulates the process functionality.
        ServiceParameter, //! The service parameter.
        ReportValue, //! The report value.
        Procedure, //! The procedure executing the specified behavior.
        TextSet, //! Defines the text aspect of the MTP.
        ServiceInteraction, //! The service interaction.
        EnumDefinition, //! The enum definition.
        ServicePosition, //! The service position.
        EnumItem, //! The enum item.
        PositionText, //! The position text.
        Question, //! Describes a question which can be asked.
        Answer, //! Describes an answer which can be given to a specific question.
        Message, //! The event message.
        ServiceSourceModeBaseFunction, //! ServiceSourceMode defines the SourceMode of the service.
        ServiceOperationModeBaseFunction, //! The ServiceOperationMode defines the operation mode of the service.
        ScaleSettingsInBaseFunction, //! ScaleSettings define the limits by design of a value, which cannot be changed during runtime.
        ReadDataItem, //! The read data item specifying the information of an attribute defined within the standard. The access is readonly within the OPC UA server. The data type is specified via a generic argument.
        ReadWriteDataItem, //! The read write data item specifying the information of an attribute defined within the standard. The access is read write within the OPC UA server. The data type is specified via a generic argument.
        AttachmentSet, //! Defines the attachment aspect of the MTP.
        ApplyBaseFunction, //! Base function which provides the apply functionality of values according to part four.
        ProcessValue, //! Defines a base process value.
        ProcessValueSet, //! Defines the process value aspect of the MTP.
        ServerProfile, //! Defines a basic server profile.
        ActiveElement, //! ActiveElement defines active elements, such as valves, controls and drives.
        OperationElement, //! OperationElement defines elements which are used to process values from the POL to the PEA.
        IndicatorElement, //! IndicatorElement defines elements which are used to show values of the PEA.
        DiagnosticElement, //! DiagnosticElement defines element for the representation of diagnosis information.
        InputElement, //! InputElement defines input process variables of a service.
        EventView, //! AlarmView defines an element for the visualization of events and information about its condition type.
        PeaElement, //! PeaElement defines PEA-wide once-only information.
        ServiceElement, //! Base class for all service specific data assembly children.
        ComElement, //! Defines a basic communication element.
        Source, //! The source describing an ingoing boundary.
        Sink, //! The sink describing an outgoing boundary.
        ConfigurationParameter, //! The configuration parameter.
        ProcedureParameter, //! The procedure parameter.
        ProcessValueOut, //! The process value output.
        ProcessValueIn, //! The process value input.
        BasicServerProfile, //! Refers to communication related capabilities specified by the basic server profile.
        StandardServerProfile, //! Refers to communication related capabilities specified by the standard server profile.
        ExtendedServerProfile, //! Refers to communication related capabilities specified by the extended server profile.
        PIDCtrl, //! PIDCtrl defines a continuous PID controller.
        AnaVlv, //! AnaVlv defines an analogue valve.
        BinVlv, //! BinVlv defines a binary valve.
        AnaMan, //! AnaMan defines to set an analogue value.
        BinMan, //! BinMan defines to set a binary value.
        DIntMan, //! DIntMan defines to set an integer value.
        BinView, //! BinView defines a view element of a binary value.
        AnaView, //! AnaView defines a view element of an analogue value.
        DIntView, //! DIntView defines a view element of an integer value.
        LockView4, //! LockView4 defines a view of a logical base operation with four inputs.
        AnaDrv, //! AnaDrv defines an analogue drive.
        BinDrv, //! BinDrv defines a binary drive.
        StringView, //! StringView defines a view element of a string value.
        ServiceControl, //! ServiceControl defines a service.
        BinProcessValueIn, //! BinProcessValueIn defines a binary input process variable of a service.
        AnaProcessValueIn, //! AnaProcessValueIn defines an analogue input process variable of a service.
        DIntProcessValueIn, //! DIntProcessValueIn defines an integer input process variable of a service.
        ParameterElement, //! Base class for defining parameters of a service.
        AlarmView, //! AlarmView defines an element for the visualization of alarms and information about its condition type.
        PeaInformationLabel, //! Describes product- and instance-specific information for the PEA handling within a modular plant environment.
        WebServerUrlInfo, //! Describes the endpoint of a proprietary web server.
        ProcedureHealthView, //! Provides the service procedure health information.
        StringProcessValueIn, //! StringProcessValueIn defines a string input process variable of a service.
        IpV4AddressConfig, //! Allows to configure the IPv4 address at runtime in the standard server profile.
        IpV6AddressConfig, //! Allows to configure the IPv6 address at runtime in the standard server profile.
        ExtendedIpAddressConfig, //! Provides additional configuration in the extended server profile (e.g. activation of DHCP).
        NtpServerUriSet, //! Provides a list of NTP server URIs in the standard server profile.
        OpcUaBasicServerProfile, //! Refers to communication related capabilities specified by the basic server profile for OPC UA.
        OpcUaStandardServerProfile, //! Refers to communication related capabilities specified by the standard server profile for OPC UA.
        OpcUaExtendedServerProfile, //! Refers to communication related capabilities specified by the extended server profile for OPC UA.
        LockView8, //! LockView8 defines a view of a logical base operation with eight inputs.
        AnaManInt, //! AnaManInt defines to set an analogue value by different sources.
        BinManInt, //! BinManInt defines to set a binary value by different sources.
        DIntManInt, //! DIntManInt defines to set an integer value by different sources.
        AnaMon, //! AnaMon defines a view element of an analogue value including a limit monitoring.
        DIntMon, //! DIntMon defines a view element of an integer value including a limit monitoring.
        BinMon, //! BinMon defines a view element of a binary value including a flutter detection.
        MonBinVlv, //! MonBinVlv defines a binary valve including a feedback monitoring.
        MonAnaVlv, //! MonAnaVlv defines an analogue valve including a feedback monitoring.
        MonBinDrv, //! MonBinDrv defines a binary drive including feedback monitoring.
        MonAnaDrv, //! MonAnaDrv defines an analogue drive including a feedback monitoring.
        AnaServParam, //! AnaServParam defines an analogue service parameter.
        DIntServParam, //! DIntServParam defines an integer service parameter.
        BinServParam, //! BinServParam defines a binary service parameter.
        StringServParam, //! StringServParam defines a string service parameter.
        LockView16, //! LockView16 defines a view of a logical base operation with 16 inputs.
        MissedValueFlag, //! Extension for a missed value flag at report values.
        TextReference, //! Base for text reference extensions.
        Timestamped, //! Extension to add the last processing time stamp of the corresponding data assembly to any data assembly.
        EnumDefinitionTextReference, //! Extension for an enumeration definition at DIntView, DIntMan, DIntServParam and DIntProcessValueIn.
        ServicePositionTextReference, //! Extension for a service position at a service.
        ServiceInteractionTextReference, //! Extension for a service interaction at a service.
    };   
}

#endif // HAVE_MTPTYPEINDEX_HPP