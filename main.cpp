#include <iostream>
#include <iomanip>
#include "MatrixOperations.h"
#include "Solver.h"
#include <cmath>
#include "PropertyPackage.h"
#include "ExpressionBuilder.h"
#include "FlashCalculation.h"
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


vector<double> systemEq(const vector<double>& vars){
 
 double x1 = vars[0];
 
vector<double> T_cr={369.8,425.2,469.7};
vector<double> P_cr={4.25,3.8,3.37};
vector<double> xmol={0.5,0.25,0.25};
vector<double> omega={0.153,0.199,0.255};
 
int nc = T_cr.size();
double T =400;
double press = 1.5;

PropertyPackage pr(nc,omega,T_cr,P_cr,xmol);
pr.nc=nc;
pr.T_cr=T_cr;
pr.P_cr=P_cr;
pr.omega=omega;
pr.x_mol=xmol;
vector<double> K = pr.calcKi(T,press);

//double result= pr.evalPengRobinsonEq(press,T,xmol,x1);
double result = rachfordRice(K,xmol,0.5);
                           
vector <double> system = {
result
};

 return system;
 
}


double eq(double x){


vector<double> T_cr={369.8,425.2,469.7};
vector<double> P_cr={4.25,3.8,3.37};
vector<double> xmol={0.5,0.25,0.25};
vector<double> omega={0.153,0.199,0.255};
 
int nc = T_cr.size();
double T =400;
double press = 1.5;

PropertyPackage pr(nc,omega,T_cr,P_cr,xmol);
pr.nc=nc;
pr.T_cr=T_cr;
pr.P_cr=P_cr;
pr.omega=omega;
pr.x_mol=xmol;
vector<double> K = pr.calcKi(T,press);

//double result= pr.evalPengRobinsonEq(press,T,xmol,x1);
double result = rachfordRice(K,xmol,x);


return result;

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

vector<double> T_cr={369.8,425.2,469.7};
vector<double> P_cr={4.25,3.8,3.37};
vector<double> xmol={0.5,0.25,0.25};
vector<double> omega={0.153,0.199,0.255};
 
int nc = T_cr.size();
double T =400;
double press = 1.5;

PropertyPackage pr(nc,omega,T_cr,P_cr,xmol);
pr.nc=nc;
pr.T_cr=T_cr;
pr.P_cr=P_cr;
pr.omega=omega;
pr.x_mol=xmol;
vector<double> Ki = pr.calcKi(T,press);
//vector<double> result2 = pr.calcPi_sat(400);
//vector<double> result3 = pr.calcPi(A,B,C,400);

vector<double> sols = pr.solvePengRobinsonEq(T,press,xmol);
cout<<"solutions"<<endl;
printVector(sols);
cout<<"end of sols"<<endl;










vector<double> testRemoveAtIndexI ={1,2,3,4,5};

vector<double> resultTest = removeAtIndex(testRemoveAtIndexI,2);
cout<<"------------- here  ---------"<<endl;
printVector(Ki);
double value = rachfordRice(Ki,xmol,0.5);
cout<<"=========0 "<<value<<endl;
//printVector(result3);

//printVector(P_cr);
//vector<double> vec = {1,2};    
//vector<double> result = vecTimesMat(matrix,vec);
//vector<double> x0 {0.1,0.1,0.10,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
//printVector(sys(x0));
double x0 = 0.5;
double solution = nRaphson(eq,x0,1e-4,1000);
cout<<"solution "<<solution<<endl;
//printVector(pr.calcFi(T,press,xmol,0.5));

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
