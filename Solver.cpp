#include <cmath>
#include <iostream>
#include <iomanip>
#include <functional>
#include "MatrixOperations.h"


using namespace std;

vector<double> newtonRaphson(const function<vector<double>(const vector<double>&)>& eq,
vector<double> x0, double tol) {

int numVars = x0.size();
int maxIter = 100;
int iter = 0;
int flag=0;


vector<double> sol(numVars);
vector<double> F(numVars);
vector<double> diff(numVars);

vector<vector<double>> x(maxIter,vector<double>(numVars));

x[0] =x0;

 for (int i=1; i < maxIter; i++){
//printMatrix(computeJacobian(eq,x[i-1]));


x[i]=vecDiff(x[i-1] , vecTimesMat(invertMatrix(computeJacobian(eq,x[i-1])),eq(x[i-1]))); 

cout<<"Solution "<<endl;

printVector(x[i]);
cout<<" at "<<i<<" iteration "<<endl;

if (euclidean_norm(vecDiff(x[i],x[i-1]))<= tol){
 sol = x[i];
 flag = 1;

}

 if (flag>0) break;

 }
if (flag == -1) {

cout<<"Solution not found"<<endl;
}
return sol;

}


