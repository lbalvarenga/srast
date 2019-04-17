//                     _   
//   ___ _ __ __ _ ___| |_ 
//  / __| '__/ _` / __| __|
//  \__ \ | | (_| \__ \ |_ 
//  |___/_|  \__,_|___/\__|
//  (c) Lucas Alvarenga
//      (lukeathedev)

#pragma once

#include <cstddef> // For NULL definition

// Maybe I should template-ception this and
// have a single template that allows for
// multiple vector sizes.

namespace types
{
    template <typename T>
    class vec3
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
} // namespace types
