#include <iostream>
#include "Alkalmazott.h"

using namespace std;

int main() {
    (new Szemely("Futy", "Imre", 1999))->print();
    cout << endl;
    (new Alkalmazott("Futy", "Imre", 1999, "okos"))->print();
    cout << endl;

    return 0;
}
