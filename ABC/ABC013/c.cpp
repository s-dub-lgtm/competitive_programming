#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(ll i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n, h, a, b, c, d, e;
	cin >> n >> h >> a >> b >> c >> d >> e;
	
	ll ans = 1e16;
	rep(x, n + 1) {
		long double min_poor = (long double) ((n - x) * e - h - b * x) / (long double) (d + e);
		ll y;
		if (min_poor < 0) {
			y = 0;
		} else {
			y = (ll) (min_poor) + 1;
		}
//		cout << x << " " << y << endl;
		ll sum = a * x + c * y;
		ans = min(sum, ans);
	}

//	ll ans = 1e16;
//	rep(x, n + 1) {
//		rep(y, n - x + 1) {
//			if (h + b * x + d * y - (n - x - y) * e > 0) {
//				ans = min(a * x + c * y, ans);
//			}
//		}
//	}
	
	cout << ans << endl;
	
	return 0;
}