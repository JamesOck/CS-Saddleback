include "librarystorage.h"
#include "item.h"
#include "item.h"

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
int main() {
    try {
        int numShelves, compartmentsPerShelf;
        cout << "Enter number of shelves: ";
        cin >> numShelves;
        cout << "Enter number of compartments per shelf: ";
        cin >> compartmentsPerShelf;
        clearInput();

        LibraryStorage libraryInventory(numShelves, compartmentsPerShelf);

        int choice;
        do {
            cout << "\nLibrary Inventory Menu:\n";
            cout << "1. Add an Item\n";
            cout << "2. Checkout an Item\n";
            cout << "3. Checkin an Item\n";
            cout << "4. Swap Items\n";
            cout << "5. Print Items in Storage\n";
            cout << "6. Print Checked-Out Items\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            clearInput();

            switch (choice) {
                case 1: {
                    int shelf, compartment;
                    cout << "Enter shelf index: ";
                    cin >> shelf;
                    cout << "Enter compartment index: ";
                    cin >> compartment;
                    clearInput();

                    Item* newItem = createItem();
                    if (newItem) {
                        libraryInventory.addItem(shelf, compartment, newItem);
                        cout << "Item added successfully.\n";
                    } else {
                        cout << "Failed to add item.\n";
                    }
                    break;
                }
                case 2: {
                    int shelf, compartment;
                    string personName, dueDate;
                    cout << "Enter shelf index: ";
                    cin >> shelf;
                    cout << "Enter compartment index: ";
                    cin >> compartment;
                    clearInput();
                    cout << "Enter name of person checking out the item: ";
                    getline(cin, personName);
                    cout << "Enter due date (YYYY-MM-DD): ";
                    getline(cin, dueDate);

                    if (libraryInventory[shelf][compartment]) {
                        libraryInventory[shelf][compartment]->checkout(personName, dueDate);
                        cout << "Item checked out successfully.\n";
                    } else {
                        cout << "No item found in the specified compartment.\n";
                    }
                    break;
                }
                case 3: {
                    int shelf, compartment;
                    cout << "Enter shelf index: ";
                    cin >> shelf;
                    cout << "Enter compartment index: ";
                    cin >> compartment;
                    clearInput();

                    if (libraryInventory[shelf][compartment]) {
                        libraryInventory[shelf][compartment]->checkin();
                        cout << "Item checked in successfully.\n";
                    } else {
                        cout << "No item found in the specified compartment.\n";
                    }
                    break;
                }
                case 4: {
                    int shelf1, compartment1, shelf2, compartment2;
                    cout << "Enter first shelf index: ";
                    cin >> shelf1;
                    cout << "Enter first compartment index: ";
                    cin >> compartment1;
                    cout << "Enter second shelf index: ";
                    cin >> shelf2;
                    cout << "Enter second compartment index: ";
                    cin >> compartment2;
                    clearInput();

                    libraryInventory.swapItems(shelf1, compartment1, shelf2, compartment2);
                    cout << "Items swapped successfully.\n";
                    break;
                }
                case 5:
                    cout << "Items in storage:\n";
                    libraryInventory.printStorage();
                    break;
                case 6:
                    cout << "Checked-out items:\n";
                    libraryInventory.printCheckedOutItems();
                    break;
                case 0:
                    cout << "Exiting the system. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 0);

    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        
    }

    return 0;
}
