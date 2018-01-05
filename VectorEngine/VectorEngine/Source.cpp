#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"


int main()
{
	SimpleMatrixCalculations calc;
	matrixReff rref;

	Matrix m1;
	m1.rows = 3;
	m1.columns = 3;


	calc.constructMatrix(&m1);

	calc.fillMatrix(&m1);
	//calc.fillMatrix(&m2);

	//--------------------------------------------
	calc.printMatrix(&rref.echelonReduction(&m1));
	
	
	//--------------------------------------------

	calc.deconstructMatrix(&m1);
	//calc.deconstructMatrix(&mulMatrix);
	return 0;
}