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

    string s;
    cin >> s;

    bool yymm = true, mmyy = true;
    if (!("01" <= s.substr(2, 2) and s.substr(2, 2) <= "12")) yymm = false;
    if (!("01" <= s.substr(0, 2) and s.substr(0, 2) <= "12")) mmyy = false;

    if (yymm and mmyy)
        cout << "AMBIGUOUS" << endl;
    else if (yymm)
        cout << "YYMM" << endl;
    else if (mmyy)
        cout << "MMYY" << endl;
    else
        cout << "NA" << endl;

    return 0;
}