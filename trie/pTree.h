/*
 *  Prefix Tree(trie's header file)
 *
 */


#ifndef PTREE_H
#define PTREE_H


#include <string>
#include "pTreeNode.h"
using namespace std;

class Ptree{
    PtreeNode *root;
    int al;
    public:
        Ptree(int val);
        void addToPtree(string word);
        bool checkCriteria(string word, int len);
        ~Ptree();
};


#endif
