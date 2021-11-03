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
    string str = to_string(id);
    throw invalid_argument("Customer corresponding to ID \"" + str + "\" is not in the system!");
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
        exit(1);
    }
    string firstName, lastName;
    while(in >> firstName >> lastName) {
        IDs.emplace_back(newCustomer(firstName, lastName));
    }
    in.close();
    return IDs;
}