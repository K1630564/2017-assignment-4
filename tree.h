#ifndef TREE_H
#define TREE_H
#include <iostream>
using std::cout;

#include <memory>
using std::unique_ptr;

#include "treenode.h"

template <typename T>
class BinarySearchTree{

private:

    unique_ptr<TreeNode<T>> root;

public:

    void write(ostream & o) const {
        root->write(o);
    }

    TreeNode<T>* insert(T it){

        T* hej = &root->data;
        TreeNode<T>* ins = new TreeNode<T>(it);
        TreeNode<T>* current = new TreeNode<T>(*hej);
        BinarySearchTree* bst = new BinarySearchTree;
        cout << ins->data << endl;
        cout << current->data << endl;

        if(root != nullptr) {
/*

            if (ins->data < root->data) {
                //go to leftChild
                current->leftChild;
                current->setLeftChild(ins);
                this->insert(it);


            } else if (root->data < ins->data) {
                // go to right child
                current->rightChild;
                current->setRightChild(ins);
                this->insert(it);


            } else {

                this->insert(it);
            }

            return ins;

                */
        }

        else{
            root.reset(ins);
            cout << &root->leftChild << endl;
            return ins;
        }



    }

};




// do not edit below this line

#endif
