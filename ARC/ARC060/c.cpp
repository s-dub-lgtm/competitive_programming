#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 50
#define MAX_X 50

// 入力
int N, A;
int x[MAX_N + 1];

// DPテーブル
long long dp[MAX_N + 1][MAX_N + 1][MAX_N * MAX_X + 1];

int main(void) {
    cin >> N >> A;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i];
    }

    for (int j = 0; j <= N; ++j) {
        for (int k = 0; k <= N; ++k) {
            for (int s = 0; s <= N * MAX_X; ++s) {
                if (j == 0 && k == 0 && s == 0) {
                    dp[j][k][s] = 1;
                } else if (j >= 1 && s < x[j]) {
                    dp[j][k][s] = dp[j - 1][k][s];
                } else if (j >= 1 && k >= 1 && s >= x[j]) {
                    dp[j][k][s] = dp[j - 1][k][s] + dp[j - 1][k - 1][s - x[j]];
                } else {
                    dp[j][k][s] = 0;
                }
            }
        }
    }

    long long num = 0;
    for (int k = 1; k <= N; ++k) {
        num += dp[N][k][k * A];
    }

    cout << num << endl;
    return 0;
}
