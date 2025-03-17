#include "matplotlibcpp.h"
#include <vector>
#include <iostream>
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
void dft(cVector vec, cVector& fBin);
void idft(cVector fBin);
std::vector<Signal> origin(cVector fBin);
void dftInfo(cVector& vec);
void calcGraph(std::vector<Signal> sig, Eigen::VectorXd& x, Eigen::VectorXd& y, Limit lim, std::vector<double>& yLim);
double roundDp(double n, int dp);
void plotGraph(Limit lim, std::vector<double> xStd, std::vector<double> yStd, std::vector<double> yLim,
    std::string title, std::vector<double> xTicks, std::vector<double> yTicks, 
    std::vector<std::string> xLabels, std::vector<std::string> yLabels);

namespace plt = matplotlibcpp;
const double pi = M_PI;
const int n = 5000;
int N;

void trig(std::string req, Signal signal, Limit lim, Eigen::VectorXd& x, Eigen::VectorXd& y){
    x = Eigen::VectorXd::LinSpaced(5000, lim.xmin, lim.xmax); //size, low, high, :: is scope resolution operator
    switch((char)toupper(req[0])){
        case 'S':   
            y = signal.ampl*((x.array()*signal.freq+signal.phase).sin());
            break;
        case 'C':
            y = signal.ampl*((x.array()*signal.freq+signal.phase).cos());
            break;
        case 'T':
            y = signal.ampl*((x.array()*signal.freq+signal.phase).tan()); 
            break;
        default:
            std::cout << "Hey! Invalid choice. Defaulting to a sine graph.";
            y = signal.ampl*((x.array()*signal.freq+signal.phase).sin());
    }
}

int main() {    
    Eigen::VectorXd x, y;
    Limit lim = {4, -4, 5, -5};
    double xStep = 1;
    double yStep = 1;
    std::vector<double> yLim(2, 0);
    int xScaleCount = (int)((lim.xmax - lim.xmin)/xStep) + 1;
    int yScaleCount = (int)((lim.ymax - lim.ymin)/yStep) + 1;
    Eigen::VectorXd xTicksEigen = Eigen::VectorXd::LinSpaced((int)((lim.xmax-lim.xmin)/xStep), lim.xmin, lim.xmax);
    Eigen::VectorXd yTicksEigen = Eigen::VectorXd::LinSpaced((int)((lim.ymax-lim.ymin)/yStep), lim.ymin, lim.ymax);
    std::vector<double> xTicks = toDoubleVector(xTicksEigen), yTicks = toDoubleVector(yTicksEigen);
    std::vector<std::string> xLabels = toStringVector(xTicksEigen), yLabels = toStringVector(yTicksEigen);
    std::vector<Signal> sig;

    std::cout << "Welcome to the *Ultimate* DFT Calculator!!!!!!!!!!!!!!!!\n";
    std::cout << "Enter your number of samples: ";
    std::cin >> N;
    cVector vec(N);
    cVector fBin(N);
    dftInfo(vec);
    std::cout << "\nUsing DFT: \n";
    dft(vec, fBin);
    std::cout << "Using IDFT: \n";
    idft(fBin);
    std::cout << "Original Function: \n";
    sig = origin(fBin);
    calcGraph(sig, x, y, lim, yLim);
    std::vector<double> xStd = toDoubleVector(x);
    std::vector<double> yStd = toDoubleVector(y);
    plotGraph(lim, xStd, yStd, yLim, "Ultimate Fourier Transform YEAHHHH", xTicks, yTicks, xLabels, yLabels);
    return 0;
}

void plotGraph(Limit lim, std::vector<double> xStd, std::vector<double> yStd, std::vector<double> yLim,
    std::string title, std::vector<double> xTicks, std::vector<double> yTicks, 
    std::vector<std::string> xLabels, std::vector<std::string> yLabels){
    plt::plot({lim.xmax, lim.xmin}, {0, 0}, "k-");
    plt::plot({0, 0}, {yLim[0]*1.1, yLim[1]*1.1}, "k-");
    plt::plot(xStd, yStd, "r-");
    plt::title(title);
    plt::xlim(lim.xmin, lim.xmax);
    plt::ylim(yLim[1]*1.1, yLim[0]*1.1);
    //plt::xticks(xTicks, xLabels);
    //plt::yticks(yTicks, yLabels);
    plt::axis("on");
    plt::grid(true);
    plt::show();
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

void dftInfo(cVector& vec){
    double reTemp;
    double imTemp;
    Complex cmplxTemp;

    for(int i = 0; i < N; i++){
        std::cout << "\nReal part of " << i+1 << "th sample: ";
        std::cin >> reTemp;
        std::cout << "Imaginary part of " << i+1 << "th sample: ";
        std::cin >> imTemp;
        cmplxTemp.real(reTemp);
        cmplxTemp.imag(imTemp);
        vec[i] = cmplxTemp;
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

void dft(cVector vec, cVector& fBin){
    Complex sum;
    double angle;
    double phase;
    for(int a = 0; a < N; a++){
        sum = Complex(0, 0);
        for(int i = 0; i < N; i++){
            angle = -2*pi*a*i/N;
            sum += vec[i]*Complex(cos(angle), sin(angle));
        }
        fBin[a] = sum;
        phase = arg(sum);
        sum.real(roundDp(sum.real(), 4));
        sum.imag(roundDp(sum.imag(), 4));
        std::cout << "X[" << a << "] = " << sum << ", Magnitude = " << abs(sum) << ", Argument = " << roundDp(phase, 4) << "\n";
    }
}

void idft(cVector fBin){
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
        std::cout << "X[" << a << "] = " << sum << "\n";
    }
}

void fft(cVector vec, bool invert){
    int N = vec.size();
    if(N == 1) return;
    
}

std::vector<Signal> origin(cVector fBin){
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