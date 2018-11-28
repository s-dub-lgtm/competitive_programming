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

ll rec(ll x) {
	stringstream ss;
	ss << x;
	string s = ss.str();
	ll dp[20][2] = {};
	dp[0][0] = 1;
	rep(i, s.size()) {
		rep(j, 2) {
			for (int k = 0; k < (j ? 10 : s[i] - '0' + 1); ++k) {
				if (k == 4 || k == 9) continue;
				int jj = j;
				if (k < s[i] - '0') jj = 1;
				dp[i + 1][jj] += dp[i][j];
			}
		}
	}
	return x - (dp[s.size()][0] + dp[s.size()][1]);
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll a, b;
	cin >> a >> b;
	cout << rec(b) - rec(a - 1) << endl;
	
	return 0;
}