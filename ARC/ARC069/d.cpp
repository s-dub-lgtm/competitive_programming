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
    string s;
    cin >> n >> s;

    int cnt = 0;
    rep(i, n) {
        if (s[i] == 'x') cnt++;
    }
    if (cnt % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    bool w = false;
    rep(i, n) {
        if (s[i] == 'o') {
            if (w) {
                cout << 'W';
            } else {
                cout << 'S';
            }
        } else {
            cout << 'S';
            w = !w;
        }
    }

    return 0;
}