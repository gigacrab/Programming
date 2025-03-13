#include "matplotlibcpp.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <complex>
#include <eigen3/Eigen/Dense>

namespace plt = matplotlibcpp;
//using namespace plt;
//using namespace std;

typedef struct {
    double amplitude;
    double frequency;
    double phase;
}Signal;

typedef struct {
    double xmax;
    double xmin;
    double ymax;
    double ymin;
}Limit;

std::vector<double> toStdVector(const Eigen::VectorXd& x){
    return std::vector<double>(x.data(), x.data()+x.size());
}

int main() {    
    int n = 5000;
    Limit lim = {4*M_PI, -4*M_PI, 5, -5};

    std::string req;
    Signal signal;
    std::cout << "What kind of wave do you want?(sin/cos) ";
    std::cin >> req;
    std::cout << "Amplitude: ";
    std::cin >> signal.amplitude;
    std::cout << "Frequency: ";
    std::cin >> signal.frequency;
    std::cout << "Phase(Radians): ";
    std::cin >> signal.phase;
    if((char)toupper(req[0]) == 'S'){
        
    }else if((char)toupper(req[0]) == 'C'){

    }else{
        std::cout << "Hey! Invalid choice.";
        return 0;
    }

    Eigen::VectorXd x = Eigen::VectorXd::LinSpaced(n, lim.xmin, lim.xmax); //size, low, high, :: is scope resolution operator
    Eigen::VectorXd y = signal.amplitude*((x.array()*signal.frequency+signal.phase).sin());
    std::vector<double> xaxis = {10, -10};

    std::vector<double> x_std = toStdVector(x);
    std::vector<double> y_std = toStdVector(y);
    
    /*for(int i = 0; i < n; i++){
        std::cout << x[i] << std::endl;
    }*/
    //endl to move to new line to flush the buffer, \n doesn't flush buffer

    plt::plot({lim.xmax, lim.xmin}, {0, 0}, "k-");
    plt::plot({0, 0}, {lim.ymax, lim.ymin}, "k-");
    plt::plot(x_std, y_std, "r-");
    plt::title("Sine Wave");
    plt::xlim(lim.xmax, lim.xmin);
    plt::ylim(lim.ymax, lim.ymin);
    plt::axis("on");
    plt::show();
    
    return 0;
}
