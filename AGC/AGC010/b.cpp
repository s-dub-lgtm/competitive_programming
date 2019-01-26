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
	
	ll n;
	cin >> n;
	ll a[n];
	rep(i, n) cin >> a[i];
	
	ll sum = 0;
	rep(i, n) sum += a[i];
	ll m = n * (n + 1) / 2;
	if (sum % m != 0) {
		cout << "NO" << endl;
		return 0;
	}
	ll time = sum / m;
	
	rep(i, n) {
		ll dif = a[(i + 1) % n] - a[i];
		dif -= time;
		if (dif > 0) {
			cout << "NO" << endl;
			return 0;
		}
		if (dif % n != 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	
	return 0;
}