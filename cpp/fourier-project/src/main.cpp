#include "matplotlibcpp.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>
#include <string>
#include <eigen3/Eigen/Dense>

typedef std::complex<double> Complex;
typedef std::vector<Complex> cVector;
typedef struct {
    double ampl = 0;
    double freq = 0;
    double phase = 0;
}Signal;    
typedef struct {
    double xmax;
    double xmin;
    double ymax;
    double ymin;
}Limit;

std::vector<double> toDoubleVector(const Eigen::VectorXd& x);
std::vector<std::string> toStringVector(const Eigen::VectorXd& x);
void dft(cVector& vec, bool invert);
std::vector<Signal> originalFunc(cVector fBin);
void getInfo(cVector& vec);
void calcGraph(std::vector<Signal> sig, Eigen::VectorXd& x, Eigen::VectorXd& y, Limit lim, std::vector<double>& yLim);
void fft(cVector& vec, bool invert);
double roundDp(double n, int dp);
std::pair<std::vector<double>, std::vector<double>> calcFreq(cVector vec, std::vector<double>& yLim);
void logResult(cVector vec);
void plotGraph(Limit lim, std::vector<double> xStd, std::vector<double> yStd, std::vector<double> yLim, std::string title, bool line);

namespace plt = matplotlibcpp;
const double pi = M_PI;
const int n = 5000;

int main() {  
    int N;  
    Eigen::VectorXd x, y;
    Limit lim = {4, -4, 5, -5};
    std::string choice;
    std::vector<double> yLim(2, 0);

    std::cout << "Welcome to the ULTIMATE FOURIER TRASNFORM CALCULATRO!!!\n";
    cVector vec;
    getInfo(vec);
    std::cout << "DFT or FFT: ";
    std::cin >> choice;
    switch((char)toupper(choice[0])){
        case 'D':
            std::cout << "\nUsing DFT: \n";
            dft(vec, false);
            break;
        case 'F':
            std::cout << "\nUsing FFT: \n";
            fft(vec, false);
            break;
        default:
            std::cout << "Invalid choice!";
            return 1;
    }
    logResult(vec);
    std::cout << "Using Inverse: \n";
    dft(vec, true);
    logResult(vec);
    std::cout << "Original Function: \n";
    calcGraph(originalFunc(vec), x, y, lim, yLim);
    std::vector<double> xStd = toDoubleVector(x);
    std::vector<double> yStd = toDoubleVector(y);
    plotGraph(lim, xStd, yStd, yLim, "Function in the Time Domain", true);
    Limit fLim;
    std::vector<double> yFLim(2, 0);
    auto [xFreq, yFreq] = calcFreq(vec, yFLim);
    Limit FLim;
    FLim.xmax = xFreq[xFreq.size()-1];
    FLim.xmin = xFreq[0];
    FLim.ymax = 10; FLim.ymin = -10;
    plotGraph(FLim, xFreq, yFreq, yFLim, "Function in Frequency Domain", false);
    return 0;
}

void plotGraph(Limit lim, std::vector<double> x, std::vector<double> y, std::vector<double> yLim, std::string title, bool line){
    std::string sym = "";
    if(line) sym = "-";
    else sym = "o";
    plt::figure();
    plt::plot({lim.xmax, lim.xmin}, {0, 0}, "k-");
    plt::plot({0, 0}, {yLim[0]*1.1, yLim[1]*1.1}, "k-");
    plt::plot(x, y, "r"+sym);
    plt::title(title);
    plt::xlim(lim.xmin, lim.xmax);
    plt::ylim(yLim[1]*1.1, yLim[0]*1.1);
    plt::axis("on");
    plt::grid(true);
    plt::show();
}

std::pair<std::vector<double>, std::vector<double>> calcFreq(cVector vec, std::vector<double>& yLim){
    fft(vec, false);
    std::vector<double> x, y;
    for(int i = 0; i < vec.size(); i++){
        x.push_back(i);
        y.push_back(abs(vec[i]));
        if(y[i] > yLim[0]){
            yLim[0] = y[i];
        } else if(y[i] < yLim[1]){
            yLim[1] = y[i];
        }
    }
    return {x, y};
}

void calcGraph(std::vector<Signal> sig, Eigen::VectorXd& x, Eigen::VectorXd& y, Limit lim, std::vector<double>& yLim){
    x = Eigen::VectorXd::LinSpaced(n, lim.xmin, lim.xmax);
    y = Eigen::VectorXd::Zero(n);
    for(int i = 0; i < sig.size(); i++){
        y.array() += (sig[i].ampl*((x.array()*2*pi*sig[i].freq+sig[i].phase).cos()));
    }
    for(int i = 0; i < y.size(); i++){
        yLim[0] = y[i] > yLim[0]? y[i] : yLim[0];
        yLim[1] = y[i] < yLim[1]? y[i] : yLim[1];
    }
}

void getInfo(cVector& vec){
    std::ifstream iFile;
    std::string filename = "../data.csv", line = "", real = "", imag = "";
    double dReal, dImag;
    int location = 0;
    iFile.open(filename);
    while(std::getline(iFile, line)){
        location = line.find(",");
        real = line.substr(0, location);
        imag = line.substr(location + 1, line.length());
        dReal = stod(real);
        dImag = stod(imag);
        vec.push_back(Complex(dReal, dImag));
    }
}

std::vector<double> toDoubleVector(const Eigen::VectorXd& x){
    return std::vector<double>(x.data(), x.data()+x.size());
}

std::vector<std::string> toStringVector(const Eigen::VectorXd& x){
    std::vector<std::string> result;
    result.reserve(x.size());  // Reserve space for efficiency
    for (int i = 0; i < x.size(); ++i) {
        result.push_back(std::to_string(x[i]));  // Convert double to string
    }
    return result;
}

double roundDp(double n, int dp){
    return round(n * pow(10, dp)) / pow(10, dp);
}

void logResult(cVector vec){
    for(int i = 0; i < vec.size(); i++){
        std::cout << "X[" << i << "] = " << vec[i] << "\n";
    }
}

void dft(cVector& vec, bool invert){
    int N = vec.size();
    Complex sum;
    cVector temp = vec;
    int x = invert? 1 : -1;
    double y = invert? 1.0/N : 1;
    for(int k = 0; k < N; k++){
        sum = Complex(0, 0);
        for(int i = 0; i < N; i++){
            sum += temp[i]*Complex(cos(2*pi*k*i*x/N)*y, sin(2*pi*k*i*x/N)*y);
        }
        vec[k] = sum;
    }
}

void fft(cVector& vec, bool invert){
    int size;
    int N = vec.size();
    if(N <= 1) return;

    cVector even(N/2);
    cVector odd(N/2);
    for(int i = 0; i < N/2; i++){
        even[i] = vec[i*2];
        odd[i] = vec[i*2+1];
    }

    fft(even, invert);
    fft(odd, invert);

    Complex w;    
    int x = invert? 1 : -1;
    for(int k = 0; k < N/2; k++){
        w = Complex(cos(2*pi*k*x/N), sin(2*pi*k*x/N));
        vec[k] = even[k] + w*odd[k];
        vec[k+N/2] = even[k] - w*odd[k];
    }    
    if (invert) {
        for (int i = 0; i < N; i++) {
            vec[i] /= N;
        }
    }
}

std::vector<Signal> originalFunc(cVector fBin){
    int N = fBin.size();
    int nyquist = N/2;
    std::vector<Signal> signal; 
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
        std::cout << "+ " << signal[i].ampl << "cos(" << signal[i].freq << "x+" << signal[i].phase << ")\n";
    }
    return signal;
}