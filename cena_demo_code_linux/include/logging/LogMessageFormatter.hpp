/*
 * @author  Georg Graßnick
 * @date 5/28/21
 * @copyright (c) 2021 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_LOGMESSAGEFORMATTER_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_LOGMESSAGEFORMATTER_HPP

#pragma once

#include <memory>
#include <string>

#include "LogMessage.hpp"

namespace semodia::controlengine::native::osal::logging
{

    /**
     * @class LogMessageFormatter
     * @brief Formats LogMessage objects to match a specific output layout
     * @details Defined by a format string defined in the constructor,
     * incoming LogMessage objects will be formatted to a certain layout
     * when invoking formatLogMessage()
     * @note Custom format strings are not implemented yet, instead every message
     * is formatted to "[$severity$] $logMessagePayload$"
     */
    class LogMessageFormatter
    {
    private:
        /**
         * @brief Defines the format, incoming messages should be formatted to
         */
        const std::string formatString;

        /**
         * @brief Weather to format at all
         * @details If set to false, just the message payload will be returned by formatLogMessage()
         */
        bool doFormat;

    public:
        /**
         * @brief Constructs a LogMessageFormatter for the default format string
         */
        LogMessageFormatter();
        virtual ~LogMessageFormatter() = default;

        /**
         * @brief Constructs a LogMessageFormatter which will format incoming LogMessages according to
         * the defined format string
         * @param formatString The format string which will be used later on
         */
        explicit LogMessageFormatter(const std::string& formatString);

        /**
         * @brief Formats a log message object to a std::string according to the defined formatting string
         * @param message The LogMessage to be formatted
         * @return The formatted log message
         */
        [[nodiscard]] std::string formatLogMessage(std::shared_ptr<LogMessage> message) const;

        /**
         * @brief Enable or disable the formatting completely
         * @param shouldEnable If set to false, messages will not be formatted at all,
         * just the message payload will be returned
         */
        void enableFormatting(bool shouldEnable);
    };

} // namespace semodia::controlengine::native::osal::logging

#endif // SEMODIA_CONTROLENGINE_NATIVE_LOGMESSAGEFORMATTER_HPP
