#ifndef LAB6_ACCOUNT_H
#define LAB6_ACCOUNT_H

#include <iostream>

using namespace std;

class Account {
    static int counter;
    int id;
    double balance;
public:
    Account(double balance=0);
    void deposit( double amount);
    bool withdraw(double amount);
    int getId() const;
    double getBalance() const;
    void print(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Account& account);
};


#endif //LAB6_ACCOUNT_H
