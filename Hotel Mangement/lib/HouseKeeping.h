#ifndef HOUSEKEEPING_H
#define HOUSEKEEPING_H
#include <iostream>
#include <string>
#include "RoomMangement.h"
#include "Room.h"
#include "hotelstaff.h"

class HouseKeeping {
    private :
    RoomMangement* roomMangement1;
    Room* room1;
    static hotelstaff* staffArr[10];

public:
    HouseKeeping();
    ~HouseKeeping();
    void addStaff();
    void staffInfo();
    bool HouseKeepingCheck();
    void getHouseKeepingDetails();
    void setHouseKeepingDetails();
    void HouseKeepingStart();
};
#endif