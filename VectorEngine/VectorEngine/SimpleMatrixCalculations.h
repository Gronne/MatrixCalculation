#pragma once
#include "Information.h"

class SimpleMatrixCalculations
{
public:
	SimpleMatrixCalculations(bool = 0);
	~SimpleMatrixCalculations();

	void constructMatrix(Matrix*);
	void deconstructMatrix(Matrix*);

	void printMatrix(Matrix*);
	void fillMatrix(Matrix*);

	Matrix plus(Matrix*, Matrix*);
	Matrix minus(Matrix*, Matrix*);
	Matrix multiplication(Matrix*, Matrix*);

	Matrix scale(Matrix*, double);
	Matrix transpose(Matrix*);

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

