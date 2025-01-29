#include<iostream>
#include<cmath>
#include "Solver.h"
#include <vector>
#include <functional>
#include "ExpressionBuilder.h"
#include "PropertyPackage.h"
#include "FlashCalculation.h"
//double fun(vector<double> K, vector<double> xmol, double x){



//return rachfordRice(K, xmol,x);
//}



FlashCalculation::FlashCalculation(){


}

FlashCalculation::FlashCalculation(PropertyPackage pr){

PR=pr;

}

double FlashCalculation::solVapFrac(vector<double> K, vector<double> xmol, double x0){

//double V0;
//double error =1e-6;
//int maxIter = 10000;
///auto fun  f=(K,xmol
K=PR.calcKi(430,2.8);


auto fun = [](vector<double> K, vector<double> xmol, double V) -> double {return rachfordRice(K,xmol,V);};
double vaporFrac = nRaphson(fun,x0,1e-5,1000);


return vaporFrac;

}




