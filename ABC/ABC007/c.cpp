#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)

typedef pair<int, int> P;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

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

int r, c;
int sy, sx;
int gy, gx;
char maze[55][55];

int d[55][55];

int bfs() {
	queue<P> que;
	REP(i, r) REP(j, c) d[i][j] = INF;
	que.push(P(sy, sx));
	d[sy][sx] = 0;
	
	while (que.size()) {
		P p = que.front();
		que.pop();
		if (p.first == gy && p.second == gx) break;
		
		REP(i, 4) {
			int ny = p.first + dy[i], nx = p.second + dx[i];
			if (0 <= ny && ny < r && 0 <= nx && nx < c && maze[ny][nx] != '#' && d[ny][nx] == INF) {
				que.push(P(ny, nx));
				d[ny][nx] = d[p.first][p.second] + 1;
			}
		}
	}
	
	return d[gy][gx];
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> r >> c;
	cin >> sy >> sx;
	sy--, sx--;
	cin >> gy >> gx;
	gy--, gx--;
	REP(i, r) REP(j, c) cin >> maze[i][j];
	
	cout << bfs() << endl;
	
	return 0;
}