#include <iostream>
#include <queue>

using namespace std;

const int INF = 1000000;

typedef pair<int, int> P;

#define MAX_H 50
#define MAX_W 50

int H, W;
char s[MAX_H][MAX_W + 1];
int sx = 0, sy = 0;
int gx, gy;
int d[MAX_H][MAX_W];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<P> que;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            d[i][j] = INF;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (que.size()) {
        P p = que.front();
        que.pop();
        if (p.first == gx && p.second == gy) break;
        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && s[nx][ny] != '#' && d[nx][ny] == INF) {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main(void) {
    cin >> H >> W;
    int cnt = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> s[i][j];
            if (s[i][j] == '#') cnt++;
        }
    }
    gx = H - 1, gy = W - 1;

    int res = bfs();
    if (res == INF) {
        cout << "-1" << endl;
    } else {
        cout << H * W - cnt - res - 1 << endl;
    }
    return 0;
}