#include "SimpleMatrixCalculations.h"


int main()
{
	SimpleMatrixCalculations calc;

	Matrix m1;
	m1.rows = 4;
	m1.columns = 4;

	Matrix m2;
	m2.rows = 4;
	m2.columns = 2;

	calc.constructMatrix(&m1);
	calc.constructMatrix(&m2);

	calc.fillMatrix(&m1);
	//calc.fillMatrix(&m2);

	//--------------------------------------------
	Matrix mulMatrix;
	calc.printMatrix(&m1);

	cout << calc.determinant(&m1) << endl;
	
	//--------------------------------------------

	calc.deconstructMatrix(&m1);
	calc.deconstructMatrix(&m2);
	//calc.deconstructMatrix(&mulMatrix);

	return 0;
}