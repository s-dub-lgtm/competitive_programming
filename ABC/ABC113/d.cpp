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
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<int> > dp(h + 1, vector<int>(w, 0));
    dp[0][0] = 1;
    rep(i, h) {
        rep(j, w) {
            rep(k, 1 << (w - 1)) {
                bool ok = true;
                rep(l, w - 2) {
                    if (((k >> l) & 1) && ((k >> (l + 1)) & 1)) {
                        ok = false;
                    }
                }
                if (ok) {
                    if (j >= 1 && ((k >> (j - 1)) & 1)) {
                        dp[i + 1][j - 1] += dp[i][j];
                        dp[i + 1][j - 1] %= MOD;
                    } else if (j <= w - 2 && ((k >> j) & 1)) {
                        dp[i + 1][j + 1] += dp[i][j];
                        dp[i + 1][j + 1] %= MOD;
                    } else {
                        dp[i + 1][j] += dp[i][j];
                        dp[i + 1][j] %= MOD;
                    }
                }
            }
        }
    }

    cout << dp[h][k - 1] << endl;

    return 0;
}