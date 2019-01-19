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
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, x;
	cin >> n >> x;
	
	if (x == 1 or x == 2 * n - 1) {
		cout << "No" << endl;
	} else {
		int ans[2 * n - 1];
		memset(ans, -1, sizeof(ans));
		ans[n - 2] = x - 1;
		ans[n - 1] = x;
		ans[n] = x + 1;
		int now = 1;
		rep(i, 2 * n - 1) {
			if (ans[i] == -1) {
				while (abs(now - x) <= 1) now++;
				ans[i] = now++;
			}
		}
		cout << "Yes" << endl;
		rep(i, 2 * n - 1) cout << ans[i] << endl;
	}
	
	return 0;
}