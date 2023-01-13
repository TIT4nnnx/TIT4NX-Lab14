#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int N , double B[]){

    double n = N;
    double sum = 0;
    double sumx2 = 0;
    double powx = 1;
    double divid = 0;
    double MAX = A[0];
    double MIN = A[0];

    for( int i=0; i<N ; i++){
        sum += A[i];
        sumx2 += pow(A[i], 2);
        powx = powx*A[i];
        divid += 1/A[i];
        if (A[i] < MIN) {
            MIN = A[i];
        }
        else if (A[i] > MAX) {
            MAX = A[i];
        }
    }
  
    double mean = sum/n;
    double SD = sqrt((sumx2/n) - pow(mean, 2));
    double GM = pow(powx, 1/n);
    double HM = n/divid;

    B[0]=mean;
    B[1]=SD;
    B[2]=GM;
    B[3]=HM;
    B[4]=MAX;
    B[5]=MIN;
}
