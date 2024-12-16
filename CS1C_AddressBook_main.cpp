#include <iostream>
#include <string>
#include "AddressBook.h"

int main() {
    AddressBook ab;

    int numberOfEntries;
    std::cout << "How many entries would you like to add to the Address Book? ";
    std::cin >> numberOfEntries;
    std::cin.ignore(); // Clear the newline character from the input buffer

    for (int i = 0; i < numberOfEntries; ++i) {
        std::string name, email, phone;

        std::cout << "Enter full name for entry " << (i + 1) << ": ";
        std::getline(std::cin, name);

        std::cout << "Enter email for entry " << (i + 1) << ": ";
        std::getline(std::cin, email);

        std::cout << "Enter telephone number for entry " << (i + 1) << ": ";
        std::getline(std::cin, phone);

        ab.add(name, email, phone);
    }

    std::cout << "\nYour Address Book:\n" << ab;

    return 0;
}
