/***********************************************************************/
/* This file is *generated* - manual modification will be overwritten. */
/***********************************************************************/

/**
 * @file OpcUaNodeIdType.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_OPC_UA_NODE_ID_TYPE_HPP
#define HAVE_OPC_UA_NODE_ID_TYPE_HPP

#pragma once

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @brief Defines the enumeration of node ID types.
     */
    enum class OpcUaNodeIdType 
    {
        Numeric,
        String,
        Guid,
        Opaque
    };   
}

#endif // defined HAVE_OPC_UA_NODE_ID_TYPE_HPP