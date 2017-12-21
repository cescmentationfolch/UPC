function res = Trapezi(f, xnum)
x = linspace(0, 2, xnum);
res = 0;
% Podem Precalcular els n punts que utilitzem pel metode del trapezi per 
% no haber de calcular un punt mes d'un cop
for i = 1:xnum-1
    res = res + (f(x(i))+f(x(i+1)))*(x(i+1)-x(i))/2;
end

end