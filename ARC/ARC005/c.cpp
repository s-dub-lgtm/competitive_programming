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
char maze[505][505];

bool used[505][505][3];

bool bfs() {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(sy, sx, 0));
	used[sy][sx][0] = true;
	
	while (q.size()) {
		int y, x, t;
		tie(y, x, t) = q.front();
		q.pop();
		if (y == gy && x == gx) break;
		
		REP(i, 4) {
			int ny = y + dy[i], nx = x + dx[i];
			if (!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
			if (maze[ny][nx] == '#' && t == 2) continue;
			if (used[ny][nx][t]) continue;
			if (maze[ny][nx] == '#') {
				used[ny][nx][t + 1] = true;
				q.push(make_tuple(ny, nx, t + 1));
			} else {
				used[ny][nx][t] = true;
				q.push(make_tuple(ny, nx, t));
			}
		}
	}
	bool res = false;
	REP(i, 3) res = res | used[gy][gx][i];
	return res;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> h >> w;
	REP(i, h) {
		REP(j, w) {
			cin >> maze[i][j];
			if (maze[i][j] == 's') sy = i, sx = j;
			if (maze[i][j] == 'g') gy = i, gx = j;
		}
	}
	
	if (bfs()) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}