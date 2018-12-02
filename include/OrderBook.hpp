#ifndef __ORDER_BOOK_HPP__
#define __ORDER_BOOK_HPP__
#pragma once

#include <map>
#include "OrderBookAbstract.hpp"
#include "BidInfo.hpp"

class OrderBook : public OrderBookAbstract {
    public:
        virtual void add(int order_id, char side, double price, int size);
        virtual void modify(int order_id, int new_size);
        virtual void remove(int order_id);
        virtual double get_price(char side, int level);
        virtual int get_size(char side, int level);

    private:
        void addBidInfoDetails(int order_id, const BidInfo& bidInfo);
        void updateBidInfoDetails(int order_id, const BidInfo& bidInfo);
        void removeBidInfoDetails(int order_id);

    private:
        std::map<double, int, std::greater<double> > mBuySidePriceToSizeMap;
        std::map<double, int, std::less<double> > mSellSidePriceToSizeMap;
        std::map<int, BidInfo> mOrderIdToBidMap;
};

#endif