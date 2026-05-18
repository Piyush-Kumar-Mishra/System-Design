#ifndef CART_H
#define CART_H

#include<iostream>
#include<vector>
#include<string> 
#include "Restaurant.h"
#include "MenuItem.h"

using namespace std;

class Cart{
    private:
        Restaurant* restaurant;
        vector<MenuItem> items;
    public:
        Cart(){
            restaurant = nullptr;
        }

        void setRestaurant(Restaurant* res){
            restaurant = res;
        }

        void addItem(MenuItem item){
            if(!restaurant){
                cerr << "select a restaurant first";
            }
            items.push_back(item);
        }

        double totalCost(){
            double sum = 0 ;
            for(auto& it: items){
                sum += it.getPrice();
            }
            return sum;
        }
        Restaurant* getRestaurant(){
            return restaurant;
        }
        vector<MenuItem> getItem(){
            return items;
        }
        vector<MenuItem> getItems(){
            return items;
        }

        bool isEmpty(){
            return(!restaurant || items.empty());
        }

        void clear(){
            items.clear();
            restaurant = nullptr;
        }
};

#endif