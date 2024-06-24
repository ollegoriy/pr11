#include "Admin.h"
#include <iostream>

void Admin::adminMenu() {
    int choice;

    do {
        std::cout << "1. ������������� ����\n2. ������������� ��������\n3. ������������� �����������\n4. �����\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            editMenu();
            break;
        case 2:
            editProducts();
            break;
        case 3:
            editEmployees();
            break;
        case 4:
            std::cout << "�����" << std::endl;
            break;
        default:
            std::cout << "�������� �����" << std::endl;
        }
    } while (choice != 4);
}

void Admin::editMenu() {
    int choice;
    std::string name, description;
    double price;
    int preparationTime, productId;
    std::vector<int> productIds;

    do {
        std::cout << "1. �������� ����� ����\n2. ������� ����� ����\n3. �����\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "������� ��������: ";
            std::cin >> name;
            std::cout << "������� ��������: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            std::cout << "������� ����� ������������� (� �������): ";
            std::cin >> preparationTime;
            std::cout << "������� ���������: ";
            std::cin >> price;

            std::cout << "������� ID ��������� (0 ��� ����������): ";
            while (true) {
                std::cin >> productId;
                if (productId == 0) break;
                productIds.push_back(productId);
            }

            menu.emplace_back(name, price, description, preparationTime, productIds);
            std::cout << "����� ���� ��������.\n";
            break;

        case 2:
            std::cout << "������� �������� ������ ���� ��� ��������: ";
            std::cin >> name;
            menu.erase(std::remove_if(menu.begin(), menu.end(),
                [&name](const MenuItem& item) { return item.getName() == name; }),
                menu.end());
            std::cout << "����� ���� ������.\n";
            break;

        case 3:
            std::cout << "�����" << std::endl;
            break;

        default:
            std::cout << "�������� �����" << std::endl;
        }
    } while (choice != 3);
}

void Admin::editProducts() {
    int choice;
    int id;
    std::string name;
    double cost;

    do {
        std::cout << "1. �������� �������\n2. ������� �������\n3. �����\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "������� ID: ";
            std::cin >> id;
            std::cout << "������� ��������: ";
            std::cin >> name;
            std::cout << "������� ���������: ";
            std::cin >> cost;

            products.emplace_back(id, name, cost);
            std::cout << "������� ��������.\n";
            break;

        case 2:
            std::cout << "������� ID �������� ��� ��������: ";
            std::cin >> id;
            products.erase(std::remove_if(products.begin(), products.end(),
                [id](const Product& product) { return product.getId() == id; }),
                products.end());
            std::cout << "������� ������.\n";
            break;

        case 3:
            std::cout << "�����" << std::endl;
            break;

        default:
            std::cout << "�������� �����" << std::endl;
        }
    } while (choice != 3);
}

void Admin::editEmployees() {
    int choice;
    std::string role, lastName, firstName, middleName, login, password;

    do {
        std::cout << "1. �������� ����������\n2. ������� ����������\n3. �����\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "������� ����: ";
            std::cin >> role;
            std::cout << "������� �������: ";
            std::cin >> lastName;
            std::cout << "������� ���: ";
            std::cin >> firstName;
            std::cout << "������� ��������: ";
            std::cin >> middleName;
            std::cout << "������� �����: ";
            std::cin >> login;
            std::cout << "������� ������: ";
            std::cin >> password;

            employees.emplace_back(role, lastName, firstName, middleName, login, password);
            std::cout << "��������� ��������.\n";
            break;

        case 2:
            std::cout << "������� ����� ���������� ��� ��������: ";
            std::cin >> login;
            employees.erase(std::remove_if(employees.begin(), employees.end(),
                [&login](const Employee& employee) { return employee.getLogin() == login; }),
                employees.end());
            std::cout << "��������� ������.\n";
            break;

        case 3:
            std::cout << "�����" << std::endl;
            break;

        default:
            std::cout << "�������� �����" << std::endl;
        }
    } while (choice != 3);
}
