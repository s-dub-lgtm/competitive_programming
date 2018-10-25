#include <iostream>

using namespace std;

#define MAX_N 100
#define MAX_P 100

// 入力
int N;
int p[MAX_N + 1];

bool dp[MAX_N + 1][MAX_N * MAX_P + 1];

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> p[i];
    }

    dp[0][0] = true;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= MAX_N * MAX_P; ++j) {
            if (p[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - p[i]];
            }
        }
    }

    int cnt = 0;
    for (int j = 0; j <= MAX_N * MAX_P; ++j) {
        if (dp[N][j]) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}