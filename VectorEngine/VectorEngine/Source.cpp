#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"


int main()
{
	SimpleMatrixCalculations calc;
	matrixReff rref(false);

	Matrix A;
	A.rows = 3;
	A.columns = 4;

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
	int pivot = rref.pivots();
	double *results = rref.result();

	cout << "Pivot: " << pivot << endl;
	
	for (size_t i = 0; i < pivot; i++)
		cout << (char)(65+i) << ": " << results[i] << endl;

	//--------------------------------------------

	calc.deconstructMatrix(&A);
	calc.deconstructMatrix(&B);
	calc.deconstructMatrix(&C);
	//calc.deconstructMatrix(&mulMatrix);
	return 0;
}