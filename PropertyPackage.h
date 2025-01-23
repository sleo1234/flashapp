#ifndef PROPERTYPACKAGE_H
#define PROPERTYPACKAGE_H
#include <vector>
#include <cmath>
#include <functional>
#include "MatrixOperations.h"

using namespace std;


class PropertyPackage {

double R=8.31;

public:
 int nc;
 vector<double> omega;
 vector<double> T_cr;
 vector<double> P_cr;
 vector<double> x_mol;

public:
 PropertyPackage();
 PropertyPackage(int nc, vector<double> omega,vector<double> T_cr, vector<double> P_cr, vector<double> x_mol);
 
 vector<double> calcKi (double temp, double press); 
 vector<double> calcPi_sat(double temp); 
 vector<double> calcPi( vector<double> A,  vector<double> B, vector<double> C, double T); 
 vector<double> a_M(double temp);
 vector<double> lambda_vec();
 vector<double> alfa_m(double temp);
 vector<vector<double>> getAij(double temp, double p);
 
};



#endif
