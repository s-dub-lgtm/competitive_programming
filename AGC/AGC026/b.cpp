#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)

typedef pair<int, int> P;

const int MOD = (int) 1e9 + 7;

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

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	REP(i, t) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		
		if (a - b < 0) {
			cout << "No" << endl;
		} else if (b == d) {
//				if (a - b >= 0) cout << "Yes" << endl;
//				else cout << "No" << endl;
//			ll k = (ll) ((double) (-(c - a)) / b);
//			if (a - k * b >= b) cout << "Yes" << endl;
//			else cout << "No" << endl;
			cout << "No" << endl;
		} else if (b > d) {
			cout << "No" << endl;
		} else if (a % b > c) {
			cout << "No" << endl;
		} else {
			if (c - (a - b) < 0) {
				ll k = (ll) ((double) (-(c - a)) / b);
//				cout << k << endl;
//				cout << a - k * b << endl;
				if (a - k * b >= b) cout << "Yes" << endl;
				else cout << "No" << endl;
			} else {
				ll k = (ll) ((double) (c - (a - b)) / (d - b)) + 1;
//				cout << 1000000000000000000 % 17 << endl;
//				cout << (c - (a - b)) / (d - b) << endl;
//				cout << k << endl;
				if (a - b + k * (d - b) >= b) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
		}
	}
	
	return 0;
}