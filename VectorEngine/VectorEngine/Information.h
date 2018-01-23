#pragma once
#include <vector>
#include <iostream>
//#include <bitset>

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
	int type = 1;				
	double A = 1;		
	double B = 1;
	string variables = "10"; //It need to be as long as the leftside in 'regression'	- the first one is the first x
	//bitset<16> variables{ 0100010010010011 };
};								

//Type:
//1. A*X^B
//2. A*exp(X*B)
//3. A*sin(X*B)
//4. A*log2(X*B)

struct Regression
{
	vector<RegressionPart> regression;		//Leftside is just the size of the regression vector
	string rightSide = "01";				//Rightside can't be variables multiplicated, but it can have variables from different rows, and not just the last ones
};											//The size of the string must be the same length as the dataSet


struct Space
{
	int variables = 1;
	int sets = 1;
	RegressionPart **spaces;
};