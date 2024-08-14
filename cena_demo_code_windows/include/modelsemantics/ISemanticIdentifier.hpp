/*
 * @author  Chris Paul Iatrou
 * @date 7/22/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_ISEMANTICIDENTIFIER_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_ISEMANTICIDENTIFIER_HPP

#include <string>
          
namespace semodia::controlengine::native::model
{
    /**
     * @brief A unique identifier that links a model entity to its semantic (and if generated, the information of its origin).
     *        In the simplest case, this can be treated as an instance GUID within an address space.
     * @param typename T is the type used as a instance identifier; this is the only model component that must be
     *        provided by a semantic object and is used to index/retrieve/access a class instance. May be any value, but
     *        must be unique.
     */
    template<typename T>
    class ISemanticIdentifier
    {
    public:
        virtual ~ISemanticIdentifier() = default;
        
        /**
         * @return Return a string representation of the identifier; this must include the instance ID, but may be more elaborate.
         */
        virtual std::string toString() const = 0;
    
        /**
         * @return Return the instance identifier only; other semantic info (model ID, reference URI...) is omitted.
         */
        virtual T getInstanceId() const = 0;
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_ISEMANTICIDENTIFIER_HPP
