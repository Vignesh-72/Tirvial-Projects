#include <iostream>
#include "Room.h"
#include "RoomMangement.h"

void RoomMangement::roomReservations() {
    std::cout << "================================================================================" << std::endl;
    std::cout << "                              Room Reservations                                 " << std::endl;
    std::cout << "================================================================================" << std::endl;

    if (mangementCheck()) {
        for (int i = 0; i < Room::count+1; i++) {
            Room* roomPtr = Room::Rooms[i];
            if (roomPtr == nullptr) {
                continue;
            }
            
            std::cout << roomPtr->roomNo << "-Room     ";
            if ((i + 1) % 5 == 0) {
                std::cout << "\n";
            }
        }
    }

    std::cout << "\n";
    system("PAUSE");
}

bool RoomMangement::mangementCheck() {
    system("cls");
    if (Room::count == -1) {
        std::cout << "================================================================================" << std::endl;
        std::cout << "                                 Management                                     " << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cout << "                           <  Report Form Management  >                          " << std::endl;
        std::cout << "                             ! No Rooms Are Reserved !                           " << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::system("PAUSE");
        return false;
    }

    return true;
}

void RoomMangement::getRoomsDetails() {
    system("cls");
    int roomNum = 0;
    std::cout << "================================================================================" << std::endl;
    std::cout << "                             Get Room Details                                   " << std::endl;
    std::cout << "================================================================================" << std::endl;

    if (mangementCheck()) {
        for (int i = 0; i < Room::count+1 ; i++) {
            Room* roomPtr = Room::Rooms[i];
            if (roomPtr == nullptr) {
                continue;
            }
            
            std::cout << roomPtr->roomNo << "-Room     ";
            if ((i + 1) % 5 == 0) {
                std::cout << "\n";
            }
        }

        std::cout << "\nEnter The Room Number: ";
        std::cin >> roomNum;

        if (roomNum >= 1 && roomNum <= Room::count) {
            Room* temp = Room::Rooms[roomNum - 1];
            temp->getRoomDetails();
            return;
        } else {
            std::cout << "Invalid room number." << std::endl;
            return;
        }
    }
}

void RoomMangement::mangementStart() {
    system("cls");
    while (true) {
        char choice;
        std::cout << "================================================================================" << std::endl;
        std::cout << "                              Room Management                                   " << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cout << "1.                            Room Booking        \n";
        std::cout << "2.                            Room Reservations   \n";
        std::cout << "3.                            Get Room Details    \n";
        std::cout << "4.                            Change Room Details \n";
        std::cout << "5.                            Empty Room          \n";
        std::cout << "6.                            Exit                \n";

        std::cout << "\nEnter: ";
        std::cin >> choice;
                switch (choice) {
            case '1':
                roomBooking();
                break;
            case '2':
                roomReservations();
                break;
            case '3':
                getRoomsDetails();
                break;
            case '4':
                changeRoomDetails();
                break;
            case '5':
                emptyRoom();
                break;
            case '6':
                return;
            default:
                std::cout << "Invalid input. Please choose a valid option.\n";
                break;
        }
        system("cls");
    }
}

void RoomMangement::checkcount() {
    if (Room::count == 9) {
        std::cout << "All the rooms are reserved." << std::endl;
        return;
    }
}

void RoomMangement::roomBooking() {
    std::cout << "================================================================================" << std::endl;
    std::cout << "                               Room Booking                                     " << std::endl;
    std::cout << "================================================================================" << std::endl;
    checkcount();

    if (mangementCheck() == false) {
        Room* r = new Room();
        r->RoomStart();
        
    } else {
        roomReservations();
        Room* r = new Room();
        r->RoomStart();
        
    }
    
}

void RoomMangement::changeRoomDetails() {

    if (mangementCheck()) {
         std::cout << "================================================================================" << std::endl;
         std::cout << "                             Change Room Details                                " << std::endl;
         std::cout << "================================================================================" << std::endl;
        for (int i = 0; i < Room::count+1; i++) {
            if (Room::Rooms[i] == nullptr) {
                continue;
            }
            std::cout << i + 1 << "-Room     ";
            if ((i + 1) % 5 == 0) {
                std::cout << "\n";
            }
        }

        int choice;
        std::cout << "\nEnter The Room NO : ";
        std::cin >> choice;

        if (choice >= 1 && choice <= Room::count) {
            Room* roomPtr = Room::Rooms[choice - 1];
            roomPtr->RoomStart();
            return;
        } else {
            std::cout << "Invalid room number." << std::endl;
            return;
        }
    }
}

void RoomMangement::emptyRoom() {

    if (mangementCheck()) {

        std::cout << "================================================================================" << std::endl;
        std::cout << "                                 Empty Room                                     " << std::endl;
        std::cout << "================================================================================" << std::endl;

        for (int i = 0; i < Room::count + 1; i++) {
            Room* roomPtr = Room::Rooms[i];
            if (Room::Rooms[i] == nullptr) {
                continue;
            }
            std::cout << roomPtr->roomNo << "-Room     ";
            if ((i + 1) % 5 == 0) {
                std::cout << "\n";
            }
        }
        int choice;
        std::cout << "\nEnter The Room NO: ";
        std::cin >> choice;

    if (choice >= 1 && choice <= Room::count) {
        delete Room::Rooms[choice - 1];
        Room::Rooms[choice - 1] = nullptr;
        std::cout << "Room " << choice << " has been emptied." << std::endl;
        Room::count--;

        for (int i = choice - 1; i < Room::count; i++) {
            Room::Rooms[i] = Room::Rooms[i + 1];
        }
        Room::Rooms[Room::count] = nullptr;

        return;
    } else {
        std::cout << "Invalid room number." << std::endl;
        return;
    }
    }
}
