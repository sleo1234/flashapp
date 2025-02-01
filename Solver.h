#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include <stdexcept>
#include <functional>

using namespace std;

vector<double> newtonRaphson(const function<vector<double>(const vector<double>&)>& eq,
vector<double> x0, double tol);
double nRaphson(const function<double(double)>& fun, double x0, double error, int maxIter,...);
//double nRaphson(double (*fun)(vector<double>,vector<double>,double,...), double x0, double error, int maxIter,...);


#endif
