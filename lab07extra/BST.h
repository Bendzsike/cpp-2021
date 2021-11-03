#ifndef LAB7_BST_H
#define LAB7_BST_H



class BST {
public:
    virtual ~BST() {}
    virtual void insert(int val) = 0;
    virtual bool find(int val) const = 0;
    virtual void print_inorder() const = 0;
    virtual void print_preorder() const = 0;
    virtual void print_postorder() const = 0;
};


#endif //LAB7_BST_H
