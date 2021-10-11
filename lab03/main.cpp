#include <iostream>
#include "Stack.h"
#include "List.h"

using namespace std;

int main() {
    try {
        List list;
        cout << "We insert elements [0, 9] in the list." << endl;
        for (int i = 0; i < 10; ++i) {
            list.insertFirst(i);
        }
        cout << "We print the list:" << endl;
        list.print();
    cout << "Does number '1' exist in the list? " << (list.exists(1) ? "Yes" : "No") << endl;
    cout << "List size: " << list.size() << endl;
        list.removeFirst();
        cout << "We removed the first element." << endl;
        cout << "We print the list:" << endl;
        list.print();
        cout << "We remove the first element which is less, equal, and greater comapared to '5'." << endl;
        list.remove(5, List::DeleteFlag::LESS);
        list.remove(5);
        list.remove(5, List::DeleteFlag::GREATER);
        list.print();
        cout << "We remove all of the elements!" << endl;
        while(!list.empty()) {
            list.removeFirst();
        }
        cout << "We try to remove from an empty list, resulting in exception." << endl;
        list.removeFirst();
        cout << endl << endl;
    } catch(const length_error &e) {
        cerr << e.what() << endl;
    }

    try {
        Stack stack;
        cout << "We insert elements [0, 9] in the stack." << endl;
        for(int i = 0; i < 10; ++i) {
            stack.push(i);
        }
        cout << "We pop and print the elements of the stack." << endl;
        while(!stack.isEmpty()) {
            cout << stack.pop() << ", ";
        }
        cout << endl;
        cout << "We try to pop from an empty stack, resulting in exception." << endl;
        stack.pop();
    } catch(const length_error &e) {
        cerr << e.what() << endl;
    }
}

