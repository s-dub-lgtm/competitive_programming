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
	ll a[n];
	rep(i, n) cin >> a[i];
	
	sort(a, a + n);
	
	ll ans;
	if (n % 2 == 1) {
		ll sum1 = 0;
		FOR(i, 0, n / 2) {
			sum1 -= 2 * a[i];
		}
		sum1 += a[n / 2];
		sum1 += a[n / 2 + 1];
		FOR(i, n / 2 + 2, n) {
			sum1 += 2 * a[i];
		}
		
		ll sum2 = 0;
		FOR(i, 0, n / 2 - 1) {
			sum2 -= 2 * a[i];
		}
		sum2 -= a[n / 2 - 1];
		sum2 -= a[n / 2];
		FOR(i, n / 2 + 1, n) {
			sum2 += 2 * a[i];
		}
		
		ans = max(sum1, sum2);
	} else {
		ll sum3 = 0;
		FOR(i, 0, n / 2) {
			sum3 -= 2 * a[i];
		}
		FOR(i, n / 2, n) {
			sum3 += 2 * a[i];
		}
		sum3 += a[n / 2 - 1];
		sum3 -= a[n / 2];
		
		ans = sum3;
	}
	
	cout << ans << endl;
	
	return 0;
}
