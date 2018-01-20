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

	//Init regression
	calc.constructRegression(&_regression);
}


ComplexMatrixCalculations::~ComplexMatrixCalculations()
{
	//Deconstruc objects constructed in the constructor
	calc.deconstructMatrix(&resultMatrix);
	calc.deconstructMatrixResult(&results);
	calc.deconstructRegression(&_regression);
}


Regression * ComplexMatrixCalculations::findStandardRegression(Matrix *orginalDataSet, Regression *OrginalRegression)
{
	//Copy dataSet
	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.columns = orginalDataSet->columns;
	resultMatrix.rows = orginalDataSet->rows;
	calc.constructMatrix(&resultMatrix);
	calc.mergeMatrix(&resultMatrix, orginalDataSet);

	//SortData
	sortRegressionData();

	//Find regression
	findRegression();

	//Return result
	return &_regression;
}


Regression * ComplexMatrixCalculations::findBestRegression(Matrix*)
{


	return nullptr;
}


double ComplexMatrixCalculations::precision(Matrix*, Regression *)
{


	return 0.0;
}

void ComplexMatrixCalculations::copyRegression(Regression *)
{
}

void ComplexMatrixCalculations::printRegression(Regression *)
{
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


void ComplexMatrixCalculations::findRegression(void)
{


	
}


Regression * ComplexMatrixCalculations::findDominantRegression(Matrix*, Regression *)
{


	return nullptr;
}


Regression * ComplexMatrixCalculations::getRegressionFromCoordinates(Matrix*, Regression *)
{


	return nullptr;
}


double ComplexMatrixCalculations::regressionPredicsion(Matrix*, Regression *)
{


	return 0.0;
}


void ComplexMatrixCalculations::sortRegressionData(void)
{


	
}
