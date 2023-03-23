#include <iostream>
#include "Structer.hpp"
#include "data_render.hpp"
#include "Imaging.hpp"
#include "Function.hpp"

int main(){
    Image a(10,10);
    std::cout << a << std::endl;
    data_render::get_random_image(a,10,10);
    std::cout << a << std::endl;
    return 0;
}