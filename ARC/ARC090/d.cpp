#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define MAX_N 100000

typedef pair<int, int> pii;
vector<pii> edge[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1];

bool dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < edge[v].size(); ++i) {
        int next = edge[v][i].first;
        int cost = edge[v][i].second;
        if (!visited[next]) {
            dist[next] = dist[v] + cost;
            if (!dfs(next)) {
                return false;
            }
        } else {
            if (dist[next] != dist[v] + cost) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    if (M == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = 0; i < M; ++i) {
        int l, r, val;
        cin >> l >> r >> val;
        edge[l].push_back(make_pair(r, val));
        edge[r].push_back(make_pair(l, -val));
    }

    for (int i = 0; i < MAX_N + 2; ++i) {
        visited[i] = false;
    }

    for (int i = 1; i < N; ++i) {
        if (!visited[i]) {
            dist[i] = 0;
            if (!dfs(i)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}