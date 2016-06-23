#ifndef TRIE_HPP
#define TRIE_HPP
#include <unordered_map>
#include <string>


template <class valueType>
class TrieNode{
    private:
        std::unordered_map<char, TrieNode *> dictionary;
        valueType val;
    public:
        TrieNode();
        TrieNode(valueType v);

        TrieNode<valueType> *  addChild(char c, valueType v);

        void setValue(valueType v);

        valueType getValue();

        TrieNode * get(char c);
};

typedef TrieNode<bool> TN;
class Trie{
    private:
        TN * root;
    public:
        Trie();

        void insert(std::string word);

        TN * find(std::string word);
};
#endif //TRIE_H
