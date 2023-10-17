#include "Trie.h"

const int ALPHABET_SIZE = 26;

struct Trie::TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(std::string word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!isEnglishLetter(c)) {
            return;
        }
        int index = c - 'a';
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

void Trie::autoComplete(std::string prefix, std::vector<std::string>& suggestions, int maxSuggestions) {
    TrieNode* node = root;
    for (char c : prefix) {
        if (!isEnglishLetter(c)) {
            return;
        }
        int index = c - 'a';
        if (!node->children[index]) {
            return;
        }
        node = node->children[index];
    }

    findWordsWithPrefix(node, prefix, suggestions, maxSuggestions);
}

void Trie::findWordsWithPrefix(TrieNode* node, std::string currentPrefix, std::vector<std::string>& suggestions, int maxSuggestions) {
    if (suggestions.size() >= maxSuggestions) {
        return;
    }

    if (node->isEndOfWord) {
        suggestions.push_back(currentPrefix);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            findWordsWithPrefix(node->children[i], currentPrefix + char('a' + i), suggestions, maxSuggestions);
        }
    }
}

bool Trie::isEnglishLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
