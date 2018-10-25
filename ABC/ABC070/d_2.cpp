#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<ll, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

const int limit = 100010;
struct edge {
	int to;
	ll cost;
};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d) {
	depth[v] = d;
	for (auto &e: tree[v]) {
		if (e.to == p) continue;
		dfs(e.to, v, d + e.cost);
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	REP(i, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		tree[a].push_back({b, c});
		tree[b].push_back({a, c});
	}
	
	int q, k;
	cin >> q >> k;
	k--;
	
	dfs(k, -1, 0);
	
	REP(i, q) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << depth[x] + depth[y] << endl;
	}
	
	return 0;
}