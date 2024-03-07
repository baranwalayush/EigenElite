#pragma once

#include "defines.h"

#include <utility>

#ifdef __clang__
using std::size_t;
#endif

#ifdef __GNUG__ 
#include <cstddef>
#endif

template <class T>
class Vector {
    private:
        T* m_Data;
        size_t m_Size;
        size_t m_BufferSize;
        /**
         * 
         * @param  size_t theNewBuffer : 
         */
        void IncreaseBuffer(size_t theNewBuffer);

    public:
        Vector();
        Vector(size_t theSize);
        Vector(const Vector&);
        Vector(Vector&&);
        ~Vector();
        
        /**
         * 
         */
        void Print();
        
        /**
         * 
         * @return size_t 
         */
        inline size_t GetSize() const {return m_Size;}
        /**
         * 
         * @param T 
         */
        void PushBack(const T&);
        /**
         * 
         * @param  T& 
         */
        void PushBack(T&&);
        /**
         * 
         */
        void Pop();
        /**
         * 
         * @return T 
         */
        T& Last();

        /**
         * 
         * @param  Args&... args  
         * @return T 
         */
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
        
        /**
         * 
         */
        void Clear();

        T& operator[](size_t);
        const T& operator[](size_t) const;

        Vector<T>& operator=(const Vector&);
        Vector<T>& operator=(Vector&&);

        bool operator==(const Vector&);
};
