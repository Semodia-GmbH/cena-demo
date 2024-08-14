/**
 * @brief     This header acts as a proxy for the version-specific headers and definitions of open62541
 *            it can be included by the API and may contain compatibility definitions and macros in the future
 *            THIS FILE DOES NOT CONTAINS C++ A CLASS.
 * @date      8/28/20
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_OPEN62541COMPAT_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_OPEN62541COMPAT_HPP

#pragma once

// Include a specific version of the stack, either as a single file or multiple files
#include "_open62541.h"

// Include the default type converter
#include "opcua/open62541/Open62541TypeTool.hpp"

#endif //SEMODIA_CONTROLENGINE_NATIVE_OPEN62541COMPAT_HPP
