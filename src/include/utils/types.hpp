//                     _   
//   ___ _ __ __ _ ___| |_ 
//  / __| '__/ _` / __| __|
//  \__ \ | | (_| \__ \ |_ 
//  |___/_|  \__,_|___/\__|
//  (c) Lucas Alvarenga    
//      (lukeathedev)      

#pragma once

#include <cstddef> // For NULL definition

namespace types
{
    template <typename T>
    class vec3 // TODO: Make it variadic
    {
      public:
        T x, y, z;

        vec3()
        {
            this->x = (T)NULL;
            this->y = (T)NULL;
            this->z = (T)NULL;
        }

        vec3(T x, T y, T z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        T &operator [](int i)
        {
            switch(i)
            {
                case 0:  return this->x;
                case 1:  return this->y;
                case 2:  return this->z;
                default: throw;
            }
        }
    };

    template <typename T>
    class vec2
    {
      public:
        T x, y;

        vec2()
        {
            this->x = (T)NULL;
            this->y = (T)NULL;
        }

        vec2(T x, T y)
        {
            this->x = x;
            this->y = y;
        }

        T &operator [](int i)
        {
            switch(i)
            {
                case 0:  return this->x;
                case 1:  return this->y;
                default: throw;
            }
        }
    };
} // namespace types
