#include "MenuItem.h"

MenuItem::MenuItem(const std::string& name, double price, const std::string& description, int preparationTime, const std::vector<int>& productIds)
    : name(name), price(price), description(description), preparationTime(preparationTime), productIds(productIds) {}

std::string MenuItem::getName() const {
    return name;
}

double MenuItem::getPrice() const {
    return price;
}

std::string MenuItem::getDescription() const {
    return description;
}

int MenuItem::getPreparationTime() const {
    return preparationTime;
}

const std::vector<int>& MenuItem::getProductIds() const {
    return productIds;
}
