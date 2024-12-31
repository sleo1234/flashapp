#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

vector<vector<double>> computeJacobian(const function<vector<double>(const vector<double>&)>& equations,
const vector<double>& vars,
double stepSize = 1e-6) {


int numEquations = equations(vars).size();
int numVariables = vars.size();

vector<vector<double>> jacobian (numEquations, vector<double>(numVariables,0.0));

for (int j=0; j< numVariables; ++j){


vector<double> perturbedVars = vars;
perturbedVars[j] += stepSize;

vector<double> fPlus = equations(perturbedVars);
vector<double> fOriginal = equations(vars);

for (int i=0; i< numEquations; ++i){

jacobian[i][j] = (fPlus[i]-fOriginal[i])/stepSize;

  }

}

return jacobian;

}



vector<double> sys(const vector<double>& vars){

double x1 = vars[0];
double x2 = vars[1];
double x3 = vars[2];

return {x1*x1+x2*x2+x3, 

x1+x2*x3+x2,

x1*x2*x3-x2};



}


int main() {

vector<double> vars={1.0,2.0,1.0};

vector<vector<double>> jacobian = computeJacobian(sys, vars);


cout<<" Jacobian matrix: "<<endl;

for (const auto& row : jacobian){

  for(double val : row){
      cout<<val<<" ";

    }

cout<<endl;


}



return 0;
}






























