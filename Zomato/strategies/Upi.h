#ifndef UPI_H
#define UPI_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
using namespace std;

class Upi : public PaymentStrategy{
    public:
        void pay(double amount) override{
            cout<< "paid" <<amount <<" using UPI"<<endl;
        }
};
#endif