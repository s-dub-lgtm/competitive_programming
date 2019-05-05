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

    ll n;
    ll num[5];
    cin >> n;
    rep(i, 5) cin >> num[i];

    ll minnum = (ll)(1e16);
    int index;
    rep(i, 5) {
        if (num[i] < minnum) {
            minnum = num[i];
            index = i;
        }
    }

    if (minnum >= n) {
        cout << 5 << endl;
        return 0;
    }

    if (n % minnum == 0) {
        cout << n / minnum + 4 << endl;
    } else {
        cout << n / minnum + 5 << endl;
    }

    return 0;
}