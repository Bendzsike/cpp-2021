#include "Account.h"

int Account::counter{0};

Account::Account(double balance) {
    this->id = ++counter;
    this->balance = balance;

}

void Account::deposit( double amount) {
    if(amount < 0) {
        cout << "You can't deposit negative value!" << endl;
        return;
    }
    this->balance += amount;
}

bool Account::withdraw(double amount) {
    if(amount > balance) {
        cout << "You don't have this amount of money!" << endl;
        return false;
    } else if(amount < 0) {
        cout << "You can't withdraw negative value!" << endl;
        return false;
    }
    this->balance -= amount;
    return true;
}

int Account::getId() const {
    return this->id;
}

double Account::getBalance() const {
    return this->balance;
}

void Account::print(ostream& os) const {
    os << "ID: " << id << " Balance: " << balance << endl;
}

ostream& operator<<(ostream& os, const Account& account) {
    os << "ID: " << account.id << " Balance: " << account.balance << endl;
    return os;
}