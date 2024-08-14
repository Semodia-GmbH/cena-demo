/*
 * @author  Chris Paul Iatrou
 * @date 8/4/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ISEMANTICIDENTIFIERFACTORY_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ISEMANTICIDENTIFIERFACTORY_HPP

#include <memory>

#include "locking/Lock.hpp"
#include "modelsemantics/ISemanticIdentifier.hpp"
#include "modelsemantics/model_config.hpp"

namespace semodia::controlengine::native::model
{
    /**
     * @brief Interface to a factory method or class that provides new unique identifiers.
     */
    template<typename T>
    class ISemanticIdentifierFactory
    {
    protected:
    
    public:
        virtual ~ISemanticIdentifierFactory() {};
        
        /**
         * @brief Create a new, globally unique identifier of the given type
         * @return Instance of a new identifier
         */
        virtual std::unique_ptr<ISemanticIdentifier<T>> createNewIdentifier() = 0;
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_ISEMANTICIDENTIFIERFACTORY_HPP
