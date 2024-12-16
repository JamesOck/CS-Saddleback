#include "AddressBookEntry.h"

// Constructor for AddressBookEntry
// Initializes a new entry with the provided name, email, and phone number.
AddressBookEntry::AddressBookEntry(const std::string& name, const std::string& email, const std::string& phone)
    : fullName(name), email(email), phoneNumber(phone) {}

// Accessor method to retrieve the full name of the entry.
// Returns the full name as a string.
std::string AddressBookEntry::getFullName() const {
    return fullName;
}

// Accessor method to retrieve the email of the entry.
// Returns the email as a string.
std::string AddressBookEntry::getEmail() const {
    return email;
}

// Accessor method to retrieve the phone number of the entry.
// Returns the phone number as a string.
std::string AddressBookEntry::getPhoneNumber() const {
    return phoneNumber;
}
