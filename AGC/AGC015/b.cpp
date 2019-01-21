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
	
	string s;
	cin >> s;
	
	int n = s.length();
	
	ll sum = 0;
	rep(i, n) {
		if (s[i] == 'U') {
			sum += 2 * (i - 0) + (n - i - 1);
		} else {
			sum += (i - 0) + 2 * (n - i - 1);
		}
//		cout << sum << endl;
	}
	
	cout << sum << endl;
	
	return 0;
}