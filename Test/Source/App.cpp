#include "Linear/Core.h"
#include "Linear/Matrix.h"

int main()
{
	Matrix<int> mat1(2, 3);
	mat1[0][0] = 1;
	mat1[0][1] = 2;
	mat1[0][2] = 3;
	mat1[1][0] = 4;
	mat1[1][1] = 5;
	mat1[1][2] = 6;

	mat1.Print();

	auto mat2 = mat1.Transpose();
	mat2.Print();
}