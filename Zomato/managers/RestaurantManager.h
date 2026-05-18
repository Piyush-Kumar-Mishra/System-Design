#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include<iostream>
#include<vector>
#include<string> 
#include "../models/Restaurant.h"
using namespace std;


//skeleton class
class RestaurantManager{
    private:
        vector<Restaurant*> restaurants;
        static RestaurantManager* instance;

        RestaurantManager(){}
    public:
        static RestaurantManager* getInstance(){
            if(!instance){
                instance = new RestaurantManager();
            }
            return instance;
        }

    void addRestaurant(Restaurant* r){
        restaurants.push_back(r);
    }

    vector<Restaurant*> searchRestaurant(string loc){
        vector<Restaurant*> ans;

        for(auto r : restaurants){
            string location = r->getLocation();
            if(location == loc){
                ans.push_back(r);
            }
        }
        return ans;
    }    
};

RestaurantManager* RestaurantManager::instance = nullptr;

#endif