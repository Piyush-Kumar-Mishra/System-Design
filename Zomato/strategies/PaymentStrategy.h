#ifndef PAYMNTSTRATEGY_H
#define PAYMNTSTRATEGY_H

#include<iostream>
using namespace std;

class PaymentStrategy{
    public:
        virtual void pay(double amount) = 0;
};

#endif