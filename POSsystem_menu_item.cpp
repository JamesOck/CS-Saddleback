// menu_item.cpp
#include "menu_item.h"

MenuItem::MenuItem(const std::string& name, double cost, double sales_price)
    : name(name), cost(cost), sales_price(sales_price) {}

std::string MenuItem::getName() const { return name; }
double MenuItem::getCost() const { return cost; }
double MenuItem::getSalesPrice() const { return sales_price; }
