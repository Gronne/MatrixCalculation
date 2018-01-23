#include "ComplexMatrixCalculations.h"



ComplexMatrixCalculations::ComplexMatrixCalculations(bool intermediateCalculation) :
	calc(intermediateCalculation),
	rref(intermediateCalculation),
	type(intermediateCalculation)
{
	//Init intermiate calculations through out the code
	(intermediateCalculation == 0 || intermediateCalculation == 1) ? _intermediateCalculation = intermediateCalculation : _intermediateCalculation = 0;

	//Construct a 1x1 matrix
	resultMatrix.columns = 1;
	resultMatrix.rows = 1;
	calc.constructMatrix(&resultMatrix);

	//Construct a base result
	results.freeVariable = 0;
	results.size = 0;
	calc.constructMatrixResult(&results);

}


ComplexMatrixCalculations::~ComplexMatrixCalculations()
{
	//Deconstruc objects constructed in the constructor
	calc.deconstructMatrix(&resultMatrix);
	calc.deconstructMatrixResult(&results);
}


Matrix * ComplexMatrixCalculations::gramSchmidtProcess(Matrix *)
{


	return nullptr;
}


double ComplexMatrixCalculations::orthogonalProjection(Matrix *, Matrix *)
{


	return 0.0;
}


Matrix * ComplexMatrixCalculations::leastSquare(Matrix *, Matrix *)
{


	return nullptr;
}


Matrix * ComplexMatrixCalculations::SVD(Matrix *)
{


	return nullptr;
}


double ComplexMatrixCalculations::QRfactorization(Matrix *)
{


	return 0.0;
}


Matrix * ComplexMatrixCalculations::eigenvector(Matrix *)
{


	return nullptr;
}


double * ComplexMatrixCalculations::eigenValues(Matrix *)
{


	return nullptr;
}

