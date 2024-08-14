/**
 * @file      FloatPid.hpp
 * @date      3/7/23
 * @author    Georg Graßnick
 * @copyright (c) Semodia GmbH (2023). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_FLOATPID_HPP
#define CONTROLENGINE_NATIVE_FLOATPID_HPP

#pragma once

#include "computedvalue/PidControl.hpp"

namespace semodia::controlengine::native::util::computedvalue
{

    class FloatPid : public PidControl<float, float>
    {
    public:
        FloatPid(
            const float p,
            const float i,
            const float d,
            const float minChange = std::numeric_limits<float>::lowest(),
            const float maxChange = std::numeric_limits<float>::max());

        virtual ~FloatPid() = default;
        FloatPid& operator=(FloatPid&& rhs) noexcept = default;
        FloatPid& operator=(const FloatPid& rhs) noexcept = default;
    };
} // namespace semodia::controlengine::native::util::computedvalue

#endif // CONTROLENGINE_NATIVE_FLOATPID_HPP
