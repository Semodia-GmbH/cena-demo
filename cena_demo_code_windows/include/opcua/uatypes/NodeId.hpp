/**
 * @date      9/2/20
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */
/**
 * @date      9/2/20
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_NODEID_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_NODEID_HPP

#pragma once

#include <cstdint>
#include <string>
#include "OpcUaGuid.hpp"
#include "opcua/uatypes/NodeId.hpp"

namespace semodia::controlengine::native::reflection::opcua
{
    /**
     * @enum NodeIdType
     * @brief Types of nodeid encodings; ">" operator is defined in the order given here (i.e. GUID > SHORT_NUMERIC)
     */
    enum class NodeIdType
    {
        SHORT_NUMERIC,
        NUMERIC,
        STRING,
        BYTESTRING,
        GUID,
    };

    /**
     * @brief A struct that can contain any of the possible node-id types
     */
    typedef struct {
        uint32_t i;
        std::string s;
        GUID g;
    } OpcUaMultitypeNodeId;

    /**
     * @class NodeId
     * @brief
     */
    class NodeId {
    protected:
        /**
         * @brief indicate the type of
         */
        NodeIdType type;

        /**
         * @brief stores the actual if value; can't be a memory-saving union because that would delete the DTor of g and s
         */
        OpcUaMultitypeNodeId id;

        /**
         * @brief the namespace index of this node. This should be provided by the server.
         */
        std::uint16_t namespaceIndex;
    public:
        /**
         * @brief CTor for numeric (short) nodeIds
         * @param namespaceIndex
         * @param id
         */
        NodeId(std::uint16_t namespaceIndex, std::uint8_t id);

        /**
         * @brief CTor for "normal" (short) nodeIds
         * @param namespaceIndex
         * @param nodeId; CTor will still construct a short nodeId if id < 8
         */
        NodeId(std::uint16_t namespaceIndex, std::uint32_t id);

        /**
         * @brief constructor used for String-NodeIds or ByteString-NodeIds
         * @param namespaceIndex
         * @param stringId will be interpreted as bytestring if it contains ASCII outside the range of 33-125; as a string otherwise.
         */
        NodeId(std::uint16_t namespaceIndex, std::string id);

        /**
         * @brief Rare but quite possible GUID CTor
         * @param namespaceIndex
         * @param guid
         */
        NodeId(std::uint16_t namespaceIndex, GUID id);

        /**
         * @brief CTor for a null-id; usable to signify "None" or "Any"
         */
        NodeId();

        ~NodeId() = default;

        /**
         * @return a non-modifiable pointer to our type field
         */
        const NodeIdType& getType() const;

        /**
         * @return a non-modifiable pointer to the contentof our id field
         */
        const OpcUaMultitypeNodeId& getIdContent() const;

        /**
         * @return a non-modifiable pointer to our namespace index
         */
        const std::uint16_t& getNamespaceIndex() const;

        /**
         * @return true if nsindex=0, numeric & id.i=0; usable as "AnyId" or "NoId"
         */
        bool isNull() const;

        // Defined
        NodeId& operator= (const NodeId &other);
        bool operator== (const NodeId &other) const;
        bool operator< (const NodeId &other) const;

        // Derived from ==, <
        bool operator> (const NodeId &other) const;
        bool operator!= (const NodeId &other) const;
    };
}

#endif //SEMODIA_CONTROLENGINE_NATIVE_NODEID_HPP
