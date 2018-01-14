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
	bool vectorSpace(Space*);
	bool subSpace(Space*);
	bool nullSpace(Matrix*, Matrix*);		//Done
	MatrixResult* nullSpaceSpan(Matrix*);	//Done
	int nullity(Matrix*);					//Done
	bool columnSpace(Matrix*, Matrix*);		//Done
	bool rowSpace(Matrix*, Matrix*);
	int rank(Matrix*);						//Done
	int rank(MatrixResult*);				//Done
	bool basis(Matrix*);					//Done
	bool basis(Matrix*, Space*);
	int span(Matrix*);
	double orthogonal(Matrix*, Matrix*);
	double orthogonal(Matrix*);
	double orthonormal(Matrix*, Matrix*);
	double dot(Matrix*, Matrix*);
	double cross(Matrix*, Matrix*);
	double innerProduct(Matrix*);
	bool isomorphic(Matrix*, Matrix*);

private:
	

	
	//-------objects---------
	SimpleMatrixCalculations calc;
	matrixReff rref;
	MatrixResult results;
	Matrix resultMatrix;
	Space _space;

	//------variables--------
	bool _intermediateCalculation = 0;					//can also be used for debugging
};

