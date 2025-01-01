#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H
#include <vector>
#include <stdexcept>
#include <functional>
using namespace std;

// Function prototype for matrix inversion
std::vector<std::vector<double>> invertMatrix(const std::vector<std::vector<double>>& matrix);
void printMatrix(vector<vector<double>> mat);
void printVector(vector<double> vec);
vector<double> vecTimesMat(vector<vector<double>> mat,vector<double> vec);
vector<double> vecDiff(vector<double> vec1, vector<double> vec2);
double euclidean_norm(vector<double>);
vector<vector<double>> computeJacobian(const function<vector<double>(const vector<double>&)>& equations,const vector<double>& vars, double stepSize = 1e-6);
#endif // MATRIX_OPERATIONS_H
