#include <iostream>
#include "Node.h"
#include "illegal_exception.h"
class trie {
    private:
        int wordCount;
        node* root;
    public:
    trie();
    ~trie();
    node getRoot();
    void add_word(std::string word);
    void add_word_no_prints(std::string word);
    bool word_exists(std::string word);
    void delete_word(std::string word);
    void print();
    void spellCheck(std::string word);
    void empty();
    void clear();
    void size();
    int charConversion(char character);
};