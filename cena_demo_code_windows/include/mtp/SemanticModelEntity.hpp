/**
 * @file      SemanticModelEntity.hpp
 * @date      1/12/22
 * @createdBy ichrispa
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef CONTROLENGINE_NATIVE_SEMANTICMODELENTITY_HPP
#define CONTROLENGINE_NATIVE_SEMANTICMODELENTITY_HPP

#include "modelsemantics/SemanticModelEntity.hpp"
#include "mtp/MtpTypeIndex.hpp"

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @brief Extends base type from model with interface requirements specific to all MTP model elements
     */
    class SemanticModelEntity : public model::SemanticModelEntity
    {
    public:
        SemanticModelEntity(std::string modelReferenceURI)
            : model::SemanticModelEntity(modelReferenceURI)
        {
            return;
        }

        SemanticModelEntity(std::string modelReferenceURI, SEMODIA_MODEL_NUMERIC_ID_TYPE instanceId)
                : model::SemanticModelEntity(modelReferenceURI, instanceId)
        {
            return;
        }

        SemanticModelEntity()
        {
            return;
        }

        virtual ~SemanticModelEntity() = default;

        /**
         * @brief All MTP model elements are required to implement a simplified form of RTTI so that the reflection API can determine
         *        the class specialization (e.g. AnaMon) from lists containing the base type (e.g. list<IndicatorElement>)
         * @return Enumerated ID of the highest order specialization
         */
        virtual mtp::MtpTypeIndex getTypeId() const = 0;

    };
}
#endif //CONTROLENGINE_NATIVE_SEMANTICMODELENTITY_HPP
