#include <iostream>
#include "Structer.hpp"
#include "data_render.hpp"
#include "Function.hpp"
#include "Color.hpp"
int main(){
    Image<rgb> a(10,10,Color<rgb>(4,5,6));
    std::cout << a << std::endl;
    return 0;
}