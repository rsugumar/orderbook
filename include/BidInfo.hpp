#ifndef __BID_INFO_HPP__
#define __BID_INFO_HPP__
#pragma once

#include <ostream>
#include "BidType.hpp"

struct BidInfo {
    public:
        BidInfo() :
            mBidType {BidType::UNKNOWN_BID_TYPE}, mBidPrice {0.0}, mBidSize {-1} {}

        BidInfo(BidType type, double price, int size) :
            mBidType(type), mBidPrice(price), mBidSize(size) {}
        
        BidInfo(char bidType, double price, int size) :
            mBidPrice(price), mBidSize(size) {
                mBidType = ::toupper(bidType)=='B' ?BidType::BUY_BID_TYPE :BidType::SELL_BID_TYPE;
            }

        char getBidSideChar() const;

        BidType mBidType;
        double mBidPrice;
        int mBidSize;
};

std::ostream& operator<< (std::ostream& os, const BidInfo& bidInfo);

#endif