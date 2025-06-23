%set(0, 'DefaultFigureRenderer', 'painters')
x=0:pi/10:6*pi;
y=x.*sin(x);
plot(x,y,"rp--");
title("Plot of y=x.*sin(x)");
xlabel("x");
ylabel("y");
grid on;