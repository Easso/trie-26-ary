#include <iostream>
#include <fstream>
#include "trie.h"

int main () {

    std::string command = "", word;
    trie *new_trie = new trie();
    command = "";
    bool exited = false;
    while(std::cin >> command) {
        if (command == "load") {
            std::ifstream fin("corpus.txt");
            while (fin>>word) {
                new_trie->add_word_no_prints(word);
            }
            fin.close();
            std::cout << "success" << std::endl;

        } else if (command == "i") {
            try {
                std::cin >> word;
                new_trie->add_word(word);
            } catch (illegal_exception A) {
                std::cout << A.what() << std::endl;
            }

        } else if (command == "s") {
            
            try {
                std::cin >> word;
                if (new_trie->word_exists(word)) {
                std::cout << "found " << word << std::endl;
                } else {
                    std::cout << "not found" << std::endl;
                    }
            } catch (illegal_exception A) {
                    std::cout << A.what() << std::endl;
                }

        } else if (command == "e") {

            try {    
                std::cin >> word;
                new_trie->delete_word(word);
            } catch (illegal_exception A) {
                std::cout << A.what() << std::endl;
            }

        } else if (command == "p") {

            new_trie->print();

        } else if (command == "spellcheck") {

            std::cin >> word;
            new_trie->spellCheck(word);

        } else if (command == "empty") {

            new_trie->empty();

        } else if (command == "clear") {

            new_trie->clear();
            std::cout << "success" << std::endl;

        } else if (command == "size") {

            new_trie->size();

        } else if (command == "exit") {
            new_trie->clear();
            delete new_trie;
            exited = true;
            break;

        } 

    }
      if (!exited) {
      new_trie->clear();
      delete new_trie;
      return 0;
      }
}