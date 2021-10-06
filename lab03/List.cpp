#include "List.h"

List::List() {
//    cout << "List constructor" << endl;
    first = nullptr;
}
List::~List() {
//    cout << "List destructor" << endl;
    auto *node = first;
    while(node != nullptr) {
        auto *temp = node;
        node = node->next;
        delete temp;
    }
    nodeCounter = 0;
}
bool List::exists(int d) const {
    auto *node = first;
    while(node != nullptr) {
        if(node->value == d) {
            return true;
        }
        node = node->next;
    }
    return false;
}
int List::size() const {
    return nodeCounter;
}
bool List::empty() const {
    if(nodeCounter == 0) {
        return true;
    }
    return false;
}
void List::insertFirst(int d) {
    first = new Node(d, first);
    ++nodeCounter;
}
int List::removeFirst() {
    if(empty()) {
        throw length_error("The list is empty!");
    }
    auto *node = first;
    first = first->next;
    --nodeCounter;
    return node->value;
}

//void List::remove(int d, DeleteFlag df = DeleteFlag::EQUAL) {
//
//}
void List::print() const {
    auto *node = first;
    cout << "[";
    while(node != nullptr) {
        cout << node->value << ", ";
        node = node->next;
    }
    cout << "\b\b" << "]" << endl;
}
