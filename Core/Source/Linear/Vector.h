#pragma once

#include "defines.h"

#include <utility>

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

        inline size_t GetSize() const {return m_Size;}

        void PushBack(const T&);
        void PushBack(T&&);
        void Pop();
        T& Last();

        template<typename... Args>
        T& EmplaceBack(Args&&... args)
        {
            if (m_Size >= m_BufferSize)
            {
                if (m_BufferSize == 0)
                    m_BufferSize = 2;
                IncreaseBuffer(m_BufferSize + (m_BufferSize >> 1));
            }
            new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
            return m_Data[m_Size++];
        }

        void Clear();

        T& operator[](size_t);
        const T& operator[](size_t) const;

        Vector<T>& operator=(const Vector&);
        Vector<T>& operator=(Vector&&);

        bool operator==(const Vector&);
};
