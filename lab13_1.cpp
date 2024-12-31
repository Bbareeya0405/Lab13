#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double A[],int N,double B[]){
    B[0] = accumulate(A, A + N, 0.0) / N;
    B[1] = sqrt(inner_product(A, A + N, A, 0.0) / N - B[0] * B[0]);
    
    double product = 1.0;
    
    for (int i = 0; i < N; ++i) product *= A[i];
    B[2] = pow(product, 1.0 / N);
    B[3] = N / accumulate(A, A + N, 0.0, [](double acc, double x) { return acc + 1.0 / x; });
    B[4] = *max_element(A, A + N);
    B[5] = *min_element(A, A + N);
}