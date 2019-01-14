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

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> pyi;
    rep(i, m) {
        int p, y;
        cin >> p >> y;
        pyi.push_back(make_tuple(p, y, i));
    }
    sort(pyi.begin(), pyi.end());

    string ans[m];
    int index = 1;
    int old_p = 0;
    for (auto& t : pyi) {
        if (get<0>(t) == old_p)
            index++;
        else
            index = 1;
        // cout << index << endl;
        // cout << string(6 - to_string(get<0>(t)).length(), '0') +
        // to_string(get<0>(t))
        //  << endl;
        // cout << get<2>(t) << endl;
        ans[get<2>(t)] = string(6 - to_string(get<0>(t)).length(), '0') +
                         to_string(get<0>(t)) +
                         string(6 - to_string(index).length(), '0') +
                         to_string(index);
        // cout << ans[get<2>(t)] << endl;
        old_p = get<0>(t);
    }

    rep(i, m) cout << ans[i] << endl;

    return 0;
}