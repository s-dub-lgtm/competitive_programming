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
	
	int n, ma, mb;
	cin >> n >> ma >> mb;
	int a[n], b[n], c[n];
	REP(i, n) cin >> a[i] >> b[i] >> c[i];
	
	int dp[n + 1][405][405];
	REP(i, n + 1) REP(j, 405) REP(k, 405) dp[i][j][k] = INF;
	
	dp[0][0][0] = 0;
	
	REP(i, n) {
		REP(j, 405) {
			REP(k, 405) {
				if (dp[i][j][k] == INF) continue;
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
				dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
			}
		}
	}
	
	int ans = INF;
	FOR(j, 1, 405) {
		FOR(k, 1, 405) {
			if (j * mb == k * ma) chmin(ans, dp[n][j][k]);
		}
	}
	
	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}