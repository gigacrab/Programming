function[area] = integration(a,b)
    area = 0;
    for x = a:0.0001:b-0.0001
        area = area + 0.0001*(x^3-4*x^2+2*x+5);
    end
end