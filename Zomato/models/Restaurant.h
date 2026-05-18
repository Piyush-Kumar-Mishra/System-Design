#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<iostream>
#include<string>
#include<vector>
#include "MenuItem.h"

using namespace std;



class Restaurant{
    private:
        static int resId;
        string name;
        string location;
        vector<MenuItem> menu;

    public:
        Restaurant(const string& name , const string& location){
            this->name = name;
            this->location= location;
            this->resId = ++resId;
        }

        string getName(){
            return name;
        }

        string getLocation(){
            return location;
        }

        //setters can also be added for name and location , if want to replace it with new name or location

        void addMenuItem(MenuItem item){
            menu.push_back(item);
        }

        
        vector<MenuItem> getMenu(){
            return menu;
        }
};

int Restaurant::resId=0;

#endif