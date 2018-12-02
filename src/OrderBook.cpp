#include <iostream>
#include "OrderBook.hpp"

void
OrderBook::add(int order_id, char side, double price, int size) {
    switch(side) {
        case 'B': {
            if (mBuySidePriceToSizeMap.find(price) != mBuySidePriceToSizeMap.end()) {
                mBuySidePriceToSizeMap[price] += size;
            } else {
                mBuySidePriceToSizeMap[price] = size;
            }
        }
        break;

        case 'S': {
            if (mSellSidePriceToSizeMap.find(price) != mSellSidePriceToSizeMap.end()) {
                mSellSidePriceToSizeMap[price] += size;
            } else {
                mSellSidePriceToSizeMap[price] = size;
            }
        }
        break;

        default: {
            std::cout << "OrderBook::add: Encountered unrecognized side" << std::endl;
        }
    }

    BidInfo bidInfo(side, price, size);
    addBidInfoDetails(order_id, bidInfo);
}

void
OrderBook::modify(int order_id, int new_size) {
    if (mOrderIdToBidMap.find(order_id) != mOrderIdToBidMap.end()) {
        BidInfo bidInfo = mOrderIdToBidMap[order_id];
        if (bidInfo.mBidType == BidType::BUY_BID_TYPE) {
            mBuySidePriceToSizeMap[bidInfo.mBidPrice] = new_size;
        } else {
            mSellSidePriceToSizeMap[bidInfo.mBidPrice] = new_size;
        }
    }

    BidInfo bidInfo;
    bidInfo.mBidSize = new_size;
    updateBidInfoDetails(order_id, bidInfo);
}

void
OrderBook::remove(int order_id) {
    if (mOrderIdToBidMap.find(order_id) != mOrderIdToBidMap.end()) {
        BidInfo bidInfo = mOrderIdToBidMap[order_id];
        if (bidInfo.mBidType == BidType::BUY_BID_TYPE) {
            mBuySidePriceToSizeMap.erase(bidInfo.mBidPrice);
        } else {
            mSellSidePriceToSizeMap.erase(bidInfo.mBidPrice);
        }
        removeBidInfoDetails(order_id);
    }
}

double
OrderBook::get_price(char side, int level) {
    double priceVal = 0.0;
    switch (side) {
        case 'B': {
            if (level <= 0 || level > mBuySidePriceToSizeMap.size()) {
                return -1;
            }

            auto level_cntr = 1;
            for (auto const& x: mBuySidePriceToSizeMap) {
                if (level_cntr++ == level) {
                    priceVal = x.first;
                    break;
                }
            }
        }
        break;

        case 'S': {
            if (level <= 0 || level > mSellSidePriceToSizeMap.size()) {
                return -1;
            }

            auto level_cntr = 1;
            for (auto const& x: mSellSidePriceToSizeMap) {
                if (level_cntr++ == level) {
                    priceVal = x.first;
                    break;
                }
            }
        }
        break;

        default: {
            return -1;
        }
    }

    return priceVal;
}

int
OrderBook::get_size(char side, int level) {
    int size;
    switch (side) {
        case 'B': {
            if (level <= 0 || level > mBuySidePriceToSizeMap.size()) {
                return -1;
            }

            auto level_cntr = 1;
            for (auto const& x: mBuySidePriceToSizeMap) {
                if (level_cntr++ == level) {
                    size = x.second;
                    break;
                }
            }
        }
        break;

        case 'S': {
            if (level <= 0 || level > mSellSidePriceToSizeMap.size()) {
                return -1;
            }

            auto level_cntr = 1;
            for (auto const& x: mSellSidePriceToSizeMap) {
                if (level_cntr++ == level) {
                    size = x.second;
                    break;
                }
            }
        }
        break;

        default: {
            return -1;
        }
    }

    return size;
}

void
OrderBook::addBidInfoDetails(int order_id, const BidInfo& bidInfo) {
    mOrderIdToBidMap[order_id] = bidInfo;
}

void
OrderBook::removeBidInfoDetails(int order_id) {
    mOrderIdToBidMap.erase(order_id);
}

void
OrderBook::updateBidInfoDetails(int order_id, const BidInfo& bidInfo) {
    if (mOrderIdToBidMap.find(order_id) != mOrderIdToBidMap.end()) {
        BidInfo updateInfo = mOrderIdToBidMap[order_id];
        updateInfo.mBidSize = bidInfo.mBidSize;
        mOrderIdToBidMap[order_id] = updateInfo;
    } else {
        std::cout << "Unable to find the given order id: " << order_id << std::endl;
    }
}
