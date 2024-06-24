#ifndef CHEF_H
#define CHEF_H

#include <vector>
#include "Order.h"

class Chef {
public:
    void chefMenu();
    void viewOrders();
    void startOrderPreparation(Order& order);
private:
    std::vector<Order> orders;
};

#endif
