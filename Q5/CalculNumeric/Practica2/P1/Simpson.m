function res = Simpson(f, xnum)
x = linspace(0, 2, xnum);
res = 0;
% Podem Precalcular els 2n-1 punts que utilitzem pel metode del trapezi per 
% no haber de calcular un punt mes d'un cop
for i = 1:xnum-1
            res = res + (f(x(i)) + 4*f((x(i)+x(i+1))/2) + f(x(i+1))) * (x(i+1)-x(i))/6;
end

end
