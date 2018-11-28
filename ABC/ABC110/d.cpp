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

ll modpow(ll a, ll n) {
    ll r = 1;
    while (n) r = r * ((n % 2) ? a : 1) % mod, a = a * a % mod, n >>= 1;
    return r;
}

ll comb(int p_, int q_) {
    if (p_ < 0 || q_ < 0 || q_ > p_) return 0;
    ll p = 1, q = 1;
    q_ = min(q_, p_ - q_);
    FORE(i, 1, q_) {
        p = p * p_ % mod;
        q = q * i % mod;
        p_--;
    }

    return p * modpow(q, mod - 2) % mod;
}

ll hcomb(int p, int q) { return (p == 0 && q == 0) ? 1 : comb(p + q - 1, q); }

map<ll, int> enumpr(ll n) {
    map<ll, int> v;

    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            v[i]++;
            n /= i;
        }
    }
    if (n > 1) v[n]++;
    return v;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    auto V = enumpr(m);

    ll ret = 1;
    for (auto &v : V) {
        ret = ret * hcomb(n, v.second) % mod;
    }
    cout << ret << endl;

    return 0;
}