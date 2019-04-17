//                     _   
//   ___ _ __ __ _ ___| |_ 
//  / __| '__/ _` / __| __|
//  \__ \ | | (_| \__ \ |_ 
//  |___/_|  \__,_|___/\__|
//  (c) Lucas Alvarenga    
//      (lukeathedev)      

#pragma once

#include <utils/types.hpp>
using namespace types;

#include <utils/colors.hpp>

#include <vector>

namespace geometry
{
    class canvas
    {
      public:
        int width;
        int height;
        std::vector<vec3<int>> image;

        canvas(int width, int height, vec3<int> bg_color = COLOR_BLACK)
        {
            this->width = width;
            this->height = height;
            this->image = std::vector<vec3<int>>(width * height, bg_color);
        }

        void pixel(vec2<int> point, vec3<int> color)
        {
            image[point.x + point.y * width][0] = color[0];
            image[point.x + point.y * width][1] = color[1];
            image[point.x + point.y * width][2] = color[2];

            return;
        }

        // https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
        void line(vec2<int> p0, vec2<int> p1)
        {

            if (p0.x > p1.x) std::swap(p0.x, p1.x);
            if (p0.y > p1.y) std::swap(p0.y, p1.y);

            if (p1.x > width)  p1.x = width;
            if (p1.y > height) p1.y = height;

            int dx = p1.x - p0.x;
            int dy = p1.y - p0.y;
            int D  = 2 * dy - dx;
            int y = p0.y;

            for (int x = 0; x < p1.x; ++x)
            {
                pixel({ x, y }, COLOR_WHITE);
                if (D > 0)
                {
                    y += 1;
                    D -= 2 * dx;
                }
                D += 2 * dy;
            }

            return;
        }
    }; 
} // namespace geometry
