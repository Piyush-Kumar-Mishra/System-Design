#ifndef CREDIT_H
#define CREDIT_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
using namespace std;

class Credit : public PaymentStrategy{
    public:
        void pay(double amount) override{
            cout<< "paid" <<amount <<" using Credit"<<endl;
        }
};
#endif