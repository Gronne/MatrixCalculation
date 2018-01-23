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

	Matrix* gramSchmidtProcess(Matrix *);
	double orthogonalProjection(Matrix*, Matrix*);

	Matrix* leastSquare(Matrix*, Matrix*);
	Matrix* SVD(Matrix*);
	double QRfactorization(Matrix*);

	//InnerProduct

	Matrix* eigenvector(Matrix*);
	double* eigenValues(Matrix*);	//Eller er matrix?

	void sortData(void);

private:


	//-------objects---------
	SimpleMatrixCalculations calc;
	matrixReff rref;
	MatrixResult results;
	MatrixType type;
	Matrix resultMatrix;

	//------variables--------
	bool _intermediateCalculation = 0;					//can also be used for debugging
};

