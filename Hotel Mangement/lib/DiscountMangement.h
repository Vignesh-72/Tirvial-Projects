#ifndef DISCOUNTMANGEMENT_H
#define DISCOUNTMANGEMENT_H

#include "Room.h"
#include <string>

class DiscountMangement{

    public:
        void discountRooms();
        void setDiscountDetails();
        void displayDiscount();
        void getValidDiscountRooms();
        void discountMangementStart();
        void removeDiscountRooms();
        bool isRoomsReserved();
        int getDiscountForBilling(std::string);
};

#endif
