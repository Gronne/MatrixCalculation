#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"


int main()
{
	SimpleMatrixCalculations calc(true);
	matrixReff rref(true);

	Matrix A;
	A.rows = 2;
	A.columns = 3;

	Matrix B;
	B.rows = 3;
	B.columns = 1;

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
	rref.echelonReduction(&A);
	rref.printResult(rref.result());

	//--------------------------------------------

	calc.deconstructMatrix(&A);
	calc.deconstructMatrix(&B);
	calc.deconstructMatrix(&C);
	//calc.deconstructMatrix(&mulMatrix);
	return 0;
}