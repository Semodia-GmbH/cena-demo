/* 
 * @brief   CMake generated, global model configuration header.
 * @author  Chris Paul Iatrou
 * @created 8/4/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_MODEL_CONFIG_H_IN_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_MODEL_CONFIG_H_IN_HPP


#include <stdint.h>

/**
 * @ingroup compile-time configuration
 * @ingroup optional config values
 * @brief Preprocessor directive to inhibit the use of strings wherever technically feasible. Most notably, if defined,
 *        SemanticIdentifiers will not contain URI or RefBase attributes and will be limited to the numeric instance ID.
 */
//#define SEMODIA_MODEL_SUPPRESS_STRINGS

/**
 * @ingroup compile-time configuration
 * @brief The type used as an instance-ID in semantic identifiers; mandatory.
 */
#define SEMODIA_MODEL_NUMERIC_ID_TYPE uint32_t

/**
 * @ingroup compile-time configuration
 * @brief Initial ID used for creating new model elements
 */
#define SEMODIA_MODEL_NUMERIC_ID_INITIAL 1000

#endif //SEMODIA_CONTROLENGINE_NATIVE_MODEL_CONFIG_H_IN_HPP
