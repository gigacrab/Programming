function [area, volume] = calculateCylinder(radius, height)
    area = 2 * pi * radius^2 + 2 * pi * radius * height;
    volume = pi * radius^2 * height;
end