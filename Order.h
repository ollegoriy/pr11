#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "MenuItem.h"

class Order {
public:
    void addItem(const MenuItem& item);
    void confirmOrder();
    void startPreparation();
    void completePreparation();
    void markAsReady();
    void markAsCompleted();
    std::string getStatus() const;
    const std::vector<int>& getProductIds() const;

private:
    std::vector<MenuItem> items;
    std::string status;
    std::vector<int> productIds;
};

#endif
