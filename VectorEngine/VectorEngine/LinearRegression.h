#pragma once
#pragma once
#include "Information.h"
#include "SimpleMatrixCalculations.h"
#include "matrixReff.h"
#include "MatrixType.h"
#include "vector"

using namespace std;

class LinearRegression
{
public:
	LinearRegression(bool = 0);
	~LinearRegression();

	Regression* findStandardRegression(Matrix*, Regression*);
	Regression* findBestRegression(Matrix*, int = 1, int = 1);					//Will this one return the prototype or the hole regression?
	double precision(Matrix*, Regression*);						//Hvor godt regressionen passer på matrix datasættet
	void copyRegression(Regression*);							//Will copy the found regression.
	void printRegression(Regression*);


private:
	void findRegression(Regression*);
	Regression* findDominantRegression(Matrix*, Regression*);
	Regression* getRegressionFromCoordinates(Matrix*, Regression*);
	double regressionPredicsion(Matrix*, Regression*);
	void sortRegressionData(void);
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

