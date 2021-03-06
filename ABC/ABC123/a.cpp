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

    int d[5];
    rep(i, 5) cin >> d[i];
    int k;
    cin >> k;

    bool ok = true;
    rep(i, 5) {
        FOR(j, i + 1, 5) {
            if (d[j] - d[i] > k) ok = false;
        }
    }

    if (ok)
        cout << "Yay!" << endl;
    else
        cout << ":(" << endl;

    return 0;
}