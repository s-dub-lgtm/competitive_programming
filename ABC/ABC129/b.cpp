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

    int n;
    cin >> n;
    int w[n];
    rep(i, n) cin >> w[i];

    int minabs = INF;
    int sum1 = 0, sum2 = 0;
    rep(i, n) {
        rep(j, n) {
            if (j <= i)
                sum1 += w[j];
            else
                sum2 += w[j];
        }
        minabs = min(abs(sum1 - sum2), minabs);
        sum1 = 0, sum2 = 0;
    }

    cout << minabs << endl;

    return 0;
}