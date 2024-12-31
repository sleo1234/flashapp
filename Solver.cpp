#include "MatrixOperations.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <functional>

using namespace std;


vector<double> newtonRaphson(const function<vector<double>(const vector<double>&)>& eq,
const vector<double>& x0, double tol
) {

int numVars = x0.size();
int maxIter = 100;
int iter = 0;


vector<double> sol(numVars);
vector<double> F(numVars);

 for (int i=0; i<numVars; i++){





 }


return sol;

}
