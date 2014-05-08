/*
 *  Prefix tree(Trie)'s implementation file
 *  It contain function to add word to tree, and function to check the criteria (i.e. if the current word is composed of other words already 
 *  in the trie)
 *
 */



#include "pTree.h"


Ptree::Ptree(int val){
    al = val;
    root = new PtreeNode(val);
}

Ptree::~Ptree(){
    delete(root);
}
// Function to insert a word into the trie
void Ptree::addToPtree(string word){
    PtreeNode *rt = root;
    for(unsigned int i = 0; i < word.length(); ++i){
        char ch = word.at(i);
        int index = ch - 'a';
        if((rt->children[index]) == NULL){
            rt->children[index] = new PtreeNode(al);
        }
        rt = rt->children[index];
    }
    if( !(rt->isWordEnding))
        rt->isWordEnding = true;

}

//Function to check if the current word meets the criteria of the problem, ie. it is composed of the other words in the file.
bool Ptree::checkCriteria(string word, int len){
    PtreeNode *r = root;
    int count = 0;
    if(word.empty())
        return true;
    for(unsigned int i = 0; i < word.length(); ++i){
        char ch = word.at(i);
        int index = ch - 'a';
        r = r->children[index];
        if(r!= NULL){
            if(r->isWordEnding){
                string suf = string(word, count+1);
                if(checkCriteria(suf, len)){
                    if(word.length() != (unsigned)len){
                        return true;
                        }
                    else if(suf.length() == 0){
                        return false;
                        }
                    else{
                        return true;
                        }
                }
            }

        }
        else{
            return false;
        }
        count++;
    }
    return false;
}


