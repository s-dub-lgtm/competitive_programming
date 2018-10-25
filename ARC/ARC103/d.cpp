#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
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
	
	int n;
	cin >> n;
	int x[n], y[n];
	rep(i, n) cin >> x[i] >> y[i];
	
	bool can = true;
	set<int> sx, sy;
	rep(i, n) {
		if (sx.find(x[i]) == sx.end() && sy.find(y[i]) != sy.end()) {
			can = false;
		} else if (sx.find(x[i]) != sx.end() && sy.find(y[i]) == sy.end()) {
			can = false;
		} else {
			sx.insert(x[i]);
			sy.insert(y[i]);
		}
	}
	if (!can) {
		cout << -1 << endl;
		return 0;
	}
	
	int okx[n], oky[n];
	FOR(dx, 1, 11) {
		FOR(dy, 1, 11) {
			bool ok[n];
			rep(i, n) ok[i] = false;
			rep(modex, 4) {
				rep(modey, 4) {
					int tx = 0, ty = 0;
					
					if (modex == 0) tx += dx;
					if (modex == 1) ty += dx;
					if (modex == 2) tx -= dx;
					if (modex == 3) ty -= dx;
					
					if (modey == 0) tx += dy;
					if (modey == 1) ty += dy;
					if (modey == 2) tx -= dy;
					if (modey == 3) ty -= dy;
					
					rep(i, n) {
						if (x[i] == tx && y[i] == ty) {
							ok[i] = true;
//							cout << modex << " " << modey << endl;
							okx[i] = modex, oky[i] = modey;
						}
					}
				}
			}
			can = true;
			rep(i, n) {
				if (!ok[i]) can = false;
			}
			if (can) {
				cout << 2 << endl;
				cout << dx << " " << dy << endl;
				rep(i, n) {
					if (okx[i] == 0) cout << "R";
					if (okx[i] == 1) cout << "U";
					if (okx[i] == 2) cout << "L";
					if (okx[i] == 3) cout << "D";
					
					if (oky[i] == 0) cout << "R";
					if (oky[i] == 1) cout << "U";
					if (oky[i] == 2) cout << "L";
					if (oky[i] == 3) cout << "D";
					
					cout << endl;
				}
				return 0;
			}
		}
	}
	
	return 0;
}