#include <iostream>
#include "Bank.h"

using namespace std;

int main() {
    cout << endl << "#################################\nAccount Test:\n#################################" << endl;
    Account account;

    account.print(cout);
    cout << endl;

    cout << "Deposit 1000:" << endl;
    account.deposit(1000);
    cout << account << endl;
    cout << "Withdraw 500:" << endl;
    account.withdraw(500);
    cout << account << endl;
    cout << "Withdraw 1000:" << endl;
    account.withdraw(1000);
    cout << account << endl;

    cout << endl << "#################################\nCustomer Test:\n#################################" << endl;

    Customer customer("Biro", "Tamas");
    customer.newAccount(0);
    customer.newAccount(1000);
    cout << customer << endl;

    cout << endl << "#################################\nBank Test:\n#################################" << endl;
    Bank bank("OTP");
    vector<int> IDs = bank.loadCustomers("customers.txt");
    cout << "Printing customers from the file:" << endl;
    bank.printCustomers();

    int index = 1;
        for (auto it = IDs.begin(); it != IDs.end(); ++it, ++index) {
            try {
                bank.getCustomer(*it).newAccount(index * 1000);
            } catch(invalid_argument &e) {
                cerr << e.what() << endl;
            }
            try {
                bank.getCustomer(*it).newAccount(index * 2000);
            } catch(invalid_argument &e) {
                cerr << e.what() << endl;
            }
        }
        cout << endl << "Printing the customers with their accounts:" << endl;
        bank.printCustomersAndAccounts();

        cout << endl << "Depositing and withdrawing from the customers' accounts:" << endl;
        for (auto it = IDs.begin(); it != IDs.end(); ++it, ++index) {
            try {
                cout << "Name: " << bank.getCustomer(*it).getFirstName() << " " << bank.getCustomer(*it).getLastName() << endl;
            } catch(invalid_argument &e) {
                cerr << e.what() << endl;
            }
            try {
                cout << "Deposit " << index * 100 << " to account " << bank.getCustomer(*it).getAccount((*it) * 2);
            } catch(invalid_argument &e) {
                cerr << e.what() << endl;
            }
            try {
                bank.getCustomer(*it).getAccount((*it) * 2).deposit(index * 100);
            } catch(invalid_argument &e) {
                cerr << e.what() << endl;
            }
            try {
                cout << "After deposit: " << bank.getCustomer(*it).getAccount((*it) * 2);
            } catch(invalid_argument &e) {
                cerr << e.what() << endl;
            }
            try {
                cout << "Withdraw " << index * 200 << " from acocunt " << bank.getCustomer(*it).getAccount((*it) * 2 + 1);
            } catch(invalid_argument &e) {
                cerr << e.what() << endl;
            }
            try {
                bank.getCustomer(*it).getAccount((*it) * 2 + 1).withdraw(index * 200);
            } catch(invalid_argument &e) {
                cerr << e.what() << endl;
            }
            try {
                cout << "After withdraw: " << bank.getCustomer(*it).getAccount((*it) * 2 + 1);
            } catch(invalid_argument &e) {
                cerr << e.what() << endl;
            }
            cout << endl;
        }

    cout << "Printing the customers with their accounts:" << endl;
    bank.printCustomersAndAccounts();

    return 0;
}
