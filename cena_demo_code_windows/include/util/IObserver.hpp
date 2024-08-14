/*
 * @author  Chris Paul Iatrou
 * @created 7/23/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_IOBSERVER_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_IOBSERVER_HPP

#pragma once

namespace  semodia::controlengine::native::util {
    class IObserver {
    public:
        IObserver();
        virtual ~IObserver();
        
        virtual void notifyObserver() = 0;
        virtual void registerObserver(IObserver& observer) = 0;
    };
} //namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_IOBSERVER_HPP
