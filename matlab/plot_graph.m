function[]=plot_graph()
    x = 0:pi/20:2*pi;
    y1 = cos(x);
    y2 = sin(x);
    y3 = cos(x+pi/2);
    plot(x, y1, x, y2, "b*",x, y3);
    title('Happy happy happy graph 2x^3');
    legend("hello", "", "by!2x^3");
end