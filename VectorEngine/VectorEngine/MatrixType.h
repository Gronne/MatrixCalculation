#pragma once
#include "Information.h"
#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"


class MatrixType
{
public:
	MatrixType(bool = 0);
	~MatrixType();

	bool dependency(Matrix*);				//Done
	bool vectorSpace(Matrix*);
	bool subSpace(Matrix*);
	bool nullSpace(Matrix*, Matrix*);		//Done
	MatrixResult* nullSpaceSpan(Matrix*);	//Done
	int nullity(Matrix*);					//Done
	int columnSpace(Matrix*);
	int rowSpace(Matrix*);
	int rank(Matrix*);
	int rank(MatrixResult*);
	int bases(Matrix*);
	int span(Matrix*);
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

