#include <ctime>
#include "OrderedList.h"

using namespace std;

int main() {
//    srand(time(nullptr));
    OrderedList<int> list;
    for(int i = 0; i < 10; ++i) {
        int num = rand() % 9 + 1;
        cout << num << endl;
        list.insert(num);
    }
    list.listItems();
    cout << list.find(5) << endl;
    list.remove(5);
    cout << list.find(5) << endl;
    list.listItems();
    return 0;
}