/*
 * @author  Georg Graßnick
 * @date 5/28/21
 * @copyright (c) 2021 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_LOGMESSAGE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_LOGMESSAGE_HPP

#pragma once

#include <string>

#include "LogLevels.hpp"

namespace semodia::controlengine::native::osal::logging
{

    typedef std::string LogMessagePayload;

    /**
     * @class LogMessage
     * @brief Data class modelling a log message
     * @details A container class encapsulating the different aspects of a concrete log message (currently the log
     * message text and the severity)
     */
    class LogMessage
    {
    private:
        const LogLevel severity;
        LogMessagePayload payload;

    public:
        LogMessage() = delete;
        virtual ~LogMessage() = default;

        /**
         * @brief Constructor
         * @details A logging message requires at least a payload and a severity.
         * @param message The message this log message encapsulates
         * @param severity The severity of the log message
         */
        LogMessage(const LogMessagePayload& message, const LogLevel severity);

        [[nodiscard]] const LogLevel getSeverity() const;
        [[nodiscard]] const LogMessagePayload& getPayload() const;
    };

} // namespace semodia::controlengine::native::osal::logging
#endif // SEMODIA_CONTROLENGINE_NATIVE_LOGMESSAGE_HPP
