#include <iostream>
#include <string>
#include "Event.h"

    std::string events[5], date[5] , times[5];
    bool isEventSet;
    char setEventsDetails(int i, char &stat);
    void Event::clearEvent(const int i)
    {
        system("cls");
        events[i] = "";
        date[i] = "";
        times[i] = "";
        return;
    }

    char Event::setEventsDetails(int i, char &stat)
    {

        std::cout << "Event #" << i + 1 << " : ";
        std::cin >> events[i];
        std::cout << "Date (MM/DD/YYYY): ";
        std::cin >> date[i];
        std::cout << "Times (HH:MM AM/PM): ";
        std::cin >> times[i];
        std::cout << "Do You Like To Continue :";
        std::cin >> stat;
        std::cout << "\n";
         system("PAUSE");
        return stat;
    }


    void Event::setEvents()
    {
        char stat = ' ';
        system("cls");
        std::cout << "\t[e - exit , r - reset]\n"<< std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cout << "                                Events  Entery                                  " << std::endl;
        std::cout << "================================================================================" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            if (stat == 'e')
            {
                break;
            }
            stat = setEventsDetails(i, stat);
            return;
        }
        system("PAUSE");
    }
    void Event::displayEvents() 
    {
        int count = 0;
        system("cls");
        std::cout << "================================================================================" << std::endl;
        std::cout << "                                      Events                                    " << std::endl;
        std::cout << "================================================================================" << std::endl;

        for (int i = 0; i < 5; i++)
        {
            if (events[i] == "")
            {
                count++;
                continue;
            }
            std::cout << "Event #" << i + 1 << " : " << events[i] << std::endl;
            std::cout << "Date : " << date[i] << std::endl;
            std::cout << "Times : " << times[i] << std::endl;
            std::cout << std::endl;
            isEventSet = true;
        }
        if(count > 4){
            std::cout<<"                               No Events Schduled            "<<std::endl;
            isEventSet = false;
        }
        system("PAUSE");
    }

    void Event::resetEvent()
    {   
        std::cout << "================================================================================" << std::endl;
        std::cout << "                                    Reset Event                                 " << std::endl;
        std::cout << "================================================================================" << std::endl;    
        if(isEventSet == false){
            displayEvents();
            return;
        }
        displayEvents();
        std::string choise;
        std::cout<<"Do You Like To Reset All The Event (y/n) : ";
        std::cin >> choise;
        if(choise == "N" || choise == "n" )
            return;
        for(int i = 0 ; i < 5 ; i++){
            clearEvent(i);
            std::cout<<"Reseted All The Events...\n";
            system("pause");
            return;
        }
    }

    void Event::deleteEvent()
    {   
        system("cls");
        if(isEventSet == false){
            displayEvents();
            return;
        }
        displayEvents();
        int eventToDel;
        std::cout << "Enter The Event Number To Delete :";
        std::cin >> eventToDel;
        clearEvent(eventToDel - 1);

        displayEvents();

    }
    void Event::eventStart()
    {
        system("CLS");
        char choice;
        while (true)
    {
        system("cls");
        std::cout << "================================================================================" << std::endl;
        std::cout << "                                Events  Mangement                               " << std::endl;
        std::cout << "================================================================================" << std::endl;

        std::cout << "1.                              Add Events\n";
        std::cout << "2.                              Display Events\n";
        std::cout << "3.                              Reset  Events\n";
        std::cout << "4.                              Delete  Events\n";
        std::cout << "5.                              Exit\n";

        std::cout << "\nEnter:";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            setEvents();
            break;
        case '2':
            displayEvents();
            break;
        case '3':
            resetEvent();
            break;
        case '4':
            deleteEvent();
            break;
        case '5':
            return;

        default:
        std::cout << "Invalid input. Please choose a valid option.\n";
        break;

         }
        }
    }


