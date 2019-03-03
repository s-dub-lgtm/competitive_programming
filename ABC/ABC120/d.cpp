#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define FORR(i, a, b) for(int i=(b-1);i>=(a);--i)
#define FORRE(i, a, b) for(int i=(b);i>=(a);--i)
#define rep(i, n) for(ll i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
#define repr(i, n) for(int i=(n-1);i>=0;--i)
#define repre(i, n) for(int i=(n);i>=0;--i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

#define MAX_N 100005

ll par[MAX_N];
ll level[MAX_N];

void init(ll n) {
	rep(i, n) {
		par[i] = i;
		level[i] = 0;
	}
}

ll find(ll x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(ll x, ll y) {
	x = find(x);
	y = find(y);
	if (x == y) return;

//	if (level[x] < level[y]) par[x] = y;
//	else {
//		par[y] = x;
//		if (level[x] == level[y]) level[x]++;
//	}
	par[max(x, y)] = min(x, y);
	level[min(x, y)] = level[x] + level[y] + 1;
	par[min(x, y)] = min(x, y);
}

bool same(ll x, ll y) {
	return find(x) == find(y);
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n, m;
	cin >> n >> m;
	vector<ll> a, b;
	rep(i, m) {
		ll ain, bin;
		cin >> ain >> bin;
		ain--, bin--;
		a.push_back(ain);
		b.push_back(bin);
	}
	
	reverse(ALL(a));
	reverse(ALL(b));
	
	init(n);
	
	vector<ll> ans;
	ans.push_back((n * (n - 1)) / 2);
	ll beforeans = (n * (n - 1)) / 2;
	rep(i, m - 1) {
		ll ai = a[i];
		ll bi = b[i];
		if (same(ai, bi)) {
			ans.push_back(beforeans);
			continue;
		}
		beforeans -= (level[find(ai)] + 1) * (level[find(bi)] + 1);
		ans.push_back(beforeans);
		unite(ai, bi);
//		rep(i, n) {
//			cout << par[i] << " ";
//		}
//		cout << endl;
//		rep(i, n) {
//			cout << level[i] << " ";
//		}
//		cout << endl;
	}
	
	reverse(ALL(ans));
	
	for (auto &t: ans) {
		cout << t << endl;
	}
	
	return 0;
}