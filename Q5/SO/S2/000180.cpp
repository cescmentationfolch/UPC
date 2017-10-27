#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>,
            rb_tree_tag,tree_order_statistics_node_update>;
// Use like a map: put something instead of null_type

typedef long long ll;
typedef pair<int, int> pi;

const int N = 100010;
ordered_set<pi> F[N];

void add(int idx, pi val) {
  ++idx;
  while (idx < N) {
    F[idx].insert(val);
    idx += idx&(-idx);
  }
}

int sum(int idx, pi val) {
  ++idx;
  int res = 0;
  while (idx > 0) {
    res += F[idx].order_of_key(val);
    idx -= idx&(-idx);
  }
  return res;
}

ll quad(int a, int b, int c, int d) {
  int res = sum(b, pi(d + 1, -1));
  res -= sum(b, pi(c, -1));
  res -= sum(a - 1, pi(d + 1, -1));
  res += sum(a - 1, pi(c, -1));
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; ++i) F[i].clear();
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      add(x, pi(y, i));
    }
    ll res = 0;
    while (m--) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      res += quad(a,b,c,d);
    }
    cout << res << '\n';
  }
}
