/*
 * @author  Chris Paul Iatrou
 * @date 7/22/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_SEMANTICMODELENTITY_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_SEMANTICMODELENTITY_HPP

#pragma once

#include <memory>

#include "modelsemantics/ModelReferencingSemanticIdentifier.hpp"

namespace semodia::controlengine::native::model
{
    /**
     * @brief Abstract representation of an any object, variable, ... entity inside an information model. A semantic
     *        entity is used as a primitive for basic reflection mechanisms on runtime object instances.
     */
    class SemanticModelEntity
    {
    private:
        /**
         * @brief used as a unique handle to identify the object instance, e.g. in communications.
         *        Note that this is const and will implicitly prevent copy-operations.
         */
        const std::unique_ptr<const ModelReferencingSemanticIdentifier> instanceId;

        /**
         * @brief A URI referencing a semantic tag or model component, e.g. triple-store id, eClass or 61987 CDD
         */
        std::string modelReferenceURI;

        /**
         * @brief Explicit deletion of implicitly deleted copy constructor; an instance of a
         *        SemanticModelEntity cannot be copied. A new instance must be generated.
         */
        SemanticModelEntity& operator=(const SemanticModelEntity&) = delete;
    public:
        SemanticModelEntity(std::string modelReferenceURI);
        SemanticModelEntity(std::string modelReferenceURI, SEMODIA_MODEL_NUMERIC_ID_TYPE instanceId);
        SemanticModelEntity();
        
        virtual ~SemanticModelEntity();
        
        SEMODIA_MODEL_NUMERIC_ID_TYPE getSemanticInstanceId();
    };
    
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_SEMANTICMODELENTITY_HPP
