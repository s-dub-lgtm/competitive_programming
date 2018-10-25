#include <iostream>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, z, w;
	cin >> n >> z >> w;
	int a[n];
	REP(i, n) cin >> a[i];
	
	if (n == 1) cout << abs(a[0] - w) << endl;
	else cout << max(abs(a[n - 1] - w), abs(a[n - 2] - a[n - 1])) << endl;
	
	return 0;
}