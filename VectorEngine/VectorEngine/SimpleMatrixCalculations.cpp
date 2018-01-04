#include "SimpleMatrixCalculations.h"



SimpleMatrixCalculations::SimpleMatrixCalculations(bool intermediateCalculation)
{
	//Init intermiate calculations through out the code
	(intermediateCalculation == 0 || intermediateCalculation == 1)? _intermediateCalculation = intermediateCalculation : _intermediateCalculation = 0;

	//Construct a 1x1 matrix
	resultMatrix.columns = 1;
	resultMatrix.rows = 1;

	constructMatrix(&resultMatrix);
}


SimpleMatrixCalculations::~SimpleMatrixCalculations()
{
	deconstructMatrix(&resultMatrix);
}


void SimpleMatrixCalculations::constructMatrix(Matrix *conMatrix)
{
	if (_intermediateCalculation == 1)
		cout << "Construct matrix" << endl;

	conMatrix->matrix = new double*[conMatrix->columns];
	for (int i = 0; i < conMatrix->columns; ++i)
		conMatrix->matrix[i] = new double[conMatrix->rows];
}


void SimpleMatrixCalculations::deconstructMatrix(Matrix *deconMatrix)
{
	if (_intermediateCalculation == 1)
		cout << "Deconstruct matrix" << endl; 

	for (size_t i = 0; i < deconMatrix->columns; i++)
		delete[] deconMatrix->matrix[i];
	delete[] deconMatrix->matrix;
}


void SimpleMatrixCalculations::printMatrix(Matrix *print)
{
	for (size_t i = 0; i < print->rows; i++)
	{
		for (size_t j = 0; j < print->columns; j++)
			cout << print->matrix[j][i] << "  ";
		cout << endl;
	}
}


bool SimpleMatrixCalculations::verificateMatrix(Matrix *)		//Men hvad indebærer det?
{

	return false;
}


void SimpleMatrixCalculations::fillMatrix(Matrix *fill)
{
	for (size_t i = 0; i < fill->rows; i++)
	{
		for (size_t j = 0; j < fill->columns; j++)
		{
			cout << "Row: " << i+1 << " - Column: " << j+1 << " - Value: " << endl;
			cin >> fill->matrix[j][i];
		}
	}
}


Matrix SimpleMatrixCalculations::plus(Matrix *firstMatrix, Matrix *secondMatrix)
{
	//Init result matrix
	deconstructMatrix(&resultMatrix);

	resultMatrix.columns = firstMatrix->columns;
	resultMatrix.rows = firstMatrix->rows;

	constructMatrix(&resultMatrix);

	if (_intermediateCalculation == 1)
		cout << "plus" << endl;


	//Load result matrix and plus matrixes together at the same time
	for (size_t i = 0; i < firstMatrix->rows; i++)
	{
		for (size_t j = 0; j < firstMatrix->columns; j++)
		{
			resultMatrix.matrix[j][i] = firstMatrix->matrix[j][i] + secondMatrix->matrix[j][i];		//Plus two matrix
		}
	}

	//Return result matrix
	return resultMatrix;		//Not a problem since it's being deconstructed before every use
}


Matrix SimpleMatrixCalculations::minus(Matrix *firstMatrix, Matrix *secondMatrix)
{
	//Init result matrix
	deconstructMatrix(&resultMatrix);

	resultMatrix.columns = firstMatrix->columns;
	resultMatrix.rows = firstMatrix->rows;

	constructMatrix(&resultMatrix);

	if (_intermediateCalculation == 1)
		cout << "minus" << endl;


	//Load result matrix and plus matrixes together at the same time
	for (size_t i = 0; i < firstMatrix->rows; i++)
	{
		for (size_t j = 0; j < firstMatrix->columns; j++)
		{
			resultMatrix.matrix[j][i] = firstMatrix->matrix[j][i] - secondMatrix->matrix[j][i];		//Minus 2 matrix
		}
	}

	//Return result matrix
	return resultMatrix;		//Not a problem since it's being deconstructed before every use
}


Matrix SimpleMatrixCalculations::multiplication(Matrix *firstMatrix, Matrix *secondMatrix)
{
	//Init result matrix
	deconstructMatrix(&resultMatrix);
	
	resultMatrix.columns = secondMatrix->columns;
	resultMatrix.rows = firstMatrix->rows;

	constructMatrix(&resultMatrix);
	
	//Intermediate calculations
	if (_intermediateCalculation == 1)
		cout << "multiplication" << endl;

	//Multiplication
	double result = 0;
	double mellem = 0;

	for (size_t i = 0; i < firstMatrix->rows; i++)
	{
		for (size_t m = 0; m < secondMatrix->columns; m++)
		{
			for (size_t j = 0; j < firstMatrix->columns; j++)
			{
				//DotAlg two vectors 
				mellem = firstMatrix->matrix[j][i] * secondMatrix->matrix[m][j];
				result += mellem;
			}
			resultMatrix.matrix[m][i] = result;
			result = 0;
		}
	}

	//Return result 
	return resultMatrix;
}


Matrix SimpleMatrixCalculations::scale(Matrix *orginalMatrix, double scaleProduct)
{
	//Init result matrix
	deconstructMatrix(&resultMatrix);

	resultMatrix.columns = orginalMatrix->columns;
	resultMatrix.rows = orginalMatrix->rows;

	constructMatrix(&resultMatrix);

	if (_intermediateCalculation == 1)
		cout << "scaling" << endl;

	//scale the orginal matrix
	for (size_t i = 0; i < resultMatrix.columns; i++)
	{
		for (size_t j = 0; j < resultMatrix.rows; j++)
		{
			resultMatrix.matrix[i][j] = scaleProduct * orginalMatrix->matrix[i][j];
		}
	}


	//Return result
	return resultMatrix;
}


Matrix SimpleMatrixCalculations::transpose(Matrix *orginalMatrix)
{
	//Init result matrix
	deconstructMatrix(&resultMatrix);

	resultMatrix.columns = orginalMatrix->rows;
	resultMatrix.rows = orginalMatrix->columns;

	constructMatrix(&resultMatrix);

	if (_intermediateCalculation == 1)
		cout << "transpose" << endl;


	//Fill and transpose
	for (size_t i = 0; i < resultMatrix.columns; i++)
	{
		for (size_t j = 0; j < resultMatrix.rows; j++)
		{
			resultMatrix.matrix[i][j] = orginalMatrix->matrix[j][i];
		}
	}

	return resultMatrix;
}


double SimpleMatrixCalculations::determinant(Matrix *orginalMatrix)
{
	if (_intermediateCalculation == 1)
		cout << "determinant" << endl;

	if (orginalMatrix->columns != orginalMatrix->rows)
		return NULL;

	//Init result matrix
	deconstructMatrix(&resultMatrix);
	resultMatrix.columns = orginalMatrix->columns;
	resultMatrix.rows = orginalMatrix->rows;
	constructMatrix(&resultMatrix);

	//Make it easier to calculate
	flipMatrix(orginalMatrix);

	//Allocade memory to keep track of excluded columns
	int *exclude = new int[orginalMatrix->columns-2];

	//Start recusiv function and find result
	double result = determinantPrivat(exclude);

	result = (resultMatrix.columns % 2 == 0 ? result : -result);

	//Delete dynamic memory
	delete[] exclude;

	//Return result
	return result;
}


double SimpleMatrixCalculations::determinantPrivat(int *exclude)
{
	//Find the determinant
	double result = 0;
	bool switcher = 0;

	//Over 2
	if (resultMatrix.rows > 2)
	{
		resultMatrix.rows -= 1;

		for (size_t i = 0, counter = 0; i < resultMatrix.columns; i++, counter = 0)	//'i' er den der skal excludes
		{
			//Check if the line is excluded
			for (size_t j = 0; j < resultMatrix.columns - (resultMatrix.rows+1); j++)
			{
				if (i == exclude[j])
				{
					counter++;
				}
			}

			//resusiv
			if (!counter)
			{
				//Add 'i' to the exclude-list
				exclude[resultMatrix.columns - (resultMatrix.rows + 1)] = i;

				//Call itself (resusiv)
				if(switcher == 0)
					result -= resultMatrix.matrix[i][resultMatrix.rows] * determinantPrivat(exclude);
				else if(switcher == 1)
					result += resultMatrix.matrix[i][resultMatrix.rows] * determinantPrivat(exclude);

				switcher = !switcher;

			}

		}
		resultMatrix.rows += 1;
	}


	//equel 2
	else if (resultMatrix.rows == 2)
	{
		//Find free columns
		int firstColumn, secondColumn, c = 0, count = 0, i = exclude[resultMatrix.columns-resultMatrix.rows-1];	

		if (i >= 0 && i < resultMatrix.columns)
		{
			for (size_t i = 0, count = 0; i < resultMatrix.columns; i++, count = 0)
			{
				count = 0;
				for (size_t j = 0; j < resultMatrix.columns; j++)
				{
					if (exclude[j] == i)
						count++;
				}
				if (!count)
				{
					if (c == 0)
					{
						firstColumn = i;
						c++;
					}
					else if (c == 1)
					{
						secondColumn = i;
						break;
					}
				}
			}
			if (_intermediateCalculation == 1)
			{
				cout << "exclude: " << exclude[0] << exclude[1] << endl;	//Jeg skal ikke exclude det samme element 2 gnage i arrayet
				cout << "firstcolumn: " << firstColumn << " - secondcolumn: " << secondColumn << " - equel: " << resultMatrix.matrix[firstColumn][1] * resultMatrix.matrix[secondColumn][0] - resultMatrix.matrix[secondColumn][1] * resultMatrix.matrix[firstColumn][0] << endl;
				cout << ": " << resultMatrix.matrix[firstColumn][1] << " - " << resultMatrix.matrix[secondColumn][0] << " - " << resultMatrix.matrix[secondColumn][1] << " - " << resultMatrix.matrix[firstColumn][0] << endl << endl;

			}

		}
		else
		{
			firstColumn = 0;
			secondColumn = 1;
		}

		//Calculate result
		return resultMatrix.matrix[firstColumn][1] * resultMatrix.matrix[secondColumn][0] - resultMatrix.matrix[secondColumn][1] * resultMatrix.matrix[firstColumn][0];
	}
	//under 2 = result
	else if (resultMatrix.rows == 1)
		return resultMatrix.matrix[0][0];

	//Return reuslt
	return result;

}


void SimpleMatrixCalculations::copyMatrix(Matrix *newMatrix)
{
	//Construct the new matrix
	newMatrix->columns = resultMatrix.columns;
	newMatrix->rows = resultMatrix.rows;

	constructMatrix(newMatrix);

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


double SimpleMatrixCalculations::dotAlg(Matrix *vec)
{
	//Init 
	double result = 0;
	double mellem = 0;
	
	//Intermediate calculations
	if (_intermediateCalculation == 1)
		cout << "dotalg" << endl;

	//Dot together
	for (size_t i = 0; i < vec->columns; i++)
	{
		mellem = vec->matrix[0][i] * vec->matrix[1][i];
		result += mellem;
	}


	//return result
	return result;
}

void SimpleMatrixCalculations::flipMatrix(Matrix *orginalMatrix)
{
	//Flip the matrix
	for (size_t i = 0; i < resultMatrix.columns; i++)
	{
		for (size_t j = 0; j < resultMatrix.rows; j++)
		{
			resultMatrix.matrix[i][j] = orginalMatrix->matrix[i][(resultMatrix.columns-1)-j];
		}
	}
}
