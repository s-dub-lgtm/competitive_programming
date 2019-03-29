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

    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);

    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (1) {
        if (y % (m * d) == 0) {
            printf("%d/%02d/%02d\n", y, m, d);
            return 0;
        }

        int endd = day[m - 1];
        if (m == 2) {
            if (y % 4 == 0) endd++;
            if (y % 100 == 0) endd--;
            if (y % 400 == 0) endd++;
        }
        d = (d + 1) % (endd + 1);
        if (d == 0) {
            d++;
            m = (m + 1) % 13;
            if (m == 0) {
                m++;
                y = y + 1;
            }
        }
    }

    return 0;
}