#include <iostream>
#include "Structer.hpp"
#include "data_render.hpp"
#include "Function.hpp"
#include "Color.hpp"
int main(){
   Image<bgr> a(10, 10, Color<bgr>(123,17,45));
    Image<bgr> b(a);
    std::cout << b << std::endl;;
    unsigned char* k = a.splitR();
    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < a.width; j++) {
            std::cout << (int)k[i * a.width + j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}