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

bool intersection(int ax, int ay, int bx, int by, int cx, int cy, int dx,
                  int dy) {
    ll s1 = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
    ll s2 = (bx - ax) * (dy - ay) - (by - ay) * (dx - ax);
    ll s3 = (dx - cx) * (by - cy) - (dy - cy) * (bx - cx);
    ll s4 = (dx - cx) * (ay - cy) - (dy - cy) * (ax - cx);
    if (s1 * s2 < 0 && s3 * s4 < 0)
        return true;
    else
        return false;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int n;
    cin >> n;
    int x[n], y[n];
    rep(i, n) cin >> x[i] >> y[i];

    int ans = 0;
    rep(i, n) ans += intersection(ax, ay, bx, by, x[i], y[i], x[(i + 1) % n],
                                  y[(i + 1) % n]);

    cout << ans / 2 + 1 << endl;

    return 0;
}