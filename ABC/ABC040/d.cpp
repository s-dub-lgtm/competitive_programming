#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define SP cout << fixed << setprecision(10)
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

#define MAX_N 100000

int par[MAX_N];
int rank[MAX_N];

void init(int n) {
	rep(i, n) {
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x) {
	if (par[x] == x) {
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	
	if (rank[x] < rank[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	}
}

bool same(int x, int y) { return find(x) == find(y); }

int n, m;
int ans[MAX_N];

int main(void) {
	// code
	cin >> n >> m;
	vector<tuple<int, int, int> > vec;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		vec.push_back(make_tuple(c, a, b));
	}
	sort(ALL(vec));
	
	int q;
	cin >> q;
	vector<tuple<int, int, int> > wvec;
	rep(i, q) {
		int v, w;
		cin >> v >> w;
		v--;
		wvec.push_back(make_tuple(w, v, i));
	}
	sort(ALL(wvec));
	
	init(n);
	
	int i = 0;
	for (auto t : wvec) {
		int w, v, id;
		tie(w, v, id) = t;
		
		while (i < m && get<0>(vec[i]) > w) {
			unite(get<1>(vec[i]), get<2>(vec[i]));
			i++;
		}
		
		ans[id] = rank[v];
	}
	
	rep(i, q) cout << ans[i] << endl;
	
	return 0;
}