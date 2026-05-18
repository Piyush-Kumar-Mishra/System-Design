#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include "Order.h"
using namespace std;

class PickupOrder : public Order {
    private:
        string restaurantAddress;

    public:
        PickupOrder() : Order() {
            restaurantAddress = "";
        }

        string getType() override {
            return "Pickup Order";
        }

        void setRestaurantAddress(const string& address) {
            restaurantAddress = address;
        }

        string getRestaurantAddress() const {
            return restaurantAddress;
        }
};
#endif