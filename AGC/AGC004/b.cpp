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
const int inf = (int) 1e9;
const int mod = (int) 1e9 + 7;

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
	
	int n;
	ll x;
	cin >> n >> x;
	ll a[n];
	rep(i, n) cin >> a[i];
	
	int min_index = 0;
	ll min_value = inf;
	rep(i, n) {
		if (a[i] < min_value) {
			min_value = a[i];
			min_index = i;
		}
	}
	
	
	bool get[n];
	get[min_index] = true;
	
	rep(i, 2 * n) {
		int index = i + min_index;
		if (get[index % n]) {
			if (a[(index + 1) % n] < a[index % n] + x) {
				get[(index + 1) % n] = true;
			} else {
				get[(index + 1) % n] = false;
				a[(index + 1) % n] = a[index % n] + x;
			}
		} else {
			if (a[(index + 1) % n] < a[index % n]) {
				get[(index + 1) % n] = true;
			} else {
				get[(index + 1) % n] = false;
				a[(index + 1) % n] = a[index % n];
			}
		}
	}
	
	ll sum = 0;
	rep(i, n) {
		sum += a[i];
	}
	
	cout << sum << endl;
	
	return 0;
}