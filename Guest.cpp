#include "Guest.h"
#include <iostream>
#include <algorithm>

void Guest::guestMenu() {
    int choice;

    do {
        std::cout << "1. Просмотреть меню\n2. Добавить в корзину\n3. Подтвердить заказ\n4. Отследить статус заказа\n5. Выйти\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            viewMenu();
            break;
        case 2: {
            int menuItemIndex;
            std::cout << "Введите номер блюда для добавления в корзину: ";
            std::cin >> menuItemIndex;
            if (menuItemIndex >= 0 && menuItemIndex < menu.size()) {
                addToCart(menu[menuItemIndex]);
            }
            else {
                std::cout << "Неверный номер блюда" << std::endl;
            }
            break;
        }
        case 3:
            if (!cart.empty()) {
                Order order;
                for (const auto& item : cart) {
                    order.addItem(item);
                }
                confirmOrder(order);
            }
            else {
                std::cout << "Корзина пуста" << std::endl;
            }
            break;
        case 4:
            if (!cart.empty()) {
                Order order;
                for (const auto& item : cart) {
                    order.addItem(item);
                }
                trackOrderStatus(order);
            }
            else {
                std::cout << "Корзина пуста" << std::endl;
            }
            break;
        case 5:
            std::cout << "Выход" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    } while (choice != 5);
}

void Guest::viewMenu() {
    std::cout << "Меню:\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i << ". " << menu[i].getName() << " - " << menu[i].getPrice() << " рублей\n";
        std::cout << "   " << menu[i].getDescription() << "\n\n";
    }
}

void Guest::addToCart(const MenuItem& item) {
    cart.push_back(item);
    std::cout << item.getName() << " добавлен в корзину\n";
}

void Guest::confirmOrder(Order& order) {
    order.confirmOrder();
}

void Guest::trackOrderStatus(const Order& order) {
    std::cout << "Статус заказа: " << order.getStatus() << std::endl;
}
