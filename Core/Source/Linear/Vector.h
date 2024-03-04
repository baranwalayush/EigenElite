#pragma once

#include "defines.h"

template <class T>
class Vector {
    private:
        T* m_Data;
        u32 m_Size;

    public:
        Vector<T>();
        Vector(u32 theSize);

        void Print();

        void Push(T);

        T operator[](int);
        Vector<T> operator+(Vector);
        Vector<T> operator-(Vector);
        Vector<T> operator=(Vector);
        bool operator==(Vector);
        void operator=(T*);
        T Dot(Vector);
        Vector<T> Cross(Vector);
        f32 Magnitude();
};
