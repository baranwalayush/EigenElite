#pragma once

#include "defines.h"

#ifdef __clang__
using std::size_t;
#endif

template <class T>
class Vector {
    private:
        T* m_Data;
        size_t m_Size;
        size_t m_BufferSize;

        void IncreaseBuffer(size_t theNewBuffer);

    public:
        Vector<T>();
        Vector(size_t theSize);
        Vector(const Vector&);
        Vector(Vector&&);
        ~Vector();

        void Print();

        inline size_t GetSize() const;

        void PushBack(const T&);
        void PushBack(T&&);
        void Pop();
        T& Last();

        template<typename... Args>
        T& EmplaceBack(Args... args);

        void Clear();
        //void EmplaceBack(Args... args);

        T& operator[](size_t);
        const T& operator[](size_t) const;

        Vector<T> operator+(const Vector&) const;
        Vector<T> operator-(Vector);

        Vector<T>& operator=(const Vector&);
        Vector<T>& operator=(Vector&&);

        bool operator==(Vector);
        //void operator=(T*);
        T Dot(Vector);
        Vector<T> Cross(Vector);
        f32 Magnitude();
};
