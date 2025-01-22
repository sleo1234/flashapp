#include <iostream>
#include <iomanip>
#include "MatrixOperations.h"
#include "Solver.h"
#include <cmath>
#include "PropertyPackage.h"
using namespace std;
vector<double> sys(const vector<double>& vars){
 
 double x1 = vars[0];
 //double x2 = vars[1];

 //double x3 = vars[2];
 //double x4 = vars[3];
 //double x5 = vars[4];

 //double x6 = vars[5];
 //double x7 = vars[6];
 //double x8 = vars[7];

 //double x9 = vars[8];
// double x10 = vars[9];
// double x4 = vars[3];
 //double x5 = vars[4];

// double x3 = vars[2];
                           
vector <double> system = {
x1*x1*x1+3*x1*x1-4*x1+0.98
};

 return system;
 
}
int main() {
    // Example input matrix

    std::vector<std::vector<double>> matrix = {
        {4, 7},
        {2, 6}
    };
vector<double> A={15.726,1872.46,-25.16};//propane
vector<double> B={15.678,2154.9,-34.42};//butane
vector<double> C={15.883,2477.07,-39.94};//pentane

PropertyPackage pr(3,{0.152, 0.193,0.251},{400.3,390.5,234.0},{1.3,2.4,4.3},{0.4,0.2,0.4});
pr.nc=3;
pr.T_cr={369.8,425.2,469.7};
pr.P_cr={1,2,3};
pr.omega={0.152, 0.193,0.251};
pr.x_mol={0.4,0.2,0.4};
vector<double> result = pr.calcKi(400,0.4);
vector<double> result2 = pr.calcPi_sat(400);
vector<double> result3 = pr.calcPi(A,B,C,400);

printVector(result3);

//printVector(P_cr);
//vector<double> vec = {1,2};    
//vector<double> result = vecTimesMat(matrix,vec);
//vector<double> x0 {0.1,0.1,0.10,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
//printVector(sys(x0));
vector<double> x0 = {1};
newtonRaphson(sys,x0,1e-8);

    try {
          
        // printMatrix(matrix);
        // printVector(result);

        // Call the invertMatrix function
       // std::vector<std::vector<double>> inverseMatrix = invertMatrix(matrix);

        // Output the inverse matrix
       // std::cout << "Inverse matrix:" << std::endl;
        //for (const auto& row : inverseMatrix) {
          //  for (double val : row) {
            //    std::cout << std::setw(10) << std::setprecision(6) << val << " ";
         //   }
            //std::cout << std::endl;
        }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
