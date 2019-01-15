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
	
	int n, k;
	cin >> n >> k;
	int x[n];
	rep(i, n) cin >> x[i];
	
	int min_dist = inf;
	rep(i, n - k + 1) {
		int left = x[i];
		int right = x[i + k - 1];
		int dist;
		if (left < 0 and 0 < right) {
			dist = abs(left) + abs(right) + min(abs(left), abs(right));
		} else {
			dist = max(abs(left), abs(right));
		}
		chmin(min_dist, dist);
	}
	
	cout << min_dist << endl;
	
	return 0;
}