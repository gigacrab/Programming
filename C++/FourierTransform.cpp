#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <string>

using namespace std;

typedef complex<double> Complex;
typedef vector<Complex> cVector;
typedef struct{
    double ampl;
    double freq;
    double phase;
}Signal;

double roundDp(double n, int dp = 0){
    return round(n * pow(10, dp)) / pow(10, dp);
}
double pi = M_PI;

void dft(cVector vect, cVector& fBin, int N){
    Complex sum;
    double angle;
    double phase;
    for(int a = 0; a < N; a++){
        sum = Complex(0, 0);
        for(int i = 0; i < N; i++){
            angle = -2*pi*a*i/N;
            sum += vect[i]*Complex(cos(angle), sin(angle));
        }
        fBin[a] = sum;
        phase = arg(sum);
        sum.real(roundDp(sum.real(), 4));
        sum.imag(roundDp(sum.imag(), 4));
        cout << "X[" << a << "] = " << sum << ", Magnitude = " << abs(sum) << ", Argument = " << roundDp(phase, 4) << "\n";
    }
}

void idft(cVector fBin, int N){
    Complex sum;
    double angle;
    for(int a = 0; a < N; a++){
        sum = Complex(0, 0);
        for(int i = 0; i < N; i++){
            angle = 2*pi*a*i/N;
            sum += fBin[i]*Complex(cos(angle)/N, sin(angle)/N);
        }
        sum.real(roundDp(sum.real(), 4));
        sum.imag(roundDp(sum.imag(), 4));
        cout << "X[" << a << "] = " << sum << "\n";
    }
}

void origin(cVector fBin, int N){
    int nyquist = N/2.0 > N/2? N/2 + 1: N/2;
    vector<Signal> signal; 
    double freq, mag, phase;
    for(int i = 0; i < fBin.size(); i++){
        freq = i>nyquist? i-N : i;
        mag = roundDp(abs(fBin[i])/N, 4);
        phase = roundDp(arg(fBin[i]), 4);
        if(mag != 0){
            signal.push_back({mag, freq, phase});
        }
    }
    for(int i = 0; i < signal.size(); i++){
        cout << "+ " << signal[i].ampl << "cos(" << signal[i].freq << "x+" << signal[i].phase << ")\n";
    }
}

int main(){
    int N;
    cout << "Welcome to the *Ultimate* DFT Calculator!!!!!!!!!!!!!!!!\n";
    cout << "Enter your number of samples: ";
    cin >> N;
    double reTemp;
    double imTemp;
    Complex cmplxTemp;
    cVector vect(N);
    cVector fBin(N);

    for(int i = 0; i < N; i++){
        cout << "\nReal part of " << i+1 << "th sample: ";
        cin >> reTemp;
        cout << "Imaginary part of " << i+1 << "th sample: ";
        cin >> imTemp;
        cmplxTemp.real(reTemp);
        cmplxTemp.imag(imTemp);
        vect[i] = cmplxTemp;
    }
    cout << "\nUsing DFT: \n";
    dft(vect, fBin, N);
    cout << "Using IDFT: \n";
    idft(fBin, N);
    cout << "Original Function: \n";
    origin(fBin, N);
}