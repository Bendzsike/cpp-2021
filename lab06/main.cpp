#include "Polynomial.h"
#include "Customer.h"
#include "Account.h"
#include <iostream>
#include "Bank.h"

using namespace std;

int main() {
    cout << "#################################\nLab 06:\n#################################" << endl;
    double c1[] {1, 2, 1};

    Polynomial p1(2, c1);

    cout << "P1: " << p1 << endl;

    cout << "P1(0) = " << p1.evaluate(0) << endl;

    cout << "P1(1) = " << p1.evaluate(1) << endl;

    cout << "Index: ";
    for (int i = 0; i < p1.degree() + 1; ++i) {
        cout << p1[i] << " ";
    }
    cout << endl;

    cout << "Negating P1: " << -p1 << endl;

    Polynomial dp1 = p1.derivative();

    cout << "P1 derivative: " << dp1 << endl;

    cout << "P1 derivative + P1 = " << dp1 + p1 << endl;

    cout << "P1 - P1 derivative = " << p1 - dp1 << endl;

    cout << "P1 * P1 derivative = " << p1 * dp1 << endl;

    cout << endl << "#################################\nExtra:\n#################################" << endl;
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
    for(auto it = IDs.begin(); it != IDs.end(); ++it, ++index) {
        bank.getCustomer(*it).newAccount(index * 1000);
        bank.getCustomer(*it).newAccount(index * 2000);
    }
    cout << endl << "Printing the customers with their accounts:" << endl;
    bank.printCustomersAndAccounts();

    cout << endl << "Depositing and withdrawing from the customers' accounts:" << endl;
    for(auto it = IDs.begin(); it != IDs.end(); ++it, ++index) {
        cout << "Name: " << bank.getCustomer(*it).getFirstName() << " " << bank.getCustomer(*it).getLastName() << endl;
        cout << "Deposit " << index * 100 << " to account " << bank.getCustomer(*it).getAccount((*it) * 2);
        bank.getCustomer(*it).getAccount((*it) * 2).deposit(index * 100);
        cout << "After deposit: " << bank.getCustomer(*it).getAccount((*it) * 2);
        cout << "Withdraw " << index * 200 << " from acocunt " << bank.getCustomer(*it).getAccount((*it) * 2 + 1);
        bank.getCustomer(*it).getAccount((*it) * 2 + 1).withdraw(index * 200);
        cout << "After withdraw: " << bank.getCustomer(*it).getAccount((*it) * 2 + 1);
        cout << endl;
    }

    cout << "Printing the customers with their accounts:" << endl;
    bank.printCustomersAndAccounts();

    return 0;
}
