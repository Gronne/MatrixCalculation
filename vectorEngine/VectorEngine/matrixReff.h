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
	Matrix adjugateInvert(Matrix*);		//Need optimazation - but only for 3x3 matrixes  -edit to find the adj-matrix

	MatrixResult* result(void);			//Done
	MatrixResult* result(Matrix*);		//Done
	MatrixResult* result(Matrix*, Matrix*);	//Done

	int pivots(Matrix*);				//Done
	int pivots(void);					//Done
	int* pivotRows(Matrix*);			
	int* pivotRows(void);
	int* pivotColumns(Matrix*);
	int* pivotColumns(void);

	void copyMatrix(Matrix*);			//Done
	void printResult(MatrixResult*);	//Done

private:
	void singleStair(void);				//Done	- optimize the minimizer - add so every row under coreSize is set to 0.
	void doubleStair(void);				//Done
	void initMatrix(Matrix*);			//Done
	int pivotPrivat(void);				//Done

	void switchRow(int, int);			//Done
	double findTimer(int);				//Done
	void scaleRows(double, int);		//Done
	void minusRows(int);				//Done
	void cleanMatrix(void);				//Done


	//-------objects---------
	SimpleMatrixCalculations calc;
	MatrixResult results;
	Matrix resultMatrix;

	//------variables--------
	bool _intermediateCalculation = 0;				//can also be used for debugging
	int coreSize;
	int _lastFunctionRun = 0;			//1 - rowReduction, 2 - echelonReduction, 3 - invert, 4 - adjugateInvert
	const int typeSize = 8;
	char *matrixTypes[8] = { "(n)non", "(h)homogen", "(i)inhomogen", "(c)consistent", "(d)inconsistent", "(e)equivalent", "(t)trivial", "(u)nontrivial" };
};

