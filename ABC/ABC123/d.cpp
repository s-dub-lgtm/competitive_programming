#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FORE(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repe(i, n) for (ll i = 0; i <= (n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define SP cout << fixed << setprecision(10)
typedef pair<ll, ll> P;
const ll INF = (ll)1e9;
const ll MOD = (ll)1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll a[x], b[y], c[z];
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];

    sort(a, a + x);
    sort(b, b + y);
    sort(c, c + z);

    ll aindex = max(0LL, x - 2);
    ll bindex = max(0LL, y - 2);
    ll cindex = max(0LL, z - 2);
    rep(i, k) {
        ll mindif = (ll)(1e16);
        ll type = -1;
        if (aindex != 0 and a[x - 1] - a[aindex] < mindif) {
            mindif = a[x] - a[aindex];
            type = 0;
        }
        if (bindex != 0 and b[y - 1] - b[bindex] < mindif) {
            mindif = b[y] - b[bindex];
            type = 1;
        }
        if (cindex != 0 and c[z - 1] - c[cindex] < mindif) {
            mindif = c[z] - c[cindex];
            type = 2;
        }

        if (type == 0)
            aindex--;
        else if (type == 1)
            bindex--;
        else if (type == 2)
            cindex--;
    }
    // cout << aindex << " " << bindex << " " << cindex << endl;

    vector<ll> sum;
    FOR(i, aindex, x) {
        FOR(j, bindex, y) {
            FOR(l, cindex, z) { sum.push_back(a[i] + b[j] + c[l]); }
        }
    }
    sort(ALL(sum));
    reverse(ALL(sum));
    rep(i, k) { cout << sum[i] << endl; }

    return 0;
}