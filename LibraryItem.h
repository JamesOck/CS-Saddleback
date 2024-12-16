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
};

#endif // ITEM_H
