#include <iostream>
#include "NodeBST.h"
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    NodeBST bst;
    for(int i = 0; i < 15; ++i) {
        bst.insert(rand() % 14 + 1);
    }

    bst.print_inorder();
    return 0;
}
