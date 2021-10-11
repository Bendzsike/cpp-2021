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

void List::remove(int d, DeleteFlag df) {
    auto *node = first;
    switch(df) {
        case DeleteFlag::LESS:
            if(node->value < d) {
                removeFirst();
                --nodeCounter;
                return;
            }
            while(node != nullptr) {
                if(node->next->value < d) {
                    node->next = node->next->next;
                    --nodeCounter;
                    return;
                }
                node = node->next;
            }
            break;
        case DeleteFlag::EQUAL:
            if(node->value == d) {
                removeFirst();
                --nodeCounter;
                return;
            }
            while(node != nullptr) {
                if(node->next->value == d) {
                    node->next = node->next->next;
                    --nodeCounter;
                    return;
                }
                node = node->next;
            }
            break;
        case DeleteFlag::GREATER:
            if(node->value > d) {
                removeFirst();
                --nodeCounter;
                return;
            }
            while(node != nullptr) {
                if(node->next->value > d) {
                    node->next = node->next->next;
                    --nodeCounter;
                    return;
                }
                node = node->next;
            }
            break;
    }
}
void List::print() const {
    auto *node = first;
    cout << "[";
    while(node != nullptr) {
        cout << node->value << ", ";
        node = node->next;
    }
    cout << "\b\b" << "]" << endl;
}
