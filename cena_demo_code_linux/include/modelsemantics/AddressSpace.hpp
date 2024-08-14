/*
 * @author  Chris Paul Iatrou
 * @date 7/22/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ADDRESSSPACE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ADDRESSSPACE_HPP

#pragma once

#include <map>

#include "modelsemantics/ISemanticIdentifier.hpp"
#include "modelsemantics/SemanticModelEntity.hpp"
#include "IModel.hpp"

namespace semodia::controlengine::native::model
{
    /**
     * @brief An addresspace is a container for entities (objects, variables, etc.). It implements the IModel interface,
     *        allowing external components to interact with the instances.
     */
    class AddressSpace : public IModel
    {
    private:
        //std::map<ISemanticIdentifier&, SemanticEntity> entityInstances;
        
        /**
         * @brief Copy constructor is deleted; an instanceModel cannot not be copied. It would imply a deep-copy of
         *        all referenced instances, which would invalidate the uniqueness-constraint of the semantic identifier.
         */
        AddressSpace(const AddressSpace &) = delete;
        AddressSpace& operator= (const AddressSpace &) = delete;
        
    public:
        AddressSpace();
        virtual ~AddressSpace();
    };
    
} // namespace


#endif //SEMODIA_CONTROLENGINE_NATIVE_ADDRESSSPACE_HPP

