#pragma once
#include "Information.h"

class SimpleMatrixCalculations
{
public:
	SimpleMatrixCalculations(bool = 0);
	~SimpleMatrixCalculations();

	void constructMatrix(Matrix*);
	void constructMatrixResult(MatrixResult*);
	void deconstructMatrix(Matrix*);
	void deconstructMatrixResult(MatrixResult*);

	void printMatrix(const Matrix*) const;			//Overload, so if not anything else have been specified, print resultmatrix
	void fillMatrix(Matrix*);

	Matrix plus(const Matrix*, const Matrix*);
	Matrix minus(const Matrix*, const Matrix*);
	Matrix multiplication(const Matrix*, const Matrix*);

	Matrix scale(const Matrix*, double);
	Matrix transpose(const Matrix*);

	double determinant(Matrix*);

	void copyMatrix(Matrix*);


private:
	double dotAlg(Matrix*);
	void flipMatrix(Matrix *);
	double determinantPrivat(int *exclude);

	//-------objects---------
	Matrix resultMatrix;


	//------variables--------
	bool _intermediateCalculation = 0;				//can also be used for debugging
		
};

