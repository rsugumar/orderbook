#ifndef __ORDER_INFO_HPP__
#define __ORDER_INFO_HPP__
#pragma once

#include <ostream>
#include "OrderType.hpp"
#include "BidInfo.hpp"

struct OrderInfo {
    OrderInfo() :
            mOrderType{OrderType::UNKNOWN_ORDER_TYPE}, mOrderId{-1}, mGetLevelNo{-1} {}

    OrderType mOrderType;
    int mOrderId;
    BidInfo mBidInfo;
    int mGetLevelNo;
};

std::ostream& operator<< (std::ostream& os, const OrderInfo& orderInfo);

#endif