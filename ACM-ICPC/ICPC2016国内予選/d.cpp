#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

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

int n, w[305];
int dp[305][305];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	while (1) {
		cin >> n;
		if (n == 0) break;
		REP(i, n) cin >> w[i];
		memset(dp, 0, sizeof(dp));
		
		for (int i = n - 1; i >= 0; --i) {
			dp[i][i] = 0;
			dp[i][i + 1] = 0;
			for (int j = i + 1; j <= n; ++j) {
				if (i + 1 < j && abs(w[i] - w[j - 1]) <= 1 && dp[i + 1][j - 1] == j - i - 2) {
					dp[i][j] = j - i;
				}
				for (int k = j + 1; k <= n; ++k) {
					chmax(dp[i][k], dp[i][j] + dp[j][k]);
				}
			}
		}
		
		cout << dp[0][n] << endl;
	}
	
	return 0;
}