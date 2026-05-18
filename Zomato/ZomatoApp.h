#ifndef ZOMATO_APP_H
#define ZOMATO_APP_H

#include <vector>
#include <string>
#include "models/User.h"
#include "models/Restaurant.h"
#include "models/Cart.h"
#include "managers/RestaurantManager.h"
#include "managers/OrderManager.h"
#include "strategies/PaymentStrategy.h"
#include "factory/OrderFactory.h"
#include "factory/NowOrderFactory.h"
#include "factory/ScheduleOrderFactory.h"
using namespace std;

class ZomatoApp{
    public:
        ZomatoApp(){
            inititalizeRestaurants();
        }

        void inititalizeRestaurants(){
            Restaurant* restaurant1  = new Restaurant("Bikaner", "Delhi");
            restaurant1->addMenuItem(MenuItem("P1", "Chole Bhature", 120));
            restaurant1->addMenuItem(MenuItem("P2", "Samosa", 15));

            Restaurant* restaurant2 = new Restaurant("Haldiram", "Kolkata");
            restaurant2->addMenuItem(MenuItem("P1", "Raj Kachori", 80));
            restaurant2->addMenuItem(MenuItem("P2", "Pav Bhaji", 100));
            restaurant2->addMenuItem(MenuItem("P3", "Dhokla", 50));
            
            Restaurant* restaurant3 = new Restaurant("Saravana Bhavan", "Chennai");
            restaurant3->addMenuItem(MenuItem("P1", "Masala Dosa", 90));
            restaurant3->addMenuItem(MenuItem("P2", "Idli Vada", 60));
            restaurant3->addMenuItem(MenuItem("P3", "Filter Coffee", 30));

            RestaurantManager* restManger = RestaurantManager::getInstance();
            restManger -> addRestaurant(restaurant1);
            restManger -> addRestaurant(restaurant2);
            restManger -> addRestaurant(restaurant3);
        }

        vector<Restaurant*> searchRestaurant(string location){
            return RestaurantManager::getInstance() -> searchRestaurant(location);
        }

        void selectRestaurant(User* user , Restaurant* restaurant){
            Cart* cart = user->getCart();
            cart->setRestaurant(restaurant);
        }
        
        void addToCart(User* user , const string itemCode){
            Restaurant* restaurant = user -> getCart() -> getRestaurant();

            if(!restaurant){
                cout<< "select restaurant first";
            }
            for(auto item: restaurant -> getMenu()){
                if(item.getCode() == itemCode){
                    user -> getCart() ->addItem(item);
                    break;
                }
            }
        }

        void showCart(User* user){
            cout<<"<----Cart---->"<<endl;
            for(auto item : user->getCart()-> getItem()){
                cout<<item.getName();
            }
            cout<<"Total: $" << user->getCart()->totalCost()<<endl;
        }

        Order* checkoutNow(User* user, const string& orderType, PaymentStrategy* paymentStrategy) {
            return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
        }

        Order* checkoutScheduled(User* user, const string& orderType, PaymentStrategy* paymentStrategy, const string& scheduleTime) {
            return checkout(user, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
        }

        Order* checkout(User* user, const string& orderType, 
            PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
        if (user->getCart()->isEmpty())
            return nullptr;

        Cart* userCart = user->getCart();
        Restaurant* orderedRestaurant = userCart->getRestaurant();
        vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->totalCost();

        Order* order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, totalCost, orderType);
        OrderManager::getInstance()->addOrder(order);
        return order;
    }

    void pay(User* user, Order* order) {
        bool isPaymentSuccess = order->processPayment();
        if(isPaymentSuccess) {
            user->getCart()->clear();
        }
    }

    void printUserCart(User* user) {
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : user->getCart()->getItems()) {
            cout << item.getCode() << " : " << item.getName() << " : ₹" << item.getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : ₹" << user->getCart()->totalCost() << endl;
    }
};

#endif