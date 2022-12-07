#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

struct info_v {
    int size_of_vector;
    int number_of_threads;
    double sequental_time;
    double par_time;
};

struct info {
    int size_of_matrix;
    int number_of_collapse = 1;
    int number_of_threads;
    double sequental_time;
    double par_time;
};

//bool f1(info& first, info& second);

bool f2(info& first, info& second);

std::vector<info_v> readv();
void tableVctr(std::vector<info_v>& v);


void tableMtrx(std::vector<info>& v);
std::vector<info> readm();