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
	int p[n];
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	
	int a[n], b[n];
	rep(i, n) a[i] = i * n;
	rep(i, n) b[i] = (n - i - 1) * n;
	rep(i, n) {
		int j = p[i];
		a[j] += i;
		b[j] += i;
	}
	
	rep(i, n) {
		cout << a[i] + 1;
		if (i == n - 1) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
	rep(i, n) {
		cout << b[i] + 1;
		if (i == n - 1) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
	
	return 0;
}