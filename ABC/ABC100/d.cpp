#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

typedef pair<ll, int> P;

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
	
	int n, m;
	cin >> n >> m;
	ll x[n], y[n], z[n];
	REP(i, n) cin >> x[i] >> y[i] >> z[i];
	
	ll maxsum = 0;
	REP(i, 1 << 3) {
		vector<ll> v(n);
		REP(j, n) {
			ll sum = 0;
			if (i >> 0 & 1) sum += x[j];
			else sum -= x[j];
			if (i >> 1 & 1) sum += y[j];
			else sum -= y[j];
			if (i >> 2 & 1) sum += z[j];
			else sum -= z[j];
			v[j] = sum;
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		ll total = 0;
		REP(i, m) total += v[i];
		maxsum = max(maxsum, total);
	}
	
	cout << maxsum << endl;
	
	return 0;
}