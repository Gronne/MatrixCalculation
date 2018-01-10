#include "MatrixType.h"



MatrixType::MatrixType(bool intermediateCalculation) : 
	calc(intermediateCalculation), 
	rref(intermediateCalculation)
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


MatrixType::~MatrixType()
{
	//Deconstruc objects constructed in the constructor
	calc.deconstructMatrix(&resultMatrix);
	calc.deconstructMatrixResult(&results);
}


bool MatrixType::dependency(Matrix *)
{


	return false;
}


int MatrixType::vectorSpace(Matrix *)
{


	return 0;
}


int MatrixType::nullSpace(Matrix *)
{


	return 0;
}


int MatrixType::columnSpace(Matrix *)
{


	return 0;
}


int MatrixType::rowSpace(Matrix *)
{


	return 0;
}


int MatrixType::rank(Matrix *)
{


	return 0;
}


int MatrixType::bases(Matrix *)
{

	
	return 0;
}


Matrix * MatrixType::eigenVector(Matrix *)
{


	return nullptr;
}


double * MatrixType::eigenValue(Matrix *)
{


	return nullptr;
}


double MatrixType::orthogonal(Matrix *, Matrix *)
{


	return 0.0;
}


double MatrixType::orthogonal(Matrix *)
{


	return 0.0;
}


double MatrixType::orthonormal(Matrix *, Matrix *)
{


	return 0.0;
}


double MatrixType::dot(Matrix *, Matrix *)
{


	return 0.0;
}


double MatrixType::cross(Matrix *, Matrix *)
{


	return 0.0;
}


double MatrixType::innerProduct(Matrix *)
{


	return 0.0;
}

