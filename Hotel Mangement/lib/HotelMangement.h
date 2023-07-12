#ifndef HOTELMANGEMENT_H
#define HOTELMANGEMENT_H

#include "RoomMangement.h"
#include "HouseKeeping.h"
#include "Event.h"
#include "DiscountMangement.h"
#include <iostream>
#include "billing.h"

class HotelMangement{
    private:
        char choise;
        RoomMangement* roomMangement  = nullptr;
        Event* event = nullptr;
        HouseKeeping* houseKeeping = nullptr;
        DiscountMangement* discountMangement = nullptr;
        billing* billingmodule = nullptr;
        
    public:
        HotelMangement();
        ~HotelMangement();
    

    void HotelMangementStart();

};
#endif