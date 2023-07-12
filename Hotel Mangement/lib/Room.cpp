#include "Room.h"
#include <iostream>

Room* Room::Rooms[10];
int Room::discountRooms[10];

Room::Room() {
    countCheck();
    Rooms[count] = this;
    count++;
}
    void Room::countCheck(){
        if(count == -1)
        {
            count = 0;
        }
        
    }
    void Room::RoomStart(){
        char choice;
        while (true)
        {   

            system("CLS");
            std::cout << "================================================================================" << std::endl;
            std::cout << "                                Room  Booking                                   " << std::endl;
            std::cout << "================================================================================" << std::endl;
            std::cout << "1.                            Set Room Details\n";
            std::cout << "2.                            Room Details\n";
            std::cout << "3.                            Exit\n";
    
            std::cout << "\nEnter:";
            std::cin >> choice;

            switch (choice)
            {
            case '1':
                setDetails();
                break;
            case '2':
                getRoomDetails();
                break;
            case '3':
                return;
            default:
                std::cout << "Invalid input. Please choose a valid option.\n";
                break;
            }
        }
    }
    void Room::getRoomDetails()  
    {
        system("cls");
        std::cout << "================================================================================" << std::endl;
        std::cout << "                                Room  Details                                   " << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cout << "Room No              : " << this->roomNo        << std::endl;
        std::cout << "Guest Name           : " << this->guestName     << std::endl;
        std::cout << "Guest Age            : " << this->guestAge      << std::endl;
        std::cout << "Guest Gender         : " << this->guestGender   << std::endl;
        std::cout << "Mobile Number        : " << this->mobileNo      << std::endl;
        std::cout << "Guest Date Of Entry  : " << this->entryDate     << std::endl;
        std::cout << "Guest Date Of Exit   : " << this->exitDate      << std::endl;
        std::cout << "Days Of Staying      : " << this->daysOfStaying << std::endl;
        std::cout << "Type Of Guest        : " << this->typeOfGuest   << std::endl;
        std::cout << "Number Of Guest      : " << this->numOfGuest    << std::endl;
        std::cout << "Purpose Of Arrival   : " << this->guestPurpose  << std::endl;
        std::cout << "Membership           : " << this->membership    << std::endl;
        
        system("PAUSE");
    }

    void Room::setDetails() 
    {   
        system("CLS");
        setGuestDetails();
        setRoomDetails();
    }
    void Room::setGuestDetails() 
    {
         system("cls");
        std::cout << "================================================================================" << std::endl;
        std::cout << "                                Guest  Details                                  " << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cout << "Enter The Guest Name                  : ";
        std::cin.ignore();  
        std::getline(std::cin, guestName);
        std::cout << "Enter The Guest Age                   : ";
        std::cin >> guestAge;
        std::cout << "Enter The Guest Gender (M/F)          : ";
        std::cin.ignore();  
        std::getline(std::cin, guestGender);
        std::cout << "Type Of Guest (Single,Family With...) : ";
        std::cin.ignore(); 
        std::getline(std::cin, typeOfGuest);
        std::cout << "Number Of Guest At Room               : ";
        std::cin >> numOfGuest;
        std::cout << "Purpose Of Arrival                    : ";
        std::cin.ignore(); 
        std::getline(std::cin, guestPurpose);
        
    }
    void Room::setRoomDetails()
    {   
        system("cls");
        std::cout << "================================================================================" << std::endl;
        std::cout << "                                Room  Details                                   " << std::endl;
        std::cout << "================================================================================" << std::endl;
        char choise;
        std::cout << "Enter The Room Number                : ";
        std::cin >> roomNo;
        std::cout << "Enter The Mobile Number              : ";
        std::cin >> mobileNo;
        std::cout << "Enter The Entry Date (dd/mm/yy)      : ";
        std::cin.ignore();  
        std::getline(std::cin, entryDate);
        std::cout << "Enter The Exit Date (dd/mm/yy)       : ";
        std::cin.ignore();  
        std::getline(std::cin, exitDate);
        std::cout << "Days Of Staying(integer)             : ";
        std::cin >> daysOfStaying;
        std::cout << "Membership (No,Normal,Gold,Primium,) : ";
        std::cin.ignore();  
        std::getline(std::cin, membership);

        std::cout << "\nGuest Details Set!\n";
        system("pause");
        
    }

int Room::count = -1;