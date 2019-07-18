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

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int cumsum[n + 1] = {};
    cumsum[0] = 0;
    int cnt = 0;
    bool a = false;
    rep(i, n) {
        cumsum[i + 1] = cumsum[i];
        if (a and s[i] == 'C') {
            cnt++;
            cumsum[i + 1] = cnt;
            a = false;
        } else if (s[i] == 'A') {
            a = true;
        } else {
            a = false;
        }
    }
    // rep(i, n + 1) cout << cumsum[i] << " ";

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << cumsum[r] - cumsum[l] << endl;
    }

    return 0;
}
