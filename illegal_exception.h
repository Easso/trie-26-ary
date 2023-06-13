#include <iostream>


class illegal_exception : public std::exception {
    private:

    public:
        const char * what ();
};