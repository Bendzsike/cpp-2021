#include <iostream>
#include "Ceg.h"

using namespace std;

int main() {
    Manager m("Futy", "Imre", 1999, Manager::MANAGER_MUNKAKOR);

    m.addAlkalmazott(new Alkalmazott("Moe", "Lester", 2000, "peasant"));
    m.addAlkalmazott(new Alkalmazott("Hugh", "Jass", 2000, "peasant"));
//    m.addAlkalmazott(new Alkalmazott("Reszeg", "Alpar", 2000, "gae"));
    m.addAlkalmazott(new Alkalmazott("Mike", "Oxlong", 2000, "peasant"));
    m.addAlkalmazott(new Alkalmazott("Dixie", "Normus", 2000, "peasant"));

    cout << m;

//    m.deleteAlkalmazott(4);
//
//    cout << m;

    return 0;
}
