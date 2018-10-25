#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)

typedef pair<int, int> P;

const int INF = (int) 1e9;
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
	char s[n][m];
	REP(i, n) REP(j, m) cin >> s[i][j];
	
	ll sum = 0;
	REP(i, n) {
		REP(j, m) {
			if (s[i][j] == '.') {
//				cout << "begin" << endl;
				int y = i, x = j;
//				cout << "up" << endl;
//				cout << y << " " << x << endl;
				while (0 < y && y < n) {
					x = j;
					if (s[y - 1][x] == '.') {
						y--;
					} else {
						break;
					}
					ll cnt = 0;
					while (0 <= x && x < m - 1) {
						if (s[y][x + 1] == '.') {
							x++;
							cnt++;
//							cout << "OK" << endl;
//							cout << y << " " << x << endl;
						} else {
							break;
						}
					}
					sum += cnt;
				}
				y = i, x = j;
//				cout << "down" << endl;
//				cout << y << " " << x << endl;
				while (0 <= y && y < n - 1) {
					x = j;
					if (s[y + 1][x] == '.') {
						y++;
					} else {
						break;
					}
					ll cnt = 0;
					while (0 < x && x < m) {
						if (s[y][x - 1] == '.') {
							x--;
							cnt++;
//							cout << "OK" << endl;
//							cout << y << " " << x << endl;
						} else {
							break;
						}
					}
					sum += cnt;
				}
				y = i, x = j;
//				cout << "right" << endl;
//				cout << y << " " << x << endl;
				while (0 <= x && x < m - 1) {
					y = i;
					if (s[y][x + 1] == '.') {
						x++;
					} else {
						break;
					}
					ll cnt = 0;
					while (0 <= y && y < m - 1) {
						if (s[y + 1][x] == '.') {
							y++;
							cnt++;
//							cout << "OK" << endl;
//							cout << y << " " << x << endl;
						} else {
							break;
						}
					}
					sum += cnt;
				}
				y = i, x = j;
//				cout << "left" << endl;
//				cout << y << " " << x << endl;
				while (0 < x && x < m) {
					y = i;
					if (s[y][x - 1] == '.') {
						x--;
					} else {
						break;
					}
					ll cnt = 0;
					while (0 < y && y < n) {
						if (s[y - 1][x] == '.') {
							y--;
							cnt++;
//							cout << "OK" << endl;
//							cout << y << " " << x << endl;
						} else {
							break;
						}
					}
					sum += cnt;
				}
			}
		}
	}
	
	cout << sum << endl;
	
	return 0;
}