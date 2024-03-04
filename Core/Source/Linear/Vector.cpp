#include "Linear/Vector.h"
#include "defines.h"

#include <cstdlib>
#include <cwchar>
#include <iostream>

#define ASSERT_VECTOR_SIZE(a, b) \
    a.m_Size == b.m_Size ? true : false

template <class T>
Vector<T>::Vector() {
    m_Size = 3;
    m_Data = new T(m_Size);
}

template <class T>
Vector<T>::Vector(u32 theSize) {
    m_Size = theSize;
    m_Data = new T(m_Size);
}

template<class T>
Vector<T>::~Vector()
{
    delete[] m_Data;
}

template <class T>
void Vector<T>::Print() {
    for (int i = 0; i < this->m_Size; i++) {
        std::cout << this->m_Data[i] << " ";
    }
    std::cout << "\n";
}

template <class T>
T Vector<T>::operator[](int theIndex) {
    return this->m_Data[theIndex];
}

template <class T>
Vector<T> Vector<T>::operator+(Vector<T> theVector) {
    if (this->m_Size != theVector.m_Size) {
        // error handling
        std::cerr << "Operating vectors of different sizes\n";
    }

    Vector<T> newVector(this->m_Size);
    for (int i = 0; i < this->m_Size; i++) {
        newVector.m_Data[i] = theVector.m_Data[i] + this->m_Data[i];
    }
    return newVector;
}

template <class T>
Vector<T> Vector<T>::operator=(Vector<T> theVector) {
    this->m_Data = theVector.m_Data;
    this->m_Size = theVector.m_Size;
    return *this;
}

template <class T>
bool Vector<T>::operator==(Vector<T> theVector) {
    if (this->m_Size != theVector.m_Size) {
        std::cerr << "Operating vectors of different sizes\n";
        return false;
    }
    bool equal = true;
    for (int i = 0; i < m_Size; i++) {
        if (this->m_Data[i] != theVector[i]) {
            equal = false;
        }
    }
    return equal;
}

template <class T>
void Vector<T>::operator=(T* theData) {
    for (int i = 0; i < m_Size; i++) {
        this->m_Data[i] = theData[i];
    }
}

template <class T>
T Vector<T>::Dot(Vector<T> theVector) {
    if (this->m_Size != theVector.m_Size) {
        std::cerr << "Operating vectors of different sizes\n";
    }
    T sum = 0;
    for (int i = 0; i < this->m_Size; i++) {
        sum += this->m_Data[i]*theVector.m_Data[i];
    }
    return sum;
}

template <class T>
f32 Vector<T>::Magnitude() {
    f32 sum;
    for (int i = 0; i < this->m_Size; i++) {
        sum += this->m_Data[i] * this->m_Data[i];
    }
    // TODO: should return sqrt
    return sum;
}

template class Vector<u32>;
template class Vector<i32>;
template class Vector<f32>;
