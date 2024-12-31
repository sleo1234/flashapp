#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H
#include <vector>
#include <stdexcept>
using namespace std;

// Function prototype for matrix inversion
std::vector<std::vector<double>> invertMatrix(const std::vector<std::vector<double>>& matrix);
void printMatrix(vector<vector<double>> mat);
void printVector(vector<double> vec);
vector<double> vecTimesMat(vector<vector<double>> mat,vector<double> vec);

#endif // MATRIX_OPERATIONS_H
