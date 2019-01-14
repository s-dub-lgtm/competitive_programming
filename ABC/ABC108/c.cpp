#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n, k;
	cin >> n >> k;
	
	ll cnt = 0;
	FORE(i, 1, n) {
		if (i % k == 0) cnt++;
	}
	ll ans = (ll) (pow(cnt, 3));
	
	if (k % 2 == 1) {
		cout << ans << endl;
	} else {
		cnt = 0;
		FORE(i, 1, n) {
			if ((i + (k / 2)) % k == 0) cnt++;
		}
		cout << ans + (ll) (pow(cnt, 3)) << endl;
	}
	
	return 0;
}