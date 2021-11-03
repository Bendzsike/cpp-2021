#ifndef LAB6_BANK_H
#define LAB6_BANK_H

#include "Customer.h"
#include <fstream>
#include <string>

using namespace std;

class Bank {
    vector<Customer> customers;
    string name;
public:
    Bank(const string&);
    //returns the ID of the new Customer
    int newCustomer(const string& firstName, const string& lastName );
    bool deleteCustomer(int id);
    Customer& getCustomer(int id);
    //Convenience functions
    void printCustomers(ostream& os=cout) const;
    void printCustomersAndAccounts(ostream& os=cout) const;
    //LOAD customers, returns their IDs
    vector<int> loadCustomers(const string& filename);
};


#endif //LAB6_BANK_H
