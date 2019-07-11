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
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

#define k 7368795
bool pt[k + 10];
int prime[k + 10];

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int p = 0;
    repe(i, k) pt[i] = true;
    pt[0] = pt[1] = false;
    FORE(i, 2, k) {
        if (pt[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= k; j += i) pt[j] = false;
        }
    }

    while (1) {
        int m, n;
        cin >> m >> n;
        if (m == 0 and n == 0) return 0;
        if (n == 1) {
            cout << m + 1 << endl;
            continue;
        }
        if (m > n) {
            cout << m + n << endl;
            continue;
        }

        int cnt = 0;
        FOR(i, 2, m) {
            bool is_prime = true;
            for (int j = 2; j * j <= i; j++) {
                if (!(i % j)) is_prime = false;
            }
            if (is_prime) cnt++;
        }

        n = n + cnt;
        cout << prime[n - 1] << endl;
    }

    return 0;
}