#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)

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

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	bool relation[15][15] = {};
	REP(i, m) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		relation[x][y] = relation[y][x] = true;
	}
	
	int ans = 0;
	for (int S = 1 << n; S > 0; --S) {
		int t = bitset<32>(S).count();
		if (t <= ans) continue;
		
		bool ok = true;
		REP(i, n) {
			REP(j, i) {
				if (S >> i & S >> j & 1 && !relation[i][j]) {
					ok = false;
				}
			}
		}
		if (ok) {
			ans = t;
		}
	}

	cout << ans << endl;
	
	return 0;
}