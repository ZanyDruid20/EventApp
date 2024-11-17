#include "Event.h"
#include <chrono>

// Default constructor
Event::Event() : m_title(""), m_dateTime(std::chrono::system_clock::now()), m_type(EventType::MEETING), m_priority(0) {}

// Parameterized constructor
Event::Event(const std::string& title, const std::chrono::system_clock::time_point& dateTime,
             EventType type, int priority)
        : m_title(title), m_dateTime(dateTime), m_type(type), m_priority(priority) {}

// Getter for title
std::string Event::getTitle() const {
    return m_title;
}

// Getter for dateTime
std::chrono::system_clock::time_point Event::getDateTime() const {
    return m_dateTime;
}

// Getter for type
EventType Event::getType() const {
    return m_type;
}

// Getter for priority
int Event::getPriority() const {
    return m_priority;
}

// Overloaded << operator to print event details
std::ostream& operator<<(std::ostream& sout, const Event& event) {
    sout << "Event(Title: " << event.getTitle() << ", DateTime: " << std::chrono::system_clock::to_time_t(event.getDateTime())
         << ", Type: " << static_cast<int>(event.getType()) << ", Priority: " << event.getPriority() << ")";
    return sout;
}
