#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include<vector>
#include<string> 
#include "../models/Cart.h"
#include "../models/User.h"
#include "../strategies/PaymentStrategy.h"

using namespace std;

class Order{
    private:
        static int nextOrderId;
        int order_id;
        User* user;
        Restaurant* restaurant;
        vector<MenuItem> items;
        PaymentStrategy* paymentStrategy;
        double total;
        string scheduled;

    public:
        Order(){
            user = nullptr;
            restaurant = nullptr;
            paymentStrategy = nullptr;
            total =0.0;
            scheduled = "";
            order_id = ++nextOrderId;
        }

        //override by child classes
        virtual string getType() =0;

        bool processPayment(){
            if(paymentStrategy){
                paymentStrategy -> pay(total);
                return true;
            }
            else{
                cout<< "Please choose payment mode first";
                return false;
            }
        }

        int getOrderId(){
            return order_id;
        }

        void setUser(User* u){
            user= u;
        }

        // User* getUser(){
        //     return user;
        // }

        void setRestaurant(Restaurant* r){
            restaurant = r;
        }

        Restaurant* getRestaurant() const {
        return restaurant;
    }

        void setItems(vector<MenuItem> its){
            items = its;
            total =0;
            for(auto i: items){
                total += i.getPrice();
            }
        }

        User* getUser() const {
            return user;
        }

        vector<MenuItem> getItems(){
            return items;
        }

        void setPaymentStrategy (PaymentStrategy* p){
            paymentStrategy = p;
        }

        void setScheduled(string s){
            scheduled = s;
        }

         string getScheduled() const {
        return scheduled;
        }

        double getTotal() const {
        return total;
        }

        void setTotal(double total) {
            this->total = total;
        }

};
int Order::nextOrderId = 0;
#endif