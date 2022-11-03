#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <omp.h>
#include <chrono>
#include "function.h"

int main()
{
    int n, m;
    std::cin >> n;
    double s = time_of_s_addition(n);
    double p = time_of_p_addition(n,5);

    std::cout << s << ' ' << p << ' ' << s - p;
    
    return 0;
}
