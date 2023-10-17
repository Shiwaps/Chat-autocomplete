#include <iostream>
#include <vector>
#include <string>
#include "Trie.h"

int main() {
    setlocale(LC_ALL, "rus");
    Trie dictionary;

    dictionary.insert("apple");
    dictionary.insert("help");
    dictionary.insert("good");
    dictionary.insert("cucumber");
    dictionary.insert("bat");
    dictionary.insert("dog");
    dictionary.insert("man");
    dictionary.insert("human");

    std::string input;
    while (true) {
        std::cout << "¬ведите букву, или '0' дл€ выхода: ";
        std::cin >> input;

        if (input == "0") {
            break;
        }

        std::vector<std::string> suggestions;
        dictionary.autoComplete(input, suggestions, 10);

        if (suggestions.empty()) {
            std::cout << "—лов с такой буквой не найдено." << std::endl;
        }
        else {
            std::cout << "¬аше слово: " << suggestions[0] << std::endl;
        }
    }

    return 0;
}
