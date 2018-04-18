clear;
x = [1 2 3 0.9 5 6 1];
xBool = x >= 1;


if (sum(xBool) == length(xBool))
    output = 50;
else
    output = 0;
end

output