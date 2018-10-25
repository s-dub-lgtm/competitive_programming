#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)

typedef pair<int, int> P;

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
	
	ll r, c, x, y, d, l;
	cin >> r >> c >> x >> y >> d >> l;
	
	ll pat1 = (r - x + 1) * (c - y + 1) % MOD;
	
	ll C[910][910];
	REP(i, 909) {
		C[i][0] = 1;
		FOR(j, 1, i + 1) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			C[i][j] %= MOD;
		}
	}
	
	ll pat2 = C[x * y][d];
	
//	cout << pat1 << " " << pat2 << endl;
	
	cout << pat1 * pat2 % MOD << endl;
	
	return 0;
}