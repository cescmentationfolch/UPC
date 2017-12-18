function res = Simpson(f, xnum)
x = linspace(0, 2, xnum);
res = 0;
i = 1;
for i = 1:xnum-1
            res = res + (f(x(i)) + 4*f((x(i)+x(i+1))/2) + f(x(i+1))) * (x(i+1)-x(i))/6;
end

end
