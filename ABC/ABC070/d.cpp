#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const int limit = 100010;
using edge = struct {
    int to;
    ll cost;
};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d) {
    depth[v] = d;
    for (auto &e : tree[v]) {
        if (e.to == p) continue;
        dfs(e.to, v, d + e.cost);
    }
}

int main(void) {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    int Q, K;
    cin >> Q >> K;
    K--;

    dfs(K, -1, 0);
    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << depth[x] + depth[y] << endl;
    }

    return 0;
}