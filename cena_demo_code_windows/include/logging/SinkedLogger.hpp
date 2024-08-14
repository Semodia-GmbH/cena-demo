/*
 * @author  Georg Graßnick
 * @date 5/28/21
 * @copyright (c) 2021 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_SINKEDLOGGER_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_SINKEDLOGGER_HPP

#pragma once

#include <string>
#include <unordered_map>
#include <utility>

#include "AbstractFilteringMessageLogger.hpp"
#include "ILoggingSink.hpp"
#include "ILoggingSinkManager.hpp"
#include "LogLevels.hpp"

namespace semodia::controlengine::native::osal::logging
{

    /**
     * @class SinkedLogger
     * @brief A logging facility offering the support for multiple output channels (sinks) at the same time
     */
    class SinkedLogger : public ILoggingSinkManager, public AbstractFilteringMessageLogger
    {

    private:
        /**
         * @brief Data class modeling the info associated with a certain sinkIdentifier string
         */
        class SinkDescriptor
        {
        public:
            /**
             * @brief The concrete sink instance
             */
            std::shared_ptr<ILoggingSink> sink;

            /**
             * @brief The minimum severity on which so send log messages to this sink
             */
            LogLevel minSeverity;
            SinkDescriptor() = delete;
            virtual ~SinkDescriptor() = default;
            SinkDescriptor(std::shared_ptr<ILoggingSink> sink, LogLevel minimumSeverity);
        };

        std::unordered_map<std::string, SinkDescriptor> sinks;

        /**
         * @brief Helper function which encapsulates the actual behaviour of addSink() without any locking, so that
         * there is no duplicate code between the two code paths.
         */
        inline bool doAddSink(
            std::shared_ptr<ILoggingSink> sink,
            const std::string& sinkIdentifier,
            LogLevel minimumSeverity);

        /**
         * @brief Helper function which encapsulates the actual behaviour of removeSink() without any locking, so that
         * there is no duplicate code between the two code paths.
         */
        inline std::shared_ptr<ILoggingSink> doRemoveSink(const std::string& sinkIdentifier);

        /**
         * @brief Helper function which encapsulates the actual behaviour of setMinimumLogLevel() without any locking,
         * so that there is no duplicate code between the two code paths.
         */
        inline bool doSetMinimumLogLevel(LogLevel level, const std::string& sinkIdentifier);

    protected:
        /**
         * @copydoc semodia::controlengine::native::osal::logging::AbstractFilteringMessageLogger::displayMessage()
         * @brief Propagates the log message to all managed sinks. Filtering on sink level is achieved here.
         * @details If the severity of the log message is equal or higher than the minimum severity of a sink, propagate
         * the message. If either the message severity, or the minimum severty of the sink is
         * semodia::controlengine::native::osal::logging::LogLevel::Severity::none, propagate the message despite other
         * restrictions.
         */
        void displayMessage(const std::string& logMessage, const LogLevel level) override;

        /**
         * @copydoc semodia::controlengine::native::osal::tasking::BasicTaskLoopTask::iterate()
         */
        void iterate() override;

    public:
        SinkedLogger();
        SinkedLogger(LogLevel minSeverity);

        /**
         * @See ILoggingSinkManager::addSink()
         */
        bool addSink(
            std::shared_ptr<ILoggingSink> sink,
            const std::string& sinkIdentifier,
            LogLevel minimumSeverity = LogLevel::none) override;

        /**
         * @copydoc semodia::controlengine::native::osal::logging::ILoggingSinkManager::removeSink()
         */
        std::shared_ptr<ILoggingSink> removeSink(const std::string& sinkIdentifier) override;

        /**
         * @copydoc semodia::controlengine::native::osal::logging::ILoggingSinkManager::setMinimumLogLevel()
         */
        bool setMinimumLogLevel(LogLevel level, const std::string& sinkIdentifier) override;
    };

} // namespace semodia::controlengine::native::osal::logging

#endif // SEMODIA_CONTROLENGINE_NATIVE_SINKEDLOGGER_HPP
