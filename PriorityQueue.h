#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


#include <vector>
#include <iostream>
#include "Event.h"

class Node {
public:
    friend class PriorityQueue;
    Node(Event event) {
        m_event = event;
        m_right = nullptr;
        m_left = nullptr;
        m_npl = 0;
    }

    void setNPL(int npl) { m_npl = npl; }
    int getNPL() const { return m_npl; }
    Event getEvent() const { return m_event; }

    friend std::ostream& operator<<(std::ostream& sout, const Node& node);

private:
    Event m_event; // Changed from Order to Event
    Node* m_right;
    Node* m_left;
    int m_npl; // null path length for leftist heap
};

class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();

    void enqueue(const Event& event); // Add event to the queue
    Event dequeue(); // Remove event from the queue
    bool isEmpty() const;
    size_t size() const;
    Event peek() const;

    // Additional methods as requested
    void clear();                          // Clears the priority queue
    void mergeWithQueue(PriorityQueue& rhs); // Merges with another queue
    int numOrders() const;                 // Returns the number of events
    void printEventQueue() const;          // Prints the events in the queue

private:
    void helpClear(Node* node);   // Helper function for clear()
    Node* merge(Node* L, Node* R); // Helper function for mergeWithQueue()
    void swapChildren(Node* node); // Helper function for mergeWithQueue()
    int minNPL(Node* node) const;  // Helper function to return the minimum NPL
    void preOrder(Node* node) const; // Helper function for printEventQueue()

    Node* m_heap; // Root of the heap
    int m_size;   // Number of nodes in the heap
};

#endif // PRIORITYQUEUE_H
