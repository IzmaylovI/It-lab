#include <iostream>
#include "Structer.hpp"
#include "data_render.hpp"
#include "Function.hpp"
#include "Color.hpp"
int main(){
    Image<bgr> a(10, 10, Color<bgr>(123,17,45));
    Image<rgb> b(10,10, Color<rgb>(45,67,78, -1));
    
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    unsigned char* l = a.getMemory(2,8);
    unsigned char* k = b.getMemory(9,29);
    return 0;
}