function [result] = calSeries3(n)
    x = 1:1:n;
    result = sum(1./(x.*(x+1)));
end