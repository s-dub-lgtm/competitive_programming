#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repr(i, n) for(int i=0;i<=(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int t, n, m;
	cin >> t >> n;
	int a[n];
	rep(i, n) cin >> a[i];
	cin >> m;
	int b[m];
	rep(i, m) cin >> b[i];
	
	if (n < m) {
		cout << "no" << endl;
		return 0;
	}
	
	bool sold[n];
	rep(i, n) sold[i] = false;
	rep(i, m) { // 客
		bool sell = false;
		rep(j, n) { // たこ焼き
			if (a[j] <= b[i] and b[i] <= a[j] + t) {
				if (!sold[j]) {
					sold[j] = true;
					sell = true;
				}
			}
			if (sell) {
				break;
			}
		}
	}
	
	int cnt = 0;
	rep(i, n) {
		if (sold[i]) cnt++;
	}
	
	if (cnt == m) cout << "yes" << endl;
	else cout << "no" << endl;
	
	return 0;
}