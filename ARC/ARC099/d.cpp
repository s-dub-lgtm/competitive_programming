#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(ll i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

typedef pair<int, int> P;

template<class T>
bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T>
bool chmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll tensum(ll n) {
	ll sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll k;
	cin >> k;
//	ll ans[k + 1];
	
	if (k <= 9) {
		REP(i, k) {
			cout << i + 1 << endl;
		}
	} else {
		REP(i, 9) {
			cout << i + 1 << endl;
//			ans[i] = i + 1;
		}
		
		ll res = k - 9;
		ll ninenum = 1;
		ll ans = 9;
		for (ll i = 0; i < res; ++i) {
			if (ans + (ll) pow(10, ninenum) <= (ninenum) * pow(10, ninenum + 1)) {
				ans += (ll) pow(10, ninenum);
			} else {
				ninenum++;
				ans += (ll) pow(10, ninenum);
			}
//			cout<<ninenum<<endl;
			cout << ans << endl;
		}
	}
	
	
	return 0;
}