#include <iostream>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    while (a % b != 0) a--;
    cout << a << endl;
    return 0;
}