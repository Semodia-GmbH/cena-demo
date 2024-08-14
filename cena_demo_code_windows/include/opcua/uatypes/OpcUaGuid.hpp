/**
 * @date      9/2/20
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_OPCUAGUID_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_OPCUAGUID_HPP

#pragma once

#include <cstdint>

namespace semodia::controlengine::native::reflection::opcua {
    /**
     * @class GUID
     * @brief This represents an OPC UA GUID, usable as a field in NodeIds (stack-agnostic)
     */
    class GUID {
    public:
        GUID();
        GUID(const std::uint32_t data1, const std::uint16_t data2, const std::uint16_t data3, const std::uint8_t data4[8]);
        ~GUID() = default;

        std::uint32_t data1;
        std::uint16_t data2;
        std::uint16_t data3;
        std::uint8_t data4[8];

        void clear();

        // defined
        bool operator==(const GUID &other) const;
        bool operator<(const GUID &other) const;

        //derived
        bool operator!=(const GUID &other) const;
        bool operator>(const GUID &other) const;

    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_OPCUAGUID_HPP
