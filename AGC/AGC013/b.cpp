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

vector<int> g[1000005];
bool memo[1000005];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> a, b;
	a.push_back(0);
	memo[0] = true;
	int cur = 0;
	while (1) {
		bool flag = true;
		for (int u:g[cur]) {
			if (!memo[u]) {
				memo[u] = true;
				a.push_back(u);
				cur = u;
				flag = false;
				break;
			}
		}
		if (flag) break;
	}
	
	cur = 0;
	while (1) {
		int flag = true;
		for (int u:g[cur]) {
			if (!memo[u]) {
				memo[u] = true;
				b.push_back(u);
				cur = u;
				flag = false;
				break;
			}
		}
		if (flag) break;
	}
	
	reverse(b.begin(), b.end());
	for (int x:a) b.push_back(x);
	cout << b.size() << endl;
	for (int x:b) cout << x + 1 << " ";
	cout << endl;
	
	return 0;
}