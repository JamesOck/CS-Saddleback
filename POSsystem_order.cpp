// order.cpp
#include "order.h"

void Order::addItem(const MenuItem& item, int quantity) {
    items.push_back({item, quantity});
}

double Order::calculateTotalCost() const {
    double total_cost = 0;
    for (const auto& pair : items) {
        total_cost += pair.first.getCost() * pair.second;
    }
    return total_cost;
}

double Order::calculateTotalRevenue() const {
    double total_revenue = 0;
    for (const auto& pair : items) {
        total_revenue += pair.first.getSalesPrice() * pair.second;
    }
    return total_revenue;
}
