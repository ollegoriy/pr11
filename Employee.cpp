#include "Employee.h"

Employee::Employee(const std::string& role, const std::string& lastName, const std::string& firstName, const std::string& middleName, const std::string& login, const std::string& password)
    : role(role), lastName(lastName), firstName(firstName), middleName(middleName), login(login), password(password) {}

std::string Employee::getRole() const {
    return role;
}

std::string Employee::getLastName() const {
    return lastName;
}

std::string Employee::getFirstName() const {
    return firstName;
}

std::string Employee::getMiddleName() const {
    return middleName;
}

std::string Employee::getLogin() const {
    return login;
}

std::string Employee::getPassword() const {
    return password;
}
