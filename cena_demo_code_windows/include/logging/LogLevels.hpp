/*
 * @author  Chris Paul Iatrou, Georg Graßnick
 * @created 7/29/20
 * @copyright (c) 2021 Semodia GmbH. All Rights Reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_LOG_LEVELS_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_LOG_LEVELS_HPP

#pragma once

namespace semodia::controlengine::native::osal::logging
{

    /**
     * @class LogLevel
     * @brief Encapsulates available Log Levels (i.e. severities) for logging messages
     */
    class LogLevel
    {
    public:
        /**
         * @brief Traditional log "Levels"; note that these levels are not necessarily ordered in
         *        this enum, e.g. warn and warning have the same semantic.
         */
        enum Severity
        {
            none,    //! No level is attributed to the message/output; a sign to ignore level-semantics
            debug,   //! Logs aimed at developers
            info,    //! Logs aimed at users
            warning, //! Non-critical
            warn,    //! Non-critical; common lazy alias for warning
            error,   //! Critical notifications that are commonly handled
            fatal,   //! Critical notifications that is unhandled; will (or should) cause process or task to terminated
            max,     //! Alias for fatal
        };

        LogLevel();
        LogLevel(Severity level);
        LogLevel(const LogLevel& other);
        virtual ~LogLevel() = default;

        LogLevel& operator=(const Severity& other);
        LogLevel& operator=(const LogLevel& other) = default;

        bool operator<(const LogLevel& other) const;
        bool operator<(const Severity& other) const;
        bool operator>(const LogLevel& other) const;
        bool operator>(const Severity& other) const;
        bool operator==(const LogLevel& other) const;
        bool operator==(const LogLevel::Severity& other) const;
        bool operator!=(const LogLevel& other) const;
        bool operator!=(const LogLevel::Severity& other) const;
        bool operator<=(const LogLevel& other) const;
        bool operator<=(const Severity& other) const;
        bool operator>=(const LogLevel& other) const;
        bool operator>=(const Severity& other) const;

        operator Severity() const;

    private:
        Severity severity;
    };

} // namespace semodia::controlengine::native::osal::logging

#endif // SEMODIA_CONTROLENGINE_NATIVE_LOG_LEVELS_HPP
