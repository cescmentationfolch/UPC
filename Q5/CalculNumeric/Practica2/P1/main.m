interval = [4,8,16,32,64];
f = @(x) sin(exp(2*x));
value = Integral(f, 0, 2);
for i in 1:5
    valTrapezi(i) = Trapezi(f, interval(i));
    eTrapezi(i) = abs(value - valTrapezi(i))/value;
    valSimpson(i) = Trapezi(f, interval(i));
    eSimpson(i) = abs(value - valSimpson(i))/value;
end

figure
plot(log(interval), log(eTrapezi), 'r-', log(interval), log(eSimpson), 'b*')