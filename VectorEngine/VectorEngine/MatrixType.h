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
	Matrix* span(Matrix*);					//Done
	double* span(Matrix*, Matrix*);			//Done
	bool checkSpan(Matrix*, Matrix*);		//Done - need test
	bool orthogonal(Matrix*, Matrix*);		//Done
	bool orthogonal(Matrix*);				//Done
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

