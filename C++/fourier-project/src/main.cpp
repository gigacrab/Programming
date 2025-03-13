#include "matplotlibcpp.h"
#include <vector>

namespace plt = matplotlibcpp;

int main() {
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0};
    std::vector<double> y = {1.0, 4.0, 9.0, 16.0};

    plt::plot(x, y, "r-"); // "r-" specifies a red line
    plt::show();
    
    return 0;
}
