#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    Employee(const std::string& role, const std::string& lastName, const std::string& firstName, const std::string& middleName, const std::string& login, const std::string& password);
    std::string getRole() const;
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getLogin() const;
    std::string getPassword() const;

private:
    std::string role;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string login;
    std::string password;
};

#endif
