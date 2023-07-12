#include "DiscountMangement.h"
#include <iostream>

Room* rooms;
Room* validDiscountRooms[10];
int DiscountRoomscounter = 0;
int normaldiscount = 6 , golddiscount = 10 , primiumdiscount = 15;
int summerdiscount = 5 , winterDiscount = 5 ;

 int DiscountMangement::getDiscountForBilling(std::string discount)
{

    if(discount == "Gold" || discount == "gold" )
        return golddiscount;
    else if(discount == "Primium" || discount == "primium" )
        return primiumdiscount;
    else if(discount == "Normal" || discount == "normal" )
        return normaldiscount;
    else if(discount == "summer" || discount == "Summer" )
        return summerdiscount;
    else if(discount == "Winter" || discount == "Winter" )
        return winterDiscount;
    else
        return 1; 
}

bool DiscountMangement::isRoomsReserved(){
     system("cls");
    if (Room::count == -1) {
        std::cout << "================================================================================" << std::endl;
        std::cout << "                                 Management                                     " << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cout << "                           <  Report Form Management  >                          " << std::endl;
        std::cout << "                             ! No Rooms Are Reserved !                           " << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::system("PAUSE");
        return true;
    }
    return false;
        
}

void DiscountMangement::discountRooms()
{
    system("cls");
    if(isRoomsReserved())
        return;
    std::cout << "================================================================================"<< std::endl;
    std::cout << "                              Get Discount Details                              " << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "-------------------------------Discount Rooms-----------------------------------" << std::endl;
    for(int i = 0 ; i < DiscountRoomscounter ; i++){
        if(validDiscountRooms[i]->membership == "Gold" || validDiscountRooms[i]->membership == "Normal" || validDiscountRooms[i]->membership == "Primium" || validDiscountRooms[i]->membership == "gold" || validDiscountRooms[i]->membership == "normal" || validDiscountRooms[i]->membership == "primium")
        {
            if(i == 4)
                std::cout<<"\n";
            std::cout<<"Room-"<<validDiscountRooms[i]->roomNo<<std::endl;
        }
    }
    system("pause");
    
}

void DiscountMangement::setDiscountDetails(){
    system("cls");

    displayDiscount();
    
    int choise;
    std::cout<<"Enter Choise : ";
    std::cin>>choise;

    system("cls");
    std::cout << "================================================================================\n" << std::endl;
    std::cout << "                               Set Discount Details                             \n" << std::endl;
    std::cout << "================================================================================\n" << std::endl;
    int discount;

    switch (choise)
    {
    case 1:
        std::cout<<"Normal Pass = ";
        std::cin>>discount;
        normaldiscount = discount;
        break;
     case 2:
        std::cout<<"Gold Pass = ";
        std::cin>>discount;
        golddiscount = discount;
        break;
     case 3:
        std::cout<<"Primium Pass = ";
        std::cin>>discount;
        primiumdiscount = discount;
        break;
     case 4:
        std::cout<<"Summer Discount = ";
        std::cin>>discount;
        summerdiscount = discount;
        break;
     case 5:
        std::cout<<"Winter Discount = ";
        std::cin>>discount;
        winterDiscount = discount;
    break;

    default:
        std::cout<<"Invalid Choise"<<std::endl;
        break;
    }
   

}

void DiscountMangement::displayDiscount(){

    system("cls");

    std::cout << "=================================================================================" << std::endl;
    std::cout << "                                Discount  Display                                " << std::endl;
    std::cout << "=================================================================================" << std::endl;
    std::cout << "===================================Discounts=====================================\n" << std::endl;
    std::cout << "1.Normal = "<<normaldiscount<<"%    2.Gold = "<<golddiscount<<"%   3.Primium = "<<primiumdiscount;
    std::cout << "%     4.Summer = "<<summerdiscount<<"%    5.winter = "<<winterDiscount<<std::endl;
    std::cout << "\n";

    system("PAUSE");
    
    

}
void DiscountMangement::getValidDiscountRooms()
{
    if (isRoomsReserved())
    {
        system("cls");
        return;
    }

    for (int i = 0; i < Room::count && i < 10; i++) {
        if (Room::Rooms[i]->membership == "Normal" || Room::Rooms[i]->membership == "normal") {
            Room::discountRooms[i] = 10;
            validDiscountRooms[DiscountRoomscounter] = Room::Rooms[i];
            DiscountRoomscounter++;
        }
        else if (Room::Rooms[i]->membership == "Gold" || Room::Rooms[i]->membership == "gold") {
            Room::discountRooms[i] = 20;
            validDiscountRooms[DiscountRoomscounter] = Room::Rooms[i];
            DiscountRoomscounter++;
        }
        else if (Room::Rooms[i]->membership == "Primium" || Room::Rooms[i]->membership == "primium") {
            Room::discountRooms[i] = 30;
            validDiscountRooms[DiscountRoomscounter] = Room::Rooms[i];
            DiscountRoomscounter++;
        }
        else
            Room::discountRooms[i] = 0;
    }
}

void DiscountMangement::removeDiscountRooms() {

    system("cls");
    if (isRoomsReserved())
        return;

    std::cout << "-------------------------------Discount Rooms-----------------------------------" << std::endl;
    
    for (int i = 0; i < DiscountRoomscounter; i++) {
        if (validDiscountRooms[i]->membership == "Gold" || validDiscountRooms[i]->membership == "Normal" ||
            validDiscountRooms[i]->membership == "Primium" || validDiscountRooms[i]->membership == "gold" ||
            validDiscountRooms[i]->membership == "normal" || validDiscountRooms[i]->membership == "primium") {
            if (i == 4)
                std::cout << "\n";
            std::cout << "Room-" << validDiscountRooms[i]->roomNo << "    Discount NO:" << i << std::endl;
        }
    }

    int choice;
    std::cout << "Enter: ";
    std::cin >> choice;

    if (choice >= 0 && choice < DiscountRoomscounter) {
        validDiscountRooms[choice]->membership = "no";
        std::cout << "Room-" << choice << " has been removed from discount rooms." << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter a valid discount number." << std::endl;
    }

    system("pause");
}




void DiscountMangement::discountMangementStart()
{   
        system("cls");
        char choise;
        std::cout << "================================================================================" << std::endl;
        std::cout << "                                Discount  Mangement                             " << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cout << "1.                              Display Discount Rooms \n";
        std::cout << "2.                              Display Discount       \n";
        std::cout << "3.                              Set Discounts Details  \n";
        std::cout << "4.                              Remove Discounts Rooms \n";        
        std::cout << "5.                              Exit                   \n";

        std::cout << "\nEnter:";
        std::cin >> choise;

        switch (choise)
        {
        case '1':
            discountRooms();
            break;
        case '2':
            displayDiscount();
            break;
        case '3':
            setDiscountDetails();
            break;
        case '4':
            removeDiscountRooms();
            break;
        case '5':
            return;
            break;
                
        default:
        std::cout << "Invalid input. Please choose a valid option.\n";
        break;

         }
        
        discountMangementStart();
}
