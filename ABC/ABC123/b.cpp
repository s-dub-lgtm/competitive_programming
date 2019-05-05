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

    int t[5];
    rep(i, 5) cin >> t[i];

    int maxindex;
    int maxtime = INF;
    rep(i, 5) {
        int over = t[i] % 10;
        if (over != 0 and over < maxtime) {
            maxtime = over;
            maxindex = i;
        }
    }

    cout << maxtime << " " << maxindex << endl;

    int time = 0;
    rep(i, 5) {
        if (i != maxindex) {
            if (t[i] % 10 == 0) {
                time += t[i];
            } else {
                time += (t[i] / 10 + 1) * 10;
            }
        } else {
            time += t[i];
        }
    }

    cout << time << endl;

    return 0;
}