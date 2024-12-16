#include "librarystorage.h"

// Constructor
LibraryStorage::LibraryStorage(int numShelves, int compartmentsPerShelf) {
    shelves.resize(numShelves, vector<Item *>(compartmentsPerShelf, nullptr));
}

// Destructor
LibraryStorage::~LibraryStorage() {
    for (auto &shelf : shelves) {
        for (auto &compartment : shelf) {
            delete compartment;
        }
    }
}

vector<Item *> &LibraryStorage::operator[](size_t shelfIndex) {
    if (shelfIndex >= shelves.size()) {
        throw out_of_range("Shelf index out of range.");
    }
    return shelves[shelfIndex];
}

void LibraryStorage::addItem(int shelfIndex, int compartmentIndex, Item *item) {
    if (shelfIndex >= shelves.size() || compartmentIndex >= shelves[shelfIndex].size()) {
        throw out_of_range("Invalid shelf or compartment index.");
    }
    if (shelves[shelfIndex][compartmentIndex] != nullptr) {
        throw runtime_error("Compartment is already occupied.");
    }
    shelves[shelfIndex][compartmentIndex] = item;
}

void LibraryStorage::printStorage() const {
    for (size_t i = 0; i < shelves.size(); ++i) {
        for (size_t j = 0; j < shelves[i].size(); ++j) {
            if (shelves[i][j] != nullptr && !shelves[i][j]->isCheckedOut()) {
                cout << "Shelf " << i << ", Compartment " << j << ":\n";
                cout << *shelves[i][j] << "\n";
            }
        }
    }
}

void LibraryStorage::printCheckedOutItems() const {
    for (size_t i = 0; i < shelves.size(); ++i) {
        for (size_t j = 0; j < shelves[i].size(); ++j) {
            if (shelves[i][j] != nullptr && shelves[i][j]->isCheckedOut()) {
                cout << "Shelf " << i << ", Compartment " << j << ":\n";
                cout << *shelves[i][j] << "\n";
            }
        }
    }
}

void LibraryStorage::swapItems(int shelf1, int comp1, int shelf2, int comp2) {
    if (shelf1 >= shelves.size() || shelf2 >= shelves.size() ||
        comp1 >= shelves[shelf1].size() || comp2 >= shelves[shelf2].size()) {
        throw out_of_range("Invalid shelf or compartment index.");
    }
    if (shelves[shelf1][comp1] == nullptr || shelves[shelf2][comp2] == nullptr) {
        throw runtime_error("Cannot swap empty compartments.");
    }
    swap(shelves[shelf1][comp1], shelves[shelf2][comp2]);
}
