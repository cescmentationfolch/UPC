function [I,E,P] = SimpsonAdaptat(f, l, r, tol)
x = linspace(l,r,5);
P = linspace(l,r,3);
% Podriem precalcular les avaluacions de les funciones per nomes haver de
% calcular 5 punts, a mes podem passar f(l) i f(r) del pare que ja ho haura
% calculat per fer 2n-1 punts en total on n es el nombre d'intervals
I = (f(x(1)) + 4*f(x(3)) + f(x(5))) * (x(3)-x(1))/3;
S(1) = (f(x(1)) + 4*f(x(2)) + f(x(3))) * (x(2)-x(1))/3;
S(2) = (f(x(3)) + 4*f(x(4)) + f(x(5))) * (x(4)-x(3))/3;

E = abs(I - (S(1) + S(2)));
if E > tol*(r-l)
    [L1, L2, P1] = SimpsonAdaptat(f, l, (l+r)/2, tol);
    [R1, R2, P2] = SimpsonAdaptat(f, (l+r)/2, r, tol);
    I = L1 + R1;
    E = L2 + R2;
    P = [P1 P2];
    P = unique(P);
    return
end
end
