#include "Chef.h"
#include <iostream>

void Chef::chefMenu() {
    int choice;

    do {
        std::cout << "1. Просмотр заказов\n2. Начать приготовление заказа\n3. Выйти\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            viewOrders();
            break;
        case 2: {
            int orderIndex;
            std::cout << "Введите номер заказа для начала приготовления: ";
            std::cin >> orderIndex;
            if (orderIndex >= 0 && orderIndex < orders.size()) {
                startOrderPreparation(orders[orderIndex]);
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

void Chef::viewOrders() {
    for (size_t i = 0; i < orders.size(); ++i) {
        std::cout << "Заказ " << i << ": " << orders[i].getStatus() << std::endl;
    }
}

void Chef::startOrderPreparation(Order& order) {
    order.startPreparation();
    std::cout << "Введите номера продуктов для приготовления заказа: ";
    // Пример имитации процесса ввода номеров продуктов
    for (size_t i = 0; i < order.getProductIds().size(); ++i) {
        int productId;
        std::cin >> productId;
    }
    order.completePreparation();
}
