#pragma once
#include "defines.h"

template<typename T>
class Matrix
{
public:
	class DoubleSubscript
	{
	private:
		size_t m_i;
		Array2d<T>& m_array2d;

	public:
		DoubleSubscript(size_t _i, Array2d<T>& _array2d)
			: m_i(_i), m_array2d(_array2d) {}

		T& operator[](size_t _j)
		{
			return m_array2d.m_array[_j + m_i * m_array2d.m_Y];
		}
	};

	Matrix() = delete;
	Matrix(size_t theX, size_t theY);
	Matrix(Matrix& theMatrix);
	Matrix(Matrix&& theMatrix);
	~Matrix();

	DoubleSubscript operator[](size_t _i)
	{
		DoubleSubscript second_subscript(_i, *this);
		return second_subscript;
	}

	void Print();
	void GetRow(int theRow);
	void GetColumn(int theColumn);
	void Transpose();
	i64 Trace();
	Matrix& Inverse();
	int Rank();

	inline T At(size_t theX, size_t theY) const;

private:
	T* m_Data;
	size_t m_Size;
	size_t m_X, m_Y;
};
/*
member data
- dataType\[row][column]

member function
- operator+(Matrix)
-operator-(Matrix)
-operator\ * (Matrix)
-operator\ * (int)
-operator=(Matrix)
-operator==(Matrix)
-operator\[]\[](int, int)
- norm
- eigenValues
- vector_product(Vector)
*/

