#include <iostream>
#include "Stack.h"
#include "List.h"

using namespace std;

int main() {
//    try {
//        List list;
//        for (int i = 0; i < 10; ++i) {
//            list.insertFirst(i);
//        }
//        list.print();
//    cout << list.exists(1) << endl;
//    cout << list.size() << endl;
//        list.removeFirst();
//        list.print();
//    } catch(const length_error &e) {
//        cerr << e.what() << endl;
//    }

    try {
        Stack stack;
        for(int i = 0; i < 10; ++i) {
            stack.push(i);
        }
        while(!stack.isEmpty()) {
            cout << stack.pop() << endl;
        }
        stack.pop();
    } catch(const length_error &e) {
        cerr << e.what() << endl;
    }
}

