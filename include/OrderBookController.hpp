#ifndef __ORDER_BOOK_CONTROLLER_HPP__
#define __ORDER_BOOK_CONTROLLER_HPP__
#pragma once

#include <string>
#include <vector>
#include "OrderInfo.hpp"
#include "OrderBook.hpp"

class OrderBookController {
    public:
        void executeOrders(const std::string& ordersFileName, std::ostream& output);

    private:
        OrderInfo parseEntry(const std::string& orderEntry) const;

        OrderInfo parseAddOrderTypeEntry(const std::vector<std::string>& tokens) const;
        OrderInfo parseModifyOrderTypeEntry(const std::vector<std::string>& tokens) const;
        OrderInfo parseGetOrderTypeEntry(const std::vector<std::string>& tokens) const;
        OrderInfo parseRemoveOrderTypeEntry(const std::vector<std::string>& tokens) const;

        std::vector<std::string> tokenize(const std::string& orderEntry,
                                            std::vector<std::string>& tokens) const;
    private:
        OrderBook mOrderBook;
};

#endif  // __ORDER_BOOK_CONTROLLER_HPP__