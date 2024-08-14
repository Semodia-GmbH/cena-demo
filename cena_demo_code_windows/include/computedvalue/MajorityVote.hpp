/**
 * @file      MajorityVote.hpp
 * @date      4/7/22
 * @createdBy ichrispa
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_MAJORITYVOTE_HPP
#define CONTROLENGINE_NATIVE_MAJORITYVOTE_HPP

#pragma once

#include "computedvalue/AbstractMovingWindow.hpp"
namespace semodia::controlengine::native::util::computedvalue
{
    /**
     * @class MajorityVote
     * @brief Behaves as a boolean and reports what the mojority of booleans in the moving window agree on
     */
    class MajorityVote : public AbstractMovingWindow<bool>
    {
    private:
        /**
         * @brief In windows of even size, this value is returned on ties (i.e. equal number of true and false)
         */
        const bool resultOnTies;

    public:
        MajorityVote(const std::uint32_t windowSize, const bool& initialValue);

        virtual ~MajorityVote() = default;

        MajorityVote(const MajorityVote &other) = default;
        MajorityVote &operator=(const MajorityVote &rhs) = default;

        using AbstractMovingWindow<bool>::operator=;

        virtual bool getValue() const override;

        MajorityVote& operator |=(const bool& rhs);
        MajorityVote& operator &=(const bool& rhs);
        MajorityVote& operator ^=(const bool& rhs);
    };
} // namespace

#endif //CONTROLENGINE_NATIVE_MAJORITYVOTE_HPP
