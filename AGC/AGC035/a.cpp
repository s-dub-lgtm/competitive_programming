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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    bool all_zero = true;
    rep(i, n) {
        if (a[i] != 0) all_zero = false;
    }
    if (all_zero) {
        cout << "Yes" << endl;
        return 0;
    }

    if (n == 3) {
        if ((int)(a[0] xor a[1]) == a[2])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return 0;
    }

    if (n % 3 != 0) {
        cout << "No" << endl;
        return 0;
    }

    map<int, int> m;
    rep(i, n) {
        if (m.find(a[i]) == m.end())
            m.insert(make_pair(a[i], 1));
        else
            m[a[i]]++;
    }
    map<int, int>::iterator ite;
    vector<int> memo;
    int cnt = 0;
    for (ite = m.begin(); ite != m.end(); ++ite) {
        if (cnt == 0) {
            cnt = ite->second;
            memo.push_back(ite->first);
        } else {
            if (cnt != ite->second) {
                cout << "No" << endl;
                return 0;
            }
        }
        memo.push_back(ite->first);
    }

    unique(all(memo));
    // for (int &t : memo) cout << t << " ";
    // cout << memo.size() << endl;

    if (memo.size() != 4) {
        cout << "No" << endl;
        return 0;
    }

    if ((int)(memo[0] xor memo[1]) == memo[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}