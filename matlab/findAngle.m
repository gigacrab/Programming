function [deg, rad] = findAngle(A, B)
    magA = sqrt(sum(A.^2));
    magB = sqrt(sum(B.^2));
    dot = sum(A.*B);
    deg = acosd(dot/(magA*magB));
    rad = acos(dot/(magA*magB));
end