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
<<<<<<< HEAD

}

double FlashCalculation::initial(PropertyPackage pr, double T, double press, vector<double> xmol){


int n = pr.nc;
double sum = 0.0;
double Pinit = calcPinit(pr,xmol,T); 
vector<double> K0 = pr.calcKi(T,Pinit);

cout<<"Ki0-------------------"<<endl;
printVector(K0);
cout<<endl;

vector<double> y0(n);
for(int i=0; i<n; i++) {

y0[i]=xmol[i]/K0[i];

  }
cout<<"yi0-------------------"<<endl;
printVector(y0);
cout<<endl;
vector<double> ZL = pr.analyticalPengRobinson(press,T,xmol);

vector<double> ZV = pr.analyticalPengRobinson(press,T,y0);

cout<<"ZL-------------------"<<endl;
printVector(ZL);
cout<<endl;

cout<<"ZV-------------------"<<endl;
printVector(ZV);
cout<<endl;

double ZiL = find_min_max(ZL,"min",0,ZL.size());

double ZiV = find_min_max(ZV,"max",0,ZV.size());



cout<<"ZiL-------------------"<<endl;
cout<<ZiL;
cout<<endl;

cout<<"ZiV-------------------"<<endl;
cout<<ZiV;
cout<<endl;

vector<double> FiL = pr.calcFi(T,press,xmol,ZiL);

vector<double> FiV = pr.calcFi(T,press,y0,ZiV);


cout<<"FiL-------------------"<<endl;
printVector(FiL);
cout<<endl;

cout<<"FiV-------------------"<<endl;
printVector(FiV);
cout<<endl;


vector<double> K1(n);
 for (int i=0; i<n; i++){
K1[i] = FiL[i]/FiV[i];


 }

cout<<"K1-------------------"<<endl;
printVector(K1);
cout<<endl;


for (int i=0; i<n; i++){

sum = sum+xmol[i]*K1[i];

}


cout<<"FUn val-------------------"<<endl;
cout<<sum-1;
cout<<endl;

return sum-1;
=======
>>>>>>> refs/remotes/origin/main

}




double FlashCalculation::bubblePfun(PropertyPackage pr, double T, double press,vector<double> xmol){

int n = pr.nc;
double sum = 0.0;
<<<<<<< HEAD
double Pinit = calcPinit(pr,xmol,T); 
vector<double> K0 = pr.calcKi(T,Pinit);
=======

vector<double> K0 = pr.calcKi(T,press);
>>>>>>> refs/remotes/origin/main
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
<<<<<<< HEAD
pr.evalPengRobinsonEq(press,T,xmol,0);
=======
>>>>>>> refs/remotes/origin/main

if (sols.size()>1) {

ZiL = find_min_max(sols,"min",0,sols.size()); 

ZiV = find_min_max(sols, "max",0,sols.size());  

}


<<<<<<< HEAD
=======

>>>>>>> refs/remotes/origin/main
else {
 ZiV = sols[0];
 ZiL = sols[0];
}

FiL = pr.calcFi(T, press, xmol, ZiL);

for (int i=0; i<n ;i++){

<<<<<<< HEAD
y0[i]=xmol[i]*K0[i];
=======
y0[i]=K0[i]*xmol[i];
>>>>>>> refs/remotes/origin/main

}

FiV = pr.calcFi(T, press, y0, ZiV);


for (int i=0; i<n; i++){

K[i] = FiL[i]/FiV[i];
y[i]=xmol[i]*K[i];

<<<<<<< HEAD
//sum = sum +xmol[i]*K[i]; 
}

vector<double> new_sols = pr.analyticalPengRobinson(press, T, y);

ZiV = find_min_max(new_sols,"max",0,new_sols.size());

ZiL = find_min_max(new_sols,"min",0,new_sols.size());
FiV = pr.calcFi(T,press,y,ZiV);
FiL = pr.calcFi(T,press,xmol,ZiL);

for (int i=0; i<n; i++){
K[i] = FiL[i]/FiV[i];
sum = sum +xmol[i]*K[i]; 
} 


cout<<"---------------------Results------------------------------"<<endl;

cout<<"vapor fraction "<<endl;
printVector(y);
cout<<endl;
cout<<"Fugacities liq phase============="<<endl;
printVector(FiL);
cout<<endl;
cout<<"Fugacities vap phase============="<<endl;
printVector(FiV);
cout<<endl;
cout<<"Eq. K============================"<<endl;
printVector(K);
cout<<endl;
cout<<ZiV;
cout<<endl;
cout<<"Value in bubble point "<<sum-1<<endl;
cout<<"--------------------Results-------------------------------"<<endl;
return sum-1;
}


double FlashCalculation::solveBubbleP(PropertyPackage pr, double T, double pinit, vector<double> xmol,double error,int maxIter){

double sol = 0;
int flag=-1;
double h = 0.00002;
vector<double> P(maxIter);
vector<double> der(maxIter);
vector<double> fun(maxIter);

P[0]=pinit;

for (int i=1; i<maxIter; i++){
der[i-1] = (bubblePfun(pr,T,P[i-1]+h,xmol)-bubblePfun(pr,T,P[i-1]-h,xmol))/(2*h); 
fun[i-1] = bubblePfun(pr,T,P[i-1],xmol);

;
cout<<" derivative: "<<der[i-1]<<endl;
cout<<" act. value: "<<fun[i-1]<<endl;

P[i] =  P[i-1] - fun[i-1]/der[i-1];
cout<<"Pressure at "<<i<<"th iteration "<<P[i]<<endl;
 if (abs(P[i]-P[i-1])<= error ){

sol = P[i];
flag=1;
cout<<"Bubble pressure "<<sol<<" MPa(a) found after "<<i<<" iterations"<<endl;
}

if (flag>0) break;
}

if (flag<0) {

cout<<"Solution not found."<<endl;
}




return sol;
=======
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
>>>>>>> refs/remotes/origin/main
}





<<<<<<< HEAD
double FlashCalculation::bisect(PropertyPackage pr, double a, double b, double T, vector<double> xmol,double error, int maxIter){


double sol =0;

int flag =0;

int iter =0;

int n = pr.nc;
double sum = 0.0;
double Pinit = calcPinit(pr,xmol,T); 
vector<double> K0 = pr.calcKi(T,Pinit);
vector<double> K(n);



if ( bubblePfun(pr,T,a,xmol) *  bubblePfun(pr,T,b,xmol) >0 ){

cout<<"Choose a and b such f(a) * f(b) negative";
flag=-1;
}

while (iter < maxIter){

if (flag<0){
cout<<"Solution was not found"<<endl;

}

sol=(a+b)/2;




if (bubblePfun(pr, T, sol,xmol) == 0 && (b-a)/2<error){


return sol;

}
iter++;


if (bubblePfun(pr, T,sol,xmol) *  bubblePfun(pr, T,a,xmol)>0){


a=sol;
cout<<"Solution "<<sol<<" found after "<<iter<<" iterations"<<endl;

}
 else{

b=sol;


 } 

}
return sol;
}



//function
=======




>>>>>>> refs/remotes/origin/main

















