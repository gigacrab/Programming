function[]=plot_graph()
    x = 0:pi/20:2*pi;
    y1 = cos(x);
    y2 = sin(x);
    plot(x, y1, x, y2, "b*");
    title('Happy happy happy graph');
    legend("hello", "bye!");
end