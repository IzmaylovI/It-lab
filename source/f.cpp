#include "headers/f.hpp"

bool f2(info& first, info& second) {
    bool f = false;
    if (first.size_of_matrix < second.size_of_matrix) {
        f = true;
    }
    else if (first.size_of_matrix == second.size_of_matrix && first.number_of_threads < second.number_of_threads) {
        f = true;
    }
    else if (first.size_of_matrix == second.size_of_matrix && first.number_of_threads == second.number_of_threads && first.number_of_collapse < second.number_of_collapse) {
        f = true;
    }

    return f;
}

std::vector<info_v> readv()
{
    std::vector<info_v> v(20);
    std::string s;

    std::ifstream in("vector_addition.txt");

    int i = 0;
    int j = 0;
    std::vector<std::pair<double, double>> sr_time(5, { 0,0 });

    char c;
    int size_of_vector;
    int number_of_threads;
    int launch_number;
    double seq_time;
    double par_time;
    system("vector_addition.txt");

    while (getline(in, s)) {
        in >> c;
        // std::istringstream iss(s);
        //c = s[0];
        if (c == 'N')
        {
            std::string f, s, t;
            in >> f >> s >> t >> number_of_threads;
        }
        else if (c == 'L')
        {
            std::string f, s, t;
            in >> f >> s >> launch_number;
        }
        else if (c == 't')
        {
            in >> seq_time >> par_time;

            sr_time[j].first = seq_time;
            sr_time[j].second = par_time;

            j++;

            if (j == 5)
            {
                double sr_seq_time = 0;
                double sr_par_time = 0;

                for (int k = 0; k < 5; k++)
                {
                    sr_seq_time += sr_time[i].first;
                    sr_par_time += sr_time[i].second;
                }

                v[i].number_of_threads = number_of_threads;
                v[i].size_of_vector = 100000000;
                v[i].sequental_time = sr_seq_time / 5;
                v[i].par_time = sr_par_time / 5;

                i++;
                j = 0;

            }
        }
    }
    return v;
}

void tableVctr(std::vector<info_v>& v) {
    std::ofstream myfile("vector.csv");

    if (myfile.is_open())
    {
        myfile << ",,number_of_threads, sequintal_time, parallel_time, boost" << std::endl;

        for (int i = 0; i < 5; i++)
        {
            double boost = v[i].sequental_time / v[i].par_time;
            myfile << ",," << v[i].number_of_threads << "," << v[i].sequental_time << "," << v[i].par_time << "," << boost << std::endl;
        }
    }
    else {
        throw (myfile, "File could not be opened");
    }
}

void tableMtrx(std::vector<info>& v) {
    std::ofstream myfile("example.csv");

    for (int i = 0; i < 9; i++) {
        myfile << ",,,,,,size of matrix" << v[i * 60].size_of_matrix << "x" << v[i * 60].size_of_matrix << std::endl;
        myfile << ",,number_of_collapse=1,,,,number_of_collapse=2,,,,,number_of_collapse=3" << std::endl;
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
    //std::vector<info> v(301);
    std::vector<info> v(541);
    std::ifstream in("matrix_multiplication.txt");
    std::string s;
    int i = 0;
    int j = 0;
    std::vector<std::pair<double, double>> sr_time(5, { 0,0 });
    char c;
    int number_of_collapse = 1;
    int size_of_matrix = 550;
    int number_of_threads;
    int launch_number;
    double seq_time;
    double par_time;

    while (getline(in, s)) {
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
        if (c == 'C') {
            std::string f;
            in >> number_of_collapse;
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

        if (c == 'q') {
            number_of_collapse++; v[i].number_of_collapse = number_of_collapse;
        }
    }
    //std::sort(v.begin(), v.begin() + 300, f2);
    std::sort(v.begin(), v.begin() + 540, f2);
    in.close();
    return v;
}