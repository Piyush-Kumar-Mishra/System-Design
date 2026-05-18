#include<iostream>
#include "ZomatoApp.h"
#include "strategies/Upi.h"
using namespace std;

int main(){

    ZomatoApp* zomato = new ZomatoApp();

    User* user =  new User(101, "Khushi" , "Delhi");
    cout<<"User: " <<user->getName()<<endl;

    vector<Restaurant*> restaurantList = zomato->searchRestaurant("Delhi");

    if (restaurantList.empty()) {
        cout << "No restaurants found!" << endl;
        return 0;
    }

    cout<<"<------Restaurants--------->";
    for(auto restaurant: restaurantList){
        cout<< restaurant->getName() << " | " <<endl;
    }

    zomato-> selectRestaurant(user, restaurantList[0]);
    cout<<"Restaurant selected : " << restaurantList[0] ->getName() <<endl;

    zomato -> addToCart(user , "P1");
    zomato -> addToCart(user , "P2");

    zomato->showCart(user);

    Order* order = zomato -> checkoutNow(user , "Delivery" , new Upi());
    zomato->pay(user, order);

    return 0;
}