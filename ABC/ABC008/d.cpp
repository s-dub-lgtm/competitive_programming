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
const int inf = (int) 1e9;
const int mod = (int) 1e9 + 7;

template<class T>
bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T>
bool chmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int w, h;
int n;
vector<int> x, y;

map<tuple<int, int, int, int>, int> memo;

int solve(int y1, int y2, int x1, int x2) {
	if (memo.find(make_tuple(y1, y2, x1, x2)) != memo.end())
		return memo[make_tuple(y1, y2, x1, x2)];
	
	int ret = 0;
	rep(i, n) {
		if (y[i] < y1 || y2 < y[i] || x[i] < x1 || x2 < x[i])
			continue;
		
		int tmp = y2 - y1 + x2 - x1 + 1;
		tmp += solve(y1, y[i] - 1, x1, x[i] - 1);
		tmp += solve(y1, y[i] - 1, x[i] + 1, x2);
		tmp += solve(y[i] + 1, y2, x1, x[i] - 1);
		tmp += solve(y[i] + 1, y2, x[i] + 1, x2);
		ret = max(ret, tmp);
	}
	
	return memo[make_tuple(y1, y2, x1, x2)] = ret;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> w >> h >> n;
	x.resize(n);
	y.resize(n);
	rep(i, n)cin >> x[i] >> y[i];
	
	cout << solve(1, h, 1, w) << endl;
	
	return 0;
}