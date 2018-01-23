#pragma once
#pragma once
#include "Information.h"
#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"
#include "MatrixType.h"
#include <math.h>

using namespace std;

class LinearRegression
{
public:
	LinearRegression(bool = 0);
	~LinearRegression();

	Regression* findStandardRegression(Matrix*, Regression*);			//Done - need testing
	Regression* findBestRegression(Matrix*, int = 1, int = 1);			//
	void precision(Matrix*, Regression*);								//Done - need testing
	void copyRegression(Regression*);										//Will I need this one?
	void printRegression(Regression*);									//Done - need testing
	void addRegressionPart(Regression*, RegressionPart);				//Done - need testing
	double valueAtCoordinate(Matrix*, Regression*, int);


private:
	void findRegression(Regression*);
	Regression* findDominantRegression(Matrix*, Regression*);
	Regression* getRegressionFromCoordinates(Matrix*, Regression*);
	double regressionPredicsion(Matrix*, Regression*, int);				//Done - need testing
	void createLeftSide(Matrix*, Regression*);
	void createRightSide(Matrix*, Regression*);


	//-------objects---------
	SimpleMatrixCalculations calc;
	matrixReff rref;
	MatrixResult results;
	MatrixType type;
	Matrix resultMatrix;
	Regression _regression;

	//------variables--------
	bool _intermediateCalculation = 0;					//can also be used for debugging
};

