#include "matrixReff.h"



matrixReff::matrixReff(bool intermediateCalculation) : calc(intermediateCalculation)
{
	//Init intermiate calculations through out the code
	(intermediateCalculation == 0 || intermediateCalculation == 1) ? _intermediateCalculation = intermediateCalculation : _intermediateCalculation = 0;

	//Construct a 1x1 matrix
	resultMatrix.columns = 1;
	resultMatrix.rows = 1;

	calc.constructMatrix(&resultMatrix);
}


matrixReff::~matrixReff()
{
	calc.deconstructMatrix(&resultMatrix);
}


Matrix matrixReff::rowReduction(Matrix *orginalMatrix)
{
	//Init result matrix
	initMatrix(orginalMatrix);

	if (_intermediateCalculation)
		cout << "Row reduction" << endl;

	//Start calculation
	singleStair();

	//Return the rowReduced matrix
	return resultMatrix;
}


Matrix matrixReff::echelonReduction(Matrix *orginalMatrix)
{
	//Init result matrix
	initMatrix(orginalMatrix);

	if (_intermediateCalculation)
		cout << "Echelon reduction";

	singleStair();
	doubleStair();

	//Return the echelon reduced matrix
	return resultMatrix;
}


Matrix matrixReff::invert(Matrix *orginalMatrix)
{


	return resultMatrix;
}

double * matrixReff::result(void)
{
	return nullptr;
}


void matrixReff::copyMatrix(Matrix *newMatrix)
{
	//Construct the new matrix
	newMatrix->columns = resultMatrix.columns;
	newMatrix->rows = resultMatrix.rows;

	calc.constructMatrix(newMatrix);

	if (_intermediateCalculation == 1)
		cout << "copy matrix" << endl;

	//Copy the matrix
	for (size_t i = 0; i < resultMatrix.columns; i++)
	{
		for (size_t j = 0; j < resultMatrix.rows; j++)
		{
			newMatrix->matrix[i][j] = resultMatrix.matrix[i][j];
		}
	}
}


void matrixReff::singleStair(void)
{
	//Check the number of rows that neew to be calculates.
	coreSize = (resultMatrix.columns > resultMatrix.rows ? resultMatrix.rows : resultMatrix.columns);

}

void matrixReff::doubleStair(void)
{


}


void matrixReff::initMatrix(Matrix *orginalMatrix)
{
	//Init resultmatrix
	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.columns = orginalMatrix->columns;
	resultMatrix.rows = orginalMatrix->rows;
	calc.constructMatrix(&resultMatrix);
	
	//Fill it
	for (size_t i = 0; i < resultMatrix.rows; i++)
	{
		for (size_t j = 0; j < resultMatrix.columns; j++)
		{
			resultMatrix.matrix[i][j] = orginalMatrix->matrix[i][j];
		}
	}
}
