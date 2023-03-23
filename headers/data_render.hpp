#ifndef _DATA_RENDER_
#define _DATA_RENDER_

#include <random>
#include <ctime>

namespace data_render {
    template <typename T>
    void get_random(T& source, int size, int mmax = 256) {
        srand(time(0));

        for (int i = 0; i < size; ++i)
            source[i] = (unsigned char)(rand() % mmax);
    }

    template<typename T>
    void get_random_image(T& source, int height, int width) {
        srand(time(0));

        for(int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j) {
                source[i*width + j].R() = (rand() + 10) % 256;
                source[i*width + j].G() = (rand() + 90) % 256;
                source[i*width + j].B() = (rand() + 4) % 256;
            }
    }
}

#endif