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

int top(int num) {
    int digits = log10(num) + 1;
    return num / pow(10, digits - 1);
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int cnt[10][10] = {};
    FORE(i, 1, n) { cnt[top(i)][i % 10]++; }

    int sum = 0;
    rep(i, 10) {
        rep(j, 10) { sum += cnt[i][j] * cnt[j][i]; }
    }

    cout << sum << endl;
    return 0;
}