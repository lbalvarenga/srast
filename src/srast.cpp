//                     _   
//   ___ _ __ __ _ ___| |_ 
//  / __| '__/ _` / __| __|
//  \__ \ | | (_| \__ \ |_ 
//  |___/_|  \__,_|___/\__|
//  (c) Lucas Alvarenga
//      (lukeathedev)

#include <image/bitmap.hpp>
#include <srast/types.hpp>

#include <iostream>

int main()
{
    bitmap::file bmp(400, 300, 24);
    bmp.write("test.bmp");

    return 0;
}