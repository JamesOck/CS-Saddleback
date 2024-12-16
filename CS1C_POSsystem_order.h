// order.h
#ifndef ORDER_H
#define ORDER_H

#include "menu_item.h"
#include <vector>

class Order {
private:
    std::vector<std::pair<MenuItem, int>> items;

public:
    void addItem(const MenuItem& item, int quantity);
    double calculateTotalCost() const;
    double calculateTotalRevenue() const;
};

#endif // ORDER_H
