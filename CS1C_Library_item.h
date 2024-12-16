#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Base Item class
class Item {
protected:
    string name;
    string description;
    int id;
    bool checkedOut = false;
    string checkedOutBy = "";
    string dueDate = "";

public:
    Item(string name, string description, int id);
    virtual ~Item();

    virtual void print(ostream &out) const;
    void checkout(string person, string date);
    void checkin();
    bool isCheckedOut() const;

    friend ostream &operator<<(ostream &out, const Item &item);
};

// Derived classes
class Book : public Item {
    string title;
    string author;
    int copyrightDate;

public:
    Book(string name, string description, int id, string title, string author, int copyrightDate);
    void print(ostream &out) const override;
};

class Movie : public Item {
    string title;
    string director;
    vector<string> mainActors;

public:
    Movie(string name, string description, int id, string title, string director, vector<string> actors);
    void print(ostream &out) const override;
};

class Magazine : public Item {
    string edition;
    string mainArticleTitle;

public:
    Magazine(string name, string description, int id, string edition, string mainArticleTitle);
    void print(ostream &out) const override;
}

// Helper function to clear input buffer
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to get item details from the user
Item* createItem() {
    int itemType;
    cout << "Select Item Type:\n1. Book\n2. Movie\n3. Magazine\n";
    cin >> itemType;
    clearInput();

    string name, description;
    int id;
    cout << "Enter Item Name: ";
    getline(cin, name);
    cout << "Enter Item Description: ";
    getline(cin, description);
    cout << "Enter Item ID: ";
    cin >> id;
    clearInput();

    if (itemType == 1) {
        string title, author;
        int copyrightDate;
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Copyright Date: ";
        cin >> copyrightDate;
        clearInput();
        return new Book(name, description, id, title, author, copyrightDate);
    } else if (itemType == 2) {
        string title, director;
        vector<string> mainActors;
        cout << "Enter Movie Title: ";
        getline(cin, title);
        cout << "Enter Director: ";
        getline(cin, director);
        cout << "Enter Main Actors (comma-separated): ";
        string actorsInput;
        getline(cin, actorsInput);

        size_t start = 0, end;
        while ((end = actorsInput.find(',', start)) != string::npos) {
            mainActors.push_back(actorsInput.substr(start, end - start));
            start = end + 1;
        }
        mainActors.push_back(actorsInput.substr(start));
        return new Movie(name, description, id, title, director, mainActors);
    } else if (itemType == 3) {
        string edition, mainArticle;
        cout << "Enter Magazine Edition: ";
        getline(cin, edition);
        cout << "Enter Title of Main Article: ";
        getline(cin, mainArticle);
        return new Magazine(name, description, id, edition, mainArticle);
    } else {
        cout << "Invalid item type. Returning null.\n";
        return nullptr;
    }
};



#endif // ITEM_H
