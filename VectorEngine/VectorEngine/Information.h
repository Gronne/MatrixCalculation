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


struct MatrixResult				//Det er måske godt nok at ligge ekstra funktionalitet her ind i, da de ikke skal oprettes så ofte. (måske)
{
	double **result;
	int freeVariable = 1;		//Number of free variables (also the number fo columns in the array)
	int size = 1;				//Number of rows
	string type = "n";			
};		


struct RegressionPart
{
	int type = 0;
	double constant = 1;		//Or crossSection?
	double POW = 1;
};


struct Regression
{
	vector<RegressionPart> regression;
};


struct Space
{
	int variables = 1;
	int sets = 1;
	RegressionPart **spaces;
};