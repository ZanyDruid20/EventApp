#ifndef EVENTAPP_EVENT_H
#define EVENTAPP_EVENT_H

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

// Enum for different event types
enum class EventType {
    MEETING,
    DEADLINE,
    APPOINTMENT
};

// Event class definition
class Event {
public:
    // Default constructor
    Event();

    // Parameterized constructor
    Event(const std::string& title, const std::chrono::system_clock::time_point& dateTime,
          EventType type, int priority);

    // Getter functions
    std::string getTitle() const;
    std::chrono::system_clock::time_point getDateTime() const;
    EventType getType() const;
    int getPriority() const;

    // Friend function for printing event details
    friend std::ostream& operator<<(std::ostream& sout, const Event& event);

private:
    std::string m_title; // Event title
    std::chrono::system_clock::time_point m_dateTime; // Event date and time
    EventType m_type; // Type of event
    int m_priority; // Priority of the event
};

#endif // EVENTAPP_EVENT_H
