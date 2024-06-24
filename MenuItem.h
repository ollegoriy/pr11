#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <vector>

class MenuItem {
public:
    MenuItem(const std::string& name, double price, const std::string& description, int preparationTime, const std::vector<int>& productIds);
    std::string getName() const;
    double getPrice() const;
    std::string getDescription() const;
    int getPreparationTime() const;
    const std::vector<int>& getProductIds() const;

private:
    std::string name;
    double price;
    std::string description;
    int preparationTime;
    std::vector<int> productIds;
};

#endif
