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

int dp[11][2000000];

int floor(int j, int i) {
	if (j % i == 0) return j / i;
	else return j / i + 1;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int d;
	ll g;
	cin >> d >> g;
	g /= 100;
	int p[d + 1], c[d + 1];
	FOR(i, 1, d + 1) {
		cin >> p[i] >> c[i];
		c[i] /= 100;
	}
	
	REP(i,11) REP(j,2000000) dp[i][j]=INF;
	
//	int dp[11][100000];
	
	// i=1
//	REP(j, p[1] + 1) {
//		dp[1][j] = j;
//	}
//	FOR(j, p[1] + 1, p[1] + c[1] + 1) {
//		dp[1][j] = dp[1][p[1]];
//	}
	
	FOR(i, 1, d + 1) {
		REP(j, 200000) {
			if (j <= i * p[i]) {
				dp[i][j] = floor(j, i);
			} else if (j <= i * p[i] + c[i]) {
				dp[i][j] = dp[i][i * p[i]];
			} else {
				int minValue = INF;
				FOR(k, 1, i) {
					minValue = min(minValue, dp[k][j - (i * p[i] + c[i])]);
				}
				dp[i][j] = dp[i][i*p[i]] + minValue;
			}
		}
//		REP(j, i * p[i] + 1) {
//			if (dp[i][j - 1] != 0) {
//				dp[i][j] = min(floor(j, i), dp[i][j - i]);
//			} else {
//				dp[i][j] = floor(j, i);
//			}
//		}
//		FOR(j, i * p[i] + 1, i * p[i] + c[i] + 1) {
//			dp[i][j] = dp[i][i * p[i]];
//		}
	}
	
	int minValue = INF;
	FOR(i, 1, d + 1) {
//		cout << "g: " << g << "i: " << i << endl;
//		cout << dp[][] << endl;
		minValue = min(minValue, dp[i][g]);
	}
	
//	REP(i, d + 1) {
//		REP(j, 100000) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	cout << minValue << endl;
	
	return 0;
}