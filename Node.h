#include <iostream>

class node {
    private:
        char letter;
        int words_contained;
        node *pointers[26];
        bool leafNode;
    public:
        node();
        node(char new_letter);
        ~node();
        node *get_pointer(int index);
        char get_letter();
        int get_wordCount();
        void set_pointer(node *new_letter);
        void increment_wordCount();
        void decrement_wordCount();
        int char_to_int(char character);
        void swapLeafBool();
        bool isLeaf();
        void set_all_null();
        void set_null(int index);
        bool isAllNull();
        void recursivePrint(std::string built_word);
};