#include "Guest.h"
#include <iostream>
#include <algorithm>

void Guest::guestMenu() {
    int choice;

    do {
        std::cout << "1. ����������� ����\n2. �������� � �������\n3. ����������� �����\n4. ��������� ������ ������\n5. �����\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            viewMenu();
            break;
        case 2: {
            int menuItemIndex;
            std::cout << "������� ����� ����� ��� ���������� � �������: ";
            std::cin >> menuItemIndex;
            if (menuItemIndex >= 0 && menuItemIndex < menu.size()) {
                addToCart(menu[menuItemIndex]);
            }
            else {
                std::cout << "�������� ����� �����" << std::endl;
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
                std::cout << "������� �����" << std::endl;
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
                std::cout << "������� �����" << std::endl;
            }
            break;
        case 5:
            std::cout << "�����" << std::endl;
            break;

        default:
            std::cout << "�������� �����" << std::endl;
        }
    } while (choice != 5);
}

void Guest::viewMenu() {
    std::cout << "����:\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i << ". " << menu[i].getName() << " - " << menu[i].getPrice() << " ������\n";
        std::cout << "   " << menu[i].getDescription() << "\n\n";
    }
}

void Guest::addToCart(const MenuItem& item) {
    cart.push_back(item);
    std::cout << item.getName() << " �������� � �������\n";
}

void Guest::confirmOrder(Order& order) {
    order.confirmOrder();
}

void Guest::trackOrderStatus(const Order& order) {
    std::cout << "������ ������: " << order.getStatus() << std::endl;
}
