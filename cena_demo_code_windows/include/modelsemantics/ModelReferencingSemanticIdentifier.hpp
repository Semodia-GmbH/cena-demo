/*
 * @author  Chris Paul Iatrou
 * @date 8/4/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_MODELREFERENCINGSEMANTICIDENTIFIER_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_MODELREFERENCINGSEMANTICIDENTIFIER_HPP

#pragma once

#include <string>
#include "modelsemantics/ISemanticIdentifier.hpp"
#include "modelsemantics/model_config.hpp"

namespace semodia::controlengine::native::model
{
    /**
     * @class ModelReferencingSemanticIdentifier
     * @brief An identifier containing a model reference (string/uri) along with modelling references and an instance ID
     */
    class ModelReferencingSemanticIdentifier : public ISemanticIdentifier<SEMODIA_MODEL_NUMERIC_ID_TYPE>
    {
    private:
        #ifndef SEMODIA_MODEL_SUPPRESS_STRINGS
        std::string modelUri;
        #endif
    
        const SEMODIA_MODEL_NUMERIC_ID_TYPE instanceId;
    
        /**
         * @brief A semantic identifier is considered unique and cannot be copied.
         */
        ModelReferencingSemanticIdentifier(const ModelReferencingSemanticIdentifier&) = delete;
        ModelReferencingSemanticIdentifier operator= (const ModelReferencingSemanticIdentifier&) = delete;
    public:
        ModelReferencingSemanticIdentifier(std::string modelUri, SEMODIA_MODEL_NUMERIC_ID_TYPE instanceId);
        ModelReferencingSemanticIdentifier(SEMODIA_MODEL_NUMERIC_ID_TYPE instanceId);
        virtual ~ModelReferencingSemanticIdentifier() = default;
    
        /**
         * @copydoc ISemanticIdentifier::toString
         */
        virtual std::string toString() const;
    
        /**
         * @copydoc ISemanticIdentifier::getInstanceId
         */
        virtual SEMODIA_MODEL_NUMERIC_ID_TYPE getInstanceId() const;
    };
}//namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_MODELREFERENCINGSEMANTICIDENTIFIER_HPP
