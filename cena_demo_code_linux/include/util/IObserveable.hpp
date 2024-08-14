/*
 * @author  Chris Paul Iatrou
 * @created 7/23/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_IObserveable_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_IObserveable_HPP

#pragma once

#include <queue>
#include <memory>

namespace  semodia::controlengine::native::util {
    class IObserver;
    
    class IObserveable {
        std::queue<std::shared_ptr<IObserver>> observers;
        
    public:
        IObserveable();
        virtual ~IObserveable();
        
        virtual void notifyObservers() = 0;
        virtual void registerWithObserver(IObserver& observer) = 0;
    };
} //namespace


#endif //SEMODIA_CONTROLENGINE_NATIVE_IObserveable_HPP
