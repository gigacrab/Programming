function[percentage, area] = zDistribution(a,b)
    area = 0;
    for z = a:0.0001:b-0.0001
        area = area + 0.0001*1/sqrt(2*pi)*exp(-1/2*z^2);
    end
    percentage = round(area*100,2)+"%"
end