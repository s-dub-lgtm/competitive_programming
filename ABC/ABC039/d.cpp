#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int h, w;
	cin >> h >> w;
	char s[h][w];
	
	rep(i, h) {
		rep(j, w) {
			cin >> s[i][j];
		}
	}
	
	char t[h][w];
	rep(i, h) {
		rep(j, w) {
			t[i][j] = '#';
		}
	}
	
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] == '.') {
				FOR(dx, -1, 2) {
					FOR(dy, -1, 2) {
						int y = i + dy, x = j + dx;
						if (0 <= y && y < h && 0 <= x && x < w) {
							t[y][x] = '.';
						}
					}
				}
			}
		}
	}
	
	char u[h][w];
	rep(i, h) {
		rep(j, w) {
			u[i][j] = '.';
		}
	}
	
	rep(i, h) {
		rep(j, w) {
			if (t[i][j] == '#') {
				FOR(dx, -1, 2) {
					FOR(dy, -1, 2) {
						int y = i + dy, x = j + dx;
						if (0 <= y && y < h && 0 <= x && x < w) {
							u[y][x] = '#';
						}
					}
				}
			}
		}
	}
	
	bool same = true;
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] != u[i][j]) same = false;
		}
	}
	
	if (same) {
		cout << "possible" << endl;
		rep(i, h) {
			rep(j, w) {
				cout << t[i][j];
			}
			cout << endl;
		}
	} else {
		cout << "impossible" << endl;
	}
	
	return 0;
}