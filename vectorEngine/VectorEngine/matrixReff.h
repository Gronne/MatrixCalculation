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
	Matrix invert(Matrix*);				//Done - but would be smart to do the upper an lower part, at the same time - and there is a buffer..
	Matrix adjugateInvert(Matrix*);		//Done - but only for 3x3 matrixes

	double* result(void);				//Array of int - both in a independend matrix and a dependent matrix
	double* result(Matrix*, bool = 0);			//The matrix that need to be solved
	double* result(Matrix*, Matrix*);	//The 'A' matrix and the 'B' matrix, need to be set together

	int pivots(Matrix*);
	int pivots(void);
	int* pivotRows(Matrix*);
	int* pivotRows(void);

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
	int _lastFunctionRun = 0;			//1 - rowReduction, 2 - echelonReduction, 3 - invert, 4 - adjugateInvert
};

