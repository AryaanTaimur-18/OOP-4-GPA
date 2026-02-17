#include <iostream>
#include <string>
using namespace std;

class BookType {
private:
    string title;
    string authors[4];
    int numAuthors;
    string publisher;
    string isbn;
    double price;
    int year;
    int copies;

public:
    BookType() {
        title = "";
        numAuthors = 0;
        publisher = "";
        isbn = "";
        price = 0;
        year = 0;
        copies = 0;
    }

    BookType(string t, int n, string a[], string pub,
             string i, double p, int y, int c) {
        title = t;
        numAuthors = n;
        for (int j = 0; j < n; j++)
            authors[j] = a[j];
        publisher = pub;
        isbn = i;
        price = p;
        year = y;
        copies = c;
    }

    string getISBN() const {
        return isbn;
    }

    void buyBook(int quantity) {
        if (quantity <= copies) {
            copies -= quantity;
            cout << "Total cost: $" << price * quantity << endl;
        } else {
            cout << "Not enough copies available\n";
        }
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Authors: ";
        for (int i = 0; i < numAuthors; i++) {
            cout << authors[i];
            if (i < numAuthors - 1) cout << ", ";
        }
        cout << "\nPublisher: " << publisher
             << "\nISBN: " << isbn
             << "\nPrice: $" << price
             << "\nYear: " << year
             << "\nCopies: " << copies << endl;
    }
};

bool isDuplicateISBN(BookType books[], int count, string isbn) {
    for (int i = 0; i < count; i++) {
        if (books[i].getISBN() == isbn)
            return true;
    }
    return false;
}

int main() {
    const int MAX = 100;
    BookType library[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n1. Add Book\n2. Display Books\n3. Buy Book\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title, publisher, isbn;
            double price;
            int year, copies, n;
            string authors[4];

            cout << "Title: ";
            getline(cin, title);

            cout << "Number of authors (max 4): ";
            cin >> n;
            cin.ignore();

            for (int i = 0; i < n; i++) {
                cout << "Author " << i + 1 << ": ";
                getline(cin, authors[i]);
            }

            cout << "Publisher: ";
            getline(cin, publisher);

            cout << "ISBN: ";
            getline(cin, isbn);

            if (isDuplicateISBN(library, count, isbn)) {
                cout << "Duplicate ISBN not allowed!\n";
                continue;
            }

            cout << "Price: ";
            cin >> price;
            cout << "Year: ";
            cin >> year;
            cout << "Copies: ";
            cin >> copies;

            library[count++] =
                BookType(title, n, authors, publisher, isbn, price, year, copies);

            cout << "Book added successfully!\n";
        }

        else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                cout << "\nBook " << i + 1 << endl;
                library[i].display();
            }
        }

        else if (choice == 3) {
            string isbn;
            int qty;
            cout << "Enter ISBN: ";
            getline(cin, isbn);

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (library[i].getISBN() == isbn) {
                    cout << "Quantity: ";
                    cin >> qty;
                    library[i].buyBook(qty);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found!\n";
        }

    } while (choice != 0);

    return 0;
}
