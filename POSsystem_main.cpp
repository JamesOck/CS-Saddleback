// pos_system.cpp
#include "pos_system.h"
#include <iostream>

void POSSystem::initializeMenu(const std::vector<MenuItem>& items) {
    menu = items;
}

void POSSystem::addOrder(const Order& order) {
    orders.push_back(order);
}

void POSSystem::generateReports() const {
    double total_cost = 0, total_revenue = 0, total_profit = 0;

    for (const auto& order : orders) {
        total_cost += order.calculateTotalCost();
        total_revenue += order.calculateTotalRevenue();
    }
    total_profit = total_revenue - total_cost;

    std::cout << "Total Cost: $" << total_cost << "\n";
    std::cout << "Total Revenue: $" << total_revenue << "\n";
    std::cout << "Total Profit: $" << total_profit << "\n";
}
