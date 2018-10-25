#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> g[100001];
bool flag[100001];
int d[2][100001];

void dfs(int pos, int num, int start) {
    for (int i = 0; i < g[pos].size(); ++i) {
        d[start][pos] = num;
        if (!flag[g[pos][i]]) {
            flag[pos] = true;
            dfs(g[pos][i], num + 1, start);
            flag[pos] = false;
        }
    }
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, 1);
    dfs(N, 0, 0);

    int fe = 0, su = 0;
    for (int i = 1; i <= N; ++i) {
        if (d[1][i] <= d[0][i]) fe++;
        else su++;
    }

    cout << (fe > su ? "Fennec" : "Snuke") << endl;
    return 0;
}