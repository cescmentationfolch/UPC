#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
typedef vector<ppi> vppi;
typedef vector<pi> vpi;

const int N = 100010;

int T[4*N];
int lazy[4*N];
pi V[N];
ppi A[N], B[N];


void update(int n) {
  if (lazy[n] == 0) return;
  T[n] += lazy[n];
  if (2*n + 1 < 4*N) {
    lazy[2*n] += lazy[n];
    lazy[2*n + 1] += lazy[n];
  }
  lazy[n] = 0;
}

ll ask(int node, int x, int a, int b) {
  update(node);
  if (a == b) return T[node];
  int k = (a + b)/2;
  if (x <= k) return ask(2*node, x, a, k);
  else return ask(2*node + 1, x, k + 1, b);
}

void upd(int node, int x, int y, int a, int b, int val) {
  update(node);
  if (x > b or y < a) return;
  if (x <= a and b <= y) {
    T[node] += val;
    if (a != b) {
      lazy[2*node] += val;
      lazy[2*node + 1] += val;
    }
    return;
  }
  int k = (a + b)/2;
  upd(2*node, x, y, a, k, val);
  upd(2*node + 1, x, y, k + 1, b, val);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    memset(T, 0, sizeof(T));
    memset(lazy, 0, sizeof(lazy));
    for (int i = 0; i < n; ++i) {
      cin >> V[i].first >> V[i].second;
    }
    sort(V, V + n);
    for (int i = 0; i < m; ++i) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      A[i] = ppi(a, pi(c, d));
      B[i] = ppi(b, pi(c, d));
    }
    sort(A, A + m);
    sort(B, B + m);
    int j = 0;
    int w = 0;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
      while (j < m and A[j].first <= V[i].first) {
	upd(1, A[j].second.first, A[j].second.second, 0, N, 1);
	++j;
      }
      res += ask(1, V[i].second, 0, N);
      if (i == n-1)break;
      while (w < m and B[w].first < V[i + 1].first) {
	upd(1, B[w].second.first, B[w].second.second, 0, N, -1);
	++w;
      }
    }
    cout << res << '\n';
  }
}
