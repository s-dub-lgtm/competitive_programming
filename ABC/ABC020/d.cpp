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
	
	ll begin[k], end[k];
	rep(i, k) {
		if (i > n) break;
		if (i == 0) begin[i] = k;
		else begin[i] = i;
	}
	rep(i, k) {
		if (i > n) break;
		end[(n - i) - ((n - i) / k) * k] = n - i;
	}
//	rep(i, k) {
//		cout << begin[i] << endl;
//	}
//	rep(i, k) {
//		cout << end[i] << endl;
//	}
	
	ll sum = 0;
	rep(i, k) {
		if (i > n) break;
		sum += ((begin[i] + end[i]) * ((end[i] - begin[i]) / k + 1) / 2) * k / gcd(begin[i], k);
		sum %= (MOD);
	}
	cout << sum << endl;
	
	return 0;
}