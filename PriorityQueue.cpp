#include "PriorityQueue.h"

// Constructor
PriorityQueue::PriorityQueue() : m_heap(nullptr), m_size(0) {}

// Destructor
PriorityQueue::~PriorityQueue() {
    clear();
}

// Enqueue an event (add it to the heap)
void PriorityQueue::enqueue(const Event& event) {
    Node* newNode = new Node(event);
    m_heap = merge(m_heap, newNode);
    m_size++;
}

// Dequeue an event (remove and return the highest-priority event)
Event PriorityQueue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("PriorityQueue is empty");
    }

    Node* minNode = m_heap;
    m_heap = merge(m_heap->m_left, m_heap->m_right); // Merge children
    m_size--;

    Event event = minNode->getEvent();
    delete minNode;
    return event;
}

// Check if the queue is empty
bool PriorityQueue::isEmpty() const {
    return m_heap == nullptr;
}

// Peek at the highest-priority event without removing it
Event PriorityQueue::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("PriorityQueue is empty");
    }
    return m_heap->getEvent();
}

// Clears all events in the priority queue
void PriorityQueue::clear() {
    helpClear(m_heap);
    m_heap = nullptr;
    m_size = 0;
}

// Helper function to clear the heap recursively
void PriorityQueue::helpClear(Node* node) {
    if (node == nullptr) return;
    helpClear(node->m_left);
    helpClear(node->m_right);
    delete node;
}

// Merge two heaps and return the result
Node* PriorityQueue::merge(Node* L, Node* R) {
    if (L == nullptr) return R;
    if (R == nullptr) return L;

    if (L->getEvent().getPriority() > R->getEvent().getPriority()) {
        std::swap(L, R);
    }

    L->m_right = merge(L->m_right, R);
    if (L->m_left == nullptr || L->m_left->getNPL() < L->m_right->getNPL()) {
        std::swap(L->m_left, L->m_right);
    }
    L->setNPL(L->m_right == nullptr ? 0 : L->m_right->getNPL() + 1);

    return L;
}

// Prints the queue's events in pre-order
void PriorityQueue::preOrder(Node* node) const {
    if (node == nullptr) return;
    std::cout << node->getEvent() << std::endl;
    preOrder(node->m_left);
    preOrder(node->m_right);
}

// Print all events in the queue
void PriorityQueue::printEventQueue() const {
    preOrder(m_heap);
}

// Returns the number of events in the queue
int PriorityQueue::numOrders() const {
    return m_size;
}
