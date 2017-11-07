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

    TreeNode<T>* insert( T it){

        TreeNode<T>* current = root.get();

        if(current == nullptr){
            TreeNode<T>* newNode = new TreeNode<T>(it);
            newNode->leftChild = nullptr;
            newNode->rightChild = nullptr;

            root.reset(newNode);
            current = newNode;
            return newNode;
            
        }
        else {
             current = root.get();
            
     while(current != nullptr) {


         if (it < current->data) {
             if (current->leftChild == nullptr) {
                 TreeNode<T>* newNode = new TreeNode<T>(it);
                 current->setLeftChild(newNode);
                 current = newNode;
                 return newNode;

             } else {
                 current = current->leftChild.get();

             }

         } else if (current->data < it) {
             if (current->rightChild == nullptr) {
                 TreeNode<T>* newNode = new TreeNode<T>(it);
                 current->setRightChild(newNode);
                 current = newNode;
                 return newNode;

             } else {
                 current = current->rightChild.get();

             }

         } else {
             return current;

         }


     }
        return nullptr; // to ignore warning of may reach end of non-void funtion

        }
    }

    TreeNode<T>* find( T item) const {


        TreeNode<T> *current = root.get();

        if (current == nullptr) {
            return nullptr;

        } else {
            current = root.get();


            while (current != nullptr) {

                if (item < current->data) {
                    if (current->leftChild == nullptr) {
                        return nullptr;

                    } else {
                        current = current->leftChild.get();
                    }


                } else if (current->data < item) {

                    if (current->rightChild == nullptr) {

                        return nullptr;

                    } else {
                        current = current->rightChild.get();

                    }


                } else {
                    return current;
                }


            }

            return nullptr;


        }
    }


    TreeNodeIterator<T> begin() const{
        TreeNode<T> *current = root.get();
        TreeNodeIterator<T> temp = TreeNodeIterator<T>(current);



        if(current == nullptr){
            cout << "ett " << endl;
            return temp;

        }

       else if(current->leftChild == nullptr){
            temp = TreeNodeIterator<T>(current);
            cout << "två " << endl;
            return temp;
        }

        else{
            while(current->leftChild != nullptr){
                current = current->leftChild.get();


                }
            cout << current->data << endl;
            temp = TreeNodeIterator<T>(current);
            cout << "tre " << endl;
            return temp;



            }

        }
    TreeNodeIterator<T> end() const{


        TreeNodeIterator<T> empty = TreeNodeIterator<T>(nullptr);
        cout << "end" << endl;
        return empty;
    }





};




// do not edit below this line

#endif
