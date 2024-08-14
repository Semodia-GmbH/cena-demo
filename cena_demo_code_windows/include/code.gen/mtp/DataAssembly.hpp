//GENERATED:  This file is generated; Remove this line to prevent the generator from overwriting this file.

/**
 * @file DataAssembly.hpp
 * @date Wednesday, 2 February 2022 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_DATA_ASSEMBLY_HPP
#define HAVE_DATA_ASSEMBLY_HPP

#pragma once

#include "mtp/base/DataAssembly.hpp"

namespace semodia::controlengine::native::model::mtp 
{
    /**
     * @class DataAssembly
     * @brief DataAssembly defines an element of the InstanceList.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class DataAssembly : public base::DataAssembly
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see _DataAssembly::_DataAssembly for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        DataAssembly( 
            const std::string& TagName, 
            const std::string& TagDescription, 
            std::shared_ptr<mtp::InstanceReferences> References, 
            std::shared_ptr<mtp::ObjectItem> ObjectItem, 
            std::shared_ptr<mtp::Timestamped> Timestamped
        );
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see _DataAssembly::~_DataAssembly  
          */
        virtual ~DataAssembly() = default;
    };   
}

#endif // defined HAVE_DATA_ASSEMBLY_HPP