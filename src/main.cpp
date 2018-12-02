#include <iostream>
#include "OrderBookController.hpp"

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./orderBook <inputfilename>" << std::endl;
        return -1;
    }

    auto fileName = argv[1];

    try {
        OrderBookController orderBookController;
        orderBookController.executeOrders(fileName, std::cout);
    } catch (const char* exceptionMsg) {
        std::cerr << "Error: " << exceptionMsg << std::endl;
    }

    return 0;
}
