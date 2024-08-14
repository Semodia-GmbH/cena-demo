/*
 * @author  Georg Graßnick
 * @created 5/28/21
 * @copyright (c) 2021 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ILOGGINGSINK_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ILOGGINGSINK_HPP

#pragma once

#include "tasking/BasicTaskLoopTask.hpp"
#include "locking/Lock.hpp"
#include "logging/LogMessage.hpp"
#include "logging/LogMessageFormatter.hpp"

namespace semodia::controlengine::native::osal::logging
{

    using namespace semodia::controlengine::native::osal::tasking;

    /**
     * @interface ILoggingSink
     * @brief Interface to a facility offering the output of log messages to a single output channel (e.g. stdout)
     */
    class ILoggingSink : public BasicTaskLoopTask
    {
    public:
        ILoggingSink() : BasicTaskLoopTask(std::make_unique<osal::locking::Lock>())
        {
            return;
        };

        virtual ~ILoggingSink() = default;

        /**
         * @brief Write a semodia::controlengine::native::osal::logging::LogMessage to the output channel
         * @param message The message to be written
         */
        virtual void writeMessage(std::shared_ptr<LogMessage> message) = 0;

        /**
         * @brief Force the underlying channel to write all queued messages to the output channel
         * @details As Output channels may buffer messages internally for performance reasons, a manual flush
         * might be necessary in certain scenarios
         */
        virtual void flush() = 0;

        /**
         * @brief Set the formatting for future written messages
         * @details Defines the composition of messages when written to the output channel
         * e.g. "[$severity$] $message$ \n"
         * @param formatter The formatter which will be used to format
         */
        virtual void setLogMessageFormatter(std::shared_ptr<LogMessageFormatter> formatter) = 0;
    };

} // namespace semodia::controlengine::native::osal::logging

#endif // SEMODIA_CONTROLENGINE_NATIVE_ILOGGINGSINK_HPP
