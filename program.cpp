#include <iostream>

int main(){
    for(int i = 0; i < 100; i++){
        std::cout << "Launch: " << i+1 << std::endl;
        system("it-lab_first_task.exe");
    }
    return 0;
}