/*
 * @author  Georg Graßnick
 * @date 5/28/21
 * @copyright (c) 2021 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ILOGGINGSINKMANAGER_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ILOGGINGSINKMANAGER_HPP

#pragma once

#include <string>

#include "tasking/BasicTaskLoopTask.hpp"
#include "logging/ILoggingSink.hpp"
#include "logging/LogLevels.hpp"

namespace semodia::controlengine::native::osal::logging
{

    using namespace semodia::controlengine::native::osal::tasking;

    /**
     * @interface ILoggingSinkManager
     * @brief Interface for a facility that manages semodia::controlengine::native::osal::logging::ILoggingSink objects
     * @details Each registered sink is identifiable by an id. Sinks can have individual minimum severities, so that we
     * can filter messages by severity for each sink individually.
     */
    class ILoggingSinkManager : public BasicTaskLoopTask
    {
    public:
        ILoggingSinkManager() : BasicTaskLoopTask(std::make_unique<osal::locking::Lock>())
        {
            return;
        };
        virtual ~ILoggingSinkManager() = default;

        /**
         * @brief Add a LoggingSink to be managed by this object
         * @param sink The sink to be managed by the ILoggingSinkManager
         * @param sinkIdentifier An identifier by which this specific sink can be addressed later on
         * @param minimumSeverity The minimum Severity for the sink
         * @return If the operation was successful returns true, else false
         */
        virtual bool addSink(
            std::shared_ptr<ILoggingSink> sink,
            const std::string& sinkIdentifier,
            LogLevel minimumSeverity) = 0;

        /**
         * @brief Removes a sink from the managed sinks
         * @details If there is no sink registered by this sinkIdentifier, no changes are made
         * @param sinkIdentifier The sinkIdentifier of the sink
         * @return If there is a sink registered under the sinkIdentifier, returns a pointer to this sink, else returns
         * a nullptr
         */
        virtual std::shared_ptr<ILoggingSink> removeSink(const std::string& sinkIdentifier) = 0;

        /**
         * @brief Set a new minimum severity for a specific managed LoggingSink
         * @param newMinimumSeverity The new minimum severity
         * @param sinkIdentifier The sinkIdentifier of the sink
         * @return If there is a sink registered under the sinkIdentifier and the removal was successful, returns true,
         * else false
         */
        virtual bool setMinimumLogLevel(LogLevel newMinimumSeverity, const std::string& sinkIdentifier) = 0;
    };

} // namespace semodia::controlengine::native::osal::logging

#endif // SEMODIA_CONTROLENGINE_NATIVE_ILOGGINGSINKMANAGER_HPP
