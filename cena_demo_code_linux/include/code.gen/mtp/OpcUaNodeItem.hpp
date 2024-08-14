/**
 * @file OpcUaNodeItem.hpp
 * @date Thursday, September 24, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_OPC_UA_NODE_ITEM_HPP
#define HAVE_OPC_UA_NODE_ITEM_HPP

#pragma once

#include "mtp/base/OpcUaNodeItem.hpp"
#include "mtp/MtpStatusCode.hpp"
#include "OpcUaServer.hpp"

namespace semodia::controlengine::native::model::mtp {
    /**
     * @class OpcUaNodeItem
     * @brief The OPC UA node item defining the necessary information to access a node within the corresponding OPC UA server.. 
     *        Unfortunately, the MTP stores all nodeIds as strings... this mandates some unintuitive type handling to ensure
     *        the typeId and the nodeId match.
     */
    class OpcUaNodeItem : public base::OpcUaNodeItem
    {
    protected:
        /**
         * @brief Makes sure the nodeId is a properly formatted string and the class OpcUaNodeTypeId matches the encoded id
         * @param The nodeId to check and potentially reformat
         */
        virtual void checkAndCleanupId();

    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::OpcUaNodeItem::base::OpcUaNodeItem for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        OpcUaNodeItem(const std::string& Name,
                      const std::string& NodeId,
                      const std::string& NamespaceUrl,
                      OpcUaNodeIdType NodeIdType,
                      std::shared_ptr<mtp::OpcUaServer> Server);

        /**
         * @ingroup MTP API
         * @brief Shorthand constructor for no server information, expects NodeId to be encoded with a type (string will be picked otherwise)
         * @param NamespaceUrl is a string namespace URL, default is empty (up to the server to choose)
         * @param NodeId is a string encoded nodeId, such as "i=1202", "g=C496578A-0DFE-4B8F-870A-745238C6AEAE", "s=IAmAString", "o=\x12\x12\x56"
         */
        OpcUaNodeItem(const std::string& NodeId, const std::string& NamespaceUrl="");
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::OpcUaNodeItem::~base::OpcUaNodeItem  
          */
        virtual ~OpcUaNodeItem();

        /**
         * @brief Checks the encoding of nodeId and derives the appropriate type ("s=" --> string, "i=" --> integer, etc.)
         * @param nodeId is the string-encoded id
         * @param type is a pointer to a result-holder, only valid if GOOD is returned (not modified otherwise)
         * @return GOOD if the string is prefixed with a valid encoding
         */
        static MtpStatusCode idTypeFromString(const std::string& nodeId, OpcUaNodeIdType& type);

        /**
         * @ingroup MTP API
         * @brief Encode the OPC UA Node Id as a string
         * @details If a server is set, the string will be prefixed with "endpoint=opc.tcp://some.fwdn.com:4840/...;"
         *          If the namespaceurl is not empty, the string will be prefixed with "ns=<endpointURL>;"
         *          Depending on the type, the id will be encided as "i=...", "s=...", "g=..." or "o=...".
         *          Note that the MTP does not support ByteString or Short IDs.
         * @return  A string encoded as seen above or an empty string if the nodeId type and string storage type don't match.
         */
        virtual std::string toString() const;

        /**
         * @brief Wrapper for frequently used "try-to-convert"-test
         * @param inString is a string value that may contain a numeric value
         * @param value, if not NULL, will be set to the decoded value
         * @param base is the base passed to strtol
         * @return true if the *entire string* is decodable as an integer value, false otherwise
         */
        static bool isNumeric(const std::string &inString, std::uint32_t* value, int8_t base=10, bool allowPartial=false);
    };   
}

#endif // defined HAVE_OPC_UA_NODE_ITEM_HPP