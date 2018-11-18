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
	
	int n, m;
	cin >> n >> m;
	
	repe(x, n) {
		int y = 4 * n - 2 * x - m;
		if (0 <= y and y <= n) {
			int z = n - x - y;
			if (0 <= z and z <= n) {
				cout << x << " " << y << " " << z << endl;
				return 0;
			}
		}
	}
	
	cout << "-1 -1 -1" << endl;
	
	return 0;
}