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

