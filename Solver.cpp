#include <cmath>
#include <iostream>
#include <iomanip>
#include <functional>
#include "MatrixOperations.h"
using namespace std;


vector<double> newtonRaphson(const function<vector<double>(const vector<double>&)>& eq, double tol
,vector<double> x0) {

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
cout<<" at "<<i<<"iteration ";

if (euclidean_norm(vecDiff(x[i],x[i-1]))<= tol){
 sol = x[i];
 flag = 1;

}

 if (flag>0) break;

 }

printVector(sol);
return sol;

}

vector<double> sys(const vector<double>& vars){
 
 double x1 = vars[0];
 double x2 = vars[1];
// double x3 = vars[2];
 
 return {x1+2*x2-5,  
        x1+x2+2};

 
}


int main(){

vector<double> x0 = {1.0,0.5};
double tol=1e-4;

newtonRaphson(sys,tol,x0);
return 0;
}
