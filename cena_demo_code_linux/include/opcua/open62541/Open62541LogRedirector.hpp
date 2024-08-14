/**
 * @file      Open62541LogRedirector.hpp
 * @date      1/19/21
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2021). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_LOGREDIRECTOR_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_LOGREDIRECTOR_HPP

#pragma once

#include <string>

extern "C" {
    #include "open62541.h"
}
#include "logging/LogLevels.hpp"
#include "logging/OptionalLoggingDecorator.hpp"

/**
 * @brief open62541 provides a printf-like logging, which we pre-compose into an std::string using vsprintf; this requires a buffer
 */
#define OPEN62541_LOGREDIRECT_MESSAGECOMPOSITION_BUFFER_SIZE 192

namespace semodia::controlengine::native::reflection::opcua
{
    /**
     * @class LogRedirector
     * @brief A shared inheritance for server and client that takes care of redirecting the logging messages
     */
    class Open62541LogRedirector : public osal::logging::OptionalLoggingDecorator
    {
    protected:
        std::shared_ptr<ILogger> logger;

    public:
        Open62541LogRedirector();
        virtual ~Open62541LogRedirector();

        Open62541LogRedirector(const Open62541LogRedirector &other) = default;
        Open62541LogRedirector &operator=(const Open62541LogRedirector &rhs) = default;

        /**
         * @brief OPC UA message to UA_Logger are redirected here so they can be included in implementation specific logs
         * @param level is the CENA-Abstracted log level
         * @param msg is a string message, possibly predicated with the UA_Category
         */
        virtual void logMessage(const osal::logging::LogLevel level, const std::string &message);

        /**
         * @brief Function pointer passed to open62541 as part of UA_Logger; redirects log messages to @see stackLogFunction()
         */
        static void stackLoggerRedirectLog(void *logContext, UA_LogLevel level, UA_LogCategory category, const char *msg, va_list args);

        /**
         * @brief Function pointer passed to open62541 as part of UA_Logger; does nothing (logContext is a pointer to this class instance)
         */
        static void stackLoggerRedirectClear(void *logContext);
    };
}

#endif //SEMODIA_CONTROLENGINE_NATIVE_LOGREDIRECTOR_HPP
