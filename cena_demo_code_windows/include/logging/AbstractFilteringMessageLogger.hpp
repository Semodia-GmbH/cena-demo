/*
 * @author  Chris Paul Iatrou
 * @date 7/29/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ABSTRACTFILTERINGMESSAGELOGGER_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ABSTRACTFILTERINGMESSAGELOGGER_HPP

#pragma once

#include <memory>

#include "logging/ILogger.hpp"
#include "locking/ILockable.hpp"

namespace semodia::controlengine::native::osal::logging {
    
    /**
     * @brief A logging facility that can filter messages based on their "severity" and assumes to be displaying text
     */
    class AbstractFilteringMessageLogger : public ILogger
    {
        /**
         * @brief Any message of lower importance than minLogLevel is ignored. If this is none,
         *        all messages are displayed & 'filtering' is effectively disabled.
         */
        LogLevel minLogLevel;

    protected:
        /**
         * @brief A mutex or similarly lockable object that is used to avoid overlapping output
         *        in multithreaded applications
         */
        std::unique_ptr<locking::ILockable> logOutputLock;

        /**
         * @brief Performs the actual displaying of the log message; simplifies specialization.
         *        Needs to be implemented for target platform.
         * @param logMessage The message to display
         * @param level The log level (used for formatting).
         */
        virtual void displayMessage(const std::string& logMessage, const LogLevel level=LogLevel::none) = 0;
    
    public:
        AbstractFilteringMessageLogger(LogLevel minLogLevel);
        AbstractFilteringMessageLogger();
        virtual ~AbstractFilteringMessageLogger();
        
        // Inherited from interface
        virtual void log(const std::string& logMessage) override;
        virtual void log(const LogLevel level, const std::string& logMessage) override;
        virtual void debug(const std::string& logMessage) override;
        virtual void info(const std::string& logMessage) override;
        virtual void warning(const std::string& logMessage) override;
        virtual void error(const std::string& logMessage) override;
        virtual void fatal(const std::string& logMessage) override;

        void setLock(std::unique_ptr<locking::ILockable> newLock);
        
        /**
         * @brief Adjusts the log level; only messages with this log level or higher are displayed
         * @param minLogLevel
         */
        void setMinimumLogLevel(LogLevel minLogLevel);
    };

} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_ABSTRACTFILTERINGMESSAGELOGGER_HPP
