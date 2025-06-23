function[prod] = prod_fraction(n)
    prod = 1;
    for x=1:n
        prod = prod * x/(x+1);
    end
end