#include "Node.h"
#include <iostream>

node::node() {
    letter = '\0';
    words_contained = 0;
    leafNode = false; //MAY CHANGE LATER
    for (int i{0}; i<26; ++i) {
        pointers[i] = nullptr;
    }
}


node::node(char new_letter) {
    letter = new_letter;
    words_contained = 1;
    leafNode = false; //MAY CHANGE LATER
    for (int i{0}; i<26; ++i) {
        pointers[i] = nullptr;
    }
}

node::~node() {
    for (int i{0}; i<26; ++i) {
        delete pointers[i];
    }
}


node* node::get_pointer(int index) {
    return pointers[index];
}

char node::get_letter() {
    return letter;
}

int node::get_wordCount() {
    return words_contained;
}

void node::set_pointer(node *new_letter) {
    int index = char_to_int(new_letter->get_letter());
    pointers[index] = new_letter;
}

void node::increment_wordCount() {
    ++words_contained;
}

void node::decrement_wordCount() {
    --words_contained;
}

void node::swapLeafBool() {
    leafNode = !leafNode;
}

bool node::isLeaf() {
    return leafNode;
}

void node::set_null(int index) {
    pointers[index] = nullptr;
}

bool node::isAllNull() {
    bool noNullDetected = true;
    for(int i{0}; i<26; ++i) {
        if (this->get_pointer(i) != nullptr) {
            noNullDetected = false;
            return noNullDetected;
        }
    }
    return noNullDetected;
}




void node::recursivePrint(std::string built_word ) {
    if (!(this->isAllNull())) {
        
        for (int i{0}; i<26; ++i) { // start a loop to go through all nodes after the root
            std::string growing_word = built_word;
            if (this->pointers[i]!= nullptr) {
                int wordAmount = this->pointers[i]->get_wordCount();
                growing_word = growing_word + this->pointers[i]->get_letter();
                if (this->pointers[i]->isLeaf()) {
                    std::cout << growing_word << " ";
                    }
                
                if (!this->pointers[i]->isAllNull()) {
                    
                    this->pointers[i]->recursivePrint(growing_word);
                }
            }
        }
    }
}

void node::set_all_null() {
    for (int i{0}; i<26; ++i) {
        this->pointers[i] = nullptr;
    }
}


int node::char_to_int(char character) {
    
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
