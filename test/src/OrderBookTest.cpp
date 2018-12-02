#include <gtest/gtest.h>
#include "OrderBook.hpp"

TEST(OrderBookTest, invalid_arg_for_get_price) {
    OrderBook ob;
    EXPECT_DOUBLE_EQ(-1, ob.get_price('S', 1));
    EXPECT_DOUBLE_EQ(-1, ob.get_price('B', 1));
    EXPECT_DOUBLE_EQ(-1, ob.get_price('Z', 1));
    EXPECT_DOUBLE_EQ(-1, ob.get_price('S', -1000));
    EXPECT_DOUBLE_EQ(-1, ob.get_price('B', -1000));
    EXPECT_DOUBLE_EQ(-1, ob.get_price('S', 0));
}

TEST(OrderBookTest, invalid_arg_for_get_size) {
    OrderBook ob;
    EXPECT_DOUBLE_EQ(-1, ob.get_size('S', 1));
    EXPECT_DOUBLE_EQ(-1, ob.get_size('B', 1));
    EXPECT_DOUBLE_EQ(-1, ob.get_size('Z', 1));
    EXPECT_DOUBLE_EQ(-1, ob.get_size('S', -1000));
    EXPECT_DOUBLE_EQ(-1, ob.get_size('B', -1000));
    EXPECT_DOUBLE_EQ(-1, ob.get_size('S', 0));
}
