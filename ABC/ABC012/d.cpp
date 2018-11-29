#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i < (b); ++i)
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

    int n, m;
    cin >> n >> m;
    int d[n][n];
    rep(i, n) rep(j, n) d[i][j] = INF;
    rep(i, n) d[i][i] = 0;
    rep(i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        d[a][b] = t;
        d[b][a] = t;
    }

    rep(k, n) {
        rep(i, n) {
            rep(j, n) { d[i][j] = min(d[i][k] + d[k][j], d[i][j]); }
        }
    }

    int min_time = INF;
    rep(i, n) {
        int max_time = 0;
        rep(j, n) { max_time = max(d[i][j], max_time); }
        min_time = min(max_time, min_time);
    }

    cout << min_time << endl;

    return 0;
}