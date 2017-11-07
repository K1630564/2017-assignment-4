#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;


template <typename T>
class TreeNode{

public:

    T data;

    unique_ptr<TreeNode<T>> leftChild;

    unique_ptr<TreeNode<T>> rightChild;

    TreeNode<T>* parent;

    TreeNode(const T& dataIn)
            : data(dataIn), parent(nullptr){

    }


    void setLeftChild(TreeNode* child){
        leftChild.reset(child); //new??
        child->parent = this;
    }

    void setRightChild(TreeNode* child){
        rightChild.reset(child);
        child->parent = this; // new??
    }

    ostream & write(ostream & o) const{


        // empty left child
        if(leftChild == nullptr && rightChild != nullptr){
            o << " " << this->data << " ";
            rightChild->write(o);
        }
        // empty right child
        else if(rightChild == nullptr && leftChild != nullptr){

            leftChild->write(o);
            o  << " " << this->data << " ";
        }

        // no children empty
        else if(rightChild != nullptr && leftChild != nullptr){

            leftChild->write(o);
            o  << " " << this->data << " ";
            rightChild->write(o);

        }

            // both right and left child empty
        else{
            o << " " << this->data << " ";
        }

        return o;
    }

};

template<typename T>
class TreeNodeIterator {

private:

    TreeNode<T>* current;

public:


    TreeNodeIterator(TreeNode<T>* currentIn)
            : current(currentIn) {
    }

    T & operator*() {
        return current->data;
    }

    TreeNodeIterator<T> & operator++ (){
        current = current->parent;
        return *this;
    }

     bool operator== (const TreeNodeIterator<T> & toCompare) const{

         if(current == toCompare.current){
             return true;
         }
         return false;

    }


    bool operator!= (const TreeNodeIterator<T> &  toCompare) const {

        if(current != toCompare.current){
            return true;
        }
        return false;
    }





};


// do not edit below this line

#endif
