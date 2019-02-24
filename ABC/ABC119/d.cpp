#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define FORR(i, a, b) for(int i=(b-1);i>=(a);--i)
#define FORRE(i, a, b) for(int i=(b);i>=(a);--i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
#define repr(i, n) for(int i=(n-1);i>=0;--i)
#define repre(i, n) for(int i=(n);i>=0;--i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int a, b, q;
	cin >> a >> b >> q;
	vector<ll> s, t, xvec;
	rep(i, a) {
		ll d;
		cin >> d;
		s.push_back(d);
	}
	rep(i, b) {
		ll d;
		cin >> d;
		t.push_back(d);
	}
	rep(i, q) {
		ll x;
		cin >> x;
		xvec.push_back(x);
	}
	
	sort(ALL(s));
	sort(ALL(t));
	
	for (ll x: xvec) {
//		cout << x << endl;
		int lefts = upper_bound(ALL(s), x) - s.begin() - 1;
		int leftt = upper_bound(ALL(t), x) - t.begin() - 1;
		int rights = lower_bound(ALL(s), x) - s.begin();
		int rightt = lower_bound(ALL(t), x) - t.begin();
//		cout << lefts << " " << leftt << " " << rights << " " << rightt << endl;
		
		ll ans = (ll) (1e18);
		if (lefts != -1 and leftt != -1) {
			ll bothleft = x - min(s[lefts], t[leftt]);
			ans = min(bothleft, ans);
		}
		if (lefts != -1 and rightt != b) {
			ll leftright = min(x - s[lefts], t[rightt] - x) * 2 + max(x - s[lefts], t[rightt] - x);
			ans = min(leftright, ans);
		}
		if (leftt != -1 and rights != a) {
			ll leftright = min(x - t[leftt], s[rights] - x) * 2 + max(x - t[leftt], s[rights] - x);
			ans = min(leftright, ans);
		}
		if (rights != a and rightt != b) {
			ll bothright = max(s[rights], t[rightt]) - x;
			ans = min(bothright, ans);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}