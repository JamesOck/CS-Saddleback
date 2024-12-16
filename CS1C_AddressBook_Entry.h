#ifndef ADDRESSBOOKENTRY_H
#define ADDRESSBOOKENTRY_H

#include <string>

class AddressBookEntry {
private:
    std::string fullName;
    std::string email;
    std::string phoneNumber;

public:
    AddressBookEntry(const std::string& name, const std::string& email, const std::string& phone);

    std::string getFullName() const;
    std::string getEmail() const;
    std::string getPhoneNumber() const;
};

#endif // ADDRESSBOOKENTRY_H
