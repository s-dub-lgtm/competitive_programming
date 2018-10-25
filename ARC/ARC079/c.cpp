#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define MAX_M 200000

// 入力
int N, M;
int a[MAX_M], b[MAX_M];

bool from1[MAX_M + 1], toN[MAX_M + 1];

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < M; ++i) {
        if (a[i] == 1) {
            from1[b[i]] = true;
        }
        if (b[i] == N) {
            toN[a[i]] = true;
        }
    }

    for (int j = 1; j <= MAX_M; ++j) {
        if (from1[j] && toN[j]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}