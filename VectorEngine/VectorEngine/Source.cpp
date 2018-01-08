#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"


int main()
{
	SimpleMatrixCalculations calc;
	matrixReff rref(true);

	Matrix A;
	A.rows = 4;
	A.columns = 2;

	Matrix B;
	B.rows = 2;
	B.columns = 2;

	Matrix C;
	C.rows = 2;
	C.columns = 2;


	calc.constructMatrix(&A);
	calc.constructMatrix(&B);
	calc.constructMatrix(&C);

	calc.fillMatrix(&A);
	//calc.fillMatrix(&B);
	//calc.fillMatrix(&C);


	//--------------------------------------------
	calc.printMatrix(&rref.echelonReduction(&A));
	int *rows = rref.pivotRows();
	int *columns = rref.pivotColumns();

	rref.printPivotRows(&A);
	rref.printPivotColumns(&A);

	//--------------------------------------------

	calc.deconstructMatrix(&A);
	calc.deconstructMatrix(&B);
	calc.deconstructMatrix(&C);
	//calc.deconstructMatrix(&mulMatrix);
	return 0;
}