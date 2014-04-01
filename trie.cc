#include "trie.h"
#include <iostream>

using namespace std;

// TrieNode constructor, we have a 26-ary tree
TrieNode::TrieNode(){
   isWord = false;
   for(int i=0; i<26; i++){
      letters[i] = NULL;
   }
   nodes = 0;
}

TrieNode::~TrieNode(){
   for(int i=0; i<26; i++){
      delete letters[i];
   }
}


void TrieNode::insert(const string &word, const string &meaning){
    string w = word;
    TrieNode *ndp = this; //create a pointer to loop through the tree
    while(w.length()>1){
        char cur_char = w[0];
        if(ndp->letters[(int)cur_char-97] == NULL){
           ndp->letters[(int)cur_char-97] = new TrieNode;
           ndp->nodes++; //if the node does not exist, create one and increase
                         //the number of the descents the current node has
        }
        w = w.substr(1); //update the word, look at the remaing word
        ndp = ndp->letters[(int)cur_char-97]; //update pointer to the next node
    }
      char cur_char = w[0];//reach the end of word
      if(ndp->letters[(int)cur_char-97]==NULL){
         ndp->letters[(int)cur_char-97] = new TrieNode;
         ndp->nodes++;   //if the node does not exist, create one and increase
                         //the number of the descents the current node has
      }
      ndp->letters[cur_char-97]->isWord=true;//add the word into the "dictionary"
                                             //by setting this to true
    ndp->letters[cur_char-97]->meaning =meaning;
      return;
}

//similar to insert, loop the word,
//if the word is not in the dictionary, no action to be taken
//else set the isWord to false for the word
void TrieNode::remove(const string &word){
    string w = word;
    TrieNode *ndp = this;
    while(w.length()>1){
        char cur_char = w[0];
        if(ndp->letters[(int)cur_char-97] == NULL) return;
        w = w.substr(1);
        ndp = ndp->letters[(int)cur_char-97];
    }
      char cur_char = w[0];
      if(ndp->letters[(int)cur_char-97]==NULL) return;
      ndp->letters[cur_char-97]->isWord=false;
      return;
}

//update all existing words under the node into the final_str
string find_help(const TrieNode&nd) {
   if(nd.isWord) {
       return nd.meaning;
   } else {
       for(int i=0; i<26; i++){
           if(nd.letters[i]==0) continue;
           return find_help(*nd.letters[i]);
       }
   }
    return "";
}

string TrieNode::find(const string &word){
   string cur_str = "";
   string final_str = "";
   int len = (int)word.length();
   TrieNode *ndp = this;
   for(int i=0 ; i<len; i++){
      if(ndp->letters[(int)(word[i])-97]==0) return final_str;
      cur_str.push_back(word[i]);
      ndp = ndp->letters[(int)(word[i])-97];
   }
   //ndp points to the TrieNode that we need to manipulate
    return find_help(*ndp);
   //find_help(cur_str, final_str,*ndp);
   //if(final_str.length()>0) {
   //    return ndp->meaning;
   //}
   //if there is anything to print, print it;
   //else delete all the descendentss below the node
   for(int i=0; i<26; i++){
        if(ndp->letters[i]!=0) {
            ndp->nodes--;
            delete ndp->letters[i];
            ndp->letters[i]=0;
        } else if(ndp->letters[i]==0) continue;
   }
    return "";
}

void acc_size_f(int &acc_size, const TrieNode &nd){
   if(nd.nodes==0) return;
   acc_size += nd.nodes;
   for(int i=0; i<26; i++){
     if (nd.letters[i]==0) continue;
     acc_size_f(acc_size, *nd.letters[i]);
   }
}

//loop over trie and add all the number of descendents
int TrieNode::size(){
   int acc_size = 1;
   acc_size_f(acc_size,*this);
   return acc_size;
}
