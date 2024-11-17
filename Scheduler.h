//
// Created by Furnom Dam on 11/15/2024.
//

#ifndef EVENTAPP_SCHEDULER_H
#define EVENTAPP_SCHEDULER_H
#include <vector>
#include "Order.h"
#include "Event.h"
#include "PriorityQueue.h"

class Scheduler {
public:
    Scheduler();

    void scheduleEvent(const Event& event);      // Schedules an event
    std::vector<Event> getAllEvents() const;     // Returns all scheduled events
    Event nextEvent();                           // Returns the next event
    void clearEvents();                          // Clears all events

private:
    PriorityQueue m_queue;  // PriorityQueue for managing events
};
#endif //EVENTAPP_SCHEDULER_H
