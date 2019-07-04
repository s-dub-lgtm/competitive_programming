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
const ll MOD = (ll)1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> ok(n + 1, true);
    rep(i, m) {
        int a;
        cin >> a;
        ok[a] = false;
    }

    vector<ll> dp(n + 1);
    dp[0] = 1;
    rep(i, n) {
        FORE(j, i + 1, min(n, i + 2)) {
            if (ok[j]) {
                dp[j] += dp[i];
                dp[j] %= MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}