#ifndef LIBRARYSTORAGE_H
#define LIBRARYSTORAGE_H

#include "item.h"
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

// LibraryStorage class
class LibraryStorage {
    vector<vector<Item *>> shelves;

public:
    LibraryStorage(int numShelves, int compartmentsPerShelf);
    ~LibraryStorage();

    vector<Item *> &operator[](size_t shelfIndex);
    void addItem(int shelfIndex, int compartmentIndex, Item *item);
    void printStorage() const;
    void printCheckedOutItems() const;
    void swapItems(int shelf1, int comp1, int shelf2, int comp2);
};

#endif // LIBRARYSTORAGE_H
