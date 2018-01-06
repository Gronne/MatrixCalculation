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
	_lastFunctionRun = 1;

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
	_lastFunctionRun = 2;

	if (_intermediateCalculation)
		cout << "Echelon reduction" << endl;

	singleStair();
	doubleStair();

	//Return the echelon reduced matrix
	return resultMatrix;
}


Matrix matrixReff::adjugateInvert(Matrix *orginalMatrix)
{
	if (_intermediateCalculation)
		cout << "Adjugate invert" << endl;

	_lastFunctionRun = 4;

	//Validate matrix
	if (orginalMatrix->columns != orginalMatrix->rows)
		return *orginalMatrix;

	//Init and copy matrix
	initMatrix(orginalMatrix);

	//Init det-values
	double detFirst, detSecond, detThird, detFourth;

	//go to every object and find the det
	for (size_t i = 0; i < resultMatrix.rows; i++)
	{
		for (size_t j = 0; j < resultMatrix.columns; j++)		//Use the orginial
		{
			//The first number
			detFirst = (j + 1 < resultMatrix.columns) ? (i + 1 < resultMatrix.columns ? orginalMatrix->matrix[j + 1][i + 1] : orginalMatrix->matrix[j + 1][0 + ((i + 1) - (resultMatrix.rows))]) : (i + 1 < resultMatrix.columns ? orginalMatrix->matrix[0 + ((j + 1) - (resultMatrix.rows))][i + 1] : orginalMatrix->matrix[0 + ((j + 1) - (resultMatrix.rows))][0 + ((i + 1) - (resultMatrix.rows))]);

			//The second number
			detSecond = (j + 2 < resultMatrix.columns) ? (i + 1 < resultMatrix.columns ? orginalMatrix->matrix[j + 2][i + 1] : orginalMatrix->matrix[j + 2][0 + ((i + 1) - (resultMatrix.rows))]) : (i + 1 < resultMatrix.columns ? orginalMatrix->matrix[0 + ((j + 2) - (resultMatrix.rows))][i + 1] : orginalMatrix->matrix[0 + ((j + 2) - (resultMatrix.rows))][0 + ((i + 1) - (resultMatrix.rows))]);

			//The third number
			detThird = (j + 1 < resultMatrix.columns) ? (i + 2 < resultMatrix.columns ? orginalMatrix->matrix[j + 1][i + 2] : orginalMatrix->matrix[j + 1][0 + ((i + 2) - (resultMatrix.rows))]) : (i + 2 < resultMatrix.columns ? orginalMatrix->matrix[0 + ((j + 1) - (resultMatrix.rows))][i + 2] : orginalMatrix->matrix[0 + ((j + 1) - (resultMatrix.rows))][0 + ((i + 2) - (resultMatrix.rows))]);

			//The fourth number
			detFourth = (j + 2 < resultMatrix.columns) ? (i + 2 < resultMatrix.columns ? orginalMatrix->matrix[j + 2][i + 2] : orginalMatrix->matrix[j + 2][0 + ((i + 2) - (resultMatrix.rows))]) : (i + 2 < resultMatrix.columns ? orginalMatrix->matrix[0 + ((j + 2) - (resultMatrix.rows))][i + 2] : orginalMatrix->matrix[0 + ((j + 2) - (resultMatrix.rows))][0 + ((i + 2) - (resultMatrix.rows))]);
			
			//Find determinant
			resultMatrix.matrix[j][i] = (detFirst * detFourth - detSecond * detThird);
			if (_intermediateCalculation)
				cout << "det = " << detFirst << " * " << detFourth << " - " << detSecond << " * " << detThird << " = " << resultMatrix.matrix[j][i] << endl;
		}
	}

	if (_intermediateCalculation == 1)
		calc.printMatrix(&resultMatrix);

	//Find the Identificaiton factorization
	calc.transpose(&resultMatrix);
	calc.copyMatrix(&resultMatrix);

	int factor = calc.multiplication(&resultMatrix, orginalMatrix).matrix[0][0];

	//Devide the resultMatrix with the factorization
	for (size_t i = 0; i < resultMatrix.rows; i++)
	{
		for (size_t j = 0; j < resultMatrix.columns; j++)
		{
			resultMatrix.matrix[j][i] /= factor;
		}
	}

	if (_intermediateCalculation == 1)
		calc.printMatrix(&resultMatrix);

	return resultMatrix;
}


Matrix matrixReff::invert(Matrix *orginalMatrix)
{
	//Check if it can be inverted
	if (orginalMatrix->columns != orginalMatrix->rows)
		return *orginalMatrix;

	//Init result matrix
	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.columns = orginalMatrix->columns*2;
	resultMatrix.rows = orginalMatrix->rows;
	calc.constructMatrix(&resultMatrix);

	_lastFunctionRun = 3;

	//Fill in orginal matrix
	for (size_t i = 0; i < resultMatrix.rows; i++)
	{
		for (size_t j = 0; j < resultMatrix.columns/2; j++)
		{
			resultMatrix.matrix[j][i] = orginalMatrix->matrix[j][i];
		}
	}

	//Fill in identy matrix (I)
	for (size_t i = 0; i < resultMatrix.rows; i++)
	{
		for (size_t j = resultMatrix.columns/2; j < resultMatrix.columns; j++)
		{
			if((j - (resultMatrix.columns/2)) == i)
				resultMatrix.matrix[j][i] = 1;
			else
				resultMatrix.matrix[j][i] = 0;
		}
	}

	if (_intermediateCalculation)
		cout << "Invert" << endl;


	//Find the inverted matrix
	singleStair();
	doubleStair();

	if (_intermediateCalculation)
		calc.printMatrix(&resultMatrix);

	//Substract the inverted part
	Matrix buffer;
	buffer.columns = orginalMatrix->columns;
	buffer.rows = orginalMatrix->rows;
	calc.constructMatrix(&buffer);

	for (size_t i = 0; i < buffer.rows; i++)
	{
		for (size_t j = 0; j < buffer.columns; j++)
		{
			buffer.matrix[j][i] = resultMatrix.matrix[j + buffer.columns][i];
		}
	}

	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.columns = orginalMatrix->columns;
	resultMatrix.rows = orginalMatrix->rows;
	calc.constructMatrix(&resultMatrix);

	for (size_t i = 0; i < buffer.rows; i++)
	{
		for (size_t j = 0; j < buffer.columns; j++)
		{
			resultMatrix.matrix[j][i] = buffer.matrix[j][i];
		}
	}
	

	//Return the inverted matrix
	return resultMatrix;
}


double * matrixReff::result(void)
{
	int answers = pivots();
	double *results = new double[answers];

	if (answers == resultMatrix.columns-1)
	{
		for (size_t i = 0; i < coreSize; i++)
		{
			results[i] = resultMatrix.matrix[resultMatrix.columns - 1][i];
		}
	}
	else
	{
		//Check if there is 0 = 1, statements
		for (size_t i = 0; i < resultMatrix.rows-answers; i++)
		{
			if (resultMatrix.matrix[resultMatrix.columns-1][i] != 0)
			{
				for (size_t i = 0; i < coreSize; i++)
				{
					results[i] = -1;
				}
			}
		}

		//Check for free variables - the problem?!?!


	}


	return results;
}

double * matrixReff::result(Matrix *orginalMatrix, bool stepOver)
{
	if (!stepOver)
	{
		//Reff the matrix
		echelonReduction(orginalMatrix);
	}
	
	//Find and return answer
	return result();
}

double * matrixReff::result(Matrix *orginalA, Matrix *orginalB)
{
	double r = { -1 };

	if (orginalA->rows == orginalB->rows)
		return &r;

	//Init result matrix
	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.rows = orginalA->rows;
	resultMatrix.columns = orginalA->columns + orginalB->columns;
	calc.constructMatrix(&resultMatrix);

	//Fill result matrix
	for (size_t i = 0; i < resultMatrix.rows; i++)
	{
		for (size_t j = 0; j < orginalA->columns; j++)
		{
			resultMatrix.matrix[j][i] = orginalA->matrix[j][i];
		}
	}

	for (size_t i = 0; i < resultMatrix.rows; i++)
	{
		for (size_t j = orginalA->columns; j < resultMatrix.columns; j++)
		{
			resultMatrix.matrix[j][i] = orginalB->matrix[j-orginalA->columns][i];
		}
	}

	//reff the matrix
	singleStair();
	doubleStair();

	//Find aswer and return result
	return result(&resultMatrix, 1);
}

int matrixReff::pivots(Matrix *orginalMatrix)
{
	initMatrix(orginalMatrix);

	singleStair();

	return pivots();
}

int matrixReff::pivots(void)
{
	if (_lastFunctionRun == 0 || _lastFunctionRun > 4)
	{
		//Can't finde the pivots
		return -1;
	}
	if (_intermediateCalculation)
		cout << "Find pivots" << endl;

	int numberOfPivots = 0;
	int rowCounter = 0;
	
	for (size_t j = 0; j < resultMatrix.columns && rowCounter < resultMatrix.rows; j++)
	{
		if (resultMatrix.matrix[j][rowCounter] != 0)
		{
			rowCounter++;
			numberOfPivots++;
			if (_intermediateCalculation)
				cout << "Pivot at column: " << j << endl;
		}
	}

	return numberOfPivots;
}

int * matrixReff::pivotRows(Matrix *)
{
	return nullptr;
}

int * matrixReff::pivotRows(void)
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

	//Create memory for the minimizing function
	double *timeBuffer = new double[coreSize];

	//Set rows under coreSize to zero
	for (size_t i = coreSize; i < resultMatrix.rows; i++)
	{
		for (size_t j = 0; j < resultMatrix.columns; j++)
		{
			resultMatrix.matrix[j][i] = 0;
		}
	}

	//Find argumented matrix
	for (size_t j = 0; j < coreSize-1; j++)
	{
		for (size_t i = j; i < coreSize; i++)		//Switch lanes
		{
			if (resultMatrix.matrix[j][i])
			{
				switchRow(i, j);
				break;
			}
		}

		if (_intermediateCalculation)
		{
			calc.printMatrix(&resultMatrix); cout << endl;
			cout << "Find timer" << endl;
		}

		double times = 1;
		for (size_t i = j; i < coreSize; i++)		//Find timer
		{
			if (resultMatrix.matrix[j][i])
			{
				times *= resultMatrix.matrix[j][i];
			}
		}

		if (_intermediateCalculation)
		{
			calc.printMatrix(&resultMatrix); cout << endl;
			cout << "Scale" << endl;
		}

		for (size_t i = j; i < coreSize; i++)		//scale
		{
			double scale = (resultMatrix.matrix[j][i] == 0 ? 1 : times / resultMatrix.matrix[j][i]);
			timeBuffer[i - j] = scale;				//Used to minimize later on

			if (resultMatrix.matrix[j][i])
			{
				for (size_t n = 0; n < resultMatrix.columns; n++)
				{
					resultMatrix.matrix[n][i] *= scale;
				}
			}
		}

		if (_intermediateCalculation)
		{
			calc.printMatrix(&resultMatrix); cout << endl;
			cout << "Minus" << endl;
		}

		for (size_t i = j+1; i < coreSize; i++)		//Minus
		{
			if (resultMatrix.matrix[j][i])
			{
				for (size_t n = 0; n < resultMatrix.columns; n++)
				{
					resultMatrix.matrix[n][i] -= resultMatrix.matrix[n][j];
				}
			}
		}

		if (_intermediateCalculation)
		{
			calc.printMatrix(&resultMatrix); cout << endl;
			cout << "Minimize" << endl;
		}

		for (size_t i = j; i < coreSize; i++)		//Minimize
		{
			if (resultMatrix.matrix[j+1][i])
			{
				for (size_t n = 0; n < resultMatrix.columns; n++)		
				{
					resultMatrix.matrix[n][i] /= timeBuffer[i - j];
					
				}
			}
		}
		
		if (_intermediateCalculation)
		{
			calc.printMatrix(&resultMatrix); cout << endl;
		}
	}

	cleanMatrix();

	delete[] timeBuffer;
}


void matrixReff::doubleStair(void)
{
	for (size_t i = coreSize - 1; i > 0; i--)	//0's obove the stair
	{
		double times = findTimer(i);

		scaleRows(times, i);
		if (_intermediateCalculation)
		{
			calc.printMatrix(&resultMatrix);
			cout << endl;
		}

		minusRows(i);
		if (_intermediateCalculation)
		{
			calc.printMatrix(&resultMatrix);
			cout << endl;
		}

		//Minimize?
	}

	cleanMatrix();

	for (size_t i = 0; i < coreSize; i++)		//minimize
	{
		double reduction = (resultMatrix.matrix[i][i] != 0) ? (1 / resultMatrix.matrix[i][i]) : 1;
		
		for (size_t n = 0; n < resultMatrix.columns; n++)
		{
			resultMatrix.matrix[n][i] *= reduction;
		}
	}
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
			resultMatrix.matrix[j][i] = orginalMatrix->matrix[j][i];
		}
	}
}


void matrixReff::switchRow(int firstRow, int SecondRow)
{
	if (_intermediateCalculation)
		cout << "switch row " << firstRow << " & " << SecondRow << endl;

	Matrix buffer; 
	buffer.columns = resultMatrix.columns; 
	buffer.rows = 1;
	calc.constructMatrix(&buffer);

	for (size_t i = 0; i < resultMatrix.columns; i++)	//Load buffer
	{
		buffer.matrix[i][0] = resultMatrix.matrix[i][firstRow];
	}
	for (size_t i = 0; i < resultMatrix.columns; i++)	//switch row
	{
		resultMatrix.matrix[i][firstRow] = resultMatrix.matrix[i][SecondRow];
		resultMatrix.matrix[i][SecondRow] = buffer.matrix[i][0];
	}

	calc.deconstructMatrix(&buffer);
}


double matrixReff::findTimer(int column)
{
	if (_intermediateCalculation)
		cout << "Find timer" << endl;


	double times = 1;

	for (size_t j = 0; j < coreSize; j++)		//Find timer
	{
		if (resultMatrix.matrix[column][j])
		{
			times *= resultMatrix.matrix[column][j];
		}
	}
	return times;
}


void matrixReff::scaleRows(double times, int column)
{
	if (_intermediateCalculation)
		cout << "Scale rows x" << times << endl;

	for (size_t i = 0; i < coreSize; i++)		//scale
	{
		double scale = (resultMatrix.matrix[column][i] == 0 ? 1 : times / resultMatrix.matrix[column][i]);

		if (resultMatrix.matrix[column][i])
		{
			for (size_t n = 0; n < resultMatrix.columns; n++)
			{
				resultMatrix.matrix[n][i] *= scale;
			}
		}
	}

}


void matrixReff::minusRows(int row)
{
	if (_intermediateCalculation)
		cout << "Minus rows" << endl;

	for (size_t i = row-1; i >= 0 && i < row; i--)
	{
		if (resultMatrix.matrix[row][i] != 0)
		{
			for (size_t n = row; n < resultMatrix.columns; n++)
			{
				resultMatrix.matrix[n][i] -= resultMatrix.matrix[n][row];
			}
		}
	}

}


void matrixReff::cleanMatrix(void)
{
	if (_intermediateCalculation)
		cout << "Clean" << endl;

	for (size_t i = 0; i < coreSize; i++)	//clean
	{
		for (size_t j = 0; j < resultMatrix.columns; j++)
		{
			if (resultMatrix.matrix[j][i] > -0.0001 && resultMatrix.matrix[j][i] < 0.0001)
				resultMatrix.matrix[j][i] = 0;
		}
	}
}
