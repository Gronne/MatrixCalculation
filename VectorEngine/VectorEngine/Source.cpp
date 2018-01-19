#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"
#include "MatrixType.h"


int main()
{
	SimpleMatrixCalculations calc(false);
	matrixReff rref(false);
	MatrixType type(false);

	Matrix A;
	A.rows = 3;
	A.columns = 1;

	Matrix B;
	B.rows = 3;
	B.columns = 1;

	Matrix C;
	C.rows = 3;
	C.columns = 3;


	calc.constructMatrix(&A);
	calc.constructMatrix(&B);
	calc.constructMatrix(&C);

	calc.fillMatrix(&A);
	calc.fillMatrix(&B);
	//calc.fillMatrix(&C);


	//--------------------------------------------
	cout << type.dot(&A, &B) << endl;
	//--------------------------------------------

	calc.deconstructMatrix(&A);
	calc.deconstructMatrix(&B);
	calc.deconstructMatrix(&C);
	//calc.deconstructMatrix(&mulMatrix);
	return 0;
}