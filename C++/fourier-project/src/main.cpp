#include "/home/littlecrabby/vcpkg/installed/x64-linux/include/matplotlibcpp.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <complex>
#include <eigen3/Eigen/Dense>

namespace plt = matplotlibcpp;
//using namespace plt;
//using namespace std;

typedef struct {
    double amplitude = 0;
    double frequency = 0;
    double phase = 0;
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

void trig(std::string req, Signal signal, Limit lim, Eigen::VectorXd& x, Eigen::VectorXd& y){
    x = Eigen::VectorXd::LinSpaced(5000, lim.xmin, lim.xmax); //size, low, high, :: is scope resolution operator
    switch((char)toupper(req[0])){
        case 'S':
            y = signal.amplitude*((x.array()*signal.frequency+signal.phase).sin());
            break;
        case 'C':
            y = signal.amplitude*((x.array()*signal.frequency+signal.phase).cos());
            break;
        case 'T':
            y = signal.amplitude*((x.array()*signal.frequency+signal.phase).tan()); 
            break;
        default:
            std::cout << "Hey! Invalid choice. Defaulting to a sine graph.";
            y = signal.amplitude*((x.array()*signal.frequency+signal.phase).sin());
    }
}

int main() {    
    int n = 5000;
    Limit lim = {2*M_PI, -2*M_PI, 5, -5};
    double xStep = M_PI/4;
    double yStep = 1;
    int xScaleCount = (int)((lim.xmax - lim.xmin)/xStep);
    int yScaleCount = (int)((lim.ymax - lim.ymin)/yStep);
    std::vector<double> xTicks(xScaleCount + 1), yTicks(yScaleCount + 1);
    std::vector<std::string> xLabels(xScaleCount + 1), yLabels(yScaleCount + 1);

    for(int i = 0; i <= xScaleCount; i++){
        xTicks[i] = lim.xmin + i * xStep;
        xLabels[i] = std::to_string((int)xTicks[i]);
    }
    for(int i = 0; i <= yScaleCount; i++){
        yTicks[i] = lim.ymin + i * yStep;
        yLabels[i] = std::to_string((int)yTicks[i]);
        std::cout << yLabels[i];
    }

    std::string req;
    Signal signal;
    std::cout << "What kind of wave do you want?(sin/cos/tan) ";
    std::cin >> req;
    std::cout << "Amplitude: ";
    std::cin >> signal.amplitude;
    std::cout << "Frequency: ";
    std::cin >> signal.frequency;
    std::cout << "Phase(Radians): ";
    std::cin >> signal.phase;

    Eigen::VectorXd x, y;
    trig(req, signal, lim, x, y);
    
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
    plt::xlim(lim.xmin, lim.xmax);
    plt::ylim(lim.ymin, lim.ymax);
    plt::xticks(xTicks, xLabels);
    plt::yticks(yTicks, yLabels);
    plt::axis("on");
    plt::grid(true);
    plt::show();
    
    return 0;
}
