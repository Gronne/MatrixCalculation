#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"


int main()
{
	SimpleMatrixCalculations calc;
	matrixReff rref;

	Matrix m1;
	m1.rows = 3;
	m1.columns = 3;

	Matrix m2;
	m2.rows = 4;
	m2.columns = 2;

	calc.constructMatrix(&m1);
	calc.constructMatrix(&m2);

	calc.fillMatrix(&m1);
	//calc.fillMatrix(&m2);

	//--------------------------------------------
	calc.printMatrix(&rref.echelonReduction(&m1));
	
	
	//--------------------------------------------

	calc.deconstructMatrix(&m1);
	calc.deconstructMatrix(&m2);
	//calc.deconstructMatrix(&mulMatrix);

	return 0;
}