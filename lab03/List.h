#ifndef LAB3_LIST_H
#define LAB3_LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

class List {
    int nodeCounter{0};
    struct Node {
        int value;
        Node* next;
        Node(int v, Node* n) : value(v), next(n) {}
    };
    Node* first;

public:
    List();
    ~List();
    bool exists(int d) const;
    int size() const;
    bool empty() const;
    void insertFirst(int d);
    int removeFirst();
    enum class DeleteFlag {
        LESS, EQUAL, GREATER
    };
    void remove(int d, DeleteFlag df = DeleteFlag::EQUAL);
    void print() const;
    List(const List&) = delete;
    List& operator=(const List&) = delete;
};

#endif //LAB3_LIST_H
