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

    int a, b;
    cin >> a >> b;

    int dif = abs(b - a);
    int cnt = 0;
    while (dif != 0) {
        if (dif >= 10) {
            cnt++;
            dif -= 10;
        } else if (dif >= 5) {
            cnt += min(11 - dif, dif - 4);
            dif = 0;
        } else {
            cnt += min(6 - dif, dif);
            dif = 0;
        }
    }

    cout << cnt << endl;

    return 0;
}