#include <iostream>
#include "illegal_exception.h"

const char * illegal_exception::what() {
    return "illegal argumemt";
}
