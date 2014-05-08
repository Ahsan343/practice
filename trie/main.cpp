/*
 * Program to find the words which are composed of other smaller words in the file "wordsforproblem.txt"
 * It outputs longest, second longest and total such words.
 * -Ravi Mandliya
 *
 *  File: Main.cpp
 *        Contains the main and supporting functions
 */



#include<iostream>
#include<string>
#include<fstream>
#include<iterator>
#include "pTree.h"

using namespace std;

const int ALPHABET=26;

/*
 *  Function: getConcatenatedWords
 *  Purpose: Prints longest word, second longest word and total count of such words
 *  Arguments: Prefix tree(trie) built while reading file and the words stored in vector store
 */


void getConcatenatedWords(Ptree &Tree, vector<string> &store){
    string curr_word, l_word, sl_word;
    int count = 0;
    unsigned int max_length = 0, second_length = 0;
    vector<string>::iterator it;
    for(it = store.begin(); it != store.end(); ++it){
        curr_word = *it;
        if(Tree.checkCriteria(curr_word, curr_word.length())){
            ++count;
            if(max_length < curr_word.length()){
                second_length = max_length;
                sl_word = l_word;
                max_length = curr_word.length();
                l_word = curr_word;
            }
            else if(second_length <= curr_word.length()){
                    second_length = curr_word.length();
                    sl_word = curr_word;

            }

        }
    }
    cout<<"Longest word is "<<l_word<<" of length "<< max_length<<std::endl;

    cout<<"Second Longest word is "<<sl_word<<" of length "<< second_length<<std::endl;
    cout<<"Total matching criteria words:"<<count<<endl;
}

int main(){
    //assuming we have the wordfile with name wordsforproblem.txt in the same folder;
    const char *datafile = "wordsforproblem.txt";
    ifstream infile(datafile);
    istream_iterator<string> itr(infile);
    istream_iterator<string> eof;
    Ptree Tree(ALPHABET);
    vector<string> store;
    int countWords = 0;
    //push words to Prefix Tree and vector store
    while(itr != eof){
            Tree.addToPtree(*itr);
            store.push_back(*itr);
            ++countWords;
            ++itr;
    }
    std::cout<<"DONE\n";
    std::cout<<"Total Words:"<<countWords<<std::endl;
    infile.close();
    getConcatenatedWords(Tree, store);
    return 0;
    
}
