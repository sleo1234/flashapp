#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include <stdexcept>
#include <functional>

using namespace std;

vector<double> newtonRaphson(const function<vector<double>(const vector<double>&)>& eq,
vector<double> x0, double tol);


#endif
