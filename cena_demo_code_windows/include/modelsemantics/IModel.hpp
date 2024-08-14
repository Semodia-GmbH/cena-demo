/*
 * @author  Chris Paul Iatrou
 * @date 7/22/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_IMODEL_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_IMODEL_HPP

#pragma  once

#include <string>

namespace semodia::controlengine::native::model {
    /**
     * @brief Model interface defining basic operations and attributes provided to interact with a container of
     *        entity instances.
     */
    class IModel {
    protected:
        /**
         * @brief Human readable model name, e.g. "Module Type Package (MTP)" or "Process Automation Device Integration Model (PA-DIM)".
         */
        std::string modelName;

        /**
         * @brief An URI to a machine readable model definition, e.g. an XSD document.
         */
        std::string modelURI;

    public:
        IModel();
        virtual ~IModel();

        /**
         * @ingroup modelInformation || SemanticClassEntity
         * @return a human readable name for the information model used
         */
        virtual std::string getModelName()  const;

        /**
         * @ingroup modelInformation
         * @return a machine readable reference for the information model used
         */
        virtual std::string getModelURI() const;
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_IMODEL_HPP
