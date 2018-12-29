#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(ll i=(a);i<(b);++i)
#define FORE(i, a, b) for(ll i=(a);i<=(b);++i)
#define rep(i, n) for(ll i=0;i<(n);++i)
#define repe(i, n) for(ll i=0;i<=(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<ll, ll> P;
const ll INF = (ll) 1e9;
const ll MOD = (ll) 1e9 + 7;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll l, n;
	cin >> l >> n;
	vector<ll> x;
	rep(i, n) {
		ll num;
		cin >> num;
		x.push_back(num);
	}
	
	ll ans = 0;
	ll pos = 0;
	
	while (n > 0) {
		if (n == 1) {
			ans += max(abs(x[0] + l - pos) % l, abs(pos + l - x[0]) % l);
			// cout << abs(x[0] + l - pos) % l << " " << abs(pos + l - x[0]) % l << endl;
			n--;
		} else {
			// cout << abs(x[0] + l - pos) % l << " " << abs(pos + l - x[n - 1]) % l << endl;
			if (abs(x[0] + l - pos) % l == abs(pos + l - x[n - 1]) % l) {
				// cout << "same" << endl;
				ll forwardcnt = 0, reversecnt = 0;
				if (pos < l / 2) {
					rep(i, n) {
						if (pos < x[i] and x[i] < pos + (l / 2)) reversecnt++;
						else forwardcnt++;
					}
				} else {
					rep(i, n) {
						if (pos - (l / 2) < x[i] and x[i] < pos) forwardcnt++;
						else reversecnt++;
					}
				}
				// cout << forwardcnt << " " << reversecnt << endl;
				if (forwardcnt > reversecnt) {
					ans += abs(x[0] + l - pos) % l;
					pos = x[0];
					x.erase(x.begin(), x.begin() + 1);
					n--;
				} else {
					ans += abs(pos + l - x[n - 1]) % l;
					pos = x[n - 1];
					x.erase(x.end() - 1, x.end());
					n--;
				}
			} else if (abs(x[0] + l - pos) % l > abs(pos + l - x[n - 1]) % l) {
				// cout << "reverse" << endl;
				ans += abs(x[0] + l - pos) % l;
				pos = x[0];
				x.erase(x.begin(), x.begin() + 1);
				n--;
			} else {
				// cout << "forward" << endl;
				ans += abs(pos + l - x[n - 1]) % l;
				pos = x[n - 1];
				x.erase(x.end() - 1, x.end());
				n--;
			}
			// cout << pos << endl;
			// cout << ans << endl;
			// cout << x[0] << " " << x[n - 1] << endl;
			// cout << "*****" << endl;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}