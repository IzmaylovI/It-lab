#include "function.h"
bool correctness_test_addition(const int& n) {
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


double time_of_p_addition(const int& n, int a) {
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

double time_of_s_addition(const int& n) {
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

bool correctness_test_multiplication(int n, int a) {
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

#pragma omp parallel for collapse(a)
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

double time_of_s_multiplication(const int& n) {
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

double time_of_p_multiplication(const int& n, const int& a) {
    double itime, ftime, exec_time;
    std::vector<int> mtrx1(n * n);
    std::vector<int> mtrx2(n * n);
    std::vector<int> answer(n * n, 0);

    for (int i = 0; i < n * n; i++) {
        mtrx1[i] = 2 + rand() % 10000;
        mtrx2[i] = 4 + rand() % 10000;
    }

    itime = omp_get_wtime();
#pragma omp parallel for collapse(a)
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