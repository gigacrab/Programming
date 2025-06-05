set(0, 'DefaultFigureRenderer', 'painters')
t = 0:pi/1000:2*pi;
x = cos(t+sin(50*t));
y = sin(t+cos(50*t));
plot(x, y, "m-");