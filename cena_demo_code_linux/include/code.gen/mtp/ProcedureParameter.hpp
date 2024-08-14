//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file ProcedureParameter.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_PROCEDURE_PARAMETER_HPP
#define HAVE_PROCEDURE_PARAMETER_HPP

#pragma once

#include "mtp/base/ProcedureParameter.hpp"
#include "mtp/MtpStatusCode.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class ProcedureParameter
     * @brief The procedure parameter.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ProcedureParameter : public base::ProcedureParameter
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _ProcedureParameter::_ProcedureParameter for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ProcedureParameter( 
            const std::string& Name, 
            std::shared_ptr<mtp::ParameterElement> ReferencedDataAssembly
        );

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers
          *        to null; those are done by base class @see _ProcedureParameter::~_ProcedureParameter
          */
        virtual ~ProcedureParameter() = default;

    };   
}

#endif // defined HAVE_PROCEDURE_PARAMETER_HPP