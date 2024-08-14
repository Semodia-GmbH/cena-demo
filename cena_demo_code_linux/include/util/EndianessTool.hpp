/**
 * @file      EndianessTool.hpp
 * @date      11/2/20
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ENDIANESSTOOL_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ENDIANESSTOOL_HPP

#include <cstdint>
#include <stddef.h>

namespace  semodia::controlengine::native::util
{
    /**
     * @class EndianessDetector
     * @brief A helper class that detects the endianness of the current system
     */
    class EndianessTool
    {
    public:
        EndianessTool() = delete;
        virtual ~EndianessTool() = default;

        EndianessTool(const EndianessTool& other) = default;
        EndianessTool& operator=(const EndianessTool& rhs) = default;

        /**
         * @brief Detects if an integer 0x12345678 is stored as 0x78, 0x56...
         * @return true if system is little endian (aka. motorolla byte order)
         */
        constexpr static bool isBigEndian()
        {
            constexpr std::uint16_t u16 = 1;
            constexpr std::uint8_t u8 = (const std::uint8_t&)u16;
            return !(u8);
        }

        /**
         * @brief Detects if an integer 0x12345678 is stored as 0x12, 0x34...
         * @return true if system is little endian (aka. motorolla byte order)
         */
        constexpr static bool isLittleEndian()
        {
            return !isBigEndian();
        }

        /**
         * @brief Converts a known little-Endian (intel) memory area to the native format by swapping bytes as necessary
         * @param mem_ptr is the area to convert
         * @param mem_size is the size of the memory area (in bytes)
         */
        static void littleEndianToNative(void* const mem_ptr, size_t mem_size);

        /**
         * @brief Converts a known big-Endian (motorolla) memory area to the native format by swapping bytes as necessary
         * @param mem_ptr is the area to convert
         * @param mem_size is the size of the memory area (in bytes)
         */
        static void bigEndianToNative(void* const mem_ptr, size_t mem_size);

        /**
         * @brief Converts a known little-Endian memory area to the native format by swapping bytes as necessary
         * @param mem_ptr is the area to convert
         * @param mem_size is the size of the memory area (in bytes)
         */
        static void nativeToLittleEndian(void* const mem_ptr, size_t mem_size);

        /**
         * @brief Converts a known little-Endian memory area to the native format by swapping bytes as necessary
         * @param mem_ptr is the area to convert
         * @param mem_size is the size of the memory area (in bytes)
         */
        static void nativeToBigEndian(void* const mem_ptr, size_t mem_size);

        /**
         * @brief Swap the order of the bytes in this given memory area
         * @param mem_ptr is the area to convert
         * @param mem_size is the size of the memory area (in bytes)
         */
        static void swapByteOrder(uint8_t* const mem_ptr, size_t mem_size);
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_ENDIANESSTOOL_HPP
