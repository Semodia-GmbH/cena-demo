/**
 * @file      MtpStatusCode.hpp
 * @date      10/5/20
 * @author Chris Paul Iatrou
 * @copyright (c) Semodia GmbH (2022). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_MTPSTATUSCODE_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_MTPSTATUSCODE_HPP

namespace semodia::controlengine::native::model::mtp {
    /**
     * @enum MtpStatusCode
     * @brief A more descriptive alternative for indicating errors used by high-level (non generated) functions.
     */
    enum class MtpStatusCode {
        GOOD,                            //! No error
        ERROR,                           //! Generic error (not specified)
        ERROR_NOT_IMPLEMENTED,           //! The requested functionality does not exist yet
        ERROR_NAME_NOT_UNIQUE,           //! Something that has to be referenced by name (DataAssembly Instance, Service, Parameter...) is a duplicate of an existing item
        ERROR_NO_CALLBACK,               //! A runtime-defined callback does not exist
        BAD_NO_CALLBACK,                 //! A runtime-defined callback does not exist, but it's not a problem and a safe behavior was implemented internally
        ERROR_NOT_FOUND,                 //! Something was not found, e.g. a name in a list or an item by ID
        ERROR_NOT_AVAILABLE,             //! The requested item is not set, currently busy or not determined
        ERROR_NOT_ALLOWED,               //! The operation could be performed, but is explicitly not permitted
        ERROR_NOT_EMPTY,                 //! Usually triggered on an attempt to delete something that still contains members or overwriting an already set variable
        ERROR_INVALID,                   //! An encoding, pointer, datastructure, etc. is not valid in the current context
        ERROR_MISSING_MODEL_ELEMENT,     //! Returned if parts of the model required for operation, e.g. interlockBaseFunctions or OperationModes, are missing
        BAD_MISSING_MODEL_ELEMENT,       //! Parts of the model are incomplete, but the operation did not necessarliy fail
        ERROR_EXPECTED_CALLBACK_ACTION,  //! Set as return value before invoking callbacks to determine that userspace operations succeeded
        ERROR_IN_OFFLINE_MODE,           //! The requested operation is not permitted because assembly|service is offline
        ERROR_IN_OPERATOR_MODE,          //! The requested operation is not permitted because assembly|service is offline
        ERROR_IN_AUTOMATIC_MODE,         //! The requested operation is not permitted because assembly|service is offline
        ERROR_OPERATIONMODE,             //! Generic operationmode error; The mode is invalid, an operation is not permitted with this mode, a mode was not found...
        BAD_OPERATIONMODE,               //! Like ERROR_OPERATIONMODE in every sense, but not fatal
        ERROR_SOURCEMODE,                //! Generic sourcemode error; The sourcemode is invalid, an operation is not permitted with this source mode, a source mode was not found...
        BAD_SOURCEMODE,                  //! Like ERROR_SOURCEMODE in every sense, but not fatal
        BAD_SAFE_FALLBACK_ACTIVE,        //! Something in the internal logic is "weird" - e.g. open+close in BinVlv would trigger setpoint, but setpointEnable is not set. The logic attempts to find a reasonable compromise
        ERROR_USERSPACE_DRIVER_ERROR,    //! Returned by userspace callbacks to notify of interaction problems with a driver
        BAD_USERSPACE_DRIVER_ERROR,      //! Returned by userspace callbacks to notify of interaction problems with a driver
        ERROR_USERSPACE_PROCESS,         //! Returned by userspace callbacks to notify that the given operation cannot be conducted due to the current (PEA)-process state
        BAD_USERSPACE_PROCESS,           //! Returned by userspace callbacks to notify that the given operation cannot be conducted due to the current (PEA)-process state
        ERROR_PARAMETER_INVALID,         //! A function or method parameter is not valid, NULL or not usable in this context
        ERROR_NOT_UNIQUE,                //! There already is one of <thing> that is supposed to be unique <something>
        ERROR_OUT_OF_BOUNDS,             //! Something is too large, too small or not within predefined ranges
        ERROR_COMMAND_ID_NOT_VALID,      //! Returned if a commandId (e.g. CENA internal id) is used in a context where only specific commands are allowed
        ERROR_PROCEDURE_NOT_VALID,       //! The service procedure cannot be used in this context or an expected procedure was not found
        ERROR_SERVICE_STATE_NOT_VALID,   //! The requested state cannot be used in this context, e.g. attaching callbacks to UNDEFINED
        BAD_NO_STATUS_AVAILABLE,         //! Something that is supposed to have a status (e.g. callback completion) does currently not have one
        ERROR_LICENSE_INVALID,           //! The license is not valid (anymore)
    };
} // namespace

#endif //SEMODIA_CONTROLENGINE_NATIVE_MTPSTATUSCODE_HPP
