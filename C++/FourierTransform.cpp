#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <string>

using namespace std;

typedef complex<double> Complex;
typedef vector<Complex> cVector;

double roundDp(double n, int dp = 0){
    return round(n * pow(10, dp)) / pow(10, dp);
}

int main(){
    int N;
    cout << "Welcome to the *Ultimate* DFT Calculator!!!!!!!!!!!!!!!!\n";
    cout << "Enter your number of samples: ";
    cin >> N;
    double reTemp;
    double imTemp;
    double angle;
    Complex cmplxTemp;
    cVector vect(N);
    Complex sum;
    cVector fBin(N);

    for(int i = 0; i < N; i++){
        cout << "Real part of " << i << "th sample: ";
        cin >> reTemp;
        cout << "Imaginary part of " << "th sample: ";
        cin >> imTemp;
        cmplxTemp.real(reTemp);
        cmplxTemp.imag(imTemp);
        vect[i] = cmplxTemp;
    }

    for(int a = 0; a < N; a++){
        sum = Complex(0, 0);
        for(int i = 0; i < N; i++){
            angle = -2*M_PI*a*i/N;
            sum += vect[i]*Complex(cos(angle), sin(angle));
        }
        sum.real(roundDp(sum.real(), 3));
        sum.imag(roundDp(sum.imag(), 3));
        cout << "X[" << a << "] = " << sum << ", Magnitude = " << abs(sum) << ", Argument = " << arg(sum) << "\n";
        fBin[a] = sum;
    }
}