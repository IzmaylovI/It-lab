#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

struct info {
    int size_of_matrix;
    int number_of_collapse = 1;
    int number_of_threads;
    double sequental_time;
    double par_time;
};

bool f1(info& first, info& second);

bool f2(info& first, info& second);

void tableMtrx(std::vector<info>& v);
std::vector<info> readm();
