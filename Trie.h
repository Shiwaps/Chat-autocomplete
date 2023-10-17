#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

class Trie {
public:
    Trie();
    void insert(std::string word);
    void autoComplete(std::string prefix, std::vector<std::string>& suggestions, int maxSuggestions);

private:
    struct TrieNode;
    TrieNode* root;

    void findWordsWithPrefix(TrieNode* node, std::string currentPrefix, std::vector<std::string>& suggestions, int maxSuggestions);
    bool isEnglishLetter(char c);
};

#endif

