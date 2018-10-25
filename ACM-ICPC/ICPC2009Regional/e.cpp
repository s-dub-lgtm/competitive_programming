#include <iostream>

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

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	while (1) {
		int m, n;
		cin >> m >> n;
		if (m == 0 && n == 0) return 0;
		
		int b[m], r[n];
		REP(i, m) cin >> b[i];
		REP(i, n) cin >> r[i];
		
		bool memo[m][n];
		REP(i, m) {
			REP(j, n) {
				if (gcd(b[i], r[j]) == 1) memo[i][j] = false;
				else memo[i][j] = true;
			}
		}
		
		int cnt[n];
		REP(i, n) cnt[i] = 0;
		
		REP(i, m) {
			REP(j, n) {
				if (memo[i][j]) {
					++cnt[j];
				}
			}
		}
		
		int maxpair = 0;
		REP(i, m) {
			int pairindex = n;
			int mincnt = 505;
			REP(j, n) {
				if (memo[i][j]) {
					if (cnt[j] == 0) continue;
					if (cnt[j] < mincnt) {
						pairindex = j;
						mincnt = cnt[j];
					}
				}
			}
			if (pairindex != n) {
				++maxpair;
				cnt[pairindex] = 0;
			}
		}
		
		cout << maxpair << endl;
	}
	
	return 0;
}