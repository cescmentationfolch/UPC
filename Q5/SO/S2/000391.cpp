#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<ld, ld> pld;
typedef vector<pld> vpld;

vpld V;

ld dist(pld a, pld b) {
  pld c = pld(a.first - b.first, a.second - b.second);
  return sqrt(c.first*c.first + c.second*c.second);
}

ld projX(pld a, pld b) {
  ld k = dist(a, b);
  return abs(a.first - b.first)/k;
}

ld projY(pld a, pld b) {
  ld k = dist(a, b);
  return abs(a.second - b.second)/k;
}

ld eps = 1e-8;

ld calcX(int n, ld ycor) {
  ld a = -20000.36543;
  ld b = 20000.9675;
  while (abs(a - b) > eps) {
    ld xcor = (a + b)/2.0;
    ld sum = 0;
    for (int i = 0; i < n; ++i) {
      if (V[i].first < xcor) sum -= projX(pld(xcor, ycor), V[i]);
      else sum += projX(pld(xcor, ycor), V[i]);
    }
    if (sum >= 0) a = xcor;
    else b = xcor;
  }
  return a;
}

pld calcP(int n) {
  ld a = -20000.36543;
  ld b = 20000.9675;
  while (abs(a - b) > eps) {
    ld ycor = (a + b)/2.0;
    ld xcor = calcX(n, ycor);
    ld sum = 0;
    for (int i = 0; i < n; ++i) {
      if (V[i].second < ycor) sum -= projY(pld(xcor, ycor), V[i]);
      else sum += projY(pld(xcor, ycor), V[i]);
    }
    if (sum >= 0) a = ycor;
    else b = ycor;
  }
  return pld(calcX(n, a), a);
}


bool comp(pld a, pld b) {
  if (a.first + eps < b.first) return true;
  if (abs(a.first - b.first) < 2*eps and a.second + eps < b.second) return true;
  return false;
}

int main() {
  cout.precision(5);
  cout.setf(ios::fixed);
  int n;
  cin >> n;
  V = vpld(n);
  for (int i = 0; i < n; ++i) cin >> V[i].first >> V[i].second;
  pld res;
  ld dd = 1e18;
  sort(V.begin(), V.end());
  for (int i = 0; i < n; ++i) {
    ld pp = 0;
    for (int j = 0; j < n; ++j) pp += dist(V[i], V[j]);
    if (pp + eps < dd or (abs(dd - pp) < eps and comp(V[i], res))) {
      dd = pp;
      res = V[i];
    }
  }
  pld k = calcP(n);
  ld pp = 0;
  for (int i = 0; i < n; ++i) pp += dist(V[i], k);
  if (pp + eps < dd or (abs(dd - pp) < eps and comp(k, res))) {
    res = k;
  }
  cout << setprecision(5) << fixed << res.first << ' '  << res.second << endl;
}

