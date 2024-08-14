/**
 * @date      8/28/20
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_OPEN62541TYPETOOL_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_OPEN62541TYPETOOL_HPP

#pragma once

#include <any>
#include <cstdint>
#include <string>
#include <vector>

#include "open62541_compat.hpp"
#include "opcua/uatypes/OpcUaGuid.hpp"
#include "opcua/uatypes/NodeId.hpp"

namespace semodia::controlengine::native::reflection::opcua
{
    /**
     * @class Open62541TypeConverter
     * @brief
     */
    class Open62541TypeTool
    {
    public:
         ~Open62541TypeTool() = default;

         // The following convert directly from/to
         /**
          * @brief String conversion helper function from OpcUa to Cpp
          * @param from this OPC UA String
          * @return a std::string instance
          */
         static std::string toCppString(const UA_String& from);

         /**
          * @brief String conversion helper function from Cpp to OpcUa
          * @param from this OPC UA String
          * @return a new UA_String
          */
         static UA_String toUaString(const std::string& from);

         /**
          * @brief GUID conversion helper function from OpcUa to Cpp
          * @param from this open62541 GUID representation
          * @return a OpcUaGuid, stack agnostic instance
          */
         static GUID toCppGUID(const UA_Guid& from);

         /**
          * @brief GUID conversion helper function from Cpp to OpcUa
          * @param from this open62541 GUID representation
          * @return a OpcUaGuid, stack agnostic instance
          */
         static UA_Guid toUaGUID(const GUID& from);

         /**
          * @brief GUID conversion helper function from OpcUa to Cpp
          * @param from this open62541 GUID representation
          * @return a OpcUaGuid, stack agnostic instance
          */
         static NodeId toCppNodeId(const UA_NodeId& from);

         /**
          * @brief GUID conversion helper function from Cpp to OpcUa
          * @param from this open62541 GUID representation
          * @return a OpcUaGuid, stack agnostic instance
          */
         static UA_NodeId toUaNodeId(const NodeId& from);

         // The next two convert packed data types
         /**
          * @brief General-purpose type container conversion: Turns an any-type into a UA Variant
          * @param from is any std::any type; if any.empty(), then the variant will be empty as well
          * @return a matching variant containing a UA_type best matching the C++ type
          */
         static UA_Variant toUaVariant(const std::any& from);

         /**
          * @brief Like `static UA_Variant toUaVariant(const std::any& from);`, but uses pre-existing variant.
          */
         static void toUaVariant(const std::any& from, UA_Variant& to);

        /**
         * @brief General-purpose type container conversion: Turns an UA_Variant into an any-type
         * @param from is any UA_Variant; if the variant contains no value, the resulting std::any will be empty as well
         * @return a matching std:any containing a C/C++ type best matching the UA type
         */
         static std::any toCppAny(const UA_Variant& from);

         /**
          * @brief UA_ByteString conversion helper
          * @param bytes is a vector of std::uint8_t that represents the bytes that should be contained in the resulting UA_ByteString
          * @return a matching ByteString containing the set of bytes requested
          */
         static UA_ByteString toUaByteString(const std::vector<std::uint8_t>& bytes);
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_OPEN62541TYPETOOL_HPP

