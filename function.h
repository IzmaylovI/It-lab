#pragma once
#include <vector>
#include <omp.h>

bool correctness_test_addition(const int& n);                        // function to check the correctness of vector addition
double time_of_p_addition(const int& n, int a = 4);                  // counting the execution time of parallel addition of vectors
double time_of_s_addition(const int& n);                             // counting the execution time of sequential addition of vectors

bool correctness_test_multiplication(int n, int a = 3);              // function to check the correctness of matrix multiplication  
double time_of_s_multiplication(const int& n);                       // counting the execution time of parallel matrix multiplication
double time_of_p_multiplication(const int& n, const int& a = 3);     // counting the execution time of parallel matrix multiplication