#include <iostream>
#include <iomanip>
#include "MatrixOperations.h"
#include "Solver.h"
using namespace std;
vector<double> sys(const vector<double>& vars){
 
 double x1 = vars[0];
 double x2 = vars[1];
 double x3 = vars[2];
// double x4 = vars[3];
 //double x5 = vars[4];

// double x3 = vars[2];
                           
vector <double> system = {x1+0.5*x2+x3-1.3,  
                          3*x1+2.54*x2-2.98*x3,
                          2.43*x1-3*x2+x3*0.98+0.98,
                          x1+2*x2+x3-9.5};

 return system;
 
}
int main() {
    // Example input matrix
    std::vector<std::vector<double>> matrix = {
        {4, 7},
        {2, 6}
    };
//vector<double> vec = {1,2};    
//vector<double> result = vecTimesMat(matrix,vec);
vector<double> x0 {0.1,0.1,0.5};

newtonRaphson(sys,x0,1e-4);

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
