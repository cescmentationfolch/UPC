function res = Simpson(f, xnum)
x = linspace(0, 2, xnum);
res = 0;
i = 1;
while i + 2 <= xnum
    res = res + (f(x(i)) + 4*f(x(i+1)) + f(x(i+2))) * (x(i+1)-x(i))/3;
    i = i + 2;
end

end

