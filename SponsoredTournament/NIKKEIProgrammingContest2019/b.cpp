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
	
	int n;
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;
	
	int sum = 0;
	rep(i, n) {
		if (a[i] == b[i] and b[i] == c[i]) continue;
		if (a[i] == b[i] or b[i] == c[i] or c[i] == a[i]) {
			sum++;
			continue;
		}
		sum += 2;
	}
	
	cout << sum << endl;
	
	return 0;
}