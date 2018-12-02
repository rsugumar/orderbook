#include <type_traits>
#include "OrderType.hpp"

class EnumUtils {
    public:
        template <typename Enumeration>
        static auto as_integer(Enumeration const value)
            -> typename std::underlying_type<Enumeration>::type {
            return static_cast<typename std::underlying_type<Enumeration>::type>(value);
        }

        OrderType
        static getOrderType(std::string orderTypeStr) {
            std::transform(orderTypeStr.begin(), orderTypeStr.end(), orderTypeStr.begin(), ::tolower);
            OrderType retVal = OrderType::UNKNOWN_ORDER_TYPE;

            if (orderTypeStr == "add") {
                retVal = OrderType::ADD_ORDER_TYPE;
            } else if (orderTypeStr == "modify") {
                retVal = OrderType::MODIFY_ORDER_TYPE;
            } else if (orderTypeStr == "get") {
                retVal = OrderType::GET_ORDER_TYPE;
            } else if (orderTypeStr == "remove") {
                retVal = OrderType::REMOVE_ORDER_TYPE;
            } else {
                retVal = OrderType::UNKNOWN_ORDER_TYPE;
            }

            return retVal;
        }

};
