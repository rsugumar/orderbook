#include <sstream>

#include "OrderBookController.hpp"
#include "FileReader.hpp"
#include "OrderBook.hpp"
#include "EnumUtils.hpp"

void
OrderBookController::executeOrders(const std::string& ordersFileName, std::ostream& output) {
    FileReader fr(ordersFileName);
    std::vector<std::string> fContents = fr.getFileContentLines();

    for (auto const& entry: fContents) {
        OrderInfo orderInfo = parseEntry(entry);
        switch (orderInfo.mOrderType) {
            case OrderType::ADD_ORDER_TYPE: {
                mOrderBook.add(orderInfo.mOrderId,
                                orderInfo.mBidInfo.getBidSideChar(),
                                orderInfo.mBidInfo.mBidPrice,
                                orderInfo.mBidInfo.mBidSize);
            }
            break;

            case OrderType::MODIFY_ORDER_TYPE: {
                mOrderBook.modify(orderInfo.mOrderId,
                                orderInfo.mBidInfo.mBidSize);
            }
            break;

            case OrderType::GET_PRICE_ORDER_TYPE: {
                output <<
                    mOrderBook.get_price(orderInfo.mBidInfo.getBidSideChar(),
                                        orderInfo.mGetLevelNo) << std::endl;
            }
            break;

            case OrderType::GET_SIZE_ORDER_TYPE: {
                output <<
                    mOrderBook.get_size(orderInfo.mBidInfo.getBidSideChar(),
                                        orderInfo.mGetLevelNo) << std::endl;
            }
            break;

            case OrderType::REMOVE_ORDER_TYPE: {
                mOrderBook.remove(orderInfo.mOrderId);
            }
            break;

            default:
                output << orderInfo << std::endl;
        }
    }
}

OrderInfo
OrderBookController::parseEntry(const std::string& orderEntry) const {
    OrderInfo retVal;
    std::vector<std::string> tokens;
    tokenize(orderEntry, tokens);

    if (tokens.size() > 0) {
        OrderType orderType = EnumUtils::getOrderType(tokens[0]);
        switch (orderType) {
            case OrderType::ADD_ORDER_TYPE: {
                retVal = parseAddOrderTypeEntry(tokens);
            }
            break;

            case OrderType::MODIFY_ORDER_TYPE: {
                retVal = parseModifyOrderTypeEntry(tokens);
            }
            break;

            case OrderType::GET_ORDER_TYPE: {
                retVal = parseGetOrderTypeEntry(tokens);
            }
            break;
        
            case OrderType::REMOVE_ORDER_TYPE: {
                retVal = parseRemoveOrderTypeEntry(tokens);
            }
            break;

            default: {
            }
        }
    }

    return retVal;
}

OrderInfo
OrderBookController::parseAddOrderTypeEntry(const std::vector<std::string>& tokens) const {
    OrderInfo orderInfo;
    if (tokens.size() < 5) {
        // throw exception;
        return orderInfo;
    }

    orderInfo.mOrderType = OrderType::ADD_ORDER_TYPE;
    orderInfo.mOrderId = std::stoi(tokens[1]);

    if (tokens[2] == "B") {
        orderInfo.mBidInfo.mBidType = BidType::BUY_BID_TYPE;
    } else if (tokens[2] == "S") {
        orderInfo.mBidInfo.mBidType = BidType::SELL_BID_TYPE;
    }

    orderInfo.mBidInfo.mBidPrice = std::stod(tokens[3]);
    orderInfo.mBidInfo.mBidSize = std::stoi(tokens[4]);

    return orderInfo;
}

OrderInfo
OrderBookController::parseModifyOrderTypeEntry(const std::vector<std::string>& tokens) const {
    OrderInfo orderInfo;
    if (tokens.size() < 3) {
        // throw exception;
        return orderInfo;
    }

    orderInfo.mOrderType = OrderType::MODIFY_ORDER_TYPE;
    orderInfo.mOrderId = std::stoi(tokens[1]);
    orderInfo.mBidInfo.mBidSize = std::stoi(tokens[2]);

    return orderInfo;
}

OrderInfo
OrderBookController::parseGetOrderTypeEntry(const std::vector<std::string>& tokens) const {
    OrderInfo orderInfo;
    if (tokens.size() < 4) {
        // throw exception;
        return orderInfo;
    }

    if (tokens[1] == "price") {
        orderInfo.mOrderType = OrderType::GET_PRICE_ORDER_TYPE;
    } else if (tokens[1] == "size") {
        orderInfo.mOrderType = OrderType::GET_SIZE_ORDER_TYPE;
    }

    if (tokens[2] == "B") {
        orderInfo.mBidInfo.mBidType = BidType::BUY_BID_TYPE;
    } else if (tokens[2] == "S") {
        orderInfo.mBidInfo.mBidType = BidType::SELL_BID_TYPE;
    }

    orderInfo.mGetLevelNo = std::stoi(tokens[3]);

    return orderInfo;
}

OrderInfo
OrderBookController::parseRemoveOrderTypeEntry(const std::vector<std::string>& tokens) const {
    OrderInfo orderInfo;
    if (tokens.size() < 2) {
        // throw exception;
        return orderInfo;
    }

    orderInfo.mOrderType = OrderType::REMOVE_ORDER_TYPE;
    orderInfo.mOrderId = std::stoi(tokens[1]);
    return orderInfo;
}

std::vector<std::string>
OrderBookController::tokenize(const std::string& orderEntry,
                                std::vector<std::string>& tokens) const {
    std::istringstream tokenStream(orderEntry);
    std::string token;
    while (std::getline(tokenStream, token, ' ')) {
        if (!token.empty()) { // Avoid empty tokens, if any
            tokens.push_back(token);
        }
    }

    return tokens;
}