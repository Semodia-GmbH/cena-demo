/*
 * @author  Chris Paul Iatrou
 * @date 8/4/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_INSTANCEIDENTIFIERFACTORY_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_INSTANCEIDENTIFIERFACTORY_HPP

#pragma once

#include <memory>
#include "modelsemantics/model_config.hpp"
#include "modelsemantics/ModelReferencingSemanticIdentifier.hpp"
#include "modelsemantics/GlobalSemanticIdentifierFactory.hpp"
#include "modelsemantics/ISemanticIdentifier.hpp"

namespace semodia::controlengine::native::model
{
    /**
     * @class InstanceIdentifierFactory
     * @brief A semi-singleton class that is automatically instantiated on a call to getNewUniqueIdentifier
     */
    class ModelReferencingSemanticIdentifierFactory : public GlobalSemanticIdentifierFactory
    {
    public:
        ModelReferencingSemanticIdentifierFactory() = default;
        virtual ~ModelReferencingSemanticIdentifierFactory() = default;
    
        virtual std::unique_ptr<ISemanticIdentifier<SEMODIA_MODEL_NUMERIC_ID_TYPE>> createNewIdentifier() override;
        virtual std::unique_ptr<ModelReferencingSemanticIdentifier> createNewNumericIdentifier();
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_INSTANCEIDENTIFIERFACTORY_HPP
