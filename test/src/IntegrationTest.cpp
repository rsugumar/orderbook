#include <sstream>
#include <gtest/gtest.h>
#include "OrderBookController.hpp"

TEST(IntegrationTest, SuccessScenario_with_inputFile1) {
    std::string file1 = "resources/inputFile1.txt";
    OrderBookController orderBookController;
    std::stringstream out;
    orderBookController.executeOrders(file1, out);
    std::stringstream verify;
    verify << "45.2" << std::endl
            << "200" << std::endl
            << "45.2" << std::endl
            << "50" << std::endl
            << "51.2" << std::endl
            << "500" << std::endl;
    ASSERT_STREQ(verify.str().c_str(), out.str().c_str());
}

TEST(IntegrationTest, SuccessScenario_with_inputFile2) {
    std::string file2 = "resources/inputFile2.txt";
    OrderBookController orderBookController;
    std::stringstream out;
    orderBookController.executeOrders(file2, out);
    std::stringstream verify;
    verify << "24.7" << std::endl
            << "22.5" << std::endl
            << "35.1" << std::endl
            << "250" << std::endl
            << "400" << std::endl
            << "200" << std::endl
            << "37.6" << std::endl
            << "450" << std::endl
            << "37.8" << std::endl;
    ASSERT_STREQ(verify.str().c_str(), out.str().c_str());
}
