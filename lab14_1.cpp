#include <iostream>
#include <cmath>
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
void stat(const double A[],int N,double B[]){
    double sum = 0,sumz =0,max = A[0],min = A[N-1],sumofmulti=A[0],sumofdivide=0;
    for(int i =0;i<N;i++){
        sum += A[i];
    }
    double mean = sum/N;
    for(int i =0;i<N;i++){
        sumz += pow(A[i]-mean,2);
    }
    double SD = sqrt(sumz/N);
    for(int i=1;i<N;i++){
        sumofmulti *= A[i];
    }
    double GM = pow(sumofmulti,1.0/N);
    for(int i=0;i<N;i++){
        sumofdivide += (1.0/A[i]);
    }
    double HM = N/sumofdivide;
    for(int i=1;i<N;i++){
        if(max<A[i]){
            max = A[i];
        }
    }
    for(int i=1;i<N;i++){
        if(min>A[i]){
            min = A[i];
        }
    }
    
    B[0] = mean;
    B[1] = SD;
    B[2] = GM;
    B[3] = HM;
    B[4] = max;
    B[5] = min;
}
