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
	
	int n, m, p, q, r;
	cin >> n >> m >> p >> q >> r;
	int x[r], y[r], z[r];
	rep(i, r) {
		cin >> x[i] >> y[i] >> z[i];
		x[i]--, y[i]--;
	}
	
	int ans = 0;
	vector<int> v;
	rep(i, 1 << n) {
		int cnt = 0;
		rep(j, n) cnt += i >> j & 1;
		if (cnt != p) continue;
		v.assign(m, 0);
		rep(j, r) {
			if (i >> x[j] & 1) {
				v[y[j]] += z[j];
			}
		}
		sort(ALL(v), greater<int>());
		int t = 0;
		rep(j, q) t += v[j];
		chmax(ans, t);
	}
	
	cout << ans << endl;
	
	return 0;
}