m = -1;
x1 = -0.01;
while m < 0
    x1 = x1 + 0.01;
    y1 = x1^2 - 6*x1 + 3;
    x2 = x1 + 0.01;
    y2 = x2^2 - 6*x2 + 3;
    m = (y2-y1)/0.01;
end
fprintf("Your stationary point is (%d, %d).\n", round(x1), round(y1));