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
	
	int n, ng1, ng2, ng3;
	cin >> n >> ng1 >> ng2 >> ng3;
	
	if (n == ng1 || n == ng2 || n == ng3) {
		cout << "NO" << endl;
		return 0;
	}
	
	rep(i, 100) {
//		cout << n << endl;
		if (n <= 0) {
			cout << "YES" << endl;
			return 0;
		}
		int next = n - 3;
		if (!(next == ng1 || next == ng2 || next == ng3)) {
			n = next;
			continue;
		}
		next = n - 2;
		if (!(next == ng1 || next == ng2 || next == ng3)) {
			n = next;
			continue;
		}
		next = n - 1;
		if (!(next == ng1 || next == ng2 || next == ng3)) {
			n = next;
			continue;
		}
	}
	
	if (n <= 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}