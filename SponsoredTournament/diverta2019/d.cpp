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
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n;
	cin >> n;
	
	if (n == 2) {
		cout << 0 << endl;
		return 0;
	}
//	if (n == 6) {
//		cout << 5 << endl;
//		return 0;
//	}
	
	ll sum = 0;
	for (ll i = 1; i * i < n; ++i) {
		if (n % i == 0) {
			ll num = n / i - 1;
			if (n / num == n % num) {
				sum += num;
			}
		}
	}
	
	cout << sum << endl;
	
	return 0;
}