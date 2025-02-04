#ifndef FLASHCALCULATION_H
#define FLASHCALCULATION_H
#include <vector>
#include <functional>
#include "PropertyPackage.h"

using namespace std;
class FlashCalculation {

public:
 PropertyPackage PR;

public:
 FlashCalculation();
 FlashCalculation(PropertyPackage pr);

double solVapFrac(vector<double> K, vector<double> xmol,double x0);
double calcPinit(PropertyPackage pr, vector<double> xmol, double T);
double bubblePfun(PropertyPackage pr, double T, double press, vector<double> xmol);
double solveBubbleP(PropertyPackage pr, double T, double pinit, vector<double> xmol,double error,int maxIter);
double initial(PropertyPackage pr, double T, double press, vector<double> xmol);
double bisect(PropertyPackage pr, double a, double T,  double b, vector<double> xmol, double error, int maxIter);
};

#endif
