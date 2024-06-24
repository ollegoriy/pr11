#ifndef WAITER_H
#define WAITER_H

#include <vector>
#include "Order.h"

class Waiter {
public:
    void waiterMenu();
    void viewReadyOrders();
    void markOrderAsCompleted(Order& order);
private:
    std::vector<Order> orders;
};

#endif
