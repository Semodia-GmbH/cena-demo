/**
 * @file ServiceSet.hpp
 * @date Thursday, September 24, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_SERVICE_SET_HPP
#define HAVE_SERVICE_SET_HPP

#pragma once

#include "mtp/base/ServiceSet.hpp"
#include "mtp/MtpStatusCode.hpp"

namespace semodia::controlengine::native::model::mtp
{
    /**
     * @class ServiceSet
     * @brief Defines the service aspect of the MTP.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class ServiceSet : public base::ServiceSet
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::ServiceSet::base::ServiceSet for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        ServiceSet(std::string Version, std::string DocumentIdentifier);
        
        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::ServiceSet::~base::ServiceSet  
          */
        virtual ~ServiceSet();

        /**
         * @brief A convenience function for both creating and registering a new service with the service set.
         * @param serviceName is the name used for the procedure
         * @param defaultProcedureName is the name for the default procedure that is created automatically
         * @return GOOD on success, ERROR_NAME_NOT_UNIQUE if the name is not unique or an appropriate error code
         */
        virtual MtpStatusCode createService(const std::string& serviceName);

        /**
         * @brief Retrieve a service instance by its name
         * @param serviceName is the tagName used when creating the instance
         * @param instance is a pointer to the instance of the service or a nullptr on error
         * @return GOOD on success, ERROR_NOTFOUND if the service does not exist or an appropriate error code
         */
        virtual MtpStatusCode getServiceByName(const std::string& serviceName, std::shared_ptr<mtp::Service>& instance);

        /**
         * @brief Triggers each service's state logic in sequence; note that if a callback blocks, this will also
         *        block further service execution.
         */
        void update();
    };   
}

#endif // defined HAVE_SERVICE_SET_HPP