function[y] = diagonal_zero()
    a = [9 -4 6;-3 1 5;7 2 -1];
    [row col] = size(a);
    for r = 1:row
        for c = 1:col
            if r == c
                a(r, c) = 0;
            end
        end
    end
    y = a;
end