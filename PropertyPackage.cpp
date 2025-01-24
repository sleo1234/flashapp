#include <iostream>
#include "PropertyPackage.h"
#include <vector>
#include "Solver.h"

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

            K_i[i] = (P_cr[i]/press)*exp(5.37*(1+omega[i])*(1-T_cr[i]/temp));
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

vector<double> PropertyPackage::lambda_vec(){



vector<double> lamb_vec(nc);

vector<double>acc = omega;

        for (int i=0; i < nc; i++) {
            if (acc[i] < 0.5215){

              lamb_vec[i] = 0.37464 + 1.5423 * acc[i] - 0.26992 * acc[i] * acc[i];
            }

            else {
                lamb_vec[i] = 0.3796 + 1.485 * acc[i] - 0.1644 * acc[i] * acc[i] + 0.01666 * acc[i] * acc[i] * acc[i];
            }

        }
        return lamb_vec;



}



vector<double> PropertyPackage::alfa_m(double temp){
vector<double> alfa(nc);
vector<double> lambda = lambda_vec();

  for (int i=0; i < nc; i++) {
         alfa[i] = pow(1+ lambda[i] * (1 - sqrt(temp/T_cr[i])),2);
         cout<<"alfa----- "<<alfa[i]<<endl;
        }
return alfa;
}

vector<double> PropertyPackage::a_M(double temp){

   vector<double> a(nc);
        vector<double> alfa = alfa_m (temp);
        for (int i=0; i < nc; i++) {
            a[i] = 0.45724 * alfa[i] * R * R * (T_cr[i] * T_cr[i]) / P_cr[i];

        }

        return a;
}



vector<vector<double>>  PropertyPackage::getAij(double temp, double p){
double k = p/(temp*temp*R*R);
vector<double> a(nc);
vector<double> alfa = alfa_m(temp);
vector<vector<double>> Aij(nc,vector<double>(nc));

  for (int i=0; i<nc;i++){
    for (int j=0; j<nc;j++){
    
    Aij[i][j] = k * sqrt(a_M(temp)[i]*a_M(temp)[j]);
 
        }
      }

return Aij;
}





vector<vector<double>> PropertyPackage::getAi(vector<vector<double>> mat,vector<double> xmol){

int n= xmol.size();

vector<vector<double>>result(n,vector<double>(n)); 

for (int i=0; i<n; i++){


result[i] =  prodVec(xmol,mat[i]);

}

return result;

}


double PropertyPackage::alfam(double temp, vector<double> xmol){

vector<double> alfa = alfa_m(temp);

double sum=0;

for(int i=0; i<nc;i++){

   for(int j=0; j<nc;j++){

if (xmol[i]==0) {
      alfa[i]=0;
      alfa[j]=0;
        sum = sum+xmol[j]*alfa[i]*alfa[j];

   }



   }

}


return sum;
}




vector<double> PropertyPackage::b_M(){

 vector<double> b(nc);

   for (int i=0; i<nc; i++){
        b[i] = 0.077796*R*(T_cr[i]/P_cr[i]);


      }




return b;
}

double PropertyPackage::covolParam(vector<double> xmol){


double B = 0;

vector<double> bm = b_M();
double sum =0;

for (int i=0; i<nc; i++){

sum = sum + bm[i] * xmol[i];


}

B=sum;

return B;
}

double PropertyPackage::attractParam(double temp, vector<double> xmol){
double A=0.0;
vector<double> am = a_M(temp);

double sum =0;
 for (int i=0; i<nc; i++){
     for (int j=0; j<nc; j++){

   sum = sum + xmol[i]*xmol[j]*sqrt(am[i]*am[j]);


    }
  }
    
A = sum;

return A;


}

        vector<double> PropertyPackage::analyticalPengRobinson(double press, double temp, vector<double> xmol)  {
        vector<double> sols(3);
        double pi = 4*atan(1);

        double A = (attractParam (temp,xmol) * press) / (R * R * temp * temp);
        double B = (covolParam(xmol) * press) /(R * temp);

        double C2 = B-1.0;
        double C1 = (A-3*B*B-2*B);
        double C0 =(B*B*B+B*B-A*B);
        double Q1 = C2*C1/6.0-C0/2.0-(C2*C2*C2)/27.0;
        double P1 = C2*C2/9.0-C1/3.0;
        double D = Q1*Q1-P1*P1*P1;
  
        double teta = 0.0;

        if ( D >= 0.0){
            double sign1 = (Q1+sqrt(D))/(abs(Q1+sqrt(D)));
            double sign2 = (Q1-sqrt(D))/(abs(Q1-sqrt(D)));
            double sol1 =sign1*pow(abs((Q1+sqrt(D))),1.0/3.0)+sign2*pow(abs((Q1-sqrt(D))),1.0/3.0)-C2/3.0;
            sols.push_back(sol1);
            
        }

        else {


            double t1 = (Q1*Q1)/(P1*P1*P1);
            double t2 = (sqrt(1-t1))/((sqrt(t1)*(Q1/abs(Q1))));
            if (atan(t2) <0){
                teta = atan(t2)+pi;
            }
            else {
                teta = atan(t2);
            }
            double sol1 = 2*sqrt(P1)*cos(teta/3.0)-C2/3.0;
            double sol2 = 2*sqrt(P1)*cos((teta+2*pi)/3.0)-C2/3.0;
            double sol3 = 2*sqrt(P1)*cos((teta+4*pi)/3.0)-C2/3.0;
            sols.push_back(sol1);
            sols.push_back(sol2);
            sols.push_back(sol3);
        }
        return sols;
    } 


//vector<double> PropertyPackage::

//vector<double> PropertyPackage::


//vector<double> PropertyPackage::
 
//vector<double> PropertyPackage::
//




















