/**
 * @file      IQualityCode.hpp
 * @date      12/4/20
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_IQualityCode_HPP
#define CONTROLENGINE_NATIVE_IQualityCode_HPP

#include <cstdint>
#include "mtp/MtpStatusCode.hpp"
#include "QualityCode.hpp"

namespace semodia::controlengine::native::model::mtp {
    /**
     * @class IQualityCode
     * @brief Defines a common interface for DataItems with the WQC/VQC property, which unfortunately do not inherit
     *        this type from a common parent but need identical handling functions.
     */
    class IQualityCode
    {
    protected:
        /**
         * @brief Included here for the convenience of every function that must implement getQualityCode() (see below)
         * @return A valid enum value, INVALID if the value does not correspond to any known code
         */
        static mtp::QualityCode translateMtpByteToQualityCode(std::uint8_t WqcOrVqcValue)
        {
            switch (WqcOrVqcValue)
            {
                case (std::uint8_t) QualityCode::OK:
                    return QualityCode::OK;
                case (std::uint8_t) QualityCode::NO_STATUS:
                    return QualityCode::NO_STATUS;
                case (std::uint8_t) QualityCode::FAILURE:
                    return QualityCode::FAILURE;
                case (std::uint8_t) QualityCode::FUNCTION_CHECK:
                    return QualityCode::FUNCTION_CHECK;
                case (std::uint8_t) QualityCode::MAINTENANCE_REQUEST:
                    return QualityCode::MAINTENANCE_REQUEST;
                case (std::uint8_t) QualityCode::OUT_OF_SERVICE:
                    return QualityCode::OUT_OF_SERVICE;
                case (std::uint8_t) QualityCode::OUT_OF_SPECIFICATION:
                    return QualityCode::OUT_OF_SPECIFICATION;
                default:
                    return QualityCode::INVALID;
            }
            return QualityCode::INVALID;
        }

    public:
        virtual ~IQualityCode() = default;

        /**
         * @brief Changes the value of WQC/VQC without reallocating it. This method allows the module to update the WQC/VQC to
         *        reflect specific conditions, like a communications failure with whatever updates the value.
         * @param wqcValue is an enumeration class value with specific semantics.
         * @return GOOD if updated, NOT_AVAILABLE if WQC is NULL
         */
        virtual MtpStatusCode setQualityCode(const mtp::QualityCode& qualityCode) = 0;

        /**
         * @brief Returns a valid quality code
         * @return a valid code, QualityCode::INVALID or QualityCode::MISSING if WQC/VWC are NULL
         */
        virtual const mtp::QualityCode getQualityCode() const = 0;
    };
} //namespace

#endif //CONTROLENGINE_NATIVE_IQualityCode_HPP
