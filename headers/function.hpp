#pragma once
#include <iostream> 
#include <fstream>
#include <vector>
#include <omp.h>

bool correctness_test_addition(int n);                                          // function to check the correctness of vector addition
double time_of_p_addition(int n, int a = 4);                                    // counting the execution time of parallel addition of vectors
double time_of_s_addition(int n);                                               // counting the execution time of sequential addition of vectors
void test_of_addition();

bool correctness_test_multiplication(int n);                                // function to check the correctness of matrix multiplication  
double time_of_s_multiplication(int n);                                         // counting the execution time of parallel matrix multiplication
double time_of_p_multiplication(int n, int b = 1);     // counting the execution time of parallel matrix multiplication
void test_of_multiplication();