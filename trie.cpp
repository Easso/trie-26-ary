#include "trie.h"
#include <iostream>


trie::trie() {
    root = new node('\0');
    wordCount = 0;
}

trie::~trie() {
    this->clear();
    delete root;
}
node trie::getRoot() {
    return *root;
}
void trie::add_word(std::string word) {

    for (int i{0}; i<word.length(); ++i) { //determines if there is a illegal arugment
        if ((97 > int(word[i])) || (122 < int(word[i]))) {
            illegal_exception A;
            throw A;
        }
    }


    if (!word_exists(word)) {
        int start_index = charConversion(word[0]);
        ++wordCount;
        if (root->get_pointer(start_index) == nullptr) {
            // iterate through word to add word fully by creating new nodes
            node * new_node = new node(word[0]);
            root->set_pointer(new_node);
            node * prev_node = new_node;
            if (word.length() == 1) {
                root->get_pointer(charConversion(word[0]))->swapLeafBool();
            }
            for (int i{1}; i < word.length(); ++i) { //set the new node at the end of all iterations so we can add any new letters
                node * new_node = new node(word[i]); // create new node with the next letter
                prev_node->set_pointer(new_node); // set the previous node next pointer for a specific index to the new node
                prev_node = new_node; // set the prev to new node so we can access it's pointers next iteration
                if (i == (word.length() - 1)) { //if word at last index (letter) set it to a leaf node (may not be the very last node in that path, but allows the program to determine if its the end of a word or not) 
                    prev_node->swapLeafBool();
                }
            } 
            std::cout << "success" << std::endl;
        } else {
                node * current_node = root;
            for (int i{0}; i<word.length(); ++i) {
                if (current_node->get_pointer(charConversion(word[i])) == nullptr) {
                    node * new_node = new node(word[i]);
                    current_node->set_pointer(new_node);
                    current_node = new_node;
                    if (i == (word.length() - 1)) {
                        new_node->swapLeafBool();
                    }
                } else {
                    current_node->get_pointer(charConversion(word[i]))->increment_wordCount();
                    current_node = current_node->get_pointer(charConversion(word[i]));
                    if (i == (word.length() - 1)) {
                        current_node->swapLeafBool();
                    }
                }
            }
            std::cout << "success" << std::endl;
        }
    } else {
        std::cout << "failure" << std::endl;
    }
}

void trie::add_word_no_prints(std::string word) {

    if (!word_exists(word)) {
        int start_index = charConversion(word[0]);
        ++wordCount;
        if (root->get_pointer(start_index) == nullptr) {
            node * new_node = new node(word[0]);
            root->set_pointer(new_node);
            node * prev_node = new_node;
            if (word.length() == 1) {
                root->get_pointer(charConversion(word[0]))->swapLeafBool();
            }
            for (int i{1}; i < word.length(); ++i) { 
                node * new_node = new node(word[i]);
                prev_node->set_pointer(new_node);
                prev_node = new_node; 
                if (i == (word.length() - 1)) {  
                    prev_node->swapLeafBool();
                }
            } 
        } else {
                node * current_node = root;
            for (int i{0}; i<word.length(); ++i) {
                if (current_node->get_pointer(charConversion(word[i])) == nullptr) {
                    node * new_node = new node(word[i]);
                    current_node->set_pointer(new_node);
                    current_node = new_node;
                    if (i == (word.length() - 1)) {
                        new_node->swapLeafBool();
                    }
                } else {
                    current_node->get_pointer(charConversion(word[i]))->increment_wordCount();
                    current_node = current_node->get_pointer(charConversion(word[i]));
                    if (i == (word.length() - 1)) {
                        current_node->swapLeafBool();
                    }
                }
            }
        }
    }
}

bool trie::word_exists(std::string word) {
    for (int i{0}; i<word.length(); ++i) { //determines if there is a illegal arugment
        if ((97 > int(word[i])) || (122 < int(word[i]))) {
            illegal_exception A;
            throw A;
        }
    }
    
    bool found = true;
    int start_index = charConversion(word[0]);
    if (root->get_pointer(start_index) == nullptr) {
        return false;
    } else {
        // determine if word is contained
        // one case is that word being search is apart of another word, but word is not actually on the list
        node * current = root;
        for (int i{0}; i<word.length(); ++i) { 
            if (current->get_pointer(charConversion(word[i])) == nullptr && (i != (word.length()-1))) { //checks if it terminates earlier than expected
                return false;
            }
            if (i == (word.length()-1) && current->get_pointer(charConversion(word[i])) != nullptr) {
                if ((current->get_pointer(charConversion(word[i]))->isLeaf())) {
                    return true;
                }
            }
            current = current->get_pointer(charConversion(word[i]));
        }
    }
    return false;
}

void trie::delete_word(std::string word) {
    for (int i{0}; i<word.length(); ++i) { //determines if there is a illegal arugment
        if ((97 > int(word[i])) || (122 < int(word[i]))) {
            illegal_exception A;
            throw A;
        }
    }
    if (word_exists(word)) {
        --wordCount;
        node * current = root->get_pointer(charConversion(word[0]));
        node * temp = current;
        int initCount = current->get_wordCount();
        if (root->get_pointer(charConversion(word[0]))->get_wordCount() == 1) {
            delete root->get_pointer(charConversion(word[0]));
            root->set_null(charConversion(word[0]));
        } else {
            for (int i{1}; i<word.length(); ++i) {
                current = temp->get_pointer(charConversion(word[i]));
                if (temp->get_wordCount() > 1) {
                    
                    temp->decrement_wordCount();
                    
                    if (current->get_wordCount() == 1) {
                        temp->set_null(charConversion(word[i]));
                        delete current;
                        break;
                    }
                    if (i == word.length()-1) {
                        current->swapLeafBool();
                    }
                    temp = current;
                }
            }
        }
        std::cout << "success" << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }
}


void trie::print() {
    if (wordCount > 0) {    
        root->recursivePrint("");
        std::cout << std::endl;
    }
}

void trie::spellCheck(std::string word) {
    bool valid = false;
    if (word_exists(word)) {
        std::cout << "correct" << std::endl;
    } else if (root->get_pointer(charConversion(word[0])) == nullptr) {
            std::cout << std::endl;
    } else {
        std::string first_part = "";
        node * current = root;
        for (int i{0}; i<word.length(); ++i) {
            if (current->get_pointer(charConversion(word[i])) != nullptr) {
                if (word[i] != current->get_pointer(charConversion(word[i]))->get_letter()) {
                    break;
                } else {
                    first_part = first_part + current->get_pointer(charConversion(word[i]))->get_letter();
                    current = current->get_pointer(charConversion(word[i]));
                }
            }
        }
        if (first_part.length() > 0) {
            current->recursivePrint(first_part);
            valid = true;
        }
        if (valid) {
        std::cout << std::endl;
        }
    }
}

void trie::empty() {
    if (wordCount == 0) {
        std::cout << "empty 1" << std::endl;
    } else if (wordCount > 0) {
        std::cout << "empty 0" << std::endl;
    }
}

void trie::clear() {

        
        delete this->root;
        root = new node('\0');
        wordCount = 0;
}

void trie::size() {
    std::cout << "number of words is: " << wordCount << std::endl;
}

int trie::charConversion(char character) {
    
    if (character == 'a' || character == 'A') {
        return 0;
    } else if (character == 'b' || character == 'B') {
        return 1;
    } else if (character == 'c' || character == 'C') {
        return 2;
    } else if (character == 'd' || character == 'D') {
        return 3;
    } else if (character == 'e' || character == 'E') {
        return 4;
    } else if (character == 'f' || character == 'F') {
        return 5;
    } else if (character == 'g' || character == 'G') {
        return 6;
    } else if (character == 'h' || character == 'H') {
        return 7;
    } else if (character == 'i' || character == 'I') {
        return 8;
    } else if (character == 'j' || character == 'J') {
        return 9;
    } else if (character == 'k' || character == 'K') {
        return 10;
    } else if (character == 'l' || character == 'L') {
        return 11;
    } else if (character == 'm' || character == 'M') {
        return 12;
    } else if (character == 'n' || character == 'N') {
        return 13;
    } else if (character == 'o' || character == 'O') {
        return 14;
    } else if (character == 'p' || character == 'P') {
        return 15;
    } else if (character == 'q' || character == 'Q') {
        return 16;
    } else if (character == 'r' || character == 'R') {
        return 17;
    } else if (character == 's' || character == 'S') {
        return 18;
    } else if (character == 't' || character == 'T') {
        return 19;
    } else if (character == 'u' || character == 'U') {
        return 20;
    } else if (character == 'v' || character == 'V') {
        return 21;
    } else if (character == 'w' || character == 'W') {
        return 22;
    } else if (character == 'x' || character == 'X') {
        return 23;
    } else if (character == 'y' || character == 'Y') {
        return 24;
    } else if (character == 'z' || character == 'Z') {
        return 25;
    }
    return -1;
}