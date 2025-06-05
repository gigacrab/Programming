function [] = myGraph1(a, b)
    x = a:pi/1000:b;
    y = x.*sin(x);
    plot(x, y);
    title("x*sin(x) Graph");
    xlabel("x");
    ylabel("y");
end