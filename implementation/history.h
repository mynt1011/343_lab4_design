#pragma once
#ifndef HISTORY_H
#define HISTORY_H
#include "event.h"
#include <list>
#include <string>

/*
History objects hold a list of event objects. It is used to keep track of
customer transaction history.
*/

class History {
private:
    std::list<Event*> eventList;  //list of event objects
public:
    History();
    virtual ~History();               // deletes each node in the list. 
    void displayAll() const;  // Iterates through displays all event objects
    void addEvent(Event*);// Adds event to eventList

};
#endif