#include <iostream>
#include "Authorization.h"
#include "Restaurant.h"
#include "Admin.h"
#include "Chef.h"
#include "Waiter.h"

int main() {
    setlocale(LC_ALL, "ru");

    Restaurant restaurant;
    Authorization auth;

    std::string role = auth.login();

    if (role == "admin") {
        Admin admin;
        admin.adminMenu();
    }
    else if (role == "chef") {
        Chef chef;
        chef.chefMenu();
    }
    else if (role == "waiter") {
        Waiter waiter;
        waiter.waiterMenu();
    }
    else if (role == "guest") {
        restaurant.guestMenu();
    }
    else {
        std::cout << "Неизвестная роль. Выход из программы." << std::endl;
    }

    return 0;
}
