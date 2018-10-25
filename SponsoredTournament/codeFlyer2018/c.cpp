#include <iostream>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

#define MAX_N 100000

int N;
ll D;
ll bit[MAX_N + 1];
ll X[MAX_N + 1];

ll sum(int i) {
    ll s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

ll sum(int a, int b) {//array[a]~array[b]までの総和を求めます
    if (a > b)
        return 0;
    return sum(b) - sum(a - 1);
}

void add(int i, ll x) {
    while (i <= N) {
        bit[i] += x;
        i += i & -i;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> D;
    for (int i = 1; i <= N; ++i) {
        cin >> X[i];
    }

    for (int i = 1; i <= N - 1; ++i) {
//        cout << X[i + 1] - X[i] << endl;
        add(i, X[i + 1] - X[i]);
    }

    ll cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
//                cout << i << " " << j << " " << k << endl;
//                cout << sum(i) << " " << sum(j) << " " << sum(k) << endl;
//                cout << sum(j) - sum(i) << endl;
//                cout << sum(k) - sum(j) << endl;
//                cout << sum(k) - sum(i) << endl;
                if (sum(j) - sum(i) > D) break;
                if (sum(k) - sum(j) > D) break;
                if (sum(k) - sum(i) > D) cnt++;
//                cout << cnt << endl;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}