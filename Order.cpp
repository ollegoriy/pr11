#include "Order.h"
#include <iostream>

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
    const std::vector<int>& itemProductIds = item.getProductIds();
    productIds.insert(productIds.end(), itemProductIds.begin(), itemProductIds.end());
}

void Order::confirmOrder() {
    status = "������� � ������� �� �����";
    std::cout << "����� ����������� � �������" << std::endl;
}

void Order::startPreparation() {
    status = "� �������� �������������";
    std::cout << "������������� ��������" << std::endl;
}

void Order::completePreparation() {
    status = "������� ��������� �� ������";
    std::cout << "������������� ���������" << std::endl;
}

void Order::markAsReady() {
    status = "������� ��������� �� ������";
}

void Order::markAsCompleted() {
    status = "��������";
}

std::string Order::getStatus() const {
    return status;
}

const std::vector<int>& Order::getProductIds() const {
    return productIds;
}
