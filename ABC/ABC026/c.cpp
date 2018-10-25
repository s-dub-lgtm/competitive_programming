#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int b[n];
	rep(i, n - 1) cin >> b[i + 1];
	
	vector<ll> c[n];
	ll p[n];
	for (int i = n - 1; i >= 0; i--) {
		if (c[i].empty()) p[i] = 1;
		else {
			sort(ALL(c[i]));
			p[i] = 1 + c[i].front() + c[i].back();
		}
		if (i) c[b[i] - 1].push_back(p[i]);
	}
	
	cout << p[0] << endl;
	
	return 0;
}