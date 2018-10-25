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
	int a[m], b[m], c[m];
	REP(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
	}
	
	int d[n][n];
	REP(i, n) {
		REP(j, n) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
	
	REP(i, m) {
		chmin(d[a[i]][b[i]], c[i]);
		chmin(d[b[i]][a[i]], c[i]);
	}
	
	REP(k, n) {
		REP(i, n) {
			REP(j, n) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	
	int ans = m;
	REP(i, m) {
		bool used = false;
		REP(j, n) {
			if (d[j][a[i]] + c[i] == d[j][b[i]]) used = true;
		}
		if (used) ans--;
	}
	
	cout << ans << endl;
	
	return 0;
}