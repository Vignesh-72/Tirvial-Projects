#include <iostream>
#include <string>
#include "HouseKeeping.h"
hotelstaff* HouseKeeping::staffArr[10];
int staffCount = -1;

HouseKeeping::HouseKeeping() {
    roomMangement1 = new RoomMangement;
    room1 = new Room;
}

HouseKeeping::~HouseKeeping() {
    delete roomMangement1;
    delete room1;
}


   void HouseKeeping::addStaff() {
    system("cls");
    if(staffCount == -1){
        staffCount = 0;
    }
    hotelstaff* hotelstaf  = new hotelstaff;

    std::cout << "================================================================================" << std::endl;
    std::cout << "                              Add Staff                                        " << std::endl;
    std::cout << "================================================================================" << std::endl;

    std::cout << "Name              : " ;
    std::cin >> hotelstaf->staffName;
    std::cout << "Age               : ";
    std::cin >> hotelstaf->ageArr;
    std::cout << "Staff No          : ";
    std::cin >> hotelstaf->staffNo;
    std::cout << "Date Of Joined    : ";
    std::cin >> hotelstaf->jointedDate;
    std::cout << "Room To Maintain  : ";
    std::cin >> hotelstaf->roomMatined;

    staffArr[staffCount] = hotelstaf;
    staffCount++;
}


   void HouseKeeping::staffInfo() {
    if(staffCount == -1){
        system("cls");
        std::cout << "================================================================================" << std::endl;
        std::cout << "                         !No Staff Are There For HouseKeeping!                  " << std::endl;
        std::cout << "================================================================================" << std::endl;
        system("pause");
        return;
    }
    system("cls");
    std::cout << "================================================================================" << std::endl;
    std::cout << "                              Staff  Details                                    " << std::endl;
    std::cout << "================================================================================" << std::endl;
    for (int i = 0; i < staffCount; i++) {
        hotelstaff* temp = staffArr[i];
        std::cout << i + 1 << "-" << temp->staffName << std::endl;
    }
    int choice;
    std::cout << "Enter : ";
    std::cin >> choice;

    if (choice < 1 || choice > staffCount) {
        std::cout << "Invalid choice. Please try again." << std::endl;
        return;
    }
    hotelstaff* hotelstaf = staffArr[choice-1];
    system("cls");
    std::cout << "================================================================================" << std::endl;
    std::cout << "                              Staff  Details                                    " << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "Name         : " << hotelstaf->staffName << std::endl;
    std::cout << "Age          : " << hotelstaf->ageArr << std::endl;
    std::cout << "Staff NO     : " << hotelstaf->staffNo << std::endl;
    std::cout << "Joined Date  : " << hotelstaf->jointedDate<< std::endl;
    std::cout << "Room Matined : " << hotelstaf->roomMatined << std::endl;
    system("pause");
}


void HouseKeeping::getHouseKeepingDetails() {
    system("cls");
    std::cout << "================================================================================" << std::endl;
    std::cout << "                              Get HouseKeeping  Details                         " << std::endl;
    std::cout << "================================================================================" << std::endl;
    if (!HouseKeepingCheck()) {
        std::cout << "No Rooms Are Reserved!" << std::endl;
        system("pause");
        return;
    }

    for (int i = 0; i < Room::count + 1; i++) {
        Room* roomPtr = Room::Rooms[i];
        if (roomPtr == nullptr) {
            continue;
        }

        std::cout << roomPtr->roomNo << "-Room     ";
        if ((i + 1) % 5 == 0) {
            std::cout << "\n";
        }
    }

    int roomNum;
    std::cout << "\nEnter The Room Number: ";
    std::cin >> roomNum;

    system("PAUSE");
    system("cls");
    std::cout << "================================================================================" << std::endl;
    std::cout << "                              Get HouseKeeping  Details                         " << std::endl;
    std::cout << "================================================================================" << std::endl;

    Room* temp = Room::Rooms[roomNum - 1];
    if (temp->isHouseKeepingDone == "true") {
        std::cout << "House Keeping Is Done" << std::endl;
        std::cout << "By: ";
        int staffno = (roomNum <= 3) ? 0 : (roomNum <= 6) ? 1 : 2;
        //std::cout << hotelstaf->staffName[staffno-1] << std::endl;
        std::cout << "HouseKeeping Date : " << temp->houseKeepingDate << std::endl;
        std::cout << "HouseKeeping Time : " << temp->houseKeepingTime << std::endl;
    }
    else {
        std::cout << "HouseKeeping Is Not Done Yet" << std::endl;
    }

    system("PAUSE");
}

void HouseKeeping::setHouseKeepingDetails() {
    system("cls");
    std::cout << "================================================================================" << std::endl;
    std::cout << "                              Set HouseKeeping  Details                         " << std::endl;
    std::cout << "================================================================================" << std::endl;
    if (!HouseKeepingCheck()) {
        std::cout << "No Rooms Are Reserved!" << std::endl;
        system("pause");
        return;
    }

    for (int i = 0; i < Room::count + 1; i++) {
        Room* roomPtr = Room::Rooms[i];
        if (roomPtr == nullptr) {
            continue;
        }

        std::cout << roomPtr->roomNo << "-Room     ";
        if ((i + 1) % 5 == 0) {
            std::cout << "\n";
        }
    }

    int roomNum;
    std::cout << "\nEnter The Room Number: ";
    std::cin >> roomNum;

    system("PAUSE");
    system("cls");
     std::cout << "================================================================================" << std::endl;
    std::cout << "                              Set HouseKeeping  Details                         " << std::endl;
    std::cout << "================================================================================" << std::endl;
    Room* temp = Room::Rooms[roomNum - 1];
    std::cout <<"Room Number : "<<temp->roomNo << std::endl;
    std::cout << "Enter the HouseKeeping Date: ";
    std::cin >> temp->houseKeepingDate;
    std::cout << "Enter the HouseKeeping Time: ";
    std::cin >> temp->houseKeepingTime;
    std::cout << "Enter 'true' if HouseKeeping is done, 'false' otherwise: ";
    std::cin >> temp->isHouseKeepingDone;

    std::cout << "\nHouseKeeping details set for Room " << temp->roomNo << "." << std::endl;
    system("PAUSE");
}

bool HouseKeeping::HouseKeepingCheck() {
    return (Room::count > 0);
}

void HouseKeeping::HouseKeepingStart() {
    system("cls");
    std::cout << "================================================================================" << std::endl;
    std::cout << "                              HouseKeeping Menu                                 " << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "1.                            Add Staff"                << std::endl;
    std::cout << "2.                            View Staff Information"   << std::endl;
    std::cout << "3.                            Get HouseKeeping Details" << std::endl;
    std::cout << "4.                            Set HouseKeeping Details" << std::endl;
    std::cout << "5.                            Exit"                     << std::endl;

    int choice;
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        addStaff();
        break;
    case 2:
        staffInfo();
        break;
    case 3:
        getHouseKeepingDetails();
        break;
    case 4:
        setHouseKeepingDetails();
        break;
    case 5:
        std::cout << "\nExiting HouseKeeping Menu..." << std::endl;
        return;
    default:
        std::cout << "\nInvalid choice! Please try again." << std::endl;
        break;
    }

    HouseKeepingStart();
}