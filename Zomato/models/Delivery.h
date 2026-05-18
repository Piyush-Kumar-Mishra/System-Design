#ifndef DELIVERY_H
#define DELIVERY_H

#include "Order.h"
using namespace std;

class Delivery : public Order {
    private:
        string userAddress;

    public:
        Delivery() : Order() {
            userAddress = "";
        }

        string getType() override {
            return "Delivery Order";
        }

        void setUserAddress(const string& address) {
            userAddress = address;
        }

        string getUserAddress() const {
            return userAddress;
        }
};
#endif