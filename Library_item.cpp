#include "item.h"

// Item class implementation
Item::Item(string name, string description, int id)
    : name(name), description(description), id(id) {}

Item::~Item() {}

void Item::print(ostream &out) const {
    out << "ID: " << id << "\nName: " << name
        << "\nDescription: " << description << "\n";
    if (checkedOut) {
        out << "Checked Out By: " << checkedOutBy
            << "\nDue Date: " << dueDate << "\n";
    }
}

void Item::checkout(string person, string date) {
    if (checkedOut) {
        throw runtime_error("Item is already checked out.");
    }
    checkedOut = true;
    checkedOutBy = person;
    dueDate = date;
}

void Item::checkin() {
    if (!checkedOut) {
        throw runtime_error("Item is not currently checked out.");
    }
    checkedOut = false;
    checkedOutBy = "";
    dueDate = "";
}

bool Item::isCheckedOut() const {
    return checkedOut;
}

ostream &operator<<(ostream &out, const Item &item) {
    item.print(out);
    return out;
}

// Book class implementation
Book::Book(string name, string description, int id, string title, string author, int copyrightDate)
    : Item(name, description, id), title(title), author(author), copyrightDate(copyrightDate) {}

void Book::print(ostream &out) const {
    Item::print(out);
    out << "Title: " << title << "\nAuthor: " << author
        << "\nCopyright Date: " << copyrightDate << "\n";
}

// Movie class implementation
Movie::Movie(string name, string description, int id, string title, string director, vector<string> actors)
    : Item(name, description, id), title(title), director(director), mainActors(actors) {}

void Movie::print(ostream &out) const {
    Item::print(out);
    out << "Title: " << title << "\nDirector: " << director
        << "\nMain Actors: ";
    for (const auto &actor : mainActors) {
        out << actor << ", ";
    }
    out << "\n";
}

// Magazine class implementation
Magazine::Magazine(string name, string description, int id, string edition, string mainArticleTitle)
    : Item(name, description, id), edition(edition), mainArticleTitle(mainArticleTitle) {}

void Magazine::print(ostream &out) const {
    Item::print(out);
    out << "Edition: " << edition << "\nMain Article: " << mainArticleTitle << "\n";
}
    
