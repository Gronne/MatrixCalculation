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
bool MatrixType::vectorSpace(Matrix *space)
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
bool MatrixType::subSpace(Matrix *orginalMatrix)
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


bool MatrixType::nullity(Matrix *)
{

	return false;
}


int MatrixType::columnSpace(Matrix *orginalMatrix)
{
	int result = 0;

	return result;
}


int MatrixType::rowSpace(Matrix *orginalMatrix)
{
	int result = 0;

	return result;
}


int MatrixType::rank(Matrix *orginalMatrix)
{
	int result = 0;

	return result;
}

int MatrixType::rank(MatrixResult *)
{
	return 0;
}


int MatrixType::bases(Matrix *orginalMatrix)
{
	int result = 0;

	return result;
}


int MatrixType::span(Matrix *)
{

	return 0;
}


Matrix * MatrixType::eigenVector(Matrix *orginalMatrix)
{


	return &resultMatrix;
}


double * MatrixType::eigenValue(Matrix *orginalMatrix)
{
	double result;

	return &result;
}


double MatrixType::orthogonal(Matrix *vec1, Matrix *vec2)
{
	double result = 0;

	return result;
}


double MatrixType::orthogonal(Matrix *orginalMatrix)
{
	double result = 0;

	return result;
}


double MatrixType::orthonormal(Matrix *vec1, Matrix *vec2)
{
	double result = 0;

	return result;
}


double MatrixType::dot(Matrix *vec1, Matrix *vec2)
{
	double result = 0;

	return result;
}


double MatrixType::cross(Matrix *vec1, Matrix *vec2)
{
	double result = 0;

	return result;
}


double MatrixType::innerProduct(Matrix *orginalMatrix)
{
	double result = 0;

	return result;
}

