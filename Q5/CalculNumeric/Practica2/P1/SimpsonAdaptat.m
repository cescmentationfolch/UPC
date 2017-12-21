function [I,E,P] = SimpsonAdaptat(f, l, r, tol)
I = Simpson(f, l, r, 1);
S = Simpson(f, l, (l+r)/2, 1) + Simpson(f, (l+r)/2, r, 1);
P = linspace(l,r,2);

E = abs(I - S);
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
