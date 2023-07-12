#ifndef BILLING_H
#define BILLING_H

#include <string>
#include "DiscountMangement.h"
#include "Room.h"

class billing{
        
    public: 
        void printBill(); 
        void setPrice();
        void billingStart();
        void checkoutBill(int);
        void viewBill();
};

#endif