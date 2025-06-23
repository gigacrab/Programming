function[sum] = sum_reciprocal(n)
    sum = 0;
    for x=1:n
        sum = sum + 1/(x*(x+1));
    end
end