/**
 * @date 7/29/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_FILTERINGMESSAGELOGGER_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_FILTERINGMESSAGELOGGER_HPP

#pragma once

#include "AbstractFilteringMessageLogger.hpp"

namespace semodia::controlengine::native::osal::logging {
    /**
     * @brief   Implements a rudimentary, non thread-safe, text-only logger **based on iostream**
     *          This logger requires a platform with a meaningful I/O implementation for iostream.
     */
    class FilteringMessageLogger : public AbstractFilteringMessageLogger {
    protected:
        /**
         * @copydoc semodia::controlengine::native::osal::logging::AbstractFilteringMessageLogger::displayMessage()
         * @brief Derives a log prefix from level and uses std::cout to print the message
         */
        virtual void displayMessage(const std::string& logMessage, const LogLevel level=LogLevel::none) override ;
        
    public:
        FilteringMessageLogger();
        FilteringMessageLogger(LogLevel level);
        virtual ~FilteringMessageLogger();
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_FILTERINGMESSAGELOGGER_HPP
