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
const ll INF = (ll) 1e18;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	ll a[n];
	rep(i, n) cin >> a[i];
	
	ll sum[n + 1], sum2[n + 1];
	sum[0] = 0, sum2[0] = 0;
	rep(i, n) {
		sum[i + 1] = sum[i] + a[i];
		sum2[i + 1] = sum2[i];
		if (a[i] > 0) sum2[i + 1] += a[i];
	}
	
	ll ans = 0;
	rep(i, n - k + 1) {
		ans = max(ans, sum2[i] - sum2[0] + sum2[n] - sum2[i + k] + max(sum[i + k] - sum[i], 0ll));
	}
	
	cout << ans << endl;
	
	return 0;
}