//                     _   
//   ___ _ __ __ _ ___| |_ 
//  / __| '__/ _` / __| __|
//  \__ \ | | (_| \__ \ |_ 
//  |___/_|  \__,_|___/\__|
//  (c) Lucas Alvarenga
//      (lukeathedev)

#pragma once

#include <utils/types.hpp>

#include <fstream>
#include <vector>
#include <cstdint>
#include <string>

using namespace types;

namespace bitmap
{
    class file
    {
      private:
        #pragma pack(push, 1) // Avoids compiler padding;

        typedef struct _bmp_header
        {
            uint16_t file_type   { 0x4D42 };
            uint32_t file_size   { 0 };
            uint16_t reserved1   { 0 };
            uint16_t reserved2   { 0 };
            uint32_t data_offset { 0 };
        } BMP_HEADER;

        typedef struct _img_header
        {
            uint32_t header_size  { 0 };
            uint32_t image_width  { 0 };
            uint32_t image_height { 0 };
            uint16_t planes       { 1 };
            uint16_t bit_depth    { 0 };
            uint32_t compression  { 0 };
            uint32_t image_size   { 0 }; // Leave at 0 if uncompressed;
            uint32_t x_px_per_m   { 0 };
            uint32_t y_px_per_m   { 0 };
            uint32_t colors_used  { 0 };
            uint32_t colors_sigf  { 0 };
        } IMG_HEADER;

        #pragma pack(pop)

      public:
        BMP_HEADER bmp_header;
        IMG_HEADER img_header;
        std::vector<vec3<float>> img_data;

        file(int width, int height, int bit_depth)
        {
            bmp_header.file_size = width * height * (bit_depth / 8);
            bmp_header.file_size += sizeof(bmp_header) + sizeof(img_header);

            img_header.image_width  = width;
            img_header.image_height = height;
            img_header.bit_depth    = bit_depth;
            img_header.header_size  = sizeof(img_header);
        }

        void write(std::string filename)
        {
            std::ofstream image { filename, std::ios::binary };

            image.write((char *)&bmp_header, sizeof(bmp_header));
            image.write((char *)&img_header, sizeof(img_header));

            for (unsigned int j = 0; j < img_header.image_height; ++j)
            {
                for (unsigned int i = 0; i < img_header.image_width; ++i)
                {
                    // Since values are between 0 and 1, and each color takes
                    // up a byte, we can just multiply it by 255 (0xFF).
                    int color0 = img_data[i + j * img_header.image_width][0] * 0xFF;
                    int color1 = img_data[i + j * img_header.image_width][1] * 0xFF;
                    int color2 = img_data[i + j * img_header.image_width][2] * 0xFF;
                    //int color = img_data[0][0];
                    image.write((char *)&color0, 1);
                    image.write((char *)&color1, 1);
                    image.write((char *)&color2, 1);
                }
            }

            return;
        }
    };
} // namespace bitmap
