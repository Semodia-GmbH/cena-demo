/**
 * @file      LockedObject.hpp
 * @date      3/3/23
 * @author    Georg Graßnick
 * @copyright (c) Semodia GmbH (2023). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_LOCKEDOBJECT_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_LOCKEDOBJECT_HPP

#pragma once

#include <functional>
#include <memory>

#include "locking/ILockable.hpp"

namespace semodia::controlengine::native::osal::locking
{
    /**
     * @brief Restrict access to internal object by ILockable for exclusive access
     * @details The LockedObject is the owner of the internal element
     * @tparam T The type of the stored object
     */
    template <
        class T,
        typename std::enable_if<
            std::is_copy_constructible_v<T>
                && std::is_move_constructible_v<T>, bool>::type = true
        >
    class LockedObject
    {
    private:
        std::unique_ptr<ILockable> lock;
        T val;

    public:
        /**
         * @brief Construct a LockedObject
         * @param lockable the locking facility to use for access management
         * @param value The object to restrict access to
         * @details The locked object takes ownership of @param value
         */
        LockedObject(std::unique_ptr<ILockable> lockable, const T&& value)
            : lock(std::move(lockable))
            , val(std::move(value))
        {
            return;
        }

        /**
         * @brief Perform blocking interaction in locked context.
         * @param f A functional object that describes the interaction with the locked object
         * @details The only parameter provided to the function is the inner object managed by the LockedObject.
         * If the object is already locked, this function will block until the internal lock is released by the former caller.
         */
        void interact(const std::function<void(T&)>& f)
        {
            this->lock->lock();
            std::invoke(f, this->val);
            this->lock->unlock();
            return;
        }

        /**
         * @brief Get a copy of the stored object via its copy constructor
         * @details If the object is already locked, this function will block until the internal lock is released by the former caller.
         * @return The copy of the object as determined by its copy constructor
         */
        T getCopy() const
        {
            this->lock->lock();
            T copy = T(this->val);
            this->lock->unlock();

            // Todo: Is copy elision guaranteed in C++17 here?
            return std::move(copy);
        }

        /**
         * @brief Assign a new value to the LockedObject
         * @param newValue The new value to encapsulate in the LockedObject
         * @details Ownership is transferred to the LockedObject.
         * If the object is already locked, this function will block until the internal lock is released by the former caller.
         */
        void set(T&& newValue)
        {
            this->lock->lock();
            this->val = std::move(newValue);
            this->lock->unlock();
            return;
        }

        /**
         * @brief Attempt interaction with the inner object managed by the LockedObject.
         * When the object is locked, return immediately.
         * @param f A functional object that describes the interaction with the locked object
         * @return True if the operation was performed, false, if the object was locked and no interaction took place.
         */
        bool tryInteract(const std::function<void(T&)>& f)
        {
            const auto acquiredLock = this->lock->trylock();
            if (!acquiredLock)
            {
                return false;
            }
            std::invoke(f, this->val);
            this->lock->unlock();
            return true;
        }
    };
} // namespace semodia::controlengine::native::osal::locking

#endif // SEMODIA_CONTROLENGINE_NATIVE_LOCKEDOBJECT_HPP
