/**
 * @file      OptionalLoggingDecorator.hpp
 * @date      3/16/21
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2021). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_OPTIONALLOGGINGDECORATOR_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_OPTIONALLOGGINGDECORATOR_HPP

#pragma once

#include <memory>

#include "logging/ILogger.hpp"
using typename semodia::controlengine::native::osal::logging::ILogger;

namespace semodia::controlengine::native::osal::logging {
    /**
     * @class LoggingDecorator
     * @brief Extends an existing class with optional logging capabilities.
     * @details An optional logging facility that can be assigned from userspace; enables userspace to assign log
     *          where needed (e.g. from global log file in main, but not in tests). Provides all log-functions as "this"
     */
    class OptionalLoggingDecorator : public ILogger
    {
    private:
        std::shared_ptr<ILogger> logFacility;

    protected:
        /**
         * @brief An optional prefix that a class can prepend to log messages to make the origin of the message clearer
         *        The class' name tends to be a good choice; empty by default
         */
        std::string logPrefix;

    public:
        /**
         * @brief Extends an existing class with optional logging capabilities
         */
        OptionalLoggingDecorator();

        /**
         * @brief Create a new logging decorator for a class, initializing the assigned facility
         * @param logFacility is a shared logger; the pointer will be copied by the constructor before use
         */
        OptionalLoggingDecorator(std::shared_ptr<ILogger>& logFacility);
        virtual ~OptionalLoggingDecorator() = default;

        OptionalLoggingDecorator(const OptionalLoggingDecorator &other) = default;
        OptionalLoggingDecorator &operator=(const OptionalLoggingDecorator &rhs) = default;

        /**
         * @brief Changes the assigned, optional logging facility to the one provided
         * @param logFacility to use
         */
        virtual void assignLoggingFacility(std::shared_ptr<ILogger> logFacility);

        /**
         * @param prefix that will be prepended to each log message (after the log level)
         */
        virtual void setLogPrefix(const std::string& prefix);

        /**
         * @return the prefix that we prepend to each log message
         */
        virtual inline const std::string& getLogPrefix() const
        {
            return this->logPrefix;
        }

        /**
         * @brief if logFacility is set, behaves as @see semodia::controlengine::native::osal::logging::ILogger::log()
         */
        virtual void log(const std::string &logMessage) override;

        /**
         * @brief if logFacility is set, behaves as @see semodia::controlengine::native::osal::logging::ILogger::log()
         */
        virtual void log(const controlengine::native::osal::logging::LogLevel severity, const std::string &logMessage) override;

        /**
         * @brief if logFacility is set, behaves as @see semodia::controlengine::native::osal::logging::ILogger::debug
         */
        virtual void debug(const std::string &logMessage) override;

        /**
         * @brief  if logFacility is set, behaves as @see semodia::controlengine::native::osal::logging::ILogger::info
         */
        virtual void info(const std::string &logMessage) override;

        /**
         * @brief if logFacility is set, behaves as @see semodia::controlengine::native::osal::logging::ILogger::warning
         */
        virtual void warning(const std::string &logMessage) override;

        /**
         * @brief if logFacility is set, behaves as @see semodia::controlengine::native::osal::logging::ILogger::error
         */
        virtual void error(const std::string &logMessage) override;

        /**
         * @brief if logFacility is set, behaves as @see semodia::controlengine::native::osal::logging::ILogger::fatal
         */
        virtual void fatal(const std::string &logMessage) override;
    };
}

#endif //SEMODIA_CONTROLENGINE_NATIVE_OPTIONALLOGGINGDECORATOR_HPP
