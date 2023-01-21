#include <iostream>
#include "headers/f.hpp"

int main(int argc, char** argv) {
    std::vector<info> v = readm();
    tableMtrx(v);

    return 0;
}
