#include <bits/stdc++.h>

using namespace std;

inline bool puc (int m, int a, int b, int c, int d){
	if (a < m) d -= (m - a);
	if (b < m) d -= (m - b);
	if (c < m) d -= (m - c);
	return (d >= 0);
}

int find (int a, int b, int c, int co){
	int l = 0;
	int r = 5e5;
	while (l+1 < r){
		int mig = (l+r)/2;
		if (puc(mig,a,b,c,co)) l = mig;
		else r = mig;
	}
	return l;
}

int main(){
	int t;
	cin >> t;
	for (int jk = 0; jk < t; jk++){
		int n;
		cin >> n;
		string a,b,c;
		cin >> a >> b >> c;
		int ans = 0;
		int comod = 0;
		int ab = 0, ac = 0, bc = 0;
		for (int i = 0; i < n; i++){
			char a1 = a[i];
			char b1 = b[i];
			char c1 = c[i];
			if (a1 == b1 and a1 == c1) {
				ans++;
				continue;
			}
			if (a1 != b1 and b1 != c1 and a1!=c1){
				comod++;
				continue;
			}
			if (a1 == b1) {
				ab++;
				continue;
			}
			if (a1 == c1) {
				ac++;
				continue;
			}
			if (c1 == b1) {
				bc++;
				continue;
			}
		}
		int r1, r2;
		if (ab <= ac and ab <= bc){
			ans += ab*2;
			ac -= ab;
			bc -= ab;
			r1 = max(ac, bc);
			r2 = min(ac, bc);
		}
		else if (ac <= ab and ac <= bc){
			ans += ac*2;
			ab -= ac;
			bc -= ac;
			r1 = max(ab, bc);
			r2 = min(ab, bc);
		} 
		else {
			ans += bc*2;
			ab -= bc;
			ac -= bc;
			r1 = max(ab, ac);
			r2 = min(ab, ac);
		}
		ans += r2;
		int a1 = r2;
		r1 -= r2;
		int ma = 0;
		for (int i = 0; i <= r1; i++){
			ma = max(ma, find(a1 + i, i,r1 - i, comod));
		}
		cout << ma + ans << endl;
	}
}
