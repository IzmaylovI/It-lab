#include <iostream>
#include "Structer.hpp"
#include "data_render.hpp"
#include "Imaging.hpp"
#include "function.hpp"

int main(){
    /*
    Image a(10,10);
    std::cout << a << std::endl;
    data_render::get_random_image(a,10,10);
    std::cout << a << std::endl;
    */

    Mtrx<float> a(5,5);
    Mtrx<float> b(5,5);
    Mtrx<float> c(5,5,0);

    data_render::get_random(a,25,6);
    data_render::get_random(b,25,5);
    //std::cout << c << std::endl;

    //std::cout << a << std::endl;
    //std::cout << b << std::endl;

    multiplication_neon_float_4x4<float>(a.get_ptr(),b.get_ptr(),c.get_ptr(), 5, 5, 5);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return 0;
}
