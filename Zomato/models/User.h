#ifndef USER_H
#define USER_H

#include<iostream>
#include<vector>
#include<string> 
#include "../models/Cart.h"

using namespace std;

class User{
    private:
        int userId;
        string name;
        string address;
        Cart* cart;
    
        public:
            User(int userId, string name , string address){
                this->userId = userId;
                this->name  = name;
                this->address = address;
                cart = new Cart();
            }
    
        string getName(){
            return name;
        }
        string getAddress(){
            return address;
        }
        Cart* getCart(){
            return cart;
        }
        
};

#endif