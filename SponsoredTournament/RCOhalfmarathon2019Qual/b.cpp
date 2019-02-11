#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define FORR(i, a, b) for(int i=(b-1);i>=(a);--i)
#define FORRE(i, a, b) for(int i=(b);i>=(a);--i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
#define repr(i, n) for(int i=(n-1);i>=0;--i)
#define repre(i, n) for(int i=(n);i>=0;--i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	int a[n][n];
	rep(i, n)rep(j, n) cin >> a[i][j];
	
	int cnt[10] = {};
	rep(i, n)rep(j, n) cnt[a[i][j]]++;
	
	int cost[10] = {};
	FOR(i, 1, 10) {
		cost[i] = cost[i - 1];
		FORE(j, 1, i) {
			cost[i] += cnt[j];
		}
	}
//	rep(i,10) cout<<cost[i]<<" ";
	
	FOR(k, 3, 4) {
		m -= cost[k - 1];
		if (m <= 0) return 0;
		rep(i, n) {
			rep(j, n) {
				if (a[i][j] < k) {
					rep(l, k - a[i][j]) {
						cout << 1 << " " << i << " " << j << endl;
						m--;
						if (m <= 0) return 0;
					}
				}
				cout << 2 << " " << i << " " << j << endl;
				m--;
				if (m <= 0) return 0;
			}
		}
//		rep(i, n) {
//			rep(j, n) {
//				if (a[i][j] == k) {
//					cout << 2 << " " << i << " " << j << endl;
//					m--;
//					if (m <= 0) return 0;
//				}
//			}
//		}
		m = 2500;
	}
	
	return 0;
}