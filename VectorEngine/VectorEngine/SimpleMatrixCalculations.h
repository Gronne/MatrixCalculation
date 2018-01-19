#pragma once
#include "Information.h"

class SimpleMatrixCalculations
{
public:
	SimpleMatrixCalculations(bool = 0);
	~SimpleMatrixCalculations();

	void constructMatrix(Matrix*);						//Done
	void constructMatrixResult(MatrixResult*);			//Done
	void constructSpace(Space*);						//Done
	void deconstructMatrix(Matrix*);					//Done
	void deconstructMatrixResult(MatrixResult*);		//Done
	void deconstructSpace(Space*);						//Done

	void printMatrix(const Matrix*) const;				//Done
	void fillMatrix(Matrix*);							//Done

	Matrix plus(const Matrix*, const Matrix*);			//Done
	Matrix minus(const Matrix*, const Matrix*);			//Done
	Matrix multiplication(const Matrix*, const Matrix*);//Done
	Matrix hadamardProduct(Matrix*, Matrix*);			//Done

	Matrix scale(const Matrix*, double);				//Done
	Matrix transpose(const Matrix*);					//Done

	double determinant(Matrix*);						//Done

	void copyMatrix(Matrix*);							//Done
	bool mergeMatrix(Matrix*, Matrix*);					//Done
	void mergeIntoResultMatrix(Matrix*, Matrix*);		//Done


private:
	double dotAlg(Matrix*);								//Done
	void flipMatrix(Matrix *);							//Done
	double determinantPrivat(int *exclude);				//Done

	//-------objects---------
	Matrix resultMatrix;


	//------variables--------
	bool _intermediateCalculation = 0;				//can also be used for debugging
		
};

