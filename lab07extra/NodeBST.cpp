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
    if(node == nullptr) {
        return;
    }

    cout << node->value << " ";

    preorder(node->left);

    preorder(node->right);
}

void NodeBST::postorder(Node *node) const {
    if(node == nullptr) {
        return;
    }

    postorder(node->left);

    postorder(node->right);

    cout << node->value << " ";
}

void NodeBST::deleteSubTree(Node *node) {
    if(node->left) {
        deleteSubTree(node->left);
    }
    if(node->right) {
        deleteSubTree(node->right);
    }
    delete node;
    node = nullptr;
}

NodeBST::NodeBST() {
    root = nullptr;
}

NodeBST::~NodeBST() {
    deleteSubTree(root);
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
            //Value already exists
            break;
        }
    }
}

bool NodeBST::find(int val) const {
    if(root == nullptr) {
        cout << "Error, tree doesn't exist!" << endl;
        return false;
    }
    Node *temp = root;
    while(temp) {
        if(val < temp->value) {
            temp = temp->left;
        } else if(val > temp->value){

            temp = temp->right;
        } else {
            return true;
        }
    }
    return false;
}

void NodeBST::print_inorder() const {
    inorder(root);
    cout << endl;
}

void NodeBST::print_preorder() const {
    preorder(root);
    cout << endl;
}

void NodeBST::print_postorder() const {
    postorder(root);
    cout << endl;
}
