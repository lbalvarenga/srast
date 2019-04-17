//                     _
//   ___ _ __ __ _ ___| |_
//  / __| '__/ _` / __| __|
//  \__ \ | | (_| \__ \ |_
//  |___/_|  \__,_|___/\__|
//  (c) Lucas Alvarenga
//      (lukeathedev)

#include <image/bitmap.hpp>
#include <utils/types.hpp>

#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace types;

int main()
{
    auto start_time = high_resolution_clock::now();

    int width = 1920;
    int height = 1080;

    std::vector<vec3<float>> image(width * height);

    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            // Team red all the way
            // Remember that due to endianness, values are
            // actually BGR, not RGB.
            image[i + j * width][0] = 0.0f;
            image[i + j * width][1] = 0.0f;
            image[i + j * width][2] = 1.0f;
        }
    }

    bitmap::file bmp(width, height, 24);
    bmp.img_data = image;
    bmp.write("test.bmp");

    auto end_time = high_resolution_clock::now();
    auto exec_time = duration_cast<nanoseconds>(end_time - start_time).count();

    std::cout << "Completed in " << (double)exec_time / 1000000000 << "s" << std::endl;

    return 0;
}