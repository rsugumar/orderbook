#include "OrderInfo.hpp"
#include "EnumUtils.hpp"

std::ostream&
operator<< (std::ostream& os, const OrderInfo& orderInfo) {
    os << "Order Type: " << EnumUtils::as_integer(orderInfo.mOrderType) << std::endl
        << "Order ID: " << orderInfo.mOrderId << std::endl
        << "Bid Info: " << orderInfo.mBidInfo << std::endl
        << "Get Level No: " << orderInfo.mGetLevelNo << std::endl;
    return os;
}