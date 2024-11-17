#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "Event.h"
#include "PriorityQueue.h"
#include "Scheduler.h"

using namespace std;
using namespace std::chrono;

int main() {
    cout << "Hello, This is the tester program for the event scheduler" << endl;

    // Create a Scheduler instance
    Scheduler scheduler;

    int numberOfEvents;
    cout << "Enter the number of events to schedule: ";
    cin >> numberOfEvents;

    // Clear input buffer
    cin.ignore();

    // Create a vector to store the events
    vector<Event> events;

    // Loop to get event details from the user
    for (int i = 0; i < numberOfEvents; ++i) {
        string title;
        int type, priority;
        int year, month, day, hour, minute;

        // Input event title
        cout << "Enter title for event " << i + 1 << ": ";
        getline(cin, title);

        // Input event type (1 = Meeting, 2 = Deadline, 3 = Appointment)
        cout << "Enter event type (1 = Meeting, 2 = Deadline, 3 = Appointment): ";
        cin >> type;

        // Input event priority
        cout << "Enter event priority (integer): ";
        cin >> priority;

        // Input event date and time
        cout << "Enter event date and time (Year Month Day Hour Minute): ";
        cin >> year >> month >> day >> hour >> minute;

        // Clear input buffer
        cin.ignore();

        // Convert input to a chrono time_point
        system_clock::time_point eventTime = system_clock::from_time_t(mktime(new tm{0, minute, hour, day, month - 1, year - 1900}));

        // Create the event and add it to the scheduler
        Event newEvent(title, eventTime, static_cast<EventType>(type), priority);
        events.push_back(newEvent);
        scheduler.scheduleEvent(newEvent);
    }

    // Print next event
    cout << "Next event: " << scheduler.nextEvent() << endl;

    // Get all events
    vector<Event> allEvents = scheduler.getAllEvents();
    cout << "All events in the scheduler:" << endl;
    for (const Event& e : allEvents) {
        cout << e << endl;
    }

    // Clear all events
    scheduler.clearEvents();
    cout << "All events cleared." << endl;

    // Check if scheduler is empty
    if (scheduler.getAllEvents().empty()) {
        cout << "Scheduler is empty." << endl;
    } else {
        cout << "Scheduler is not empty." << endl;
    }

    return 0;
}
