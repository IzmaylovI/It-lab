#include <iostream>
#include "headers/f.hpp"

int main(int argc, char** argv) {
    int a;

    std::cout << "data render" << std::endl;
    std::cout << "1. vector addition" << std::endl;
    std::cout << "2. matrix multiplivation" << std::endl;

    std::cin >> a;

    switch (a) {
    case 1:
    {
        std::vector<info_v> v = readv();
        tableVctr(v);
        break;
    }
    case 2:
    {
        std::vector<info> v = readm();
        tableMtrx(v);
        break;
    }
    }



    return 0;
}



