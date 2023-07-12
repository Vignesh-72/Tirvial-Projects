#include "HotelMangement.h"

#include <iostream>

        HotelMangement::HotelMangement()
        {
            roomMangement = new RoomMangement();
            HotelMangementStart();
        }
        HotelMangement::~HotelMangement()
        {
            delete roomMangement;
        }

    void HotelMangement::HotelMangementStart(){
        while (true)
        {
            system("CLS");
            std::cout<<"==============================================================================================\n";
            std::cout<<"                                 Hotel Mangement                                e-exit        \n";
            std::cout<<"==============================================================================================\n";
            std::cout<<"   1.Room Mangement              2.HouseKeeping                     3.Billing                 \n\n";
            std::cout<<"   4.Event Mangement             5.Discount Mangement               6.Credits                 \n";
            std::cout<<"==============================================================================================\n";
            std::cout<<"Enter : ";
            std::cin>>choise;

            switch(choise)
            {
                case '1':
                    roomMangement->mangementStart();
                    break;
                case '2':
                    houseKeeping->HouseKeepingStart();
                    break;
                case '3':
                    billingmodule->billingStart();
                    break;
                case '4':
                    event->eventStart();
                    break;
                case '5':
                    discountMangement->getValidDiscountRooms();
                    discountMangement->discountMangementStart();
                    break;
                case '6':
                    return;
                    break;
                case 'e':
                    return;
                    break;
            }
        }
    }
