//
// Created by Chris Paul Iatrou on 8/26/20.
//

#ifndef SEMODIA_CONTROLENGINE_NATIVE_OPCUASTATUSCODE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_OPCUASTATUSCODE_HPP

#pragma once

namespace semodia::controlengine::native::reflection::opcua {
    /**
     * @class OpcUaStatusCode
     * @brief A list of status codes used to communicate success or errors (applies to multiple stacks)
     */
    enum class OpcUaStatusCode  {
        GOOD,                              //! No error, success
        ERROR_FAILED,                      //! Generic error in the context of the current operation
        ERROR_INVALID,                     //! The operation failed because it was conducted on an invalid object, e.g. writing a variable to an object node
        ERROR_FORBIDDEN,                   //! Whatever the server/client was instructed to do is not allows, e.g. writing a node w/o permissions
        ERROR_UNSUPPORTED,                 //! The operation is not supported by the client or server, e.g. creating new nodes from the client side
        ERROR_OFFLINE,                     //! An operation can not be performed because the connection is down
        ERROR_CONNECT_FAILED,              //! Connection failed
        ERROR_NOT_FOUND,                   //! In an operation that needs seomething be present or searches something, the item was not found
        ERROR_SERVICEFAIL_BROWSE,          //! The underlying call to this service of the stack returned an error
        ERROR_SERVICEFAIL_ADDNODE,         //! The underlying call to this service of the stack returned an error
        ERROR_SERVICEFAIL_READ,            //! The underlying call to this service of the stack returned an error
        ERROR_SERVICEFAIL_WRITE,           //! The underlying call to this service of the stack returned an error
        ERROR_SERVICEFAIL_ADDREFERENCE,    //! Adding or modifying a reference failed
        ERROR_DUPLICATE,                   //! Something that requires uniqueness already exists
        ERROR_NOT_IMPLEMENTED,             //! Not yet implemented, usually a placeholder during development or a missing upstream feature

        BAD_CLIENT_READ_UNCERTAIN         //! The service returned a valid value but its status was marked as uncertain on the server
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_OPCUASTATUSCODE_HPP

