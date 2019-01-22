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
	
	ll n;
	ll a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	
	if (b > a + (n - 1) * d or b < a - (n - 1) * d) {
		cout << "NO" << endl;
		return 0;
	}
	
	if (2 * c - (n - 2) * (d - c) <= 0) {
		cout << "YES" << endl;
		return 0;
	}
	
	cout << "mid" << endl;
	
	ll top = a + (n - 1) * d;
	rep(i, 2 * n - 1) {
		cout << top << endl;
		if (i % 2 == 0) {
			top -= (n - 1) * (d - c);
			if (b >= top) {
				cout << "YES" << endl;
				return 0;
			}
		} else {
			top -= (2 * c) - (n - 2) * (d - c);
			if (b >= top) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	return 0;
}