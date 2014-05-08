/*
 *  Implementation/Construction of Trie's nodes
 */


#include "pTreeNode.h"

PtreeNode::PtreeNode(int al){
        isWordEnding = false;
        totalChildren = al;
        for(int i = 0; i < totalChildren; ++i){
            children.push_back(NULL);
        }
}


PtreeNode::~PtreeNode(){
    std::vector<PtreeNode*>::iterator itr = children.begin();
    while(itr != children.end()){
            if(*itr != NULL)
                delete(*itr);
            ++itr;
    }
}

