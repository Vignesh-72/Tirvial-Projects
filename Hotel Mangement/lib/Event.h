#ifndef EVENT_H
#define EVENT_H

class Event 
{
    
public:
    void clearEvent(const int i);
    void setEvents();
    void displayEvents();
    void resetEvent();
    void deleteEvent();
    void eventStart();
    char setEventsDetails(int i, char &stat);
};

#endif