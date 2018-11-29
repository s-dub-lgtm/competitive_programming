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

double combination(int n, int r) {
    if (n < r) {
        return 0;
    }
    if (n - r < r) {
        r = n - r;
    }
    double ret = 1;
    rep(i, r) {
        ret *= (n--);
        ret /= i + 1;
    }
    return ret;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, d, x, y;
    cin >> n >> d >> x >> y;

    if (x % d != 0 || y % d != 0) {
        cout << 0 << endl;
        return 0;
    }

    x = abs(x / d);
    y = abs(y / d);

    double ret = 0.0;
    repe(i, n) {
        if (i < x || n - i < y) {
            continue;
        }
        if ((i - x) % 2 != 0) {
            continue;
        }
        if ((n - i - y) % 2 != 0) {
            continue;
        }

        ret += combination(n, i) / pow(2.0, n) * combination(i, (i - x) / 2) /
               pow(2.0, i) * combination(n - i, (n - i - y) / 2) /
               pow(2.0, n - i);
    }

    SP;
    cout << ret << endl;

    return 0;
}