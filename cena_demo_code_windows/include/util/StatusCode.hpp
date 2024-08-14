/**
 * @file      StatusCode.hpp
 * @date      4/22/21
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2021). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_STATUSCODE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_STATUSCODE_HPP


namespace  semodia::controlengine::native::util
{
    /**
     * @enum StatusCode
     * @brief CENA/Global Status code that serves as a template for creating more specialized status codes
     * @details Developers are encouraged to prefer creating their own status code class in their own namespace instead of "picking an approximate" status code from the below template
     */
    enum class StatusCode
    {
        GOOD,                          //! Absence of error, success
        BAD_NOT_FOUND,                 //! An index, object, list/container item was not found; not a fatal error but must be explicitly handled, not GOOD either
        BAD_NOT_UNIQUE,                //! A duplicate entry; not a fatal error but must be explicitly handled, not GOOD either
        BAD_VALUE_OUT_OF_BOUNDS,       //! A bounded (numeric) value is too big or too small; not a fatal error but must be explicitly handled, not GOOD either
        ERROR_NOT_PERMITTED,           //! Not allowed/not permitted by specification
        ERROR_NOT_FOUND,               //! An index, object, list/container item was not found
        ERROR_NOT_IMPLEMENTED,         //! Development placeholder
        ERROR_NOT_UNIQUE,              //! A duplicate entry
        ERROR_VALUE_OUT_OF_BOUNDS,     //! A bounded (numeric) value is too big or too small
        ERROR_VALUE_INVALID,           //! A value is not appropriate in the current context
        ERROR_ARGUMENT_INVALID,        //! A provided argument is not valid in the context of this operation
        ERROR_ARGUMENT_MISSING,        //! An optional argument is required for this functionality, but was not provided
        ERROR_MEMBER_INVALID,          //! The operation requires a member variable/class to operate on, but that member is missing, null or not available
        ERROR_FAILED,                  //! "Generic" error -> if you are inclined to use this, create your own enum class!
        ERROR_UNSPECIFIED              //! "Generic" error -> if you are inclined to use this, create your own enum class!
    };
}

#endif //SEMODIA_CONTROLENGINE_NATIVE_STATUSCODE_HPP
