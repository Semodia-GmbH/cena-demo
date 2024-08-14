/* 
 * @brief   
 * @author  Chris Paul Iatrou
 * @date 7/21/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ILOCKABLE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ILOCKABLE_HPP

#pragma once

namespace semodia::controlengine::native::osal::locking {
    
    /**
     * @brief A lockable object's interface, roughly modelled akin to a POSIX mutex
     */
    class ILockable {
    public:
        ILockable() {};
        virtual ~ILockable() {};
        
        /**
         * @brief Obtain a lock on a lockable object (aka mutex.lock()).
         * @return True if a lock was obtained, false otherwise.
         */
        virtual bool lock() = 0;
        
        /**
         * @brief Return a lock from a lockable object (aka mutex.unlock()).
         * @return True if unlock succeeded.
         */
        virtual bool unlock() = 0;
        
        /**
         * @brief Attempt to lock, but don't block.
         * @return true if lock was obtained, false if lock is currently unavailable.
         */
        virtual bool trylock() = 0;
    };
} //namespace semodia::controlengine::native::osal

#endif //SEMODIA_CONTROLENGINE_NATIVE_ILOCKABLE_HPP
