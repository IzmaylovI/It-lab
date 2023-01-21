#include <iostream>
#include <omp.h>
#include "function.hpp"

int main(){
    //test_of_addition();
    //test_of_multiplication();

    test_of_neon_multiplication(); 

    return 0;
}