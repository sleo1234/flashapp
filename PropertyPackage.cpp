#include <iostream>
#include "PropertyPackage.h"
#include <vector>


double R=8.31;



PropertyPackage::PropertyPackage(){


}

PropertyPackage::PropertyPackage(int Nc, vector<double> acc, vector<double> Tcr, vector<double> Pcr, vector<double> xmol){
nc=Nc;
omega=acc;
T_cr=Tcr;
P_cr=Pcr;
x_mol=xmol;


}

vector<double> PropertyPackage::calcKi (double temp, double press) {
        vector<double> K_i(nc);
           cout<<"hereeee"<<endl;
                
        for (int i=0; i < nc; i++) {

            K_i[i] = (P_cr[i]/press)*exp(5.37*(1+omega[i])*(1- T_cr[i]/temp));
              cout<<P_cr[i]<<endl;
        }
   return K_i;
    }

vector<double> PropertyPackage::calcPi_sat (double temp){

vector<double> P_i(nc);

for (int i=0; i < nc; i++) {

  P_i[i] = exp(log(P_cr[i])+(7.0/3.0)*log(10.0)*(1+omega[i])*(1-T_cr[i]/temp));
 


}


return P_i;


}

//Antoine equation for vapor pressure 
vector<double> PropertyPackage::calcPi(vector<double> A,vector<double> B,vector<double> C, double temp){
        vector<double> Pi (nc);

        for (int i=0; i < nc; i++) {
            Pi[i] = exp(A[i]-B[i]/(temp+C[i]))/7600.0;
        }
        return Pi;
}






























