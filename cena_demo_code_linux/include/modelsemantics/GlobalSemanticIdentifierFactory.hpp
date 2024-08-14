/*
 * @author  Chris Paul Iatrou
 * @date 8/4/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_GLOBALSEMANTICIDENTIFIERFACTORY_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_GLOBALSEMANTICIDENTIFIERFACTORY_HPP

#pragma once

#include "modelsemantics/model_config.hpp"
#include "locking/Lock.hpp"
#include "ISemanticIdentifierFactory.hpp"

namespace semodia::controlengine::native::model
{
    /**
     * @brief An abstract base factory class handling the the singleton-like access to a global instanceId counter.
     *        Implements a shared instanceId and an associated lock for all factories.
     */
    class GlobalSemanticIdentifierFactory : public ISemanticIdentifierFactory<SEMODIA_MODEL_NUMERIC_ID_TYPE>
    {
    private:
        static SEMODIA_MODEL_NUMERIC_ID_TYPE globalUniqueNextInstanceId;
        static semodia::controlengine::native::osal::locking::Lock instanceIdAccessLock;
        
    protected:
        SEMODIA_MODEL_NUMERIC_ID_TYPE getNextNewInstanceId();
        
    public:
        GlobalSemanticIdentifierFactory() = default;
        virtual ~GlobalSemanticIdentifierFactory() = default;
    };
} // namespace


#endif //SEMODIA_CONTROLENGINE_NATIVE_GLOBALSEMANTICIDENTIFIERFACTORY_HPP
