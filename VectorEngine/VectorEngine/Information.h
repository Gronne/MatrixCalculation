#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct Matrix
{
	double **matrix;
	int rows = 1;
	int columns = 1;
};


struct MatrixResult				//Det er m�ske godt nok at ligge ekstra funktionalitet her ind i, da de ikke skal oprettes s� ofte. (m�ske)
{
	double **result;
	int freeVariable = 1;		//Number of free variables (also the number fo columns in the array)
	int size = 1;				//Number of rows
	string type = "n";			//(n)non, (h)homogen, (i)inhomogen, (c)consistent, (d)inconsistent, (e)equivalent, (t)trivial, (u)nontrivial   - kan s�ttes i kaskade - eks. "cei" - den er consistent med en l�sning der er inhomogen
};								//T�nker at det her er et fint udgangspunkt


struct RegressionPart
{
	int type = 0;
	double crossSection = 0;
	double POW = 1;
};


struct Regression
{
	vector<RegressionPart> regression;
};

