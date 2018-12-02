#ifndef __ORDER_TYPE_HPP__
#define __ORDER_TYPE_HPP__
#pragma once

#include <algorithm>

enum class OrderType {
    ADD_ORDER_TYPE,
    MODIFY_ORDER_TYPE,
    REMOVE_ORDER_TYPE,
    GET_ORDER_TYPE,
    GET_PRICE_ORDER_TYPE,
    GET_SIZE_ORDER_TYPE,
    UNKNOWN_ORDER_TYPE
};

#endif