#include "headers/function.hpp"

bool correctness_test_addition(int n) {
    srand(11);
    std::vector<int> v(n);
    std::vector<int> w(n);
    std::vector<int> ans1(n);
    std::vector<int> ans2(n);

    for (int i = 0; i < n; i++) {
        v[i] = rand() % 1000 + 2;
        w[i] = rand() % 999 + 45;
    }

    for (int i = 0; i < n; i++) {
        ans1[i] = v[i] + w[i];
    }

#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        ans2[i] = v[i] + w[i];
    }
    bool f = true;
    for (int i = 0; i < n; i++) {
        if (ans1[i] != ans2[i]) {
            f = false;
            break;
        }
    }
    return f;
}


double time_of_p_addition(int n, int a) {
    double itime, ftime, exec_time;
    srand(11);

    std::vector<int> v(n);
    std::vector<int> w(n);
    std::vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        v[i] = rand() % 1000 + 2;
        w[i] = rand() % 999 + 45;
    }

    itime = omp_get_wtime();
    omp_set_num_threads(a);
#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        ans[i] = v[i] + w[i];
    }

    ftime = omp_get_wtime();

    exec_time = ftime - itime;

    return exec_time;
}

double time_of_s_addition(int n) {
    double itime, ftime, exec_time;
    srand(11);

    std::vector<int> v(n);
    std::vector<int> w(n);
    std::vector<int> ans1(n);


    for (int i = 0; i < n; i++) {
        v[i] = rand() % 1000 + 2;
        w[i] = rand() % 999 + 45;
    }

    itime = omp_get_wtime();

    for (int i = 0; i < n; i++) {
        ans1[i] = v[i] + w[i];
    }

    ftime = omp_get_wtime();
    exec_time = ftime - itime;

    return exec_time;
}

void test_of_addition() {
    int n;
    //std::cin >> n;
    n = 100000000;
    
    std::cout << "size of vector: " << n << '\n';

    std::ifstream in("vector_vsp.txt");
    int a;
    int b;
    in >> a >> b;
    b++;

    if (a != 20 || b != 6) {
        std::ofstream ofs;
        ofs.open("vector_addition.txt", std::ios_base::app);
        if (b == 6) {
            a++;
            b = 1;
            ofs << "Number of threads: " << a << std::endl;
        }
        else {
            b++;
        }
        if (ofs.is_open()) {
            ofs << "Launch number: " << b << std::endl;

            for (int i = 0; i < 3; i++) {
                double s = time_of_s_addition(n);
                double p = time_of_p_addition(n, a);

                ofs << s << std::endl;
                ofs << p << "\n\n";

            }
        }
        else {
            throw (ofs, "File could not be opened");
        }

        std::ofstream out("vector_vsp.txt");
        out << a << ' ' << b;
    }
}

bool correctness_test_multiplication(int n) {
    std::vector<int> mtrx1(n * n);
    std::vector<int> mtrx2(n * n);
    std::vector<int> answer1(n * n, 0);
    std::vector<int> answer2(n * n, 0);

    for (int i = 0; i < n * n; i++) {
        mtrx1[i] = 2 + rand() % 10000;
        mtrx2[i] = 4 + rand() % 10000;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                answer1[i * n + j] += mtrx1[i * n + k] * mtrx2[k * n + j];
            }
        }
    }

#pragma omp parallel for collapse(3)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                answer2[i * n + j] += mtrx1[i * n + k] * mtrx2[k * n + j];
            }
        }
    }

    bool f = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (answer1[i * n + j] != answer2[i * n + j]) {
                f = false;
                break;
            }
        }
    }
    return f;
}

double time_of_s_multiplication(int n) {
    double itime, ftime, exec_time;
    std::vector<int> mtrx1(n * n);
    std::vector<int> mtrx2(n * n);
    std::vector<int> answer(n * n, 0);

    for (int i = 0; i < n * n; i++) {
        mtrx1[i] = 2 + rand() % 10000;
        mtrx2[i] = 4 + rand() % 10000;
    }

    itime = omp_get_wtime();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                answer[i * n + j] += mtrx1[i * n + k] * mtrx2[k * n + j];
            }
        }
    }
    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    return exec_time;
}

double time_of_p_multiplication(int n, int b) {
    double itime, ftime, exec_time;
    std::vector<int> mtrx1(n * n);
    std::vector<int> mtrx2(n * n);
    std::vector<int> answer(n * n, 0);

    for (int i = 0; i < n * n; i++) {
        mtrx1[i] = 2 + rand() % 10000;
        mtrx2[i] = 4 + rand() % 10000;
    }
    

    itime = omp_get_wtime();
    omp_set_num_threads(b);
#pragma omp parallel for collapse(3)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                answer[i * n + j] += mtrx1[i * n + k] * mtrx2[k * n + j];
            }
        }
    }

    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    return exec_time;
}

void test_of_multiplication() {
    std::ifstream in("matrix_vsp.txt");

    int size, count_of_threads, number_of_launch;

    in >> size >> count_of_threads >> number_of_launch;
    number_of_launch++;
    if (in.is_open()) {
        

        if (size != 700 ||  count_of_threads != 20 || number_of_launch != 6) {
            std::ofstream ofs;
            ofs.open("matrix_multiplication.txt", std::ios_base::app);
            if (ofs.is_open()) {
                if (number_of_launch == 6) {
                    number_of_launch = 1;
                    count_of_threads++;

                }
                if (count_of_threads == 21) {
                    count_of_threads = 1;
                    size += 100;
                    if(count_of_threads == 1 && number_of_launch == 1){
                        ofs << "--------------------" << std::endl;
                    }
                    ofs << "Size of matrix: " << size << 'x' << size << std::endl;
                }
                if (number_of_launch == 1) {
                    ofs << "Number of threads: " << count_of_threads << std::endl;
                }
               
                ofs << "Launch number " << number_of_launch << std::endl;
                double time_s = time_of_s_multiplication(size);
                double time_p = time_of_p_multiplication(size, count_of_threads);
                ofs << "time of sequental mult.: " << time_s << std::endl;
                ofs << "time of parallel mult.:  " << time_p << std::endl;
                ofs << "\n";

                std::ofstream out("matrix_vsp.txt");
                out << size << ' ' << count_of_threads << ' ' << number_of_launch;
            }
            else {
                throw(ofs, "File could not be opened");
            }
        }
    }
    else {
        throw (in, "File could not be opened");
    }
}