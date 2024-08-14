/*
 * @author  Chris Paul Iatrou
 * @date 7/29/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ILOGGER_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ILOGGER_HPP

#pragma once

#include <string>
#include "LogLevels.hpp"

namespace semodia::controlengine::native::osal::logging {
    /**
     * @brief Interface to a level-based facility handling Text/Line based diagnostic output
     */
    class ILogger {
    public:
        virtual ~ILogger() {};
        
        /**
         * @brief "Raw" log; may ignore level filters
         * @param logMessage displayed by logging mechanism
         */
        virtual void log(const std::string& logMessage) = 0;
        virtual void log(const LogLevel severity, const std::string& logMessage) = 0;

        /**
         * @brief Debug messages intended for development only
         * @param logMessage displayed by logging mechanism
         */
        virtual void debug(const std::string& logMessage) = 0;
        
        /**
         * @brief Purely information messages
         * @param logMessage displayed by logging mechanism
         */
        virtual void info(const std::string& logMessage) = 0;
    
        /**
         * @brief Non critical errors
         * @param logMessage displayed by logging mechanism
         */
        virtual void warning(const std::string& logMessage) = 0;
    
        /**
         * @brief Critical errors
         * @param logMessage displayed by logging mechanism
         */
        virtual void error(const std::string& logMessage) = 0;
    
        /**
         * @brief Errors that cause the application to stop or behave out-of-specification
         * @param logMessage displayed by logging mechanism
         */
        virtual void fatal(const std::string& logMessage) = 0;
    };

} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_ILOGGER_HPP
