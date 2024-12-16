// menu_item.h
#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>

class MenuItem {
private:
  std::string name;
  double cost;
  double sales_price;

public:
  MenuItem(const std::string &name, double cost, double sales_price);
  std::string getName() const;
  double getCost() const;
  double getSalesPrice() const;
};

#endif // MENU_ITEM_H
