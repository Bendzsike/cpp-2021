#ifndef LAB7_NODEBST_H
#define LAB7_NODEBST_H

#include "BST.h"

class NodeBST : public BST {
    struct Node {
        int value;
        Node *left, *right;
        Node(int value = 0, Node *left = nullptr, Node *right = nullptr) : value(value), left(left), right(right) {}
    };
    Node *root;
    void inorder(Node *node) const;
    void preorder(Node *node) const;
    void postorder(Node *node) const;
    void deleteSubTree(Node *node);

public:
    NodeBST();
    virtual ~NodeBST();
    void insert(int val);
    bool find(int val) const;
    void print_inorder() const;
    void print_preorder() const;
    void print_postorder() const;
};


#endif //LAB7_NODEBST_H
