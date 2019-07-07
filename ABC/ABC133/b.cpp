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

    int n, d;
    cin >> n >> d;
    int x[n][d];
    rep(i, n) rep(j, d) cin >> x[i][j];

    int cnt = 0;
    rep(i, n) {
        FOR(j, i, n) {
            if (i != j) {
                double sum = 0;
                rep(k, d) { sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]); }
                if (sqrt(sum) == (int)(sqrt(sum))) cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}