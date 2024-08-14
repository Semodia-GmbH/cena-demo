/*
 * @author  Georg Graßnick
 * @created 5/28/21
 * @copyright (c) 2021 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_TERMINALOUTPUTSINK_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_TERMINALOUTPUTSINK_HPP

#pragma once

#include "logging/AbstractLoggingSink.hpp"

namespace semodia::controlengine::native::osal::logging
{

    /**
     * @class TerminalOutputSink
     * @brief A Logging sink that writes to stdout
     */
    class TerminalOutputSink : public AbstractLoggingSink
    {

    protected:
        /**
         * @see AbstractLoggingSink::doWriteMessage()
         */
        void doWriteMessage(const std::string& message) override;
        /**
         * @see AbstractLoggingSink::doFlash()
         */
        void doFlush() override;

        /**
         * @see semodia::controlengine::native::osal::tasking::BasicTaskLoopTask::iterate()
         */
        void iterate() override;

    public:
        TerminalOutputSink();
        virtual ~TerminalOutputSink() = default;
    };

} // namespace semodia::controlengine::native::osal::logging

#endif // SEMODIA_CONTROLENGINE_NATIVE_TERMINALOUTPUTSINK_HPP
