#include "Trie.hpp"

template <class valueType>
TrieNode<valueType>::TrieNode(){
    this->dictionary = std::unordered_map<char, TrieNode *>();
}

template <class valueType>
TrieNode<valueType> * TrieNode<valueType>::addChild(char c, valueType v){
    auto previous = dictionary.find(c);
    if (previous != dictionary.end()){
        delete dictionary.find(c)->second;
    }
    dictionary[c] = new TrieNode<valueType>(v);
    return dictionary[c];
}

template <class valueType>
void TrieNode<valueType>::setValue(valueType v){
    this->val = v;
}

template <class valueType>
valueType TrieNode<valueType>::getValue(){
    return this->val;
}

template <class valueType>
TrieNode<valueType> * TrieNode<valueType>::get(char c){
    auto it = dictionary.find(c);
    if (it != dictionary.end()){
        return it->second;
    }
    else{
        return nullptr;
    }
}

Trie::Trie(){
    this->root = new TN;
}

void Trie::insert(std::string word){
    TN * node = root;
    std::string::iterator it = word.begin();
    for (; it != word.end(); ++it){
        TN * curr = node->get(*it);
        if (curr == nullptr){
            break;
        }
        else{
            node = curr;
        }
    }

    for(; it != word.end(); ++it){
        node = node->addChild(*it, false);
    }
    node->setValue(true);
}

TN * Trie::find(std::string word){
    TN * node = root;
    TN * curr;
    for (char c : word){
       curr = node->get(c); 
       if (curr == nullptr){
           return nullptr;
       }
       node = curr;
    }
    if (!node->getValue()) return nullptr;
    return node;
}
