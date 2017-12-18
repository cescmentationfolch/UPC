interval = [4,8,16,32,64,128,256,512,1024,2048,4096,8192];
f = @(x) sin(exp(2*x));
value = integral(f, 0, 2);
for i = 1:12
    valTrapezi(i) = Trapezi(f, interval(i));
    eTrapezi(i) = abs(value - valTrapezi(i))/value;
    valSimpson(i) = Simpson(f, interval(i));
    eSimpson(i) = abs(value - valSimpson(i))/value;
end

figure
plot(log2(interval), log2(eTrapezi), 'r+', log2(interval), log2(eSimpson), 'b*')
grid on;
legend('Metode del Trapezi', 'Quadratura de Simpson');
xlabel('log2(Nombre de subintervals)');
ylabel('log2(error)');