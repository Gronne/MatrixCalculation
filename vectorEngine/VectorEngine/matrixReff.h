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
	Matrix adjugateInvert(Matrix*);		//Done - but only for 3x3 matrixes
	Matrix invert(Matrix*);				//Done - but would be smart to do the upper an lower part, at the same time - and there is a buffer..

	double* result(void);				//Array of int - both in a independend matrix and a dependent matrix

	void copyMatrix(Matrix*);			//Done

private:
	void singleStair(void);				//Done	- optimize the minimizer - add so every row under coreSize is set to 0.
	void doubleStair(void);				//Done
	void initMatrix(Matrix*);			//Done

	void switchRow(int, int);			//Done
	double findTimer(int);				//Done
	void scaleRows(double, int);		//Done
	void minusRows(int);				//Done
	void cleanMatrix(void);				//Done


	//-------objects---------
	SimpleMatrixCalculations calc;
	Matrix resultMatrix;

	//------variables--------
	bool _intermediateCalculation = 0;				//can also be used for debugging
	int coreSize;
};

