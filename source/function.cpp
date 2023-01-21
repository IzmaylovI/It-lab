#include "function.hpp"

void filling_the_matrix_with_elements(float* A, int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            A[i*M + j] = (rand()%100000)/3;
        }
    }
}

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


double time_of_p_addition(int n,int a) {
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
#pragma omp parallel for collapse(1)
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

/*
void matrix_multiplication_neon(float32_t* A, float32_t* B, float32_t* C, int N, int M, int L){
    int A_indx;
    int B_indx;
    int C_indx;

    float32x4_t A0;
    float32x4_t A1;
    float32x4_t A2;
    float32x4_t A3;
    
    float32x4_t B0;
    float32x4_t B1;
    float32x4_t B2;
    float32x4_t B3;

    float32x4_t C0;
    float32x4_t C1;
    float32x4_t C2;
    float32x4_t C3;

    for(int i = 0; i < N; i+=4){
        for(int j = 0; j < L; j += 4){
            // zero accumulators before matrix op
            C0 = vmovq_n_f32(0);
            C1 = vmovq_n_f32(0);
            C2 = vmovq_n_f32(0);
            C3 = vmovq_n_f32(0);

            for(int k = 0; k < M; k+=4){
                // compute base index to 4x4 block in matrix B
                A_indx = i*M+k;
                B_indx = k*L+j;

                A0 = vld1q_f32(A + A_indx);
                A1 = vld1q_f32(A + A_indx + M);
                A2 = vld1q_f32(A + A_indx + 2*M);
                A3 = vld1q_f32(A + A_indx + 3*M);

                B0 = vld1q_f32(B + B_indx);
                B1 = vld1q_f32(B + B_indx + M);
                B2 = vld1q_f32(B + B_indx + 2*M);
                B3 = vld1q_f32(B + B_indx + 3*M);

                // multiply accumulate 4x4 blocks< i. e. each column C
                C0 = vfmaq_laneq_f32(C0, B0, A0, 0);
                C0 = vfmaq_laneq_f32(C0, B1, A0, 1);
                C0 = vfmaq_laneq_f32(C0, B2, A0, 2);
                C0 = vfmaq_laneq_f32(C0, B3, A0, 3);

                C1 = vfmaq_laneq_f32(C1, B0, A1, 0);
                C1 = vfmaq_laneq_f32(C1, B1, A1, 1);
                C1 = vfmaq_laneq_f32(C1, B2, A1, 2);
                C1 = vfmaq_laneq_f32(C1, B3, A1, 3);

                C2 = vfmaq_laneq_f32(C2, B0, A2, 0);
                C2 = vfmaq_laneq_f32(C2, B1, A2, 1);
                C2 = vfmaq_laneq_f32(C2, B2, A2, 2);
                C2 = vfmaq_laneq_f32(C2, B3, A2, 3);

                C3 = vfmaq_laneq_f32(C3, B0, A3, 0);
                C3 = vfmaq_laneq_f32(C3, B1, A3, 1);
                C3 = vfmaq_laneq_f32(C3, B2, A3, 2);
                C3 = vfmaq_laneq_f32(C3, B3, A3, 3);
            }
        C_indx = i*L + j;

        vst1q_f32(C + C_indx, C0);
        vst1q_f32(C + C_indx + L, C1);
        vst1q_f32(C + C_indx + 2*L, C2);
        vst1q_f32(C + C_indx + 3*L, C3);
        }
    }
}
*/

void test_of_neon_multiplication(){
    std::ifstream in("neon_vsp.txt");

    int launch;
    int N;
    int M;
    int L;
    double start_time;
    double end_time;

    if(in.is_open()){
        in >> launch >> N >> M >> L;
    }
    else{
        throw(in, "Neon_vsp could not be opened");
    }

    float* A = new float[N*M];
    float* B = new float[M*L];
    
    filling_the_matrix_with_elements(A, N, M);
    filling_the_matrix_with_elements(B, M, L);


    
    start_time = omp_get_wtime();
    end_time = omp_get_wtime();

    std::ofstream ofs;
    ofs.open("neon_multiplication.txt", std::ios_base::app);

    if(ofs.is_open()){
        if(launch == 0){
            ofs << "-------------------------";
            ofs << "Size of matrix: " << N << "x" << M << std::endl;
        }
        ofs << "Launch number: " << launch << std::endl;
        ofs << "Neon mutiply time: " << end_time - start_time << "\n\n";

        if(launch == 5){
            launch = 0;
            N += 100;
            M += 100;
            L += 100;
        }
        else{
            launch++;
        }

        std::ofstream out ("neon_vsp.txt");
        out << launch << ' ' << N << ' ' << M << ' ' << L;
    }
    else {
        throw(ofs, "File could not be opened");
    }
}