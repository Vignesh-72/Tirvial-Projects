#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
public:
    static Room* Rooms[10];
    static int discountRooms[10];
    static int count;

    Room();
    void countCheck();
    void RoomStart();
    void getRoomDetails();
    void setDetails();

public:
    std::string guestName = "undefine ", guestGender = "undefine", exitDate = "undefine", entryDate =" undefine";
    std::string isHouseKeepingDone = "false", houseKeepingTime = "undefine", houseKeepingDate = "undefine" ;
    std::string guestAge = "undefine" ;
    int roomNo = count+1 , daysOfStaying = -1;
    std::string numOfGuest = "undefine" ;
    std::string membership = "normal" , typeOfGuest = "undefine",guestPurpose = "undefine" , mobileNo = "undefine";
    void setGuestDetails();
    void setRoomDetails();
};


#endif  // ROOM_H
