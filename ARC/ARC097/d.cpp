#include <iostream>

using namespace std;

#define MAX_V 100001

int perm[MAX_V], clr[MAX_V];

int find(int x) {
    if (x != clr[x]) {
        clr[x] = find(clr[x]);
    }
    return clr[x];
}

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> perm[i];
        clr[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int aa, bb;
        cin >> aa >> bb;
        if (find(aa) == find(bb)) continue;
        clr[clr[bb]] = clr[aa];
    }
    for (int i = 1; i <= n; ++i) {
        find(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (clr[i] == clr[perm[i]]) ans++;
    }

    cout << ans << endl;
    return 0;
}