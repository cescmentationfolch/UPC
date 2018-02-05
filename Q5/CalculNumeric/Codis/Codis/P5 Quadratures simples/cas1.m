a = 0;
b = 5;
f = @(x) exp(-x)+0.5.*exp(-(x-4).^2);

% Valor exacte
Ie = exp(-a)-exp(-b)+sqrt(pi)/4*(erf(b-4)-erf(a-4));

% Integral num�rica, NC tancada, n = 4
n = 4;
x = linspace(a, b, n+1);
C1 = QuadraturaNewtonCotes(x, a, b);
I1 = sum(C1.*f(x)');
E1 = abs((I1-Ie));

% Integral num�rica, NC oberta, n = 4
n = 4;
x = linspace(a, b, n+3);
x = x(2:n+2);
C2 = QuadraturaNewtonCotes(x, a, b);
I2 = sum(C2.*f(x)');

% Gr�fica de converg�ncia NC
n = 1:14;
Err1 = zeros(1, length(n));
Err2 = zeros(1, length(n));
for i = n
    x = linspace(a, b, n(i)+1);
    C1 = QuadraturaNewtonCotes(x, a, b);
    I1 = sum(C1.*f(x)');
    Err1(i) = abs((I1-Ie)/Ie);
end
for i = n
    x = linspace(a, b, n(i)+3);
    x = x(2:n(i)+2);
    C2 = QuadraturaNewtonCotes(x, a, b);
    I2 = sum(C2.*f(x)');
    Err2(i) = abs((I2-Ie)/Ie);
end
figure(01)
plot(log10(n), log10(Err1), 'r-o', 'MarkerFaceColor', 'r');
hold on
plot(log10(n), log10(Err2), 'b-o', 'MarkerFaceColor', [1 .5 0], 'color', [1 .5 0]);
hold off

% Canvi de variables que permet transformar [a, b] <-> [-1, 1]
% int(x), x \in (-1, 1) <-> int(y), y= (a+b)/2+(b-a)/2*x, \in (-1, 1)

% Integral num�rica, GL, n = 4
n = 5;
[z, w] = QuadraturaGauss(n);
I2 = sum((b-a)/2*w.*f((a+b)/2+(b-a)/2.*z)');
E2 = abs((I2-Ie));

% Gr�fica de converg�ncia GL
n = 1:14;
Err = zeros(1, length(n));
for i = n
    [z, w] = QuadraturaGauss(n(i));
    I2 = sum((b-a)/2*w.*f((a+b)/2+(b-a)/2.*z)');
    Err(i) = abs((I2-Ie)/Ie);
end
figure(01)
hold on
plot(log10(n), log10(Err), 'b-o', 'MarkerFaceColor', 'b');
legend('Newton-Cotes tancada', 'Newton-Cotes oberta', 'Gauss-Legendre', 'Location','southwest')
title('Integraci� num�rica per a f(x) = e^{-x}+0.5*e^{-(x-4)^2})');
hold off