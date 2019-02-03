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
	int x[m];
	rep(i, m) cin >> x[i];
	
	if (n >= m) {
		cout << 0 << endl;
		return 0;
	}
	
	sort(x, x + m);
	
	if (n == 1) {
		cout << x[m - 1] - x[0] << endl;
		return 0;
	}
	
	int d[m - 1];
	rep(i, m - 1) {
		d[i] = x[i + 1] - x[i];
	}
	
	sort(d, d + m - 1);
	
	int sum = 0;
	rep(i, m - n) sum += d[i];
	
	cout << sum << endl;
	
	return 0;
}