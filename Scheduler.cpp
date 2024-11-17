#include "Scheduler.h"

// Default constructor
Scheduler::Scheduler() : m_queue() {}

// Schedules an event by adding it to the priority queue
void Scheduler::scheduleEvent(const Event& event) {
    m_queue.enqueue(event);
}

// Returns all scheduled events as a vector, maintaining the priority order
std::vector<Event> Scheduler::getAllEvents() const {
    std::vector<Event> events;
    // Clone the queue to prevent modifying the original queue
    PriorityQueue tempQueue = m_queue;

    // Dequeue all events and add them to the vector
    while (!tempQueue.isEmpty()) {
        events.push_back(tempQueue.dequeue());
    }

    return events;
}

// Returns the next event in the queue (highest priority)
Event Scheduler::nextEvent() {
    return m_queue.peek();
}

// Clears all events in the scheduler
void Scheduler::clearEvents() {
    m_queue.clear();
}
