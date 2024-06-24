#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include "MenuItem.h"
#include "Product.h"
#include "Employee.h"

class Admin {
public:
    void adminMenu();
    void editMenu();
    void editProducts();
    void editEmployees();

private:
    std::vector<MenuItem> menu;
    std::vector<Product> products;
    std::vector<Employee> employees;
};

#endif
