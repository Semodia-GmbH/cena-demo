/*
 * @author  Georg Graßnick
 * @date 5/28/21
 * @copyright (c) 2021 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ABSTRACTLOGGINGSINK_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ABSTRACTLOGGINGSINK_HPP

#pragma once

#include <memory>

#include "locking/ILockable.hpp"
#include "logging/ILoggingSink.hpp"

namespace semodia::controlengine::native::osal::logging
{

    /**
     * @class AbstractLoggingSink
     * @brief Abstract implementation of semodia::controlengine::native::osal::logging::ILoggingSink which is subclassed
     * by concrete implementations
     * @details Manages locking and formatting of log messages so that sub classes do not have to deal with it
     */
    class AbstractLoggingSink : public ILoggingSink
    {

    private:
        /**
         * @brief The semodia::controlengine::native::osal::locking::ILockable used for thread safe operation
         * if there is no ILockable set, do not lock at all
         */
        std::unique_ptr<locking::ILockable> lock;

        /**
         * @brief The LogMessageFormatter used to format incoming LogMessages to string before writing
         * them to the output channel
         */
        std::shared_ptr<LogMessageFormatter> formatter;

    protected:
        /**
         * @brief Actual write operation depending on the output channel
         * @details Acts as a hook method for the template method pattern. This method is invoked from within
         * writeMessage().
         * @param message The text to write to the output channel
         */
        virtual void doWriteMessage(const std::string& message) = 0;

        /**
         * @brief Actual flush operation depending on the concrete output channel
         * @details Acts as a hook method for the template method pattern. This method is invoked from within flush().
         */
        virtual void doFlush() = 0;

    public:
        AbstractLoggingSink();

        /**
         * @brief Delete copy constructor
         * @details Logging sinks are often bound to concrete IO resources which often cannot be copied trivially
         */
        AbstractLoggingSink(AbstractLoggingSink& other) = delete;

        virtual ~AbstractLoggingSink() = default;

        /**
         * Set the semodia::controlengine::native::osal::locking::ILockable to be used from now on
         * @param newLock The semodia::controlengine::native::osal::locking::ILockable instance to use for internal locking
         */
        void setLock(std::unique_ptr<locking::ILockable> newLock);

        /**
         * @see semodia::controlengine::native::osal::logging::ILoggingSink::writeMessage()
         * @details Acts as the template for the template method pattern.
         * Invokes specialized doWriteMessage() implemented in subclass from within.
         */
        void writeMessage(std::shared_ptr<LogMessage> message) override;

        /**
         * @see semodia::controlengine::native::osal::logging::ILoggingSink::flush()
         * @details Acts as the template for the template method pattern.
         * Invokes specialized doFlush() method implemented in subclass from within.
         */
        void flush() override;

        /**
         * @see semodia::controlengine::native::osal::logging::ILoggingSink::setLogMessageFormatter()
         */
        void setLogMessageFormatter(std::shared_ptr<LogMessageFormatter> newFormatter) override;
    };

} // namespace semodia::controlengine::native::osal::logging
#endif // SEMODIA_CONTROLENGINE_NATIVE_ABSTRACTLOGGINGSINK_HPP
