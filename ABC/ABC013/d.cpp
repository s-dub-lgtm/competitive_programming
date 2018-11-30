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

    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m);
    rep(i, m) cin >> a[i];

    vector<int> to(n);
    rep(i, n) to[i] = i;
    for (int i = m - 1; i >= 0; --i) {
        swap(to[a[i]], to[a[i] - 1]);
    }

    vector<int> ret(n, -1);
    rep(i, n) {
        if (ret[i] != -1) continue;
        vector<int> v(1, i);
        while (to[v.back()] != i) {
            v.push_back(to[v.back()]);
        }

        int len = v.size();
        rep(j, len) { ret[v[j]] = v[(j + d) % len]; }
    }

    rep(i, n) cout << (ret[i] + 1) << endl;

    return 0;
}