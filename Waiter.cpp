#include "Waiter.h"
#include <iostream>

void Waiter::waiterMenu() {
    int choice;

    do {
        std::cout << "1. Просмотр готовых заказов\n2. Завершить заказ\n3. Выйти\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            viewReadyOrders();
            break;
        case 2: {
            int orderIndex;
            std::cout << "Введите номер заказа для завершения: ";
            std::cin >> orderIndex;
            if (orderIndex >= 0 && orderIndex < orders.size()) {
                markOrderAsCompleted(orders[orderIndex]);
            }
            else {
                std::cout << "Неверный номер заказа" << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "Выход" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    } while (choice != 3);
}

void Waiter::viewReadyOrders() {
    for (size_t i = 0; i < orders.size(); ++i) {
        if (orders[i].getStatus() == "Передан официанту на выдачу") {
            std::cout << "Заказ " << i << ": " << orders[i].getStatus() << std::endl;
        }
    }
}

void Waiter::markOrderAsCompleted(Order& order) {
    order.markAsCompleted();
    std::cout << "Заказ завершен" << std::endl;
}
