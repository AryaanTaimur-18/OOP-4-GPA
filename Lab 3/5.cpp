#include <iostream>
#include <string>
using namespace std;

class BookType {
private:
    string title;
    string isbn;
    double price;
    int copies;

public:
    BookType() {
        title = "";
        isbn = "";
        price = 0;
        copies = 0;
    }

    BookType(string t, string i, double p, int c) {
        title = t;
        isbn = i;
        price = p;
        copies = c;
    }

    string getISBN() const { return isbn; }
    double getPrice() const { return price; }

    bool sellBook() {
        if (copies > 0) {
            copies--;
            return true;
        }
        return false;
    }

    void display() const {
        cout << "Title: " << title
             << " | ISBN: " << isbn
             << " | Price: $" << price
             << " | Copies: " << copies << endl;
    }
};

class MemberType {
private:
    string name;
    string memberID;
    int booksBought;
    double amountSpent;
    double lastTen[10];
    int index;

public:
    MemberType() {
        name = "";
        memberID = "";
        booksBought = 0;
        amountSpent = 0;
        index = 0;
    }

    MemberType(string n, string id) {
        name = n;
        memberID = id;
        booksBought = 0;
        amountSpent = 0;
        index = 0;
    }

    string getID() const { return memberID; }

    void buyBook(double price) {
        double discountedPrice = price * 0.95; // 5% discount
        amountSpent += discountedPrice;
        lastTen[index % 10] = discountedPrice;
        index++;
        booksBought++;

        if (booksBought % 11 == 0) {
            double sum = 0;
            for (int i = 0; i < 10; i++)
                sum += lastTen[i];

            double avg = sum / 10;
            cout << "Special Discount Applied: $" << avg << endl;
            amountSpent -= avg;
            amountSpent = 0;
        }
    }

    void display() const {
        cout << "Member: " << name
             << " | ID: " << memberID
             << " | Books Bought: " << booksBought
             << " | Amount Spent: $" << amountSpent << endl;
    }
};

int main() {
    const int MAX_BOOKS = 1000;
    const int MAX_MEMBERS = 500;

    BookType books[MAX_BOOKS];
    MemberType members[MAX_MEMBERS];

    int bookCount = 0, memberCount = 0;
    int choice;

    do {
        cout << "\n1. Add Book\n2. Add Member\n3. Buy Book (Member)\n4. Display Books\n5. Display Members\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            string t, i;
            double p;
            int c;
            cout << "Title: "; cin >> t;
            cout << "ISBN: "; cin >> i;
            cout << "Price: "; cin >> p;
            cout << "Copies: "; cin >> c;
            books[bookCount++] = BookType(t, i, p, c);
        }

        else if (choice == 2) {
            string n, id;
            cout << "Name: "; cin >> n;
            cout << "Member ID: "; cin >> id;
            members[memberCount++] = MemberType(n, id);
            cout << "$10 Membership Fee Paid\n";
        }

        else if (choice == 3) {
            string isbn, id;
            cout << "ISBN: "; cin >> isbn;
            cout << "Member ID: "; cin >> id;

            for (int i = 0; i < bookCount; i++) {
                if (books[i].getISBN() == isbn && books[i].sellBook()) {
                    for (int j = 0; j < memberCount; j++) {
                        if (members[j].getID() == id) {
                            members[j].buyBook(books[i].getPrice());
                            cout << "Book Purchased!\n";
                        }
                    }
                }
            }
        }

        else if (choice == 4) {
            for (int i = 0; i < bookCount; i++)
                books[i].display();
        }

        else if (choice == 5) {
            for (int i = 0; i < memberCount; i++)
                members[i].display();
        }

    } while (choice != 0);

    return 0;
}
