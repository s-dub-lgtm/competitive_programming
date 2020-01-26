#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repe(i, n) for (int i = 0; i <= (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sp cout << fixed << setprecision(10)
typedef pair<int, int> P;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int h, n;
int a[10005], b[10005];
int dp[1005][10005];

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> h >> n;
    rep(i, n) cin >> a[i] >> b[i];

    repe(j, h) dp[0][j] = ceil((double)j / a[0]) * b[0];
    // repe(i, n) {
    //     repe(j, h) { cout << dp[i][j] << " "; }
    //     cout << endl;
    // }
    // cout << endl;

    FOR(i, 1, n) {
        repe(j, h) { dp[i][j] = min(dp[i - 1][j], dp[i][j - a[i]] + b[i]); }
    }

    // repe(i, n) {
    //     repe(j, h) { cout << dp[i][j] << " "; }
    //     cout << endl;
    // }

    cout << dp[n - 1][h] << endl;

    return 0;
}