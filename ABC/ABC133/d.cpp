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

    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];

    ll l = -1LL, r = (ll)2e9 + (ll)10;
    while (1) {
        long double mid = (l + r) / 2;
        long double b[n];
        long long memo[n];
        rep(i, n) b[i] = 0;
        b[n - 1] += mid / 2;
        b[0] += mid / 2;
        memo[0] = mid;
        rep(i, n - 1) {
            long double rain = (long double)a[i] - b[i];
            b[i] += rain;
            b[i + 1] += rain;
            memo[i + 1] = rain * 2;
        }
        if (a[n - 1] == b[n - 1]) {
            rep(i, n) {
                if (i == n - 1)
                    cout << memo[i] << endl;
                else
                    cout << memo[i] << " ";
            }
            return 0;
        } else if (a[n - 1] > b[n - 1]) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return 0;
}