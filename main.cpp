#include <iostream>
#include <omp.h>
#include "headers/function.hpp"
#include <string>
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv) {
    //test_of_addition();
    //std::cout << argc << std::endl;

    if (strcmp(argv[1], "a") == 0) {
        //std::cout << "hello" << std::endl;
    }
    else  if (strcmp(argv[1], "m") == 0) {

        //std::cout << "Hi" << std::endl;
        test_of_multiplication();
    }
    else if (strcmp(argv[1], "ta") == 0) {
        std::cout << time_of_p_addition(100000000);
    }
    else {
        std::cout << time_of_p_multiplication(1000);
    }

    return 0;
}