#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>

class Order {
public:
    // Default constructor
    Order() : m_customer("NONAME"), m_FIFOCost(0), m_processTime(0),
              m_dueTime(0), m_slackTime(0), m_material(0), m_importance(0),
              m_workForce(0), m_quantity(0) {}

    // Parameterized constructor
    Order(std::string customer, int FIFO, int process, int due, int slack,
          int material, int importance, int workers, int quantity)
            : m_customer(customer), m_FIFOCost(FIFO), m_processTime(process),
              m_dueTime(due), m_slackTime(slack), m_material(material),
              m_importance(importance), m_workForce(workers), m_quantity(quantity) {}

    // Getter functions
    std::string getCustomer() const { return m_customer; }
    int getFIFO() const { return m_FIFOCost; }
    int getProcessTime() const { return m_processTime; }
    int getDueTime() const { return m_dueTime; }
    int getSlackTime() const { return m_slackTime; }
    int getMaterial() const { return m_material; }
    int getImportance() const { return m_importance; }
    int getWorkForce() const { return m_workForce; }
    int getQuantity() const { return m_quantity; }

    // Overloaded insertion operator
    friend std::ostream& operator<<(std::ostream& sout, const Order& order);

private:
    std::string m_customer;   // Customer name
    int m_FIFOCost;           // FIFO cost
    int m_processTime;        // Process time
    int m_dueTime;            // Due time
    int m_slackTime;          // Slack time
    int m_material;           // Material cost
    int m_importance;         // Order importance
    int m_workForce;          // Work force required
    int m_quantity;           // Order quantity
};

// Overloaded output stream operator for Order

#endif // ORDER_H
