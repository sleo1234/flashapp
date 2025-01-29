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




};

#endif
