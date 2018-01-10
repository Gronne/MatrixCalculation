#pragma once
#include "Information.h"
#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"


class MatrixType
{
public:
	MatrixType(bool = 0);
	~MatrixType();

	bool dependency(Matrix*);
	int vectorSpace(Matrix*);
	int nullSpace(Matrix*);
	int columnSpace(Matrix*);
	int rowSpace(Matrix*);
	int rank(Matrix*);
	int bases(Matrix*);
	Matrix* eigenVector(Matrix*);
	double* eigenValue(Matrix*);
	double orthogonal(Matrix*, Matrix*);
	double orthogonal(Matrix*);
	double orthonormal(Matrix*, Matrix*);
	double dot(Matrix*, Matrix*);
	double cross(Matrix*, Matrix*);
	double innerProduct(Matrix*);

private:
	

	
	//-------objects---------
	SimpleMatrixCalculations calc;
	matrixReff rref;
	MatrixResult results;
	Matrix resultMatrix;

	//------variables--------
	bool _intermediateCalculation = 0;					//can also be used for debugging
};

