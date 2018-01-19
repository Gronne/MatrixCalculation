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

	//Construct a base Space (Will now possible) - inner values already set to default.
	calc.constructSpace(&_space);

	//Span values
	spanValues = new double[1];
}


MatrixType::~MatrixType()
{
	//Deconstruc objects constructed in the constructor
	calc.deconstructMatrix(&resultMatrix);
	calc.deconstructMatrixResult(&results);
	calc.deconstructSpace(&_space);
	delete[] spanValues;
}


bool MatrixType::dependency(Matrix *orginalMatrix)
{
	//This function is to determine if the matrix is dependent or independent.
	//The dependency is a question about free variables, and there for the matrix result just need ot be checked in this function #easy.
	bool result = 0;

	if (rref.result(orginalMatrix)->freeVariable == 0)
		result = true;									//Independent
	else
		result = false;									//Dependent

	return result;
}


//Et vector space, er en regl eller et sæt af regler, som definere hvilke vektorer der må dannes i det givet space.
//Hvis de dannede vektorer opfylder de angivet grav og ved brug af disse, stadig ikke går ud over de defineret rammer,
//opfylder det reglen for at være et vektor space.
bool MatrixType::vectorSpace(Space *spaceGuess)
{
	int result = 0;

	return result;
}


//Et subspace er et space, som holder sig inden for det angivet vektorspace, og ved reglerne for et vectorspace, stadig
//Holder sig inden for dette space. Dette er ikke i samme græd regler der opstilles, men et span der fortæller hvis en
//subspace er defineret i.
//De regler der dog skal gælde er:
//Zero vectoren fra vector spacet, skal også være i subspacet
//Subspacet er lukket under addition
//Subspavet er lukket under multiplication.
bool MatrixType::subSpace(Space *subSpaceGuess)
{
	int result = 0;


	return result;
}


bool MatrixType::nullSpace(Matrix *orginalMatrix, Matrix *vec1)
{
	bool result = 0;

	calc.multiplication(orginalMatrix, vec1);
	calc.copyMatrix(&resultMatrix);

	int count = 0;
	for (size_t i = 0; i < resultMatrix.rows; i++)
	{
		if (resultMatrix.matrix[0][i] == 0)
			count++;
	}

	if (count == resultMatrix.rows)
		result = 1;

	return result;
}


MatrixResult * MatrixType::nullSpaceSpan(Matrix *orginalMatrix)
{
	//Init matrix
	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.columns = orginalMatrix->columns + 1;
	resultMatrix.rows = orginalMatrix->rows;
	calc.constructMatrix(&resultMatrix);

	//Merge orginal and result matrixes
	calc.mergeMatrix(&resultMatrix, orginalMatrix);

	//Set null column in
	for (size_t i = 0; i < resultMatrix.rows; i++)
		resultMatrix.matrix[resultMatrix.columns - 1][i] = 0;


	//Deconstruct loacal resul
	calc.deconstructMatrixResult(&results);

	//Rref to find the matrix
	rref.echelonReduction(&resultMatrix);

	//Find the result that give the 0 space
	rref.result(&resultMatrix);

	//Get result
	rref.copyResult(&results);

	//Return nullspace span result
	return &results;
}


int MatrixType::nullity(Matrix *orginalMatrix)	//Rank + nullity = number of columns in the matrix
{
	//Init matrix
	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.columns = orginalMatrix->columns + 1;
	resultMatrix.rows = orginalMatrix->rows;
	calc.constructMatrix(&resultMatrix);

	//Merge orginal and result matrixes
	calc.mergeMatrix(&resultMatrix, orginalMatrix);

	//Set null column in
	for (size_t i = 0; i < resultMatrix.rows; i++)
		resultMatrix.matrix[resultMatrix.columns - 1][i] = 0;

	//Rref to find the matrix
	rref.echelonReduction(&resultMatrix);

	//Get number og free variables
	int amount = rref.result()->freeVariable;

	//The amount of free variables is the nullity
	return amount;
}


bool MatrixType::columnSpace(Matrix *orginalMatrix, Matrix *vec)	//Can a individual scalar on each vector in the matrix, end up give the 'vec'?
{
	//Init matrix
	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.columns = orginalMatrix->columns + 1;
	resultMatrix.rows = orginalMatrix->rows;
	calc.constructMatrix(&resultMatrix);

	//Merge orginal and result matrixes
	calc.mergeMatrix(&resultMatrix, orginalMatrix);

	//Set null column in
	for (size_t i = 0; i < resultMatrix.rows; i++)
		resultMatrix.matrix[resultMatrix.columns - 1][i] = vec->matrix[0][i];

	//Rref to find the matrix
	rref.echelonReduction(&resultMatrix);
	
	//Find result
	rref.result();

	//Get result
	rref.copyResult(&results);

	if (results.type[1] == 'd')		//But shall i return the scalars?
		return false;
	else
		return true;
}


bool MatrixType::rowSpace(Matrix *orginalMatrix, Matrix *vec)
{
	int result = 0;

	return result;
}


int MatrixType::rank(Matrix *orginalMatrix)
{
	//Init matrix
	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.columns = orginalMatrix->columns + 1;
	resultMatrix.rows = orginalMatrix->rows;
	calc.constructMatrix(&resultMatrix);

	//Merge orginal and result matrixes
	calc.mergeMatrix(&resultMatrix, orginalMatrix);

	//Set null column in
	for (size_t i = 0; i < resultMatrix.rows; i++)
		resultMatrix.matrix[resultMatrix.columns - 1][i] = 0;

	//Rref to find the matrix
	rref.echelonReduction(&resultMatrix);
	
	//Number og pivots is the rank of the matrix
	int amount = rref.pivots();

	//Return result
	return amount;
}

int MatrixType::rank(MatrixResult *orginalResult)
{
	//Find the rank
	int amount = orginalResult->size - orginalResult->freeVariable;

	//Return it
	return amount;
}


bool MatrixType::basis(Matrix *orginalMatrix)	//Before it can be a basis, it need to have a pivot in each row. If not, it does not span R^n
{
	int piv = rref.pivots(orginalMatrix);

	if (piv == orginalMatrix->columns)
		return true;
	else
		return false;
}


bool MatrixType::basis(Matrix *orginalMatrix, Space *space)
{
	

	return true;
}


Matrix* MatrixType::span(Matrix *orginalMatrix)
{
	//Find pivots collumns
	int *numberOfPivots = rref.pivotColumns(orginalMatrix);
	
	//Init resultMatrix
	calc.deconstructMatrix(&resultMatrix);
	resultMatrix.columns = rref.pivots();
	resultMatrix.rows = orginalMatrix->rows;
	calc.constructMatrix(&resultMatrix);

	//set resultMatrix
	for (size_t i = 0; i < resultMatrix.rows; i++)
	{
		for (size_t j = 0; j < resultMatrix.columns; j++)
		{
			resultMatrix.matrix[j][i] = orginalMatrix->matrix[numberOfPivots[j]][i];
		}
	}

	//Delete
	delete[] numberOfPivots;

	//Return resultMatrix
	return &resultMatrix;
}


double * MatrixType::span(Matrix *spanMatrix, Matrix *vec)
{
	//Init spanValues
	delete[] spanValues;
	spanValues = new double[spanMatrix->columns];

	//Merge matrix with vec
	calc.mergeIntoResultMatrix(spanMatrix, vec);
	calc.copyMatrix(&resultMatrix);

	//find number of pivots for spanMatrix and rref it at the same time
	rref.echelonReduction(&resultMatrix);
	int numberOfPivots = rref.pivots();

	//Get resultMatrix
	rref.copyMatrix(&resultMatrix);

	//Fill in result:
	int counter;
	for (counter = 0; counter < numberOfPivots; counter++)
	{
		spanValues[counter] = resultMatrix.matrix[resultMatrix.columns - 1][counter];
	}
	for (; counter < spanMatrix->columns; counter++)
	{
		spanValues[counter] = 0;
	}

	//Return span values
	return spanValues;
}

bool MatrixType::checkSpan(Matrix *spanMatrix, Matrix *vec)	//If a there is free variables, the ones without a pivot will be set to zero.
{
	//Merge matrix with vec
	calc.mergeIntoResultMatrix(spanMatrix, vec);
	calc.copyMatrix(&resultMatrix);

	//rref the new matrix
	int numberOfPivotsMerged = rref.pivots(&resultMatrix);
	int numberofPivots = rref.pivots(spanMatrix);

	//Check if vec can be expressed with spanMatrix
	if (numberOfPivotsMerged == numberofPivots)
		return true;
	else 
		return false;
}


bool MatrixType::orthogonal(Matrix *vec1, Matrix *vec2)
{
	if (dot(vec1, vec2))
		return false;
	else
		return true;
}


bool MatrixType::orthogonal(Matrix *orginalMatrix)
{
	//Check if it spans over enougth planes
	if (orginalMatrix->columns > orginalMatrix->rows)
		return false;

	//Make vectors
	Matrix vec1;
	Matrix vec2;

	vec1.columns = 1;
	vec2.columns = 1;
	vec1.rows = orginalMatrix->rows;
	vec2.rows = orginalMatrix->rows;

	calc.constructMatrix(&vec1);
	calc.constructMatrix(&vec2);


	//Check span
	double value = 0;
	for (size_t i = 0; i < orginalMatrix->columns-1; i++)
	{
		for (size_t j = i+1; j < orginalMatrix->columns; j++)
		{
			//Transfer information to vectors
			for (size_t m = 0; m < vec1.rows; m++)
			{
				vec1.matrix[0][m] = orginalMatrix->matrix[i][m];
			}
			for (size_t m = 0; m < vec1.rows; m++)
			{
				vec2.matrix[0][m] = orginalMatrix->matrix[j][m];
			}

			//Check dot product between vectors
			value = dot(&vec1, &vec2);

			//Validate value
			if (value)
				break;
		}
		if (value)
			break;
	}

	//Delete vectors
	calc.deconstructMatrix(&vec1);
	calc.deconstructMatrix(&vec2);

	//Return result
	if (value)
		return false;
	else
		return true;
}


double MatrixType::orthonormal(Matrix *vec1, Matrix *vec2)
{
	double result = 0;

	return result;
}


double MatrixType::dot(Matrix *vec1, Matrix *vec2)
{
	//Init 
	double result = 0;
	double mellem = 0;

	//Intermediate calculations
	if (_intermediateCalculation == 1)
		cout << "dotalg" << endl;

	//Dot together
	for (size_t i = 0; i < vec1->rows; i++)
	{
		mellem = vec1->matrix[0][i] * vec2->matrix[0][i];
		result += mellem;
	}

	//return result
	return result;
}


double MatrixType::cross(Matrix *vec1, Matrix *vec2)
{
	double result = 0;

	return result;
}


double MatrixType::innerProductSpace(Matrix *orginalMatrix)
{
	double result = 0;


	return result;
}


bool MatrixType::isomorphic(Matrix *, Matrix *)
{
	return false;
}

