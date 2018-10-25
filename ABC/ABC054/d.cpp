#include <iostream>

using namespace std;

#define MAX_N 40
#define MAX_AB 10

const int INF = 1000000;

// 入力
int N, Ma, Mb;
int a[MAX_N], b[MAX_N], c[MAX_N];

int dp[MAX_N + 1][MAX_N * MAX_AB + 1][MAX_N * MAX_AB + 1];

int main(void) {
    cin >> N >> Ma >> Mb;
    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i <= N; ++i) {
        for (int ca = 0; ca <= MAX_N * MAX_AB; ++ca) {
            for (int cb = 0; cb <= MAX_N * MAX_AB; ++cb) {
                dp[i][ca][cb] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int ca = 0; ca <= MAX_N * MAX_AB; ++ca) {
            for (int cb = 0; cb <= MAX_N * MAX_AB; ++cb) {
                if (dp[i][ca][cb] == INF) continue;
                dp[i + 1][ca][cb] = min(dp[i + 1][ca][cb], dp[i][ca][cb]);
                dp[i + 1][ca + a[i]][cb + b[i]] = min(dp[i + 1][ca + a[i]][cb + b[i]], dp[i][ca][cb] + c[i]);
            }
        }
    }

    int ans = INF;
    for (int ca = 1; ca <= MAX_N * MAX_AB; ++ca) {
        for (int cb = 1; cb <= MAX_N * MAX_AB; ++cb) {
            if (ca * Mb == cb * Ma) ans = min(ans, dp[N][ca][cb]);
        }
    }

    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}