#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "AddressBookEntry.h"
#include <iostream>

class AddressBook {
private:
    AddressBookEntry** entries; // Dynamic array of pointers to AddressBookEntry
    unsigned int size;          // Current number of entries
    unsigned int capacity;      // Current capacity of the array

    void resize();

public:
    AddressBook();
    ~AddressBook();

    void add(const std::string& name, const std::string& email, const std::string& phone);
    AddressBookEntry* operator[](unsigned int index) const;

    friend std::ostream& operator<<(std::ostream& os, const AddressBook& ab);
    AddressBook operator+(const AddressBook& other) const;
    AddressBook operator*(unsigned int times) const;
};

#endif // ADDRESSBOOK_H
