#pragma once
#include "Information.h"
#include "SimpleMatrixCalculations.h"


class matrixReff
{
public:
	matrixReff(bool = 0);				//Done
	~matrixReff();						//Done

	Matrix rowReduction(Matrix*);		//Done
	Matrix echelonReduction(Matrix*);	//Done
	Matrix invert(Matrix*);

	double* result(void);	//Array of int - both in a independend matrix and a dependent matrix

	void copyMatrix(Matrix*);			//Done

private:
	void singleStair(void);
	void doubleStair(void);
	void initMatrix(Matrix*);			//Done

	void switchRow(int, int);


	//-------objects---------
	SimpleMatrixCalculations calc;
	Matrix resultMatrix;

	//------variables--------
	bool _intermediateCalculation = 0;				//can also be used for debugging
	int coreSize;
};

