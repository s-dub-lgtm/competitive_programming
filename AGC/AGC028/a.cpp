#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(ll i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll m, ll n) {
	// 引数に０がある場合は０を返す
	if ((0 == m) || (0 == n))
		return 0;
	
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}//lcm

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	
	if (s[0] != t[0]) {
		cout << -1 << endl;
		return 0;
	}
	
	ll ans = lcm(n, m);
	map<ll, char> map1;
	rep(i, n) {
		map1[(i * ans / n) + 1] = s[i];
	}
	
	bool ok = true;
	rep(i, m) {
		if (map1.find((i * ans / m) + 1) != map1.end() && map1[(i * ans / m) + 1] != t[i]) {
			ok = false;
			break;
		}
	}
	
	if (ok) cout << ans << endl;
	else cout << -1 << endl;
	
	return 0;
}