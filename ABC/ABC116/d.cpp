#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<ll, ll> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	vector<int> f(n + 10);
	priority_queue<P> q;
	priority_queue<P, vector<P>, greater<P>> q2;
	rep(i, n) {
		ll t, d;
		cin >> t >> d;
		q.push(P(d, t));
	}
	
	int cnt = 0;
	ll kind = 0, s = 0;
	while (cnt < k) {
		P p = q.top();
		q.pop();
		q2.push(p);
		s += p.first;
		if (f[p.second] == 0) kind++;
		f[p.second]++;
		cnt++;
	}
	
	ll ans = s + kind * kind;
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		if (f[p.second]) continue;
		ll m = -1;
		while (!q2.empty()) {
			P p2 = q2.top();
			q2.pop();
			if (f[p2.second] > 1) {
				f[p2.second]--;
				m = p2.first;
				break;
			}
		}
		if (m == -1) break;
		kind++;
		f[p.second]++;
		s += p.first;
		s -= m;
		ans = max(ans, s + kind * kind);
	}
	
	cout << ans << endl;
	
	return 0;
}