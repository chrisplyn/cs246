#ifndef __TRIE_H__
#define __TRIE_H__
#include <string>

struct TrieNode {
    bool isWord;
    std::string meaning;
    int nodes;
    TrieNode *letters[26];
    TrieNode();
    ~TrieNode();

    void insert(const std::string &word, const std::string &meaning);
    void remove(const std::string &word);
    std::string find(const std::string &word);
    int size();
}; // TrieNode

#endif
