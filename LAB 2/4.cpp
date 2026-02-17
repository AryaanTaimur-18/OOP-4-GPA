#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    string publisher;
    float price;
    int stock;

public:
    Book(int id, string t, string a, string p, float pr, int s) {
        bookID = id;
        title = t;
        author = a;
        publisher = p;
        price = pr;
        stock = s;
    }

    int getBookID() {
        return bookID;
    }

    string getTitle() {
        return title;
    }

    void editDetails() {
        cout << "Enter new title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter new author: ";
        getline(cin, author);

        cout << "Enter new publisher: ";
        getline(cin, publisher);

        cout << "Enter new price: ";
        cin >> price;

        cout << "Enter new stock: ";
        cin >> stock;
    }   

    void buyBook(int quantity) {
        if (quantity <= stock) {
            float totalCost = quantity * price;
            stock -= quantity;
            cout << "Book purchased successfully!" << endl;
            cout << "Total cost: " << totalCost << endl;
        } else {
            cout << "Not enough stock available!" << endl;
        }
    }

    void displayDetails() {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    Book* library[100];
    int count = 0;
    int choice;

    do {
        cout << "\n--- E-Library Management System ---\n";
        cout << "1. Add New Book\n";
        cout << "2. Edit Book Details\n";
        cout << "3. Delete Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Buy Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, stock;
            string title, author, publisher;
            float price;
            bool duplicate = false;

            cout << "Enter Book ID: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (library[i]->getBookID() == id) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                cout << "Book with this ID already exists!" << endl;
                continue;
            }

            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "Enter Publisher: ";
            getline(cin, publisher);

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Stock: ";
            cin >> stock;

            library[count++] = new Book(id, title, author, publisher, price, stock);
            cout << "Book added successfully!" << endl;
        }

        else if (choice == 2) {
            int id;
            cout << "Enter Book ID to edit: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (library[i]->getBookID() == id) {
                    library[i]->editDetails();
                    found = true;
                    cout << "Book details updated!" << endl;
                    break;
                }
            }
            if (!found)
                cout << "Book not found!" << endl;
        }

        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to delete: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (library[i]->getBookID() == id) {
                    delete library[i];
                    for (int j = i; j < count - 1; j++)
                        library[j] = library[j + 1];
                    count--;
                    found = true;
                    cout << "Book deleted successfully!" << endl;
                    break;
                }
            }
            if (!found)
                cout << "Book not found!" << endl;
        }

        else if (choice == 4) {
            if (count == 0) {
                cout << "No books in library!" << endl;
            } else {
                for (int i = 0; i < count; i++)
                    library[i]->displayDetails();
            }
        }

        else if (choice == 5) {
            string title;
            int qty;
            bool found = false;

            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter Quantity: ";
            cin >> qty;

            for (int i = 0; i < count; i++) {
                if (library[i]->getTitle() == title) {
                    library[i]->buyBook(qty);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found!" << endl;
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++)
        delete library[i];

    return 0;
}
