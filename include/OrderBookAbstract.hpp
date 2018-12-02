#ifndef __ORDER_BOOK_ABSTRACT_HPP__
#define __ORDER_BOOK_ABSTRACT_HPP__
#pragma once

class OrderBookAbstract {
    public:
        virtual ~OrderBookAbstract() {}
        virtual void add(int order_id, char side, double price, int size) = 0;
        virtual void modify(int order_id, int new_size) = 0;
        virtual void remove(int order_id) = 0;
        virtual double get_price(char side, int level) = 0;
        virtual int get_size(char side, int level) = 0;
};
 
#endif