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

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int a[105];
	rep(i, n) cin >> a[i];
	
	double sum = 0;
	rep(i, n) {
		int t = 0;
		rep(j, n) {
			if (a[i] % a[j] == 0) t++;
		}
		sum += 1.0 - (t / 2) * 1.0 / t;
	}
	
	SP;
	cout << sum << endl;
	
	return 0;
}