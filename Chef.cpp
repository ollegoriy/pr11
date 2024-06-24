#include "Chef.h"
#include <iostream>

void Chef::chefMenu() {
    int choice;

    do {
        std::cout << "1. �������� �������\n2. ������ ������������� ������\n3. �����\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            viewOrders();
            break;
        case 2: {
            int orderIndex;
            std::cout << "������� ����� ������ ��� ������ �������������: ";
            std::cin >> orderIndex;
            if (orderIndex >= 0 && orderIndex < orders.size()) {
                startOrderPreparation(orders[orderIndex]);
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

void Chef::viewOrders() {
    for (size_t i = 0; i < orders.size(); ++i) {
        std::cout << "����� " << i << ": " << orders[i].getStatus() << std::endl;
    }
}

void Chef::startOrderPreparation(Order& order) {
    order.startPreparation();
    std::cout << "������� ������ ��������� ��� ������������� ������: ";
    // ������ �������� �������� ����� ������� ���������
    for (size_t i = 0; i < order.getProductIds().size(); ++i) {
        int productId;
        std::cin >> productId;
    }
    order.completePreparation();
}
