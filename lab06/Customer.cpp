#include "Customer.h"

int Customer::counter{0};

Customer::Customer(const string& firstName, const string& lastName) {
    this->id = ++counter;
    this->firstName = firstName;
    this->lastName = lastName;
}

const string &Customer::getFirstName() const {
    return this->firstName;
}

void Customer::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

const string &Customer::getLastName() const {
    return this->lastName;
}

void Customer::setLastName(const string &lastName) {
    this->lastName = lastName;
}

Account& Customer::getAccount(int id) {
    for(auto it = accounts.begin(); it != accounts.end(); ++it) {
        if(it->getId() == id) {
            return *it;
        }
    }
    ///No Idea what should I do here.
    return *(accounts.end() - 1);
}

int Customer::newAccount(double balance) {
    Account newAccount(balance);
    accounts.emplace_back(newAccount);
    return newAccount.getId();
}

bool Customer::deleteAccount(int id) {
    int index = 0;
    for(auto it = accounts.begin(); it != accounts.end(); ++it, ++index) {
        if(it->getId() == id) {
            accounts.erase(accounts.begin() + index);
            return true;
        }
    }
    return false;
}

int Customer::getNumAccounts() const {
    return accounts.size();
}

void Customer::print(ostream& os) const {
    os << "Name: " << firstName << " " << lastName << endl;
    os << "ID: " << id << endl;
    os << "Accounts: " << endl;
    for(auto it = accounts.begin(); it != accounts.end(); ++it) {
        os << "\t" << *it;
    }
}

ostream& operator<<(ostream& os, const Customer& customer) {
    os << "Name: " << customer.firstName << " " << customer.lastName << endl;
    os << "ID: " << customer.id << endl;
    os << "Accounts: " << endl;
    for(auto it = customer.accounts.begin(); it != customer.accounts.end(); ++it) {
        os << "\t" << *it;
    }
    return os;
}

Account& Customer::operator[](int index) {
    return accounts[index];
}

const Account& Customer::operator[](int index) const {
    return accounts[index];
}