/**
 * @file      WQC.hpp
 * @date      12/4/20
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_WQC_HPP
#define CONTROLENGINE_NATIVE_WQC_HPP

#include <cstdint>

namespace semodia::controlengine::native::model::mtp {
    /**
     * @mtp::QualityCode
     * @brief The Worst Quality Code contains the worst Quality Code of a specific variable; its
     *        interpretation is specific to the variable holding it.
     */
    class QualityCode
    {
    private:
        std::uint8_t value;

    public:
        enum QualityCodeName : std::uint8_t
        {
            NO_STATUS = (std::uint8_t) 0xFF,   //! Graue Gruppe, NE107
            FAILURE = (std::uint8_t) 0x00,   //! Graue Gruppe, NE107
            FUNCTION_CHECK = (std::uint8_t) 0x60,   //! Graue Gruppe, NE107
            MAINTENANCE_REQUEST = (std::uint8_t) 0xA4,   //! Graue Gruppe, NE107
            OUT_OF_SPECIFICATION = (std::uint8_t) 0x68,   //! Graue Gruppe, NE107
            OK = (std::uint8_t) 0x80,   //! Graue Gruppe, NE107
            OUT_OF_SERVICE = (std::uint8_t) 0x1C,   //! Graue Gruppe, NE107
            INVALID,                                      //! There is a value, but its not a valid/defined quality code
            MISSING                                       //! The model element that sets the quality code is missing from the object
        };

        QualityCode();
        QualityCode(const std::uint8_t other);
        QualityCode(const QualityCode& other);
        ~QualityCode() = default;

        /**
         * @brief Allow comparison with unitcode or unitcode name, i.e. `== mtp::QualityCode::Ohm`
         */
        bool operator==(const QualityCode& rhs) const;
        bool operator==(const QualityCodeName& rhs) const;

        /**
         * @brief Numeric comparison based on unit code integer value; allows use of unitcode as keys in collections/maps/sets
         */
        bool operator>(const QualityCode& rhs) const;
        bool operator>(const QualityCodeName& rhs) const;

        /**
         * @brief Inequality derived from ==
         */
        bool operator!=(const QualityCode& rhs) const;
        bool operator!=(const QualityCodeName& rhs) const;

        /**
         * @brief Assigns unit code value of rhs to this UniCode
         */
        QualityCode& operator=(const QualityCode& rhs);
        QualityCode& operator=(const QualityCodeName& rhs);

        /**
         * @brief Checks rhs integer value for validity/coresponance with unit code names; assigns INVALID if no match is found
         * @details This essential type-check allows using QualityCodes safely - i.e. it is also used in conversions where the
         *          SDK returns a guaranteed valid unitcode that (for the VDI/VDE/NAMUR 2658) is only encoded as integer.
         */
        QualityCode& operator=(const std::uint8_t& rhs);

        /**
         * @brief Permits use of assigned unit value as integer
         */
        operator std::uint8_t() const;
    };
} //namespace

#endif //CONTROLENGINE_NATIVE_WQC_HPP
