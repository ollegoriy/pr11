#include "Authorization.h"
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> userDatabase = {
    {"admin", "admin"},
    {"chef", "chef"},
    {"waiter", "waiter"},
    {"guest", "guest"}
};

std::unordered_map<std::string, std::string> roleDatabase = {
    {"admin", "admin"},
    {"chef", "chef"},
    {"waiter", "waiter"},
    {"guest", "guest"}
};

std::string Authorization::login() {
    std::string login, password;
    std::cout << "¬ведите логин: ";
    std::cin >> login;
    std::cout << "¬ведите пароль: ";
    std::cin >> password;

    auto it = userDatabase.find(login);
    if (it != userDatabase.end() && it->second == password) {
        return roleDatabase[login];
    }
    return "";
}
