#include "LinearRegression.h"



LinearRegression::LinearRegression(bool intermediateCalculation) :
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


LinearRegression::~LinearRegression()
{
	//Deconstruc objects constructed in the constructor
	calc.deconstructMatrix(&resultMatrix);
	calc.deconstructMatrixResult(&results);
	calc.deconstructRegression(&_regression);
}


Regression * LinearRegression::findStandardRegression(Matrix *orginalDataSet, Regression *orginalRegression)	//What if the regression doesn't have as many vaiables?
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
	findRegression(orginalRegression);

	//Return result
	return &_regression;
}

Regression * LinearRegression::findBestRegression(Matrix *orginalDataSet, int leftSide, int rightSide)
{
	//Copy dataSet
	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.columns = orginalDataSet->columns;
	resultMatrix.rows = orginalDataSet->rows;
	calc.constructMatrix(&resultMatrix);
	calc.mergeMatrix(&resultMatrix, orginalDataSet);


	return &_regression;
}


double LinearRegression::precision(Matrix *, Regression *)
{


	return 0.0;
}


void LinearRegression::copyRegression(Regression *)
{


}


void LinearRegression::printRegression(Regression *)
{


}


void LinearRegression::findRegression(Regression *dataSet)
{
	//setup left and rightside matrices
	Matrix leftSide;
	Matrix rightSide;
	Matrix bufferMatrixOne;
	Matrix bufferMatrixTwo;

	leftSide.rows = resultMatrix.columns;
	rightSide.rows = leftSide.rows;

	leftSide.columns = dataSet->regression.size();
	rightSide.columns = dataSet->rightSide.size();

	calc.constructMatrix(&leftSide);
	calc.constructMatrix(&rightSide);
	calc.constructMatrix(&bufferMatrixOne);
	calc.constructMatrix(&bufferMatrixTwo);

	//Split it up
	createLeftSide(&leftSide, dataSet);
	createRightSide(&rightSide, dataSet);		//Do i need the result matrix after this point? - if 

	//-------calculate the linear regression-------
	//Calculate the transposed leftside
	calc.transpose(&leftSide);
	calc.copyMatrix(&bufferMatrixOne);

	//Calculate leftSide times transposed leftside
	calc.multiplication(&leftSide, &bufferMatrixOne);
	calc.copyMatrix(&bufferMatrixTwo);

	//Calculate the transposed leftSide times the rightSide
	calc.multiplication(&bufferMatrixOne, &rightSide);
	calc.copyMatrix(&bufferMatrixOne);

	//Calculate the inverted matrix
	rref.invert(&bufferMatrixTwo);
	rref.copyMatrix(&bufferMatrixTwo);
	
	//Calculate the beta values
	calc.multiplication(&bufferMatrixTwo, &bufferMatrixOne);


	//Put the values into the regression


	//Deconstruct matrices
	calc.deconstructMatrix(&leftSide);
	calc.deconstructMatrix(&rightSide);
	calc.deconstructMatrix(&bufferMatrixOne);
	calc.deconstructMatrix(&bufferMatrixTwo);
}


Regression * LinearRegression::findDominantRegression(Matrix *, Regression *)
{


	return nullptr;
}


Regression * LinearRegression::getRegressionFromCoordinates(Matrix *, Regression *)
{


	return nullptr;
}


double LinearRegression::regressionPredicsion(Matrix *, Regression *)
{


	return 0.0;
}


void LinearRegression::sortRegressionData(void)
{


}

void LinearRegression::createLeftSide(Matrix *, Regression *)
{
}

void LinearRegression::createRightSide(Matrix *, Regression *)
{
}

