#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
class KeyValuePair {
    
public:
    
    const Key k;
    Value v;

    KeyValuePair(const Key kIn, Value vIn)
            : k(kIn), v(vIn){

    }

    KeyValuePair(const Key kIn)
            : k(kIn){

    }

    bool operator<(const KeyValuePair & other) const{
        return (k < other.k);
    }



};



template<typename Key, typename Value>
ostream & operator<< (ostream & o, const KeyValuePair<Key,Value> & kv){
    o << kv.k << "," << kv.v;
    return o;
}



template<typename Key, typename Value>
class TreeMap {
  
private:
    BinarySearchTree<KeyValuePair<Key,Value> > tree;
    
public:
    
    KeyValuePair<Key,Value> * insert(const Key & k, const Value & v) {
        return &(tree.insert(KeyValuePair<Key,Value>(k,v))->data);
    }
    
    void write(ostream & o) const {
        tree.write(o);
    }

    KeyValuePair<Key,Value>* find (const Key & k){


        if(tree.find(KeyValuePair<Key, Value>(k)) != nullptr) {


            if (KeyValuePair<Key, Value>(k) < tree.find(KeyValuePair<Key, Value>(k))->data) {
                return nullptr;
            } else if (tree.find(KeyValuePair<Key, Value>(k))->data < KeyValuePair<Key, Value>(k)) {
                return nullptr;
            } else {

                return &(tree.find(KeyValuePair<Key, Value>(k))->data);
            }

        } else{
            return nullptr;
        }


    };
    

    
};


// do not edit below this line

#endif
