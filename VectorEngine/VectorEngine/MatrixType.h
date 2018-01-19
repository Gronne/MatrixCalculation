#pragma once
#include "Information.h"
#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"


class MatrixType
{
public:
	MatrixType(bool = 0);
	~MatrixType();

	bool dependency(Matrix*);				//Done - need test
	bool vectorSpace(Space*);
	bool subSpace(Space*);
	bool nullSpace(Matrix*, Matrix*);		//Done - need test
	MatrixResult* nullSpaceSpan(Matrix*);	//Done - need test
	int nullity(Matrix*);					//Done - need test
	bool columnSpace(Matrix*, Matrix*);		//Done - need test
	bool rowSpace(Matrix*, Matrix*);
	int rank(Matrix*);						//Done - need test
	int rank(MatrixResult*);				//Done - need test
	bool basis(Matrix*);					//Done - need test
	bool basis(Matrix*, Space*);			
	Matrix* span(Matrix*);					//Done - need test
	double* span(Matrix*, Matrix*);			//Done - need test
	bool checkSpan(Matrix*, Matrix*);		//Done - need test
	bool orthogonal(Matrix*, Matrix*);		//Done - need test
	bool orthogonal(Matrix*);				//Done - need test
	double orthonormal(Matrix*, Matrix*);
	double dot(Matrix*, Matrix*);			//Done
	double cross(Matrix*, Matrix*);
	double innerProductSpace(Matrix*);
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
	double *spanValues;
};

