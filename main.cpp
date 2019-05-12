#include <iostream>
#include "BigInteger.h"


int main() {
    int size = MAX_SIZE / 8;
    char* a_string = new char[size * 2 + 1];
    char* b_string = new char[size + 1];
    a_string[0] = '4';
    b_string[0] = '2';
    for (int i = 1; i < size * 2 + 1; ++i) {
        a_string[i] = '0';
    }
    for (int i = 1; i < size + 1; ++i) {
        b_string[i] = '0';
    }

    BigInteger a = a_string;
    std::cout << a.sqrt() << '\n' <<  b_string;

    return 0;
}