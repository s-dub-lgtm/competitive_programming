#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int color[1000001];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		color[a]++, color[b + 1]--;
	}
	
	FOR(i, 1, 1000001) {
		color[i] += color[i - 1];
	}
	
	int ans = 0;
	rep(i, 1000001) {
		ans = max(color[i], ans);
	}
	
	cout << ans << endl;
	
	return 0;
}