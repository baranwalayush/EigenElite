#include "Matrix.h"


template<typename T>
inline Matrix<T>::Matrix(size_t theX, size_t theY)
	: m_X(theX), m_Y(theY)
{
	m_Size = m_X * m_Y;
	m_Data = new T[m_Size];
}

template<typename T>
Matrix<T>::Matrix(Matrix& theMatrix)
{

}

template<typename T>
Matrix<T>::Matrix(Matrix&& theMatrix)
{
}

template<typename T>
Matrix<T>::~Matrix()
{
	delete[] m_Data;
}

template<typename T>
void Matrix<T>::Print()
{
}

template<typename T>
void Matrix<T>::GetRow(int theRow)
{
}

template<typename T>
void Matrix<T>::GetColumn(int theColumn)
{
}

template<typename T>
void Matrix<T>::Transpose()
{
}

template<typename T>
inline T Matrix<T>::At(size_t theX, size_t theY) const
{
	
	return m_Data[theX * m_Y + theY];
}
