function[total, product, total_squared, fraction]=series(n)
    format rat
    a = 1:1:n;
    total = sum(a);
    product = prod(a);
    total_squared = sum(a.^2);
    fraction = sum(1./a);
end