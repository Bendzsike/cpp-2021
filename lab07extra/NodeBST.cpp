#include "NodeBST.h"

using namespace std;

void NodeBST::inorder(Node *node) const {
    if(node == nullptr) {
        return;
    }

    inorder(node->left);

    cout << node->value << " ";

    inorder(node->right);
}

void NodeBST::preorder(Node *node) const {

}

void NodeBST::postorder(Node *node) const {

}

void NodeBST::deleteSubTree(Node *node) {

}

NodeBST::NodeBST() {
    root = nullptr;
}

NodeBST::~NodeBST() {

}

void NodeBST::insert(int val) {
    if(root == nullptr) {
        root = new Node(val);
        return;
    }
    Node *temp = root;
    while(true) {
        if(val < temp->value) {
            if(temp->left == nullptr) {
                temp->left = new Node(val);
                break;
            }
            temp = temp->left;
        } else if(val > temp->value){
            if(temp->right == nullptr) {
                temp->right = new Node(val);
                break;
            }
            temp = temp->right;
        } else {
            break;
        }
    }
}

bool NodeBST::find(int val) const {

}

void NodeBST::print_inorder() const {
    inorder(root);
    cout << endl;
}

void NodeBST::print_preorder() const {

}

void NodeBST::print_postorder() const {

}
