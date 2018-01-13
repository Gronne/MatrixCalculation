#pragma once
#include "Information.h"
#include "SimpleMatrixCalculations.h"


class matrixReff
{
public:
	matrixReff(bool = 0);								//Done	
	~matrixReff();										//Done	- der er et problem med, at når der skal rref's og der er to 0 rows, men kun 1 relevant free variable, så prøver den stadig for begge

	Matrix rowReduction(const Matrix*);					//Done	- make is so it takes regards for the 0's that can occur after a column is done
	Matrix echelonReduction(const Matrix*);				//Done	
	Matrix invert(const Matrix*);						//Done	- but would be smart to do the upper an lower part, at the same time - and there is a buffer..
	Matrix adjugateInvert(const Matrix*);				//Need optimazation - but only for 3x3 matrixes  -edit to find the adj-matrix

	MatrixResult* result(void);							//Done	- optimize? - make it so it's the pivotrows instead of the last rows
	MatrixResult* result(const Matrix*);				//Done
	MatrixResult* result(const Matrix*, const Matrix*);	//Done

	int pivots(const Matrix*);							//Done
	int pivots(void);									//Done
	int* pivotRows(const Matrix*);						//Done
	int* pivotRows(void);								//Done, but wrong size?
	int* pivotColumns(const Matrix*);					//Done
	int* pivotColumns(void);							//Done, but wrong size?

	void copyMatrix(Matrix*);							//Done
	void copyResult(MatrixResult*);
	void printResult(const MatrixResult*);				//Done
	void printResult();									//Done
	void printPivotRows(const Matrix*);					//Done
	void printPivotColumns(const Matrix*);				//Done

private:
	void singleStair(void);								//Done	- optimize the minimizer - add so every row under coreSize is set to 0.
	void doubleStair(void);								//Done
	void initMatrix(const Matrix*);						//Done
	int pivotPrivat(void);								//Done

	void switchRow(int, int);							//Done
	double findTimer(int);								//Done
	void scaleRows(double, int);						//Done
	void minusRows(int);								//Done
	void cleanMatrix(void);								//Done


	//-------objects---------
	SimpleMatrixCalculations calc;
	MatrixResult results;
	Matrix resultMatrix;

	//------variables--------
	bool _intermediateCalculation = 0;					//can also be used for debugging
	int coreSize;
	int _lastFunctionRun = 0;			//1 - rowReduction, 2 - echelonReduction, 3 - invert, 4 - adjugateInvert
	int *pivotR;						//Pivot rows
	int *pivotC;						//Pivot columns

	const int typeSize = 8;
	char *matrixTypes[8] = { "(n)non", "(h)homogen", "(i)inhomogen", "(c)consistent", "(d)inconsistent", "(e)equivalent", "(t)trivial", "(u)nontrivial" };
};//Dependent - independent

