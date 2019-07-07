#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FORE(i, a, b) for (ll i = (a); i <= (b); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repe(i, n) for (ll i = 0; i <= (n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define SP cout << fixed << setprecision(10)
typedef pair<int, int> P;
const ll INF = (ll)1e16;
const int MOD = (int)1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll l, r;
    cin >> l >> r;

    if (r - l < (ll)(2019)) {
        ll ans = (ll)(5e18);
        FORE(i, l, r) {
            FORE(j, i + 1, r) { ans = min((i * j) % (ll)(2019), ans); }
        }
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}