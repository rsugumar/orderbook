#include "BidInfo.hpp"
#include "EnumUtils.hpp"

char
BidInfo::getBidSideChar() const {
    return mBidType == BidType::BUY_BID_TYPE ?'B' : 'S';
}

std::ostream&
operator<< (std::ostream& os, const BidInfo& bidInfo) {
    os << "Bid Type: " << EnumUtils::as_integer(bidInfo.mBidType) << std::endl
        << "Bid Price: " << bidInfo.mBidPrice << std::endl
        << "Bid Size: " << bidInfo.mBidSize << std::endl;
    return os;
}