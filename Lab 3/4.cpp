#include <iostream>
#include <string>
using namespace std;

class MemberType {
private:
    string name;
    string memberID;
    int booksBought;
    float amountSpent;

public:
    MemberType();
    MemberType(string n, string id);

    void setName(string n);
    string getName() const;
    void showName() const;

    void setMemberID(string id);
    string getMemberID() const;

    void setBooksBought(int num);
    void updateBooksBought(int num);
    int getBooksBought() const;
    void showBooksBought() const;

    void setAmountSpent(float amount);
    void updateAmountSpent(float amount);
    float getAmountSpent() const;
    void showAmountSpent() const;

    void displayMemberInfo() const;
};

MemberType::MemberType() {
    name = "";
    memberID = "";
    booksBought = 0;
    amountSpent = 0.0f;
}

MemberType::MemberType(string n, string id) {
    name = n;
    memberID = id;
    booksBought = 0;
    amountSpent = 0.0f;
}

void MemberType::setName(string n) {
    name = n;
}

string MemberType::getName() const {
    return name;
}

void MemberType::showName() const {
    cout << "Name: " << name << endl;
}

void MemberType::setMemberID(string id) {
    memberID = id;
}

string MemberType::getMemberID() const {
    return memberID;
}

void MemberType::setBooksBought(int num) {
    if (num >= 0)
        booksBought = num;
}

void MemberType::updateBooksBought(int num) {
    if (num > 0)
        booksBought += num;
}

int MemberType::getBooksBought() const {
    return booksBought;
}

void MemberType::showBooksBought() const {
    cout << "Books Bought: " << booksBought << endl;
}

void MemberType::setAmountSpent(float amount) {
    if (amount >= 0)
        amountSpent = amount;
}

void MemberType::updateAmountSpent(float amount) {
    if (amount > 0)
        amountSpent += amount;
}

float MemberType::getAmountSpent() const {
    return amountSpent;
}

void MemberType::showAmountSpent() const {
    cout << "Amount Spent: $" << amountSpent << endl;
}

void MemberType::displayMemberInfo() const {
    cout << "\nMember Details\n";
    cout << "Name: " << name << endl;
    cout << "Member ID: " << memberID << endl;
    cout << "Books Bought: " << booksBought << endl;
    cout << "Amount Spent: $" << amountSpent << endl;
}

int main() {
    MemberType member1("Aryaan", "2540");

    member1.updateBooksBought(3);
    member1.updateAmountSpent(120.50f);

    member1.displayMemberInfo();

    cout << "\nUpdating data...\n";
    member1.updateBooksBought(2);
    member1.updateAmountSpent(80.25f);

    member1.displayMemberInfo();

    return 0;
}
