#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repe(i, n) for (int i = 0; i <= (n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define SP cout << fixed << setprecision(10)
typedef pair<int, int> P;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int w, n, k;
    cin >> w >> n >> k;
    int a[n], b[n];
    rep(i, n) cin >> a[i] >> b[i];

    int dp[n + 1][w + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    rep(i, n) {
        repe(j, w) {
            repe(l, k) {
                if (j < a[i] || l < 1) {
                    dp[i + 1][j][l] = dp[i][j][l];
                } else {
                    dp[i + 1][j][l] =
                        max(dp[i][j][l], dp[i][j - a[i]][l - 1] + b[i]);
                }
            }
        }
    }

    cout << dp[n][w][k] << endl;

    return 0;
}