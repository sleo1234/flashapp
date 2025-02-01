#include<iostream>
#include<cmath>
#include "Solver.h"
#include <vector>
#include <functional>
#include "ExpressionBuilder.h"
#include "PropertyPackage.h"
#include "FlashCalculation.h"
#include "MatrixOperations.h"
//double fun(vector<double> K, vector<double> xmol, double x){
#include <algorithm>
//return rachfordRice(K, xmol,x);
//}

using namespace std;

FlashCalculation::FlashCalculation(){


}

FlashCalculation::FlashCalculation(PropertyPackage pr){

PR=pr;

}

double FlashCalculation::calcPinit(PropertyPackage pr,vector<double> xmol, double T){

vector<double> tcr = pr.T_cr;
vector<double> pcr = pr.P_cr;


int n = tcr.size();

double Pcm=0;
double Tcm=0;

for (int i=0; i<n; i++){

Pcm = Pcm + xmol[i]*pcr[i];
Tcm = Tcm + xmol[i]*tcr[i];

}

double Pinit = 1.036*Pcm*(T/Tcm);

return Pinit;

}



double FlashCalculation::solVapFrac(vector<double> K, vector<double> xmol, double x0){

//double V0;
//double error =1e-6;
//int maxIter = 10000;




auto lambda = [](vector<double> K, vector<double> xmol,double V) -> double {return rachfordRice(K,xmol,V);};
//function<double(double)> fun = lambda;
//const function<double(double)>& fun_ref = fun;
//double vaporFrac = nRaphson(fun_ref,x0,1e-5,1000);


return 0;

}




double FlashCalculation::bubblePfun(PropertyPackage pr, double T, double press,vector<double> xmol){

int n = pr.nc;
double sum = 0.0;

vector<double> K0 = pr.calcKi(T,press);
vector<double> K(n);
vector<double> y0(n);

double vapFrac = 0.0;

vector<double> x(n);
vector<double> y(n);

vector<double> FiL(n);
vector<double> FiV(n);

double ZiL=0;
double ZiV=0;



vector<double> PiSat(n);

vector<double> sols = pr.analyticalPengRobinson(press, T, xmol); 
pr.evalPengRobinsonEq(press,T,xmol,0);

if (sols.size()>1) {

ZiL = find_min_max(sols,"min",0,sols.size()); 

ZiV = find_min_max(sols, "max",0,sols.size());  

}



else {
 ZiV = sols[0];
 ZiL = sols[0];
}

FiL = pr.calcFi(T, press, xmol, ZiL);

for (int i=0; i<n ;i++){

y0[i]=K0[i]*xmol[i];

}

FiV = pr.calcFi(T, press, y0, ZiV);


for (int i=0; i<n; i++){

K[i] = FiL[i]/FiV[i];
y[i]=xmol[i]*K[i];

sum = sum +xmol[i]*K[i]; 
}
cout<<"---------------------Results------------------------------"<<endl;

printVector(sols);
cout<<"=========================="<<endl;
printVector(FiL);
cout<<endl;
printVector(FiV);
cout<<endl;
cout<<ZiL;
cout<<endl;
cout<<ZiV;
cout<<endl;
cout<<"--------------------Results-------------------------------"<<endl;
return sum;
}


























