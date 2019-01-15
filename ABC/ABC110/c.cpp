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

    string s, t;
    cin >> s >> t;

    int a[26] = {}, b[26] = {};
    rep(i, s.length()) {
        a[s[i] - 'a']++;
        b[t[i] - 'a']++;
    }

    sort(a, a + 26);
    sort(b, b + 26);

    bool ok = true;
    rep(i, 26) {
        if (a[i] != b[i]) ok = false;
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}