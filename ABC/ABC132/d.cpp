#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define FORR(i, a, b) for(int i=(b-1);i>=(a);--i)
#define FORRE(i, a, b) for(int i=(b);i>=(a);--i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
#define repr(i, n) for(int i=(n-1);i>=0;--i)
#define repre(i, n) for(int i=(n);i>=0;--i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const ll INF = (ll) 1e9;
const ll MOD = (ll) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

ll tpas[2005][2005];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll cum_sum[2005];
	cum_sum[0] = 0;
	rep(i, 2004) {
		cum_sum[i + 1] = (cum_sum[i] + i + 1) % MOD;
	}
	
	int n, k;
	cin >> n >> k;
	
	FORE(i, 1, k) {
		FORE(j, 1, k) {
			if (j == 1) tpas[i][j] = 1;
			else if (j == i) {
				tpas[i][j] = 1;
				break;
			} else tpas[i][j] = (tpas[i - 1][j - 1] + tpas[i - 1][j]) % MOD;
		}
	}
	
	FORE(i, 1, k) {
		if (i == 1) {
			cout << n - k + 1 << endl;
			continue;
		}
		if (i == 2) {
			cout << (cum_sum[n - k] * tpas[k][i]) % MOD << endl;
			continue;
		}
		ll ans = 0;
		rep(j, n - k) {
			ans = (ans + cum_sum[j]) % MOD;
			cum_sum[j] = ans;
		}
		cout << (ans * tpas[k][i]) % MOD << endl;
	}
	
	
	return 0;
}