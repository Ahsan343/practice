/*
        Header file for Prefix tree(trie)'s Node 

*/
#ifndef PTREENODE_H
#define PTREENODE_H

#include <vector>
#include <iostream>
class PtreeNode{
    public:
        bool isWordEnding;
        int totalChildren;
        std::vector<PtreeNode*> children;
        PtreeNode(int al);
        ~PtreeNode();
};

#endif

