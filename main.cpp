#include <iostream>
#include <iomanip>
#include "MatrixOperations.h"
using namespace std;

int main() {
    // Example input matrix
    std::vector<std::vector<double>> matrix = {
        {4, 7},
        {2, 6}
    };
vector<double> vec = {1,2};    
vector<double> result = vecTimesMat(matrix,vec);

    try {
          
        // printMatrix(matrix);
         printVector(result);

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
