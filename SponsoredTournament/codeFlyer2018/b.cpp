#include <iostream>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, n;
    string x;
    cin >> a >> b >> n >> x;

    for (int i = 0; i < n; ++i) {
        if (x[i] == 'S') {
            if (a > 0) a--;
        }
        if (x[i] == 'C') {
            if (b > 0) b--;
        }
        if (x[i] == 'E') {
            if (a == 0 && b == 0) continue;
            else if (a > 0 && b > 0 && a == b) a--;
            else if (a > b) a--;
            else if (a < b) b--;
        }
    }

    cout << a << endl;
    cout << b << endl;
    return 0;
}