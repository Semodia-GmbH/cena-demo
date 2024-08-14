/**
 * @file BinView.hpp
 * @date Thursday, September 24, 2020 
 * @copyright (c) Semodia GmbH 2020. All Rights Reserved.
 */

#ifndef HAVE_BIN_VIEW_HPP
#define HAVE_BIN_VIEW_HPP

#pragma once

#include <cstdint>
#include "mtp/base/BinView.hpp"
#include "mtp/IFreezableValue.hpp"

namespace semodia::controlengine::native::model::mtp {
    /**
     * @class BinView
     * @brief BinView defines a view element of a binary value.. 
     *        This is the class implementation, possibly extending the base class with business logic, convenience functions or added functionality.
     */
    class BinView : public base::BinView, public IFreezableValue<bool>
    {
    public:
        /**
         * @ingroup Generated
         * @ingroup MTP API
         * @brief Will invoke parent constructor @see base::BinView::base::BinView for pre-constructor-call allocation. 
         *        May add additional logic after default values have been assigned.  
         */
        BinView(const std::string& TagName,
                const std::string& TagDescription,
                std::shared_ptr<mtp::InstanceReferences> References,
                std::shared_ptr<mtp::ObjectItem> ObjectItem,
                std::shared_ptr<mtp::Timestamped> Timestamped,
                std::shared_ptr<mtp::MissedValueFlag> MissedValueFlag,
                std::shared_ptr<mtp::ReadDataItem<std::uint8_t>> WQC,
                std::shared_ptr<mtp::ReadDataItem<bool>> V,
                std::shared_ptr<mtp::ReadDataItem<std::string>> VState0,
                std::shared_ptr<mtp::ReadDataItem<std::string>> VState1
        );

        /**
         * @brief Simplified C'Tor; instantiates all members and provides a more direct config mechanism
         * @param initialValue is the value assumed by V after instantiation
         * @param interpretationOfTrue describes (as string) what "True"/1 means in the context of this BinView
         * @param interpretationOfFalse describes (as string) what "False"/0 means in the context of this BinView
         */
        BinView(const std::string& TagName, const std::string& TagDescription,
                bool initialValue, const std::string& interpretationOfTrue, const std::string& interpretationOfFalse);

        /**
          * @ingroup Generated
          * @ingroup MTP API
          * @brief May invoke custom business logic; neither de-allocates (delete) nor sets any pointers 
          *        to null; those are done by base class @see base::BinView::~base::BinView  
          */
        virtual ~BinView();

        /**
         * @brief Setting an AnaView sets the BinView.V to the given value
         * @param value
         */
        virtual void setV(const bool& value);
        using base::BinView::setV;

        /**
         * @brief Changes the string values that provide the interpretation of the boolean true/false values
         * @param interpretationOfTrue is a string describing what "true"/High/1 means in the context of this BinView
         * @param interpretationOfFalse is a string describing what "false"/Low/0 means in the context of this BinView
         */
        virtual void setBooleanInterpretation(const std::string& interpretationOfTrue, const std::string& interpretationOfFalse);

        /**
         * @brief Assignment operator is a shorthand for @see setV()
         * @param value
         */
        virtual BinView& operator=(const bool& rhs);

        /**
         * @brief Allow direct comparison of BinView with boolean
         */
        virtual bool operator==(const bool& rhs) const;

        /**
         * @brief Derived from ==
         */
        virtual bool operator!=(const bool& rhs) const;

        /**
         * @brief Allow implicit conversion of BinViews to bool
         */
        operator bool() const;
    };   
}

#endif // defined HAVE_BIN_VIEW_HPP