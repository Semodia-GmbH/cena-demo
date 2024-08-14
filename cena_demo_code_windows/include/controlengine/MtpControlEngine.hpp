/**
 * @file      MtpControlEngine.hpp
 * @date      3/10/21
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2021). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_MTPCONTROLENGINE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_MTPCONTROLENGINE_HPP

#pragma once

#include "tasking/FrequencyLimitedTaskLoopTask.hpp"
using typename semodia::controlengine::native::osal::tasking::FrequencyLimitedTaskLoopTask;
using typename semodia::controlengine::native::osal::locking::ILockable;
using typename semodia::controlengine::native::osal::timing::ITimer;

#include "opcua/IOpcUaServer.hpp"
using typename semodia::controlengine::native::reflection::opcua::IOpcUa;
using typename semodia::controlengine::native::reflection::opcua::IOpcUaServer;

#include "mtp/ModuleTypePackage.hpp"
using typename semodia::controlengine::native::model::mtp::ModuleTypePackage;

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @class MtpControlEngine
     * @brief Abstract control engine that automates common linkage of MTP, Services/Control and OPC UA.
     *        Does not handle specific server or execution tasks.
     */
    class MtpControlEngine : public FrequencyLimitedTaskLoopTask
    {
    protected:
        /**
         * @brief Set to "true" after @see MtpControlEngine::initializeMtpContents() was called
         */
        bool mtpInitialized;

    protected:
        /**
         * @brief The OPC UA Server used to reflect the MTP and grant access to a POL
         */
        std::shared_ptr<IOpcUaServer> server;

        /**
         * @brief The Module Type Package instance managed by this CE instance
         */
        std::shared_ptr<ModuleTypePackage> mtp;

        /**
         * @brief Sets up the already present MTP with specifics; this is called once by the constructor, but
         *        the function must be implemented by the specific control engine.
         */
        virtual void initializeMtpContents() = 0;

        /**
         * @brief Invokes initializeMtpContents once to populate mtp with contents as required by implementation
         *        also @see BasicTaskLoopTask::preStart
         */
        virtual void preStart() override final;

        /**
         * @brief Reflects MTP Model; assumes OPC UA and associated functions have been started
         *        also @see BasicTaskLoopTask::postStart
         */
        virtual void postStart() override;

        /**
         * @brief Triggers MTP Services and updates opc ua server as required; should be called by specialization
         *        also @see BasicTaskLoopTask::preStop
         */
        virtual void iterate() override;

        /**
         * @brief Aborts any running MTP services
         *        also @see BasicTaskLoopTask::preStop
         */
        virtual void preStop() override final;

    public:
        [[deprecated("This constructor is outdated and does not initialize all fields of the PeaInformationLabel. It will be removed in next major release")]]
        MtpControlEngine(std::unique_ptr<ILockable> taskLock,
                         std::unique_ptr<ITimer> taskTimer, const float& executionInterval_ms,
                         std::shared_ptr<IOpcUaServer> server,
                         const std::string& Name,
                         const std::string& DocumentId,
                         const std::string& AssetId,
                         const std::string& DeviceClass,
                         const std::string& DeviceManual,
                         const std::string& HardwareRevision,
                         const std::string& Manufacturer,
                         const std::string& ManufacturerUri,
                         const std::string& Model,
                         const std::string& ProductCode,
                         const std::string& ProductInstanceUri,
                         const std::string& SerialNumber,
                         const std::string& SoftwareRevision,
                         const std::string& Vendor,
                         const std::string& VendorURI,
                         const std::string& WebServerURI);

        MtpControlEngine(
            std::unique_ptr<ILockable> taskLock,
            std::unique_ptr<ITimer> taskTimer,
            std::shared_ptr<IOpcUaServer> server,
            const float& executionInterval_ms,
            const std::string& Name,
            const std::string& DeviceClass,
            const std::string& DeviceManual,
            const std::string& HardwareRevision,
            const std::string& Manufacturer,
            const std::string& ManufacturerUri,
            const std::string& ProductCode,
            const std::string& ProductInstanceUri,
            const std::string& SerialNumber,
            const std::string& SoftwareRevision,
            const std::string& Vendor,
            const std::string& VendorURI,
            const std::string& WebServerURI);

        virtual ~MtpControlEngine();

        // PEA is a stateful entity, it cannot be trivially copied
        MtpControlEngine(const MtpControlEngine &other) = delete;
        MtpControlEngine &operator=(const MtpControlEngine &rhs) = delete;
    };
} // namespace

#endif // SEMODIA_CONTROLENGINE_NATIVE_MTPCONTROLENGINE_HPP
