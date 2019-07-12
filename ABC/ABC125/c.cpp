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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    int l = 0, r = 1e9 + 1;
    while (1) {
        int mid = (l + r) / 2;
        if (abs(l - r) <= 1) {
            cout << mid * 2 << endl;
            return 0;
        }

        int cnt = 0;
        rep(i, n) {
            if (a[i] % mid != 0) cnt++;
        }

        // if (cnt == 1) {
        //     cout << mid << endl;
        //     return 0;
        if (cnt == 0) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return 0;
}