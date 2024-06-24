#ifndef GUEST_H
#define GUEST_H

#include <vector>
#include "MenuItem.h"
#include "Order.h"

class Guest {
public:
    void guestMenu();
    void viewMenu();
    void addToCart(const MenuItem& item);
    void confirmOrder(Order& order);
    void trackOrderStatus(const Order& order);

private:
    std::vector<MenuItem> menu;
    std::vector<MenuItem> cart;
};

#endif
