#include "Admin.h"
#include <iostream>

void Admin::adminMenu() {
    int choice;

    do {
        std::cout << "1. Редактировать меню\n2. Редактировать продукты\n3. Редактировать сотрудников\n4. Выйти\n";
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
            std::cout << "Выход" << std::endl;
            break;
        default:
            std::cout << "Неверный выбор" << std::endl;
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
        std::cout << "1. Добавить пункт меню\n2. Удалить пункт меню\n3. Выйти\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите название: ";
            std::cin >> name;
            std::cout << "Введите описание: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            std::cout << "Введите время приготовления (в минутах): ";
            std::cin >> preparationTime;
            std::cout << "Введите стоимость: ";
            std::cin >> price;

            std::cout << "Введите ID продуктов (0 для завершения): ";
            while (true) {
                std::cin >> productId;
                if (productId == 0) break;
                productIds.push_back(productId);
            }

            menu.emplace_back(name, price, description, preparationTime, productIds);
            std::cout << "Пункт меню добавлен.\n";
            break;

        case 2:
            std::cout << "Введите название пункта меню для удаления: ";
            std::cin >> name;
            menu.erase(std::remove_if(menu.begin(), menu.end(),
                [&name](const MenuItem& item) { return item.getName() == name; }),
                menu.end());
            std::cout << "Пункт меню удален.\n";
            break;

        case 3:
            std::cout << "Выход" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    } while (choice != 3);
}

void Admin::editProducts() {
    int choice;
    int id;
    std::string name;
    double cost;

    do {
        std::cout << "1. Добавить продукт\n2. Удалить продукт\n3. Выйти\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите ID: ";
            std::cin >> id;
            std::cout << "Введите название: ";
            std::cin >> name;
            std::cout << "Введите стоимость: ";
            std::cin >> cost;

            products.emplace_back(id, name, cost);
            std::cout << "Продукт добавлен.\n";
            break;

        case 2:
            std::cout << "Введите ID продукта для удаления: ";
            std::cin >> id;
            products.erase(std::remove_if(products.begin(), products.end(),
                [id](const Product& product) { return product.getId() == id; }),
                products.end());
            std::cout << "Продукт удален.\n";
            break;

        case 3:
            std::cout << "Выход" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    } while (choice != 3);
}

void Admin::editEmployees() {
    int choice;
    std::string role, lastName, firstName, middleName, login, password;

    do {
        std::cout << "1. Добавить сотрудника\n2. Удалить сотрудника\n3. Выйти\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите роль: ";
            std::cin >> role;
            std::cout << "Введите фамилию: ";
            std::cin >> lastName;
            std::cout << "Введите имя: ";
            std::cin >> firstName;
            std::cout << "Введите отчество: ";
            std::cin >> middleName;
            std::cout << "Введите логин: ";
            std::cin >> login;
            std::cout << "Введите пароль: ";
            std::cin >> password;

            employees.emplace_back(role, lastName, firstName, middleName, login, password);
            std::cout << "Сотрудник добавлен.\n";
            break;

        case 2:
            std::cout << "Введите логин сотрудника для удаления: ";
            std::cin >> login;
            employees.erase(std::remove_if(employees.begin(), employees.end(),
                [&login](const Employee& employee) { return employee.getLogin() == login; }),
                employees.end());
            std::cout << "Сотрудник удален.\n";
            break;

        case 3:
            std::cout << "Выход" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    } while (choice != 3);
}
