#include "Order.h"
#include <iostream>

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
    const std::vector<int>& itemProductIds = item.getProductIds();
    productIds.insert(productIds.end(), itemProductIds.begin(), itemProductIds.end());
}

void Order::confirmOrder() {
    status = "Оплачен и передан на кухню";
    std::cout << "Заказ подтвержден и оплачен" << std::endl;
}

void Order::startPreparation() {
    status = "В процессе приготовления";
    std::cout << "Приготовление началось" << std::endl;
}

void Order::completePreparation() {
    status = "Передан официанту на выдачу";
    std::cout << "Приготовление завершено" << std::endl;
}

void Order::markAsReady() {
    status = "Передан официанту на выдачу";
}

void Order::markAsCompleted() {
    status = "Выполнен";
}

std::string Order::getStatus() const {
    return status;
}

const std::vector<int>& Order::getProductIds() const {
    return productIds;
}
