#include "billing.h"
#include <iostream>

int oneDayPrice = 7000;
DiscountMangement* discountMangement;

void billing::printBill(){
     system("cls");
    std::cout << "================================================================================" << std::endl;
    std::cout << "                                   Print Bill                                   " << std::endl;
    std::cout << "================================================================================" << std::endl;
     if (Room::count != -1 && Room::count < 10)
     {
        for (int i = 0; i < Room::count+1; i++)
        {
            Room* roomPtr = Room::Rooms[i];
            if (roomPtr == nullptr)
            {
                continue;
            }
            
            std::cout << roomPtr->roomNo << "-Room     ";
            if ((i + 1) % 5 == 0)
            {
                std::cout << "\n";
            }
        }
    }
    else{
        std::cout<<"                           _____________________                                      "<<std::endl;
        std::cout<<"                           |                   |                                       "<<std::endl;
        std::cout<<"---------------------------No Rooms Are Reserved------------------------------------"<<std::endl;
        std::cout<<"                           |___________________|                                       "<<std::endl;
        system("pause");
        system("cls");
        return;
    }
    int choise;
    std::cout << "\n";
    std::cout << "Enter The Room NO : ";
    std::cin >> choise;
    for (int i = 0; i < Room::count ; i++)
    {
        if(Room::Rooms[i]->roomNo == choise){
            checkoutBill(i);
        }
    }
    

}
void billing::checkoutBill(int index)
{
    system("cls");
    Room* temp =  Room::Rooms[index];
    std::cout << "|===============================================================================" << std::endl;
    std::cout << "|                                  Bill                                         " << std::endl;
    std::cout << "|===============================================================================" << std::endl;
    std::cout << "| Name Of The Guest                 :                "<<temp->guestName<<std::endl;
    std::cout << "| Guest Age                         :                "<<temp->guestAge<<std::endl;
    std::cout << "| Mobile No                         :                "<<temp->mobileNo<<std::endl;
    std::cout << "| Days Of Staying                   :                "<<temp->daysOfStaying<<std::endl;
    std::cout << "| MemberShip                        :                "<<temp->membership<<std::endl;
    std::cout << "| Discount %                        :                "<<discountMangement->getDiscountForBilling(temp->membership)<<std::endl;
    std::cout << "| Bill                              :                "<<((oneDayPrice*temp->daysOfStaying)/discountMangement->getDiscountForBilling(temp->membership))<<std::endl;
    std::cout << "---------------------------------------------------------------------------------"<<std::endl;
    system("pause");
}
void billing::setPrice(){
    system("cls");
    std::cout << "================================================================================" << std::endl;
    std::cout << "                                   Set Of Price                                 " << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "Default Prices Of A Day : 7000\n";
    std::cout << "Enter The Prices : ";
    std::cin  >> oneDayPrice;
    system("pause");
}
void billing::viewBill(){
    system("cls");
    std::cout << "================================================================================" << std::endl;
    std::cout << "                                   View Bill                                    " << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "One Day Of Cost :"<<oneDayPrice<<" Including Summer Discount Of 5%"<<std::endl;
    system("pause");
}
void billing::billingStart(){
     system("cls");
        char choice;
        while (true)
        {   
            system("cls");
            std::cout << "================================================================================" << std::endl;
            std::cout << "                                Billing  Mangement                              " << std::endl;
            std::cout << "================================================================================" << std::endl;

            std::cout << "1.                                Print Bill          \n";
            std::cout << "2.                                Set Prices Details  \n";
            std::cout << "3.                                View Prices Details \n";
            std::cout << "4.                                Exit                \n";

            std::cout << "\nEnter:";
            std::cin >> choice;

        switch (choice)
        {
            case '1':
                printBill();
                break;
            case '2':
               setPrice();
                break;
            case '3':
                viewBill();
                break;
            case '4':
               return;
                break;

            default:
            std::cout << "Invalid input. Please choose a valid option.\n";
            break;

             }
        }
}