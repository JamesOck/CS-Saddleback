#include "AddressBook.h"

// Constructor
AddressBook::AddressBook() : size(0), capacity(1) {
    entries = new AddressBookEntry*[capacity];
}

// Destructor
AddressBook::~AddressBook() {
    for (unsigned int i = 0; i < size; ++i) {
        delete entries[i]; // Free each entry
    }
    delete[] entries; // Free the array
}

// Resize the dynamic array
void AddressBook::resize() {
    capacity *= 2;
    AddressBookEntry** newEntries = new AddressBookEntry*[capacity];
    for (unsigned int i = 0; i < size; ++i) {
        newEntries[i] = entries[i];
    }
    delete[] entries;
    entries = newEntries;
}

// Add an entry to the Address Book
void AddressBook::add(const std::string& name, const std::string& email, const std::string& phone) {
    if (size == capacity) {
        resize();
    }
    entries[size++] = new AddressBookEntry(name, email, phone);
}

// Access an entry by index
AddressBookEntry* AddressBook::operator[](unsigned int index) const {
    if (index < size) {
        return entries[index];
    }
    return nullptr; // Out of bounds
}

// Output the Address Book
std::ostream& operator<<(std::ostream& os, const AddressBook& ab) {
    os << "------Address Book-------\n";
    os << "Size: " << ab.size << "\n";
    for (unsigned int i = 0; i < ab.size; ++i) {
        os << ab.entries[i]->getFullName() << "\n";
        os << ab.entries[i]->getPhoneNumber() << "\n";
        os << ab.entries[i]->getEmail() << "\n\n";
    }
    os << "---------------------------";
    return os;
}

// Combine two Address Books
AddressBook AddressBook::operator+(const AddressBook& other) const {
    AddressBook newBook;
    for (unsigned int i = 0; i < size; ++i) {
        newBook.add(entries[i]->getFullName(), entries[i]->getEmail(), entries[i]->getPhoneNumber());
    }
    for (unsigned int i = 0; i < other.size; ++i) {
        newBook.add(other.entries[i]->getFullName(), other.entries[i]->getEmail(), other.entries[i]->getPhoneNumber());
    }
    return newBook;
}

// Multiply Address Book entries
AddressBook AddressBook::operator*(unsigned int times) const {
    AddressBook newBook;
    for (unsigned int i = 0; i < times; ++i) {
        for (unsigned int j = 0; j < size; ++j) {
            newBook.add(entries[j]->getFullName(), entries[j]->getEmail(), entries[j]->getPhoneNumber());
        }
    }
    return newBook;
}
