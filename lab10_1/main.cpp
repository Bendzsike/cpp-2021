#include <iostream>
#include "Ceg.h"

using namespace std;

int main() {

    Ceg c = Ceg();

    c.hireAlkalmazott(new Manager("Futy", "Imre", 1969, Manager::MANAGER_MUNKAKOR));
    c.hireAlkalmazott(new Manager("Beviz", "Elek", 1987, Manager::MANAGER_MUNKAKOR));
    c.hireAlkalmazott(new Manager("Rabsz", "Olga", 1976, Manager::MANAGER_MUNKAKOR));
    c.hireAlkalmazott(new Alkalmazott("Moe", "Lester", 2000, "IT"));
    c.hireAlkalmazott(new Alkalmazott("Hugh", "Jass", 2001, "Janitor"));
    c.hireAlkalmazott(new Alkalmazott("Mike", "Oxlong", 2002, "Admin"));
    c.hireAlkalmazott(new Alkalmazott("Rae", "Piste", 2003, "Electrician"));
    c.hireAlkalmazott(new Alkalmazott("Dixie", "Normus", 2004, "Helpdesk"));
    c.hireAlkalmazott(new Alkalmazott("Gabe", "Itch", 2005, "IT"));
    c.hireAlkalmazott(new Alkalmazott("Ben", "Dover", 2006, "Driver"));

    cout << "Printing every employee:" << endl;
    c.printAll();

    cout << endl << "Adding employees to Managers!" << endl;
    c.addAlkalmazottToManager(1, 4);
    c.addAlkalmazottToManager(1, 9);
    c.addAlkalmazottToManager(1, 6);
    c.addAlkalmazottToManager(2, 7);
    c.addAlkalmazottToManager(2, 8);
    c.addAlkalmazottToManager(3, 5);
    c.addAlkalmazottToManager(3, 10);

    cout << endl << "Printing Managers:" << endl;
    c.printManager();

    cout << endl << "Removing the driver from Manager 3 and adding it to Manager 1!" << endl;
    c.removeAlkalmazottFromManager(3, 10);
    c.addAlkalmazottToManager(1, 10);

    cout << endl << "Printing Managers:" << endl;
    c.printManager();

    return 0;
}
