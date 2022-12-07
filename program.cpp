#include <iostream>

int main() {
    int a;

    std::cout << "1. test_addition_vector" << std::endl;
    std::cout << "2. test_multiplication_matrix" << std::endl;
    std::cout << "3. time of addition vector if size 1e8" << std::endl;
    std::cout << "4. time of multiplication matrix size 800x800" << std::endl;

    std::cin >> a;

    switch (a) {
    case 1:
        for (int i = 0; i < 100; i++) {
            std::cout << "Launch " << i << std::endl;
            system("it-lab_first_task.exe a");
        }
        break;
    case 2:
        for (int i = 0; i < 900; i++) {
            std::cout << "Launcher " << i << std::endl;
            system("it-lab_first_task.exe m");
        }
        break;
    case 3:
        system("it-lab_first_task.exe ta");
        break;
    case 4:
        system("it-lab_first_task.exe tm");
        break;
    }

    system("pause");
    return 0;
}