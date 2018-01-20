#pragma once
#include "Information.h"
#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"
#include "MatrixType.h"
#include "vector"

using namespace std;

class ComplexMatrixCalculations
{
public:
	ComplexMatrixCalculations(bool = 0);
	~ComplexMatrixCalculations();

	Regression* findStandardRegression(Matrix*, Regression*);
	Regression* findBestRegression(Matrix*);			//Will this one return the prototype or the hole regression?
	double precision(Matrix*, Regression*);				//Hvor godt regressionen passer på matrix datasættet
	void copyRegression(Regression*);					//Will copy the found regression.
	void printRegression(Regression*);

	Matrix* gramSchmidtProcess(Matrix *);
	double orthogonalProjection(Matrix*, Matrix*);

	Matrix* leastSquare(Matrix*, Matrix*);
	Matrix* SVD(Matrix*);
	double QRfactorization(Matrix*);

	//InnerProduct

	Matrix* eigenvector(Matrix*);
	double* eigenValues(Matrix*);	//Eller er matrix?


private:
	void findRegression(void);
	Regression* findDominantRegression(Matrix*, Regression*);
	Regression* getRegressionFromCoordinates(Matrix*, Regression*);
	double regressionPredicsion(Matrix*, Regression*);
	void sortRegressionData(void);


	//-------objects---------
	SimpleMatrixCalculations calc;
	matrixReff rref;
	MatrixResult results;
	MatrixType type;
	Matrix resultMatrix;
	Regression _regression;

	//------variables--------
	bool _intermediateCalculation = 0;					//can also be used for debugging
};

