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

    string s;
    cin >> s;

    int cnt1 = 0;
    rep(i, s.length()) {
        if (i % 2 == 0) {
            if (s[i] == '1') cnt1++;
        } else {
            if (s[i] == '0') cnt1++;
        }
    }
    int cnt2 = 0;
    rep(i, s.length()) {
        if (i % 2 == 0) {
            if (s[i] == '0') cnt2++;
        } else {
            if (s[i] == '1') cnt2++;
        }
    }

    cout << min(cnt1, cnt2) << endl;

    return 0;
}