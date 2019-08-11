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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll s;
    cin >> s;

    int digit = 0;
    ll tmp = s;
    while (tmp > 0) {
        tmp /= 10;
        digit++;
    }
    // cout << digit << endl;

    ll x1 = pow((ll)10, digit / 2);
    ll y2 = s / x1;
    // cout << x1 << " " << y2 << endl;
    if (x1 * y2 == s) {
        cout << 0 << " " << 0 << " " << x1 << " " << 0 << " " << 0 << " " << y2
             << endl;
        return 0;
    }

    ll dif = x1 * y2 - s;
    ll l = 1, r = 1e9 + 7;
    while (l * r != dif) {
        if (l * r > dif) {
            r = (l + r) / 2;
        } else {
            l = (l + r) / 2;
        }
        if (r - l < 2) break;
    }
    cout << 0 << " " << 0 << " " << x1 << " " << l << " " << r << " " << y2
         << endl;

    return 0;
}