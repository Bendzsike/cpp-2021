#include "Bank.h"

Bank::Bank(const string &name) {
    this->name = name;
}
//returns the ID of the new Customer
int Bank::newCustomer(const string& firstName, const string& lastName ) {
    Customer newCustomer(firstName, lastName);
    customers.emplace_back(newCustomer);
    return newCustomer.getId();
}

bool Bank::deleteCustomer(int id) {
    int index = 0;
    for(auto it = customers.begin(); it != customers.end(); ++it, ++index) {
        if(it->getId() == id) {
            customers.erase(customers.begin() + index);
            return true;
        }
    }
    return false;
}

Customer& Bank::getCustomer(int id) {
    int index = 0;
    for(auto it = customers.begin(); it != customers.end(); ++it, ++index) {
        if(it->getId() == id) {
            return *it;
        }
    }
    ///Idk what to do here, so I return the last element
    return *(customers.end() - 1);
}

//Convenience functions
void Bank::printCustomers(ostream& os) const {
    for(auto it = customers.begin(); it != customers.end(); ++it) {
        os << it->getFirstName() << " " << it->getLastName() << endl;
    }
}

void Bank::printCustomersAndAccounts(ostream& os) const {
    for(auto it = customers.begin(); it != customers.end(); ++it) {
        os << *it << endl;
    }
}

//LOAD customers, returns their IDs
vector<int> Bank::loadCustomers(const string& filename) {
    vector<int> IDs;
    ifstream in(filename);
    if(!in.is_open()) {
        cout << "Unable to open file!" << endl;
        return IDs;
    }
    string firstName, lastName;
    while(in >> firstName >> lastName) {
        IDs.emplace_back(newCustomer(firstName, lastName));
    }
    in.close();
    return IDs;
}