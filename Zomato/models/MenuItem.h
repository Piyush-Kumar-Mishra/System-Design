#ifndef MENUITEM_H
#define MENUITEM_H

#include<iostream>
#include<string>


using namespace std;

class MenuItem{
    private:
        string code;
        string name;
        int price;
    public:
        MenuItem(string code , string name , int price){
            this->code = code;
            this-> name = name;
            this->price = price;
        }
        string getCode() const {
            return code;
        }
        string getName() const {
            return name;
        }
        int getPrice() const {
            return price;
        }
      
};
#endif