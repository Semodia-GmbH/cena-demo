/**
 * @date 8/21/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_LINLOCK_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_LINLOCK_HPP

#ifndef TARGET_CYGWIN
#error Lock implementation is targeted at POSIX mutexes; won't won't work for your TARGET_PLATFORM
#endif
#include <mutex>

#include "locking/ILockable.hpp"

namespace semodia::controlengine::native::osal::locking {
    class Lock : public ILockable {
    private:
        std::mutex mtx;

    public:
        Lock() = default;
        ~Lock() = default;
        
        bool lock() override;
        bool unlock() override;
        bool trylock() override;
    };
} //namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_LINLOCK_HPP

