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
	
	int n, a, b;
	cin >> n >> a >> b;
	double v[n];
	REP(i, n) cin >> v[i];
	
	sort(v, v + n);
	reverse(v, v + n);
	
	double sum = 0.0;
	REP(i, a) {
		sum += v[i];
	}
	double ave = sum / a;
	
	
	ll C[55][55];
	REP(i, n + 1) {
		REP(j, i + 1) {
			if (j == 0 || j == i) {
				C[i][j] = 1LL;
			} else {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
	}
	
	int sameNumInN = 0, sameNumInA = 0;
	REP(i, n) {
		if (v[i] == v[a - 1]) {
			sameNumInN++;
			if (i < a) {
				sameNumInA++;
			}
		}
	}
	
	ll cnt = 0LL;
	if (sameNumInA == a) {
		FOR(i, a, b + 1) {
			cnt += C[sameNumInN][i];
		}
	} else {
		cnt += C[sameNumInN][sameNumInA];
	}
	
	SP;
	cout << ave << endl;
	cout << cnt << endl;
	
	return 0;
}