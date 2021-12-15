#ifndef LAB12_ORDEREDLIST_H
#define LAB12_ORDEREDLIST_H

#include <iostream>

using namespace std;

template<class T, class LessComp = less<T>, class Equal = equal_to<T>>

class OrderedList {
    class Node {
    public:
        T value;
        Node* next;
        Node(T value, Node* next = nullptr) {
            this->value = value;
            this->next = next;
        }
    };
    Node* first = nullptr;
    int numElements = 0;
public:
    OrderedList() = default;
    ~OrderedList() = default;

    bool isEmpty() {
        if(numElements) {
            return true;
        }
        return false;
    }

    void insert(const T& value) {
        LessComp lesscomp;
        ++numElements;
        if(!first) {
            first = new Node(value);
        } else if(lesscomp(value, first->value)) {
            first = new Node(value, first);
        } else {
            Node* temp = first;
            while(temp->next) {
                if(lesscomp(value, temp->next->value)) {
                    temp->next = new Node(value, temp->next);
                    return;
                }
                temp = temp->next;
            }
            temp->next = new Node(value, nullptr);
        }
    }

    void remove(const T& value) {
        if(!first) {
            return;
        }
        Equal equal;
        Node* temp = first;
        if(equal(first->value, value)) {
            first = first->next;
            delete temp;
            --numElements;
            return;
        }
        while(temp->next) {
            if(equal(temp->next->value, value)) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
                --numElements;
                return;
            }
            temp = temp->next;
        }
    }

    int size() {
        return numElements;
    }

    bool find(const T& value) {
        Equal equal;
        Node* temp = first;
        while(temp) {
            if(equal(temp->value, value)) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void listItems(ostream& o = cout) {
        Node* temp = first;
        o << "[";
        while(temp != nullptr) {
            o << temp->value;
            if(temp->next) {
                o << ", ";
            }
            temp = temp->next;
        }
        o << "]" << endl;
    }
};

#endif //LAB12_ORDEREDLIST_H
