/**
 * @file      ServiceStateId.hpp
 * @date      9/30/20
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_SERVICESTATEID_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_SERVICESTATEID_HPP

#include <cstdint>

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @class ServiceStateId
     * @brief A listing of state IDs, including their encodings as per table 10, VDI/VDE/NAMUR  2658-3
     */
    class ServiceStateId
    {
    private:
        /**
         * @brief Internal encoding/storage type; not accessible to external values
         */
        std::uint32_t id;

        /**
         * @brief Encoder from external integer encoding to internal storage type; guarantees valid enum value is picked
         * @details Will only permit valid, MTP-conforming integers (not CENA-internal hierarchic or assistive init states)
         *          So setting `id=LEVEL_4` will result in `id==UNDEFINED`
         */
        void setIdFromValue(const std::uint32_t& value);

    public:
        enum StateName : std::uint32_t
        {
            UNDEFINED = 1 << 0,  //! 0x0000001, 0d1
            NOTUSED = 1 << 1,    //! 0x0000002, 0d2
            STOPPED = 1 << 2,    //! 0x0000004, 0d4, possibly destructive to product, harmless to PEA
            STARTING = 1 << 3,   //! 0x0000008, 0d8
            IDLE = 1 << 4,       //! 0x0000010, 0d16
            PAUSED = 1 << 5,     //! 0x0000020, 0d32
            EXECUTE = 1 << 6,    //! 0x0000040, 0d64
            STOPPING = 1 << 7,   //! 0x0000080, 0d128, possibly destructive to product, harmless to PEA
            ABORTING = 1 << 8,   //! 0x0000100, 0d256, possibly destructive to PEA
            ABORTED = 1 << 9,    //! 0x0000200, 0d512, possibly destructive to PEA
            HOLDING = 1 << 10,   //! 0x0000400, 0d1024
            HELD = 1 << 11,      //! 0x0000800, 0d2048
            UNHOLDING = 1 << 12, //! 0x0001000, 0d4096
            PAUSING = 1 << 13,   //! 0x0002000, 0d8192
            RESUMING = 1 << 14,  //! 0x0004000, 0d16384
            RESETTING = 1 << 15, //! 0x0008000, 0d32769
            COMPLETING = 1 << 16,//! 0x0010000, 0d65536
            COMPLETED = 1 << 17, //! 0x0020000, 0d131072
            LEVEL5,
            LEVEL4,
            LEVEL3,
            LEVEL2,
            LEVEL2_INIT, // Helper state: handles ambiguous entry of --START-->Starting and --UNHOLD-->UNHOLDING
            LEVEL1,
            LEVEL1_INIT, // Initial of Lvl1; can't have enter() or stay() callbacks.
        };

        ServiceStateId();
        ServiceStateId(const StateName& id);
        ServiceStateId(const std::uint32_t& id);
        ~ServiceStateId();

        /**
         * @brief Enables comparison with enum
         */
        bool operator==(const ServiceStateId &rhs) const;
        bool operator==(const StateName &rhs) const;

        /**
         * @brief Comparison operator needed to make this value mappable
         */
        bool operator<(const StateName &rhs) const;

        /**
         * @brief Derived operators
         */
        bool operator>(const StateName &rhs) const;
        bool operator!=(const StateName &rhs) const;

        /**
         * @brief Copy constructor
         */
        ServiceStateId(const ServiceStateId&value);
        ServiceStateId(ServiceStateId&& rvalue);

        /**
         * @brief Assignment constructor; will copy a valid commandid into the new id
         */
        ServiceStateId& operator=(const ServiceStateId& value);
        ServiceStateId& operator=(ServiceStateId&& rvalue);
        ServiceStateId& operator=(const StateName& value);

        /**
         * @brief Allow conversion from integer
         */
        ServiceStateId& operator=(const std::uint32_t& value);

        /**
         * @brief Allow implicit conversion to integers
         */
        explicit operator std::uint32_t() const;

        /**
         * @brief Allow implicit conversion to contained type
         */
        operator StateName() const;
    };
}

#endif //SEMODIA_CONTROLENGINE_NATIVE_SERVICESTATEID_HPP
