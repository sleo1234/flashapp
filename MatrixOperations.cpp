#include "MatrixOperations.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <functional>
const double EPSILON = 1e-9; // Threshold for considering values as zero
using namespace std;

void printMatrix(vector<vector<double>> mat) {

 for(const auto& row : mat) {
   for (double val : row) {
         cout<<setw(10)<<setprecision(6)<<val<< " ";
     
  }  
   cout<< endl;
 }

}

void printVector(vector<double> vec){


for (int i=0; i< vec.size(); i++){

    cout<<setw(10)<<setprecision(6)<<vec[i]<< " ";
 }


}


vector<double> vecDiff(vector<double> vec1, vector<double> vec2){

int n1 = vec1.size();
int n2 = vec2.size();

vector<double> result(n1);

for (int i=0; i<n1; i++){

result[i]= vec1[i]-vec2[i];

}

return result;

}

double euclidean_norm(vector<double> vec){
double sum = 0.0;

for (int i=0; i<vec.size(); i++){


sum = sum+vec[i]*vec[i];

}



return sqrt(sum);
}




vector<double> vecTimesMat(vector<vector<double>> mat, vector<double> vec){

int v_size = vec.size();
vector<double> result(v_size);

  for (int i=0; i < v_size; i++) {
    for (int j=0; j< mat[i].size(); j++){
      result[i] += mat[i][j]*vec[j];
     }

  }


return result; 


}

vector<double> prodVec(vector<double> vec1, vector<double>vec2){

int n = vec1.size();

vector<double> result (n);

for (int i=0; i<n; i++){

    result[i] = vec1[i]*vec2[i];
  }

return result;
}



std::vector<std::vector<double>> invertMatrix(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    std::vector<std::vector<double>> augmentedMatrix(n, std::vector<double>(2 * n, 0.0));

    // Create the augmented matrix by appending the identity matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmentedMatrix[i][j] = matrix[i][j];
        }
        augmentedMatrix[i][n + i] = 1.0;
    }

    // Perform Gaussian elimination
    for (int i = 0; i < n; ++i) {
        // Find the pivot
        int pivotRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::fabs(augmentedMatrix[j][i]) > std::fabs(augmentedMatrix[pivotRow][i])) {
                pivotRow = j;
            }
        }

        // Swap rows if necessary
        if (std::fabs(augmentedMatrix[pivotRow][i]) < EPSILON) {
            throw std::runtime_error("Matrix is singular and cannot be inverted.");
        }
        std::swap(augmentedMatrix[i], augmentedMatrix[pivotRow]);

        // Normalize the pivot row
        double pivotValue = augmentedMatrix[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            augmentedMatrix[i][j] /= pivotValue;
        }

        // Eliminate the current column in other rows
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double factor = augmentedMatrix[j][i];
                for (int k = 0; k < 2 * n; ++k) {
                    augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    std::vector<std::vector<double>> inverseMatrix(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverseMatrix[i][j] = augmentedMatrix[i][n + j];
        }
    }

    return inverseMatrix;
}


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
