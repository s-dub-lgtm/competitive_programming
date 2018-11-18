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
	
	int sx, sy, tx, ty, t, v;
	cin >> sx >> sy >> tx >> ty >> t >> v;
	int n;
	cin >> n;
	
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		double d1 = sqrt((sx - x) * (sx - x) + (sy - y) * (sy - y));
		double d2 = sqrt((tx - x) * (tx - x) + (ty - y) * (ty - y));
		if (d1 + d2 <= t * v) {
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
	
	return 0;
}