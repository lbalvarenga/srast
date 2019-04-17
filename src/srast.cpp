//                     _   
//   ___ _ __ __ _ ___| |_ 
//  / __| '__/ _` / __| __|
//  \__ \ | | (_| \__ \ |_ 
//  |___/_|  \__,_|___/\__|
//  (c) Lucas Alvarenga    
//      (lukeathedev)      

#include <image/bitmap.hpp>

#include <utils/types.hpp>
using namespace types;

#include <srast/geometry.hpp>
#include <utils/colors.hpp>

#include <iostream>
#include <vector>

#include <chrono>
using namespace std::chrono;

#define p(x, y) { x, y }

int main()
{
    auto start_time = high_resolution_clock::now();

    geometry::canvas c(200, 200);
    c.line(p(100, 100), p(20, 50));
    c.line(p(200, 100), p(20, 50));
    c.line(p(30, 10), p(300, 130));

    bitmap::file bmp_file(c.width, c.height, 24);
    bmp_file.data = c.image;
    bmp_file.write("test.bmp");

    auto end_time = high_resolution_clock::now();
    auto exec_time = duration_cast<nanoseconds>(end_time - start_time).count();

    std::cout << "Rendered to 'test.bmp' in " << (double)exec_time / 1000000000 << "s" << std::endl;

    return 0;
}