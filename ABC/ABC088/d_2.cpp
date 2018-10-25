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

int h, w;
int sy, sx;
int gy, gx;
char maze[55][55];

int d[55][55];

int bfs() {
	queue<P> que;
	REP(i, h)REP(j, w) d[i][j] = INF;
	que.push(P(sy, sx));
	d[sy][sx] = 0;
	
	while (que.size()) {
		P p = que.front();
		que.pop();
		if (p.first == gy && p.second == gx) break;
		
		REP(i, 4) {
			int ny = p.first + dy[i], nx = p.second + dx[i];
			if (0 <= ny && ny < h && 0 <= nx && nx < w && maze[ny][nx] != '#' && d[ny][nx] == INF) {
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
	
	cin >> h >> w;
	sy = 0, sx = 0;
	gy = h - 1, gx = w - 1;
	int blackCnt = 0;
	REP(i, h) {
		REP(j, w) {
			cin >> maze[i][j];
			if (maze[i][j] == '#') blackCnt++;
		}
	}
	
	if (bfs() == INF) {
		cout << -1 << endl;
	} else {
		cout << h * w - bfs() - 1 - blackCnt << endl;
	}
	
	return 0;
}