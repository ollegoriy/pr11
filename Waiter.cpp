#include "Waiter.h"
#include <iostream>

void Waiter::waiterMenu() {
    int choice;

    do {
        std::cout << "1. �������� ������� �������\n2. ��������� �����\n3. �����\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            viewReadyOrders();
            break;
        case 2: {
            int orderIndex;
            std::cout << "������� ����� ������ ��� ����������: ";
            std::cin >> orderIndex;
            if (orderIndex >= 0 && orderIndex < orders.size()) {
                markOrderAsCompleted(orders[orderIndex]);
            }
            else {
                std::cout << "�������� ����� ������" << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "�����" << std::endl;
            break;

        default:
            std::cout << "�������� �����" << std::endl;
        }
    } while (choice != 3);
}

void Waiter::viewReadyOrders() {
    for (size_t i = 0; i < orders.size(); ++i) {
        if (orders[i].getStatus() == "������� ��������� �� ������") {
            std::cout << "����� " << i << ": " << orders[i].getStatus() << std::endl;
        }
    }
}

void Waiter::markOrderAsCompleted(Order& order) {
    order.markAsCompleted();
    std::cout << "����� ��������" << std::endl;
}
