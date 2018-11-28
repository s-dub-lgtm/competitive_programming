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
	cin >> n;
	int d[n][n];
	rep(i, n)rep(j, n) cin >> d[i][j];
	int q;
	cin >> q;
	int p[q];
	rep(i, q) cin >> p[i];
	
	int best[n * n + 1] = {};
	rep(y0, n) {
		rep(y1, n) {
			if (y0 > y1) continue;
			rep(x0, n) {
				rep(x1, n) {
					if (x0 > x1) continue;
					
					int total = 0;
					FORE(i, y0, y1) {
						FORE(j, x0, x1) {
							total += d[i][j];
						}
					}
					int area = (y1 - y0 + 1) * (x1 - x0 + 1);
					best[area] = max(total, best[area]);
				}
			}
			rep(i, n * n) {
				best[i + 1] = max(best[i + 1], best[i]);
			}
		}
	}
//	rep(i, n * n + 1) cout << best[i] << endl;
	
	rep(i, q) {
		cout << best[p[i]] << endl;
	}
	
	return 0;
}