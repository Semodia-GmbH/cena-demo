/**
 * @file      ServiceStateId.hpp
 * @date      9/30/20
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_SERVICECOMMANDID_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_SERVICECOMMANDID_HPP

#include <cstdint>

namespace semodia::controlengine::native::model::mtp {
    /**
     * @class ServiceCommandId
     * @brief A list of "Commands" (transition IDs) for the service FSM, encoded as a bit vector. This class allows
     *        implicit use as an enum (akin to `enum class`), but is still convertible to an integer for the POL.
     */
    class ServiceCommandId
    {
    private:
        std::uint32_t id;

    public:
        enum CommandName : std::uint32_t
        {
            NONE = 0,
            UNDEFINED = 1 << 0,
            RESET = 1 << 1,        //! 2
            START = 1 << 2,        //! 4
            STOP = 1 << 3,         //! 8
            HOLD = 1 << 4,         //! 16
            UNHOLD = 1 << 5,       //! 32
            PAUSE = 1 << 6,        //! 64
            RESUME = 1 << 7,       //! 128
            ABORT = 1 << 8,        //! 256
            RESTART = 1 << 9,      //! 512
            COMPLETE = 1 << 10     //! 1024
        };

        /**
         * @brief  Bottom 11 bits of command word are listed in spec as reserved; usable as mask to clean up user input
         */
        static const std::int32_t RESERVED_COMMAND_BYTES = ~(0b11111111111);

        ServiceCommandId();
        ServiceCommandId(CommandName id);
        ServiceCommandId(std::uint32_t id);
        ~ServiceCommandId();

        /**
         * @brief Enables comparison with enum
         */
        bool operator==(const ServiceCommandId &rhs) const;
        bool operator==(const ServiceCommandId::CommandName &rhs) const;

        /**
         * @brief Copy constructor
         */
        ServiceCommandId(const ServiceCommandId &value);

        /**
         * @brief Assignment constructor; will copy a valid commandid into the new id
         */
        ServiceCommandId& operator=(const ServiceCommandId& value);
        ServiceCommandId& operator=(const ServiceCommandId::CommandName& value);

        /**
         * @brief Someone decided that a command request can be encoded as a bitvector, but neglected to consider what
         *        happens if the user passes, say 0xFFFFFF (all commands).
         * @param value is an arbitrary integer
         * @return The command exactly matching value; UNDEFINED if there is no match.
         */
        ServiceCommandId& operator=(const std::uint32_t& value);

        /**
         * @brief Allow implicit  conversion to uint32
         */
        operator std::uint32_t() const;

    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_SERVICECOMMANDID_HPP
