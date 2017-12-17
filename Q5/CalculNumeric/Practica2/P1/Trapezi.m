function res = Trapezi(f, xnum)
x = linspace(0, 2, xnum);
res = 0;
for i = 1:xnum-1
    res = res + (f(x(i))+f(x(i+1)))*(x(i+1)-x(i))/2;
end

end