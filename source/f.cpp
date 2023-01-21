#include "f.hpp"

bool f1(info& first, info& second) {
    bool f = true;
    if (first.size_of_matrix > second.size_of_matrix) {
        f = false;
    }
    else if (first.size_of_matrix == second.size_of_matrix && first.number_of_collapse > second.number_of_collapse) {
        f = false;
    }
    else if (first.size_of_matrix == second.size_of_matrix && first.number_of_collapse == second.number_of_collapse && first.number_of_threads > second.number_of_threads) {
        f = false;
    }
    return f;
}

bool f2(info& first, info& second) {
    bool f = true;
    if (first.size_of_matrix > second.size_of_matrix) {
        f = false;
    }
    else if (first.size_of_matrix == second.size_of_matrix && first.number_of_threads > second.number_of_threads) {
        f = false;
    }
    else if (first.size_of_matrix == second.size_of_matrix && first.number_of_threads == second.number_of_threads && first.number_of_collapse > second.number_of_collapse) {
        f = false;
    }

    return f;
}

void tableMtrx(std::vector<info>& v) {
    std::ofstream myfile("example.csv");
    for (int i = 0; i < 5; i++) {
        myfile << "                                                                                                                                                               size of matrix" << v[i * 60].size_of_matrix << "x" << v[i * 60].size_of_matrix << std::endl;
        myfile << ",,                                 number_of_collapse=1,,,                                               number_of_collapse=2,,,                                                 number_of_collapse=3" << std::endl;
        myfile << ",number_of_threads, sequiental_time, parallel_time, boost, number_of_threads, sequiental_time, parallel_time, boost, number_of_threads, sequiental_time, parallel_time, boost" << std::endl;
        for (int j = i * 60; j < i * 60 + 60; j += 3) {
            for (int k = j; k < j + 3; k++) {
                double bst = v[k].sequental_time / v[k].par_time;
                myfile << "," << v[k].number_of_threads << "," << v[k].sequental_time << "," << v[k].par_time << "," << bst;
            }
            myfile << std::endl;
        }
        myfile << "\n\n";
    }
}


std::vector<info> readm() {
    std::vector<info> v(301);
    std::ifstream in("matrix_multiplication.txt");
    std::string s;
    int i = 0;
    int j = 0;
    std::vector<std::pair<double, double>> sr_time(5, { 0,0 });
    char c;
    int number_of_collapse = 1;
    int size_of_matrix;
    int number_of_threads;
    int launch_number;
    double seq_time;
    double par_time;
    //getline(in, s);
    while (getline(in, s)) {
        //cout << i << j << endl;
        in >> c;
        if (c == 'S') {
            std::string f, s, t;
            in >> f >> s >> t >> size_of_matrix;
            v[i].size_of_matrix = size_of_matrix;
        }
        if (c == 'N') {
            std::string f, s, t;
            in >> f >> s >> t >> number_of_threads;
            v[i].number_of_threads = number_of_threads;
        }
        if (c == 'L') {
            std::string f, s;
            in >> f >> s >> launch_number;
        }
        if (c == 't') {
            std::string f, s, t, fo;
            in >> f >> s >> t >> fo;
            if (t == "sequental") {
                in >> seq_time;
                sr_time[j].first = seq_time;
            }
            else {
                in >> par_time;
                sr_time[j].second = par_time;
                j++;
                if (j == 5) {
                    double sr_seq_time = 0;
                    double sr_par_time = 0;
                    for (int k = 0; k < 5; k++) {
                        sr_seq_time += sr_time[k].first;
                        sr_par_time += sr_time[k].second;
                    }
                    v[i].sequental_time = sr_seq_time / 5;
                    v[i].par_time = sr_par_time / 5;
                    i++;
                    v[i].size_of_matrix = size_of_matrix;
                    v[i].number_of_collapse = number_of_collapse;
                    j = 0;
                }
            }
        }
        //cout << c << endl;
        if (c == 'q') {
            number_of_collapse++; v[i].number_of_collapse = number_of_collapse;
        }
    }
    std::sort(v.begin(), v.begin() + 300, f2);
    in.close();
    return v;
}