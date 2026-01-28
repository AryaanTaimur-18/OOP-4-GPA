#include <iostream>
using namespace std;

struct Book
{
    string title;
    string author;
    float price;
};

int main()
{
    Book books[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter details of Book " << i + 1 << endl;
        cout << "Title: ";
        cin.ignore();
        getline(cin, books[i].title);

        cout << "Author: ";
        getline(cin, books[i].author);

        cout << "Price: ";
        cin >> books[i].price;
    }

    int maxIndex = 0, minIndex = 0;

    for (int i = 1; i < 5; i++)
    {
        if (books[i].price > books[maxIndex].price)
            maxIndex = i;

        if (books[i].price < books[minIndex].price)
            minIndex = i;
    }

    cout << "\nMost Expensive Book:\n";
    cout << "Title: " << books[maxIndex].title << endl;
    cout << "Author: " << books[maxIndex].author << endl;
    cout << "Price: " << books[maxIndex].price << endl;

    cout << "\nCheapest Book:\n";
    cout << "Title: " << books[minIndex].title << endl;
    cout << "Author: " << books[minIndex].author << endl;
    cout << "Price: " << books[minIndex].price << endl;

    return 0;
}
